#include "main.h"
#include "config.hpp"

// Define ports for motors and devices.
#define LEFT_BACK_PORT 3
#define LEFT_FRONT_PORT 4
#define RIGHT_BACK_PORT -1
#define RIGHT_FRONT_PORT -2
#define INTAKE_PORT 5
#define ROLLER_PORT 10
#define LAUNCHER_PORT 7

// Configure controllers.
pros::Controller master(pros::E_CONTROLLER_MASTER);

// Configure the sensors.
extern pros::Vision color_sensor;
extern pros::vision_signature_s_t RED_SIG;
extern pros::vision_signature_s_t BLUE_SIG;

// Configure drivetrain motors.
pros::Motor left_back(LEFT_BACK_PORT, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left_front(LEFT_FRONT_PORT, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_back(RIGHT_BACK_PORT, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_front(RIGHT_FRONT_PORT, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor_Group left_wheels({left_back, left_front});
pros::Motor_Group right_wheels({right_back, right_front});

// Configure other motors.
pros::Motor intake(INTAKE_PORT, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor roller(ROLLER_PORT, pros::E_MOTOR_GEARSET_36, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor launcher(LAUNCHER_PORT, pros::E_MOTOR_GEARSET_06, pros::E_MOTOR_ENCODER_DEGREES);

// Configure configurable constants.
int ROLLER_SPIN_TIME = 125;