#include "main.h"
#include "subsystemFiles/globals.hpp"

/*This is where I define all of my intake functions
*/

//HELPER FUNCTION
   void setIntake(int power){
     intake = power;
  }

  void resetIntakeEncoders(){
    intake.tare_position();
  }

 //DRIVER CONTROL FUNCTIONS
 void  setIntakeMotors(){
   //LEFT TRIGGERS
   int intakeOn = 300 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
   setIntake(intakeOn);
 }

void intakeAuton(int units, int voltage){
int direction = abs(units/units);
resetIntakeEncoders();
while(abs(intake.get_encoder_units())<abs(units)){
 setIntake(voltage);
 pros::delay(10);
 setIntake(0);
  }
}