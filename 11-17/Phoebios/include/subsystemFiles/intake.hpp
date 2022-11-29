#pragma once
#include "main.h"
/*This file is where I declare all of the functions I make in subsystemHeaders.
*/

//HELPER FUNCTION
void setIntake(int power);

//DRIVER CONTROL FUNCTION
void  setIntakeMotors();
void resetIntakeEncoders();
void intakeAuton(int units, int voltage);