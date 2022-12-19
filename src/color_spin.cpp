#include "main.h"
#include "config.hpp"

// Spin the roller until the detected hue is in between the accepted color values.
void color_spin() {

    while (true) {

        // Get the hue of the color.
        double detected_color = color_sensor.getHue();

        // If the detected color is in between the accepted color values, stop the roller.
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