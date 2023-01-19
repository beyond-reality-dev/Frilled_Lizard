#include "main.h"
#include "config.hpp"
#include "color_spin.hpp"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

// Define ports for motors and devices.
#define LEFT_BACK_PORT 3
#define LEFT_FRONT_PORT 4
#define RIGHT_BACK_PORT -1
#define RIGHT_FRONT_PORT -2
#define INTAKE_PORT 5
#define ROLLER_PORT 6
#define LAUNCHER_PORT 7

// Configure controllers.
pros::Controller master(pros::E_CONTROLLER_MASTER);

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
pros::Motor launcher(LAUNCHER_PORT, pros::E_MOTOR_GEARSET_36, pros::E_MOTOR_ENCODER_DEGREES);

void opcontrol() {

	// Set booleans for the toggle switches.
	bool intakeOn = false;
	bool intake_button_held = false;
	bool launcherOn = false;
	bool launcher_button_held = false;

	while (true) {

		// Use the left joystick to move the left wheels of the robot.
		left_wheels.move(master.get_analog(ANALOG_LEFT_Y));

		// Use the right joystick to move the right wheels of the robot.
		right_wheels.move(master.get_analog(ANALOG_RIGHT_Y));

		// Use the R1 button to toggle the intake.
		if (master.get_digital(DIGITAL_R1)) {

			if (!intake_button_held) {

				intake_button_held = true;
				intakeOn = !intakeOn;

				if (intakeOn) {
					intake.move(127);
				}

				else {
					intake.move(0);
				}

			}

            else {
                intake_button_held = false;
            }

		}

		// Use the R2 button to toggle the launcher.
		if (master.get_digital(DIGITAL_R2)) {

			if (!launcher_button_held) {

				launcher_button_held = true;
				launcherOn = !launcherOn;

				if (launcherOn) {
					launcher.move(127);
				}

				else {
					launcher.move(0);
				}

			}

			else {
				launcher_button_held = false;
			}
			
		}

		// Use the L1 button to automatically spin the roller to the target color. (WIP)
		/*	if (master.get_digital(DIGITAL_L1)) {
			color_spin();
		}*/
		if (master.get_digital(DIGITAL_L1)) {
		roller.move(-127);
		}

		// Use the L2 button to manually spin the roller.
		else if (master.get_digital(DIGITAL_L2)) {
			roller.move(127);
		}
	
    }

}