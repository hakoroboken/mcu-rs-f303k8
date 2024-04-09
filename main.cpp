#include "mbed.h"
#include <cstdint>
#include <cstdio>
#include <string>

#if !DEVICE_CAN
#error [NOT_SUPPORTED] CAN not supported for this target
#endif

CAN can(PA_11, PA_12, 1000 * 1000);
static UnbufferedSerial serial_port(PA_9, PA_10);

DigitalIn  rp2040_life(PA_8);
DigitalIn  cw_ccw(PB_5);

namespace motor_param{
    int16_t SET_SPEED;
    int16_t speed;
    int16_t power;
    int16_t p_gain;
    int16_t d_gain;
    int16_t err_last;
}

// Constants and Variables
constexpr int16_t MAX_POWER = 2211;
constexpr int16_t MIN_POWER = -2211;

Ticker flipper;
volatile bool newCanMessage = false;
uint8_t motor_send_count = 0;
volatile bool motor_data_send_flag = false;

// MRM
uint8_t motor_life_check = 0;
uint8_t host_controller_life_check = 0;

// PID
const double rpm2ampare = 0.29411764705882354;

double prev_input_UsinginputDelay;
double prev_output_UsinginputDelay;

double inputDelay(double input){
    double output = 0.04761904761904762*input + 0.04761904761904762* prev_input_UsinginputDelay + 0.9047619047619048* prev_output_UsinginputDelay;

    prev_input_UsinginputDelay = input;
    prev_output_UsinginputDelay = output;

    return output;
}

double plantModel;
double prev_ampare;
double prev_output;

double Pm( double wantAmpare){
    plantModel = 0.085 * wantAmpare + 0.085 * prev_ampare + 0.95 * prev_output;

    prev_ampare = wantAmpare;
    prev_output = plantModel;

    return plantModel;
}

const double Kp_speed = 6.5;

void calculatePID() {
    const double filteredRPM = inputDelay((double)motor_param::SET_SPEED);
    const double needRPM = filteredRPM + Kp_speed * (filteredRPM - motor_param::speed);
    const double wantAmpare = needRPM * rpm2ampare;
    const double modelValue = Pm( wantAmpare);
    double inputAmpare = wantAmpare + ( modelValue - motor_param::speed);
    motor_param::power = inputAmpare;
    
    // Saturation Logic
    if (motor_param::power > MAX_POWER) motor_param::power = MAX_POWER;
    if (motor_param::power < MIN_POWER) motor_param::power = MIN_POWER;
}

void flip() {
    calculatePID();
    newCanMessage = true;

    // data
    motor_send_count++;
    if(motor_send_count > 7){
        motor_send_count = 0;
        motor_data_send_flag = true;
    }

    // MRM
    motor_life_check++;
    if(motor_life_check > 50){
        motor_life_check = 51;
        motor_param::power = 0;
        motor_param::err_last = 0;
    }

    // MRM
    host_controller_life_check++;
    if(host_controller_life_check > 50){
        host_controller_life_check = 51;
        motor_param::power = 0;
        motor_param::err_last = 0;
    }
}

void on_rx_interrupt()
{
    host_controller_life_check = 0;
    uint8_t power;

    if (!serial_port.read(&power, 1)) { return;}

    if(cw_ccw){
        motor_param::SET_SPEED = power * 19;
    }else{
        motor_param::SET_SPEED = power * 19 * -1;
    }
}



int main() {
    serial_port.baud(115200);
    serial_port.format(8, SerialBase::None,  1);
    serial_port.attach(&on_rx_interrupt, SerialBase::RxIrq);

    motor_param::p_gain = 10;
    motor_param::d_gain = 2;
    motor_param::SET_SPEED = 0;

    flipper.attach(&flip, 4ms);

    rp2040_life.mode(PullDown);
    cw_ccw.mode(PullDown);

    while (1) {

        CANMessage rcv_msg;
        if (can.read(rcv_msg) == 1) {
            if (rcv_msg.id == 0x201) {
                motor_param::speed  = static_cast<int16_t>((rcv_msg.data[2] << 8) | rcv_msg.data[3]);
                motor_life_check = 0;
            }
        }

        // Check flag and send CAN message outside of ISR
        if (newCanMessage) {
            auto msg = CANMessage();
            msg.id = 0x200;
            msg.len = 8;
            msg.data[0] = (motor_param::power >> 8) & 0xff;
            msg.data[1] = motor_param::power & 0xff;
            can.write(msg);
            newCanMessage = false;
        }

        if(motor_data_send_flag){
            motor_data_send_flag = false;
            char str[10];
            sprintf(str, "%d\n", motor_param::speed);
            serial_port.write(str, strlen(str));
        }
    }
}
