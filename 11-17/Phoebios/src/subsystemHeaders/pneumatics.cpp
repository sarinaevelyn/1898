#include "display/lv_objx/lv_btnm.h"
#include "main.h"
#include "pros/misc.h"
#define DIGITAL_SENSOR_PORT 4
#define DIGITAL_SENSOR_PORT_2 2
pros::ADIDigitalOut expansion (DIGITAL_SENSOR_PORT);
pros::ADIDigitalOut otherExpansion (DIGITAL_SENSOR_PORT_2);
bool state = false;
void expansionOn(){
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)){
        state= true;
        expansion.set_value(state);
        pros::screen::print(pros::E_TEXT_MEDIUM_CENTER,2,"I was pressed!");

    }
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){
        state= false;
        expansion.set_value(state);
        pros::screen::print(pros::E_TEXT_MEDIUM_CENTER,2,"I was pressed!");

    }
}
void pneumaticsAuton(){
    state = true;
    expansion.set_value(state);
}