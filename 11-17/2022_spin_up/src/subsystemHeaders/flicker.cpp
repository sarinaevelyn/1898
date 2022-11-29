#include "main.h"
#include "subsystemFiles/globals.hpp"
/*This is where I define all of my flicker functions
*/

//HELPER FUNCTION
   void setFlicker(int power){
     flicker = power;
  }

 //DRIVER CONTROL FUNCTIONS
 void  setFlickerMotors(){
   //LEFT TRIGGERS
   int flickerOn = 200 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_B));
  //  int flickerOff = -127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT));
   setFlicker(flickerOn);
  //  setFlicker(flickerOff);
 }
