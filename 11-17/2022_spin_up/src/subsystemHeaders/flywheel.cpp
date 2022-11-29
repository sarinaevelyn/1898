#include "main.h"
#include "subsystemFiles/globals.hpp"
/*This is where I define all of my flywheel functions
*/

//HELPER FUNCTION
   void setFlywheel(int power){
     flywheel = power;
  }

 //DRIVER CONTROL FUNCTIONS
 void  setFlywheelMotors(){
   //LEFT TRIGGERS
   int flywheelOn = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
   setFlywheel(flywheelOn);
 }
