#include "main.h"

/*

CONFIGURATION - MUST BE IN MAIN

*/


// important constants
const float track_width = 10;
const int inertial_port = 20;

// auton selector
int autonSelect = 0;


// drivetrain initialization

pros::MotorGroup left_motor({1, -2, -13}, pros::MotorGearset::blue);
pros::MotorGroup right_motor({5, -6, 14}, pros::MotorGearset::blue);
lemlib::Drivetrain drivetrain(&left_motor, &right_motor, track_width, lemlib::Omniwheel::NEW_325, 360, 2);

pros::Imu inertial(inertial_port);

lemlib::OdomSensors odometry(nullptr, nullptr, nullptr, nullptr, &inertial);

// lateral PID controller
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

lemlib::ExpoDriveCurve throttle_curve(3, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1.016 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steer_curve(3, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  1.016 // expo curve gain
);

lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, odometry, &throttle_curve, &steer_curve);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	
	pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    // print position to brain screen
    pros::Task screen_task([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // delay to save resources
            pros::delay(20);
        }
    });
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	/**
 		TODO MAKE AUTONOMOUS SELECTOR
   		something like:

     		initialize the button (idk how)
       		
       		while (true)
        	{
            	if (autonSelect < 3 && button.HIGH)
            	{
               	 autonSelect++;
               	 pros::delay(200);
            	}
            	else if (button.HIGH)
            	{
             	   autonSelect = 0;
	               	 pros::delay(200);
           	 }
           	 pros::delay(5);
            	if (autonSelect == 0)
            	{
                	pros::lcd::print(0, “Selected Auton 1 (Red Left)”);
            	}
            	else if (autonSelect == 1)
            	{
              	       pros::lcd::print(0, “Selected Auton 2 (Red Right)”);
           	 }
            	else if (autonSelect == 2)
            	{
                	pros::lcd::print(0, “Selected Auton 3 (Blue Left)”);
            	}	
            	else if (autonSelect == 3)
            	{
                	pros::lcd::print(0, “Selected Auton 4 (Blue Right)”);
            	}
            	pros::delay(10);
        }	
 	*/
}

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
	/**
 		-----------------------------------------------------------------------------
 		NEED TO TUNE:

   		// set position to x:0, y:0, heading:0
    		chassis.setPose(0, 0, 0);
    		// turn to face heading 90 with a very long timeout
    		chassis.turnToHeading(90, 100000);
   		lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in inches
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in inches
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
		);
  		USE THIS FOR TUNING ^^^^
    		INCREASE kP/kD until kD never stops it from oscillating no matter how high

      		REPEAT FOR LATERAL CONTROLLER TOO:
		lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in inches
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in inches
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
		);

		------------------------------------------------------------------------------
  		
 	*/

}

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
	while(true){

		driveMotors();
        intakeUpdate();
        clampUpdate();
		pros::delay(20);
	
	}
}
