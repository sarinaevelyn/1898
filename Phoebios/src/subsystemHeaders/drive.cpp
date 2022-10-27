#include "main.h"
#include "subsystemFiles/globals.hpp"

/*This is where I define all of my drive functions
*/

//HELPER FUNCTIONS
void resetDriveEncoders(){
  driveLeftFront.tare_position();
  driveLeftBack.tare_position();
  driveRightFront.tare_position();
  driveRightBack.tare_position();
}

double averageDriveEncoders(){
  return (fabs(driveLeftFront.get_position())+
  fabs (driveLeftBack.get_position())+
  fabs (driveRightFront.get_position())+
  fabs (driveRightBack.get_position())) / 4;
}

void setDrive(int leftJoystickY,int leftJoystickX, int rightJoystickX){
  //ARCADE DRIVE LEEFT JOYSTICK
  driveLeftFront = (leftJoystickY+leftJoystickX-rightJoystickX); 
  driveLeftBack = (leftJoystickY-leftJoystickX-rightJoystickX);
  driveRightFront = -(leftJoystickY-leftJoystickX+rightJoystickX); 
  driveRightBack = -(leftJoystickY+leftJoystickX+rightJoystickX);
}

void setDriveMotors(){
   int leftJoystickY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
   int leftJoystickX = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
   int rightJoystickX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
   setDrive(leftJoystickY, leftJoystickX,rightJoystickX);
}

void straight(int units, int voltage){
// setDrive(voltage);
}



// void setDriveTurn(int power){
//   //ARCADE DRIVE RIGHT JOYSTICK
//   driveLeftFront = power;
//   driveLeftBack = power;
//   driveRightFront = power;
//   driveRightBack = power;
// }

// void setDriveMotorsTurn(){
//    setDriveTurn(rightJoystick);
// }
