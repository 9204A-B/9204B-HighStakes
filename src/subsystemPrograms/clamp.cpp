#include "main.h"

void clampUpdate(){
    if(controller1.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){

        clamp.set_value(HIGH);

    } else if (controller1.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)){

        clamp.set_value(LOW);
        
    }
    
}