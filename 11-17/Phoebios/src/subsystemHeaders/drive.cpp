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
  int maxPower = 100;
  int direction = abs(rightJoystickX)/rightJoystickX;
  int rightPower = direction*(rightJoystickX/sqrt(maxPower))*(rightJoystickX/sqrt(maxPower));
  driveLeftFront = (leftJoystickY+leftJoystickX-rightPower); 
  driveLeftBack = (leftJoystickY-leftJoystickX-rightPower);
  driveRightFront = -(leftJoystickY-leftJoystickX+rightPower); 
  driveRightBack = -(leftJoystickY+leftJoystickX+rightPower);
}


void setDriveMotors(){
   int leftJoystickY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
   int leftJoystickX = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
   int rightJoystickX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
   setDrive(-leftJoystickY, -leftJoystickX,-rightJoystickX);
}
pros::c::imu_gyro_s_t gyro = pros::c::imu_get_gyro_rate(7);

void yAxisGyro(int left, int right){
driveLeftFront = left;
driveLeftBack = left;
driveRightFront = right;
driveRightBack = right;
}

void yAxis(int units, int voltage){
int direction = abs(units/units);
resetDriveEncoders();
while(averageDriveEncoders()<abs(units)){
  if(gyro.x > 2){
  yAxisGyro(0,2);
  }
  if(gyro.x>0){
  yAxisGyro(2, 0);
  }
  driveThing(-direction*voltage ,-direction*voltage , direction*voltage, direction*voltage);
  pros::delay(10);
  driveThing(0,0,0,0);
}
}
void xAxisGyro(int left, int right){
driveLeftFront = left;
driveLeftBack = left;
driveRightFront = right;
driveRightBack = right;
}

void xAxis(int units, int voltage){
int direction = abs(units/units);
resetDriveEncoders();
while(averageDriveEncoders()<abs(units)){
 if(gyro.x > 2){
  xAxisGyro(0,2);
  }
  if(gyro.x>0){
  xAxisGyro(2, 0);
  }
 
  driveThing(direction*voltage ,-direction*voltage , direction*voltage, -direction*voltage);
  pros::delay(10);
  driveThing(0,0,0,0);

 }
 
}

void gay(int units, int voltage){
int direction = abs(units/units);
resetDriveEncoders();
while(averageDriveEncoders()<abs(units)){
  driveThing(voltage, voltage , voltage, voltage);
  pros::delay(10);
  driveThing(0,0,0,0);
}}