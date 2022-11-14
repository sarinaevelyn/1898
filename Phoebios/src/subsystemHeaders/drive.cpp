#include "main.h"
#include "pros/imu.h"
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

void driveThing(int leftBack, int leftFront, int rightBack, int rightFront){
driveLeftFront = leftFront;
driveRightFront = rightFront; 
driveLeftBack = leftBack; 
driveRightBack = rightBack;
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
   setDrive(-leftJoystickY, -leftJoystickX,-rightJoystickX);
}

void yAxis(int units, int voltage){
int direction = abs(units/units);
resetDriveEncoders();
while(averageDriveEncoders()<abs(units)){
  driveThing(-direction*voltage ,-direction*voltage , direction*voltage, direction*voltage);
  pros::delay(10);
  driveThing(0,0,0,0);
}
}
pros::c::imu_gyro_s_t gyro = pros::c::imu_get_gyro_rate(7);
void xAxis(int units, int voltage){
int direction = abs(units/units);
resetDriveEncoders();
while(averageDriveEncoders()<abs(units)){
 if(abs(gyro.x) > 5){
 units = units +5;
 }
 else{
  driveThing(direction*voltage ,-direction*voltage , direction*voltage, -direction*voltage);
  pros::delay(10);
  driveThing(0,0,0,0);
 }
 
}
}

void gay(int units, int voltage){
int direction = abs(units/units);
resetDriveEncoders();
while(averageDriveEncoders()<abs(units)){
  driveThing(voltage, voltage , voltage, voltage);
  pros::delay(10);
  driveThing(0,0,0,0);
}
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
