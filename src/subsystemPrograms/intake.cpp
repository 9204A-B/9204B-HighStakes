#include "main.h"
void intakeState(int state){
    intake.move_velocity(200*state);
    
}

void intakeUpdate(){
    if(controller1.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){
        intakeState(1);
    } else if (controller1.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)){
        intakeState(-1);
    } else if (controller1.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){
        intakeState(0);
    }
    
    
    
}