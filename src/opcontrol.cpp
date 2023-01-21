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
#define ROLLER_PORT 10
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
	bool intakeStopped = false;
	bool launcherStopped = false;
	bool rollerStopped = true;

	while (true) {

		// Use the left joystick to move the left wheels of the robot.
		left_wheels.move(master.get_analog(ANALOG_LEFT_Y));

		// Use the right joystick to move the right wheels of the robot.
		right_wheels.move(master.get_analog(ANALOG_RIGHT_Y));

		// Use the R1 button to toggle the intake on.
		if (master.get_digital(DIGITAL_R1) && intakeStopped == true) {
			intake.move(127);
			intakeStopped = false;
			pros::delay(100);
		}

		// Use the R1 button to toggle the intake off if it is already on.
		else if (master.get_digital(DIGITAL_R1) && intakeStopped == false) {
			intake.move(0);
			intakeStopped = true;
			pros::delay(100);
		}

		// Use the R2 button to toggle the launcher on.
		else if (master.get_digital(DIGITAL_R2) && launcherStopped == true) {
			launcher.move(127);
			launcherStopped = true;
			pros::delay(100);
		}

		// Use the R2 button to toggle the launcher off if it is already on.
		else if (master.get_digital(DIGITAL_R2) && launcherStopped == false) {
			launcher.move(0);
			launcherStopped = true;
			pros::delay(100);
		}

		// Use the L1 button to manually spin the roller.
		if (master.get_digital(DIGITAL_L1)) {
			roller.move(127);
			rollerStopped = false;
		}

		// Use the L2 button to manually spin the roller.
		else if (master.get_digital(DIGITAL_L2)) {
			roller.move(-127);
			rollerStopped = false;
		}

		// If neither the L1 or L2 buttons are pressed, stop the roller.
		else if (rollerStopped == false) {
			roller.move(0);
			rollerStopped = true;
		}

    }

}