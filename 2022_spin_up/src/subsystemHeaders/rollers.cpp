#include "main.h"
#include "pros/misc.h"
#include "subsystemFiles/globals.hpp"
/*This is where I define all of my roller functions
*/

//HELPER FUNCTION
   void setRoller(int power){
     roller = power;
  }

 //DRIVER CONTROL FUNCTIONS
 void  setRollerMotors(){
   //LEFT TRIGGERS
   int rollerOn = 250 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT));
   setRoller(rollerOn);
 }