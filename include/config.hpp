#pragma once
#include "main.h"

// Define the controllers.
extern pros::Controller master;

// Define the sensors.
extern OpticalSensor color_sensor;

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
extern std::pair<double, double> color_tolerance;
extern std::string target_color;