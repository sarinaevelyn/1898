#include "main.h"
#include "subsystemFiles/globals.hpp"
/*This is where I define all of my flicker functions
*/

//HELPER FUNCTION
   void setFlicker(int power){
     flicker = power;
  }
  void resetFlickerEncoders(){
    flicker.tare_position();
  }

 //DRIVER CONTROL FUNCTIONS
 void  setFlickerMotors(){
   //LEFT TRIGGERS
   int flickerOn = 200 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_B));
  //  int flickerOff = -127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT));
   setFlicker(flickerOn);
  //  setFlicker(flickerOff);
 }

void flickerAuton(int units, int voltage){
int direction = abs(units/units);
resetFlickerEncoders();
while(abs(flicker.get_encoder_units())<abs(units)){
 setFlicker(voltage);
 pros::delay(10);
 setFlicker(0);
}
}