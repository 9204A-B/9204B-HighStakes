#include "lemlib/api.hpp"

// DECLARATIONS

// motor groups
extern pros::MotorGroup left_motor;
extern pros::MotorGroup right_motor;

// drivetrain setup
extern lemlib::Drivetrain drivetrain;

// inertial setup
extern pros::Imu inertial;

// odometry setup
extern lemlib::OdomSensors odometry;
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;

// total setup
extern lemlib::Chassis chassis;

// controller initialization
extern pros::Controller controller1;

// expo drive declaration
extern lemlib::ExpoDriveCurve throttle_curve;
extern lemlib::ExpoDriveCurve steer_curve;

// intake 
extern pros::Motor intake;

// ladybrown
extern pros::Motor ladybrown;

// doinker

// mogo mech

extern pros::ADIDigitalOut clamp;

// IMPORTANT CONSTANTS