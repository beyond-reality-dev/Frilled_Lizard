#pragma once
#include "main.h"

// Define the controllers.
extern pros::Controller master;

// Define the sensors.
extern pros::Vision color_sensor;
extern pros::vision_signature_s_t RED_SIG;
extern pros::vision_signature_s_t BLUE_SIG;

// Define the drivetrain motors.
extern pros::Motor left_back;
extern pros::Motor left_front;
extern pros::Motor right_back;
extern pros::Motor right_front;
extern pros::Motor_Group left_wheels;
extern pros::Motor_Group right_wheels;

// Define the other motors.
extern pros::Motor intake;
extern pros::Motor roller;
extern pros::Motor launcher;

// Define variables.
extern std::string target_color;