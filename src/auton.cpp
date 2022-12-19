#include "main.h"
#include "config.hpp"
#include "autoSelect/selection.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

void autonomous() {

// Create a chassis with 4 motors, 4 inch wheel diameter, 14 inch wheel track, and configures odometry.
	std::shared_ptr<OdomChassisController> drivetrain = ChassisControllerBuilder()
    // Set the ports of the left and right motors.
    .withMotors(
        {3, 4}, // Left motors are at ports 3 & 4.
        {-1, -2} // Right motors are at ports 1 & 2 (reversed).
    )
    // Use the green gearset, 4 inch wheel diameter, and 14 inch wheel track.
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 14_in}, imev5GreenTPR})
    // Use the same scales as the chassis.
    .withOdometry()
    // Build an odometry chassis.
    .buildOdometry();

// Runs the autonomous code for the left side, red alliance (WIP).
if (selector::auton == 1) {

	// Set the drivetrain state to zero.
	drivetrain->setState({0_in, 0_in, 0_deg});

	// Move the drivetrain backward 2 inches.
	drivetrain->moveDistance(-2_in);

    // Turn the roller 90 degrees, at an rpm of 100.
    roller.move_relative(90, 100);

}

// Runs the autonomous code for the right side, red alliance.
else if (selector::auton == 2) {
	
    pros::delay(20);

}

// Does nothing for the red alliance
else if (selector::auton == 3) {
	
    pros::delay(20);

}

// Runs the autonomous code for the left side, blue alliance.
else if (selector::auton == -1) {
	
    pros::delay(20);

}

// Runs the autonomous code for the right side, blue alliance.
else if (selector::auton == -2) {
	
    pros::delay(20);

}

// Does nothing for the blue alliance
else if (selector::auton == -3) {
	
    pros::delay(20);

}

// Runs the skills autonomous code.
else if (selector::auton == 0) {
	
    // Set the drivetrain state to zero.
	drivetrain->setState({0_in, 0_in, 0_deg});

	// Move the drivetrain backward 2 inches.
	drivetrain->moveDistance(-2_in);

    // Turn the roller 180 degrees, at an rpm of 100.
    roller.move_relative(180, 100);

    // Move the drivetrain forward 2 feet.
    drivetrain->moveDistance(2_ft);

	// Turn the drivetrain 45 degrees to the right.
	drivetrain->turnAngle(45_deg);

    // Move the drivetrain forward 12.7 feet.
    drivetrain->moveDistance(12.7_ft);

}

}