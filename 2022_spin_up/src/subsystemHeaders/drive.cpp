#include "main.h"
#include "subsystemFiles/globals.hpp"

/*This is where I define all of my drive functions
*/

//HELPER FUNCTIONS
void setDrive(int leftJoystickY,int leftJoystickX, int rightJoystickX){
  //ARCADE DRIVE LEEFT JOYSTICK
  driveLeftFront = -(leftJoystickY+leftJoystickX+rightJoystickX); 
  driveLeftBack = -(leftJoystickY-leftJoystickX+rightJoystickX);
  driveRightFront = (leftJoystickY-leftJoystickX-rightJoystickX); 
  driveRightBack = (leftJoystickY+leftJoystickX-rightJoystickX);
}

void setDriveMotors(){
   int leftJoystickY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
   int leftJoystickX = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
   int rightJoystickX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
   setDrive(leftJoystickY, leftJoystickX,rightJoystickX);
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
