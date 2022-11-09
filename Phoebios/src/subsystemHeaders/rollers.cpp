#include "main.h"
#include "pros/misc.h"
#include "pros/screen.h"
#include "subsystemFiles/globals.hpp"
/*This is where I define all of my roller functions
*/

//HELPER FUNCTION
 void setRoller(int power){
     roller = power;
  }

  void resetRollerEncoders(){
    roller.tare_position();
  }
 //DRIVER CONTROL FUNCTIONS
 void  setRollerMotors(){
   //LEFT TRIGGERS
   int rollerOn = 250 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT));
   setRoller(rollerOn);
 }

void rollerAuton(int units, int voltage){
int direction = abs(units/units);
resetRollerEncoders();
while(abs(roller.get_encoder_units())<abs(units)){
 setRoller(voltage);
 pros::delay(10);
 setRoller(0);
  }
}

void rollerAutonV2on(){

}