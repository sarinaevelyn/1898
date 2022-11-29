#pragma once 
#include "main.h"
/*This file is where I declare all of the functions I make in subsystemHeaders.
*/

//HELPER FUNCTIONS
void setDrive(int leftJoystickY,int leftJoystickX, int rightJoystickX);
void resetDriveEncoders();
void driveThing(int left, int right);
double averageDriveEncoders();
void driveThing(int leftBack, int leftFront, int rightBack, int rightFront);
void yAxis(int units, int voltage);
void xAxis(int units, int voltage);
void gay(int units, int voltage);
//DRIVER CONTROL FUNCTIONS
void setDriveMotors();
// auton functions
void auton();
void skillsAuton();
void closeAuton();
void farAuton();
void cornerAuton();
void goToOtherRollers();
void cornerRollerInverse();
void colorRolorSkills();
void spinRollerMatchAuton();