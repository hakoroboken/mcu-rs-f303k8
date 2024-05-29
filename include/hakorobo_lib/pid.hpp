// Copyright 2024 Hakoroboken
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef HAKOROBO_PID_HPP_
#define HAKOROBO_PID_HPP_

#include "hakorobo_lib/cpp_std_lib.hpp"

namespace hakorobo {
    namespace pid {
        template <typename T>
        struct pid_parameter{
            T sense_speed_rpm;
            T target_speed_rpm;
            const T pid_pram_k;
            const T max_power;
            const T min_power;
            T control_order;
        };

        template <typename T>
        inline const T inputDelay(const T & input){
            static T prev_input_UsinginputDelay = 0;
            static T prev_output_UsinginputDelay = 0;

            const auto output = 
                0.04761904761904762 * input + 
                0.04761904761904762 * prev_input_UsinginputDelay + 
                0.9047619047619048 * prev_output_UsinginputDelay;

            prev_input_UsinginputDelay = input;
            prev_output_UsinginputDelay = output;

            return output;
        }

        template <typename T>
        inline const T Pm(const T & wantAmpare){
            static double prev_ampare = 0;
            static double prev_output = 0;

            const auto plantModel = 0.085 * wantAmpare + 0.085 * prev_ampare + 0.95 * prev_output;

            prev_ampare = wantAmpare;
            prev_output = plantModel;

            return plantModel;
        }

        template <typename T>
        inline const T calculatePID(const pid_parameter<T>& param) {
            const double filteredRPM = hakorobo::pid::inputDelay(param.target_speed_rpm);
            const double needRPM = filteredRPM + param.pid_pram_k * (filteredRPM - param.sense_speed_rpm);
            const double wantAmpare = needRPM * 0.29411764705882354;
            const double modelValue = hakorobo::pid::Pm( wantAmpare);
            double inputAmpare = wantAmpare + ( modelValue - param.sense_speed_rpm);
            
            return lib_std::clamp(inputAmpare, param.min_power, param.max_power);
        }
    }
}

#endif