#include "lemlib/api.hpp"
#include "main.h"
void driveMotors(){
    int rightX = controller1.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    int leftY = controller1.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    chassis.arcade(leftY, rightX);
}