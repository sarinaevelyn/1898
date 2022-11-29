#include "main.h"
#include "subsystemFiles/globals.hpp"
/*This is where I define all of my flywheel functions
*/

//HELPER FUNCTION
   void setFlywheel(int power){
     flywheel = power;
  }
  void resetFlywheelEncoders(){
    flywheel.tare_position();
  }


 //DRIVER CONTROL FUNCTIONS
 void  setFlywheelMotors(){
   //LEFT TRIGGERS
   int halfSpeed = 100;
   int flywheelOn = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1))+ halfSpeed * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));;
   setFlywheel(flywheelOn);
 }


void flywheelAuton(int units, int voltage){
  int direction = abs(units/units);
  resetFlywheelEncoders();
  while(abs(flywheel.get_encoder_units())<abs(units)){
    setFlywheel(voltage);
    pros::delay(10);
    setFlywheel(0);
  }
}
