#pragma once
#include "main.h"

// Declare the drivetrain ports.
extern int LEFT_BACK_PORT;
extern int LEFT_FRONT_PORT;
extern int RIGHT_BACK_PORT;
extern int RIGHT_FRONT_PORT;

// Declare the other motor ports.
extern int INTAKE_PORT;
extern int ROLLER_PORT;
extern int LAUNCHER_PORT;

// Declare the pneumatic ports.
extern int PLUNGER_PORT;

// Declare the sensor ports.
extern int COLOR_SENSOR_PORT;

// Declare the controllers.
extern pros::Controller master;

// Declare the sensors.
extern pros::Vision color_sensor;
extern pros::vision_signature_s_t RED_SIG;
extern pros::vision_signature_s_t BLUE_SIG;

// Declare the drivetrain motors.
extern pros::Motor left_back;
extern pros::Motor left_front;
extern pros::Motor right_back;
extern pros::Motor right_front;
extern pros::Motor_Group left_wheels;
extern pros::Motor_Group right_wheels;

// Declare the other motors.
extern pros::Motor intake;
extern pros::Motor roller;
extern pros::Motor launcher;

// Declare the pneumatics.
extern pros::ADIDigitalOut plunger;

// Declare configurable constants.
extern int ROLLER_QUARTER_SPIN_TIME;
extern int ROLLER_HALF_SPIN_TIME;