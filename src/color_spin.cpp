#include "main.h"
#include "config.hpp"

// Spin the roller until the detected hue is in between the accepted color values.
void color_spin() {

    // Set the not_target_color variable to true.
    bool not_target_color = true;

    while (not_target_color == true) {

        // If the target color is red, roll the roller until the detected color is in between the accepted color values.
        if (target_color == "red") {
            double detected_color = color_sensor.getHue();
            if (detected_color >= color_tolerance.first or detected_color <= color_tolerance.second) {
                roller.move(0);
                break;
            }
            else {
                roller.move_relative(10, 100);
                pros::delay(20);
            }
        }

        // If the target color is blue, roll the roller until the detected color is in between the accepted color values.
        else if (target_color == "blue") {
            double detected_color = color_sensor.getHue();
            if (detected_color >= color_tolerance.first && detected_color <= color_tolerance.second) {
                roller.move(0);
                break;
            }
            else {
                roller.move_relative(10, 100);
                pros::delay(20);
            }
        }
        
    }

}