#include "mbed.h"
#include <cstdint>
#include <cstdio>
#include <string>

#include "hakorobo_lib/pid.hpp"
#include "hakorobo_lib/cpp_std_lib.hpp"


#if !DEVICE_CAN
#error [NOT_SUPPORTED] CAN not supported for this target
#endif

CAN can(PA_11, PA_12, 1000 * 1000);
static UnbufferedSerial serial_port(PA_9, PA_10);
DigitalIn  cw_ccw(PB_5);
DigitalOut rp2040reseter(PB_4);


hakorobo::pid::pid_parameter<double> pid_param = {
    0.0,    // sense_speed_rpm
    0.0,    // target_speed_rpm
    6.5,    // pid_pram_k
    16384,  // max_power
    -16384, // min_power
    0.0     // control_order
};

Ticker flipper;
volatile bool newCanMessage = false;
uint8_t motor_send_count = 0;
volatile bool motor_data_send_flag = false;

// MRM
uint8_t motor_life_check = 0;
uint8_t host_controller_life_check = 0;


void flip() {
    pid_param.control_order = hakorobo::pid::calculatePID(pid_param);
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
        pid_param.control_order = 0.0;
    }

    // MRM
    host_controller_life_check++;
    if(host_controller_life_check > 50){
        host_controller_life_check = 51;
        pid_param.control_order = 0.0;
    }
}

void on_rx_interrupt()
{
    host_controller_life_check = 0;
    uint8_t power;

    if (!serial_port.read(&power, 1)) { return;}

    if(cw_ccw){
        pid_param.target_speed_rpm = power * 19;
    }else{
        pid_param.target_speed_rpm = power * 19 * -1;
    }
}

int main() {
    serial_port.baud(115200);
    serial_port.format(8, SerialBase::None,  1);
    serial_port.attach(&on_rx_interrupt, SerialBase::RxIrq);

    flipper.attach(&flip, 4ms);
    cw_ccw.mode(PullDown);

    {
        // rp2040 reset
        ThisThread::sleep_for(500ms);
        rp2040reseter.write(0);
        ThisThread::sleep_for(10ms);
        rp2040reseter.write(1);
    }

    while (1) {

        CANMessage rcv_msg;
        if (can.read(rcv_msg) == 1) {
            if (rcv_msg.id == 0x201) {
                pid_param.sense_speed_rpm  = static_cast<int16_t>((rcv_msg.data[2] << 8) | rcv_msg.data[3]);
                motor_life_check = 0;
            }
        }

        // Check flag and send CAN message outside of ISR
        if (newCanMessage) {
            auto msg = CANMessage();
            msg.id = 0x200;
            msg.len = 8;
            msg.data[0] = (static_cast<int16_t>(pid_param.control_order) >> 8) & 0xff;
            msg.data[1] = static_cast<int16_t>(pid_param.control_order) & 0xff;
            can.write(msg);
            newCanMessage = false;
        }

        if(motor_data_send_flag){
            motor_data_send_flag = false;
            char str[10];
            sprintf(str, "%d\n", static_cast<int16_t>(pid_param.sense_speed_rpm));
            serial_port.write(str, strlen(str));
        }
    }
}