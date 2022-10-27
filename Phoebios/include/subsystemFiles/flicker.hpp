#pragma once
#include "main.h"
/*This file is where I declare all of the functions I make in subsystemHeaders.
*/

//HELPER FUNCTION
void setFlicker(int power);
void resetFlickerEncoders();

//DRIVER CONTROL FUNCTION
void  setFlickerMotors();

void flickerAuton(int units, int voltage);