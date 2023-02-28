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

void opcontrol() {

	// Set booleans for the toggle switches.
	bool intakeStopped = true;
	bool launcherStopped = true;
	bool rollerStopped = true;
	bool expansionActivated = false;

	while (true) {

		// Use the left joystick to move the left wheels of the robot.
		left_wheels.move(master.get_analog(ANALOG_LEFT_Y));

		// Use the right joystick to move the right wheels of the robot.
		right_wheels.move(master.get_analog(ANALOG_RIGHT_Y));

		// Use the L1 button to spin the roller.
		if (master.get_digital(DIGITAL_L1)) {
			roller.move(127);
			rollerStopped = false;
		}

		// If L1 button is not pressed, stop the roller.
		else if (rollerStopped == false) {
			roller.move(0);
			rollerStopped = true;
		}

		// Use the L2 button to toggle the intake on.
		if (master.get_digital(DIGITAL_L2) && intakeStopped == true) {
			intake.move(60);
			intakeStopped = false;
			pros::delay(20);
		}

		// Use the L2 button to toggle the intake off if it is already on.
		else if (master.get_digital(DIGITAL_L2) && intakeStopped == false) {
			intake.move(0);
			intakeStopped = true;
			pros::delay(20);
		}

		// Use the R1 button to extend and retract the pneumatic plunger twice.
		if (master.get_digital(DIGITAL_R1)) {
			plunger.set_value(true);
			pros::delay(500);
			plunger.set_value(false);
			pros::delay(500);
			plunger.set_value(true);
			pros::delay(500);
			plunger.set_value(false);
		}

		// Use the R2 button to toggle the launcher on.
		if (master.get_digital(DIGITAL_R2) && launcherStopped == true) {
			launcher.move(127);
			launcherStopped = false;
			pros::delay(20);
		}

		// Use the R2 button to toggle the launcher off if it is already on.
		else if (master.get_digital(DIGITAL_R2) && launcherStopped == false) {
			launcher.move(0);
			launcherStopped = true;
			pros::delay(20);
		}

		// Use the Y button to activate the expansion mechanism.
		if (master.get_digital(DIGITAL_Y) && expansionActivated == false) {
			expander.set_value(true);
			expansionActivated = true;
			pros::delay(1000);
			expander.set_value(false);
    }

}