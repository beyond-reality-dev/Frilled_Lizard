#include "main.h"
#include "config.hpp"
#include "color_spin.hpp"

// Configure sensors.
#define VISION_SENSOR_PORT 20
pros::Vision color_sensor(VISION_SENSOR_PORT);
pros::vision_signature_s_t RED_SIG = color_sensor.get_signature(1);
pros::vision_signature_s_t BLUE_SIG = color_sensor.get_signature(2);
std::string target_color;

// Spin the roller until the detected hue is in between the accepted color values.
void color_spin() {

    // Set the not_target_color variable to true.
    bool not_target_color = true;

    while (not_target_color == true) {

        // If the target color is red, roll the roller until red is no longer detected.
        if (target_color == "red") {
            
            // Detect the color of the bottom of the roller.
            pros::vision_object_s_t detected_color = color_sensor.get_by_sig(0, RED_SIG.id);

            // If red is detected, spin the roller.
            if (detected_color.signature != 255) {
                roller.move_relative(10, 100);
                pros::delay(20);
            }

            // If red is not detected, stop the roller.
            else {
                roller.move(0);
                bool not_target_color = false;
                break;
            }

        }

        // If the target color is blue, roll the roller until blue is no longer detected.
        else if (target_color == "blue") {
            
            // Detect the color of the bottom of the roller.
            pros::vision_object_s_t detected_color = color_sensor.get_by_sig(0, BLUE_SIG.id);

            // If blue is detected, spin the roller.
            if (detected_color.signature != 255) {
                roller.move_relative(10, 100);
                pros::delay(20);
            }

            // If blue is not detected, stop the roller.
            else {
                roller.move(0);
                bool not_target_color = false;
                break;
            }
            
        }

    }

}