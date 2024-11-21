#include "main.h"

pros::Controller controller1(pros::E_CONTROLLER_MASTER);

pros::Motor intake(8, pros::MotorGearset::green);

pros::Motor ladybrown(11, pros::MotorGearset::red);



pros::ADIDigitalOut clamp('H');