#include "main.h"
#include "pros/colors.h"
#include "pros/llemu.hpp"
#include "pros/rtos.hpp"
#include "pros/screen.h"
#include "pros/screen.hpp"
#include "subsystemFiles/drive.hpp"
#include "subsystemFiles/flicker.hpp"
#include "subsystemFiles/flywheel.hpp"
#include "subsystemFiles/globals.hpp"
#include "subsystemFiles/intake.hpp"
#include "subsystemFiles/rollers.hpp"
#include "subsystemFiles/pneumatics.hpp"

/*This is where I put all of my opControl code (basically everything that would
make a motor move.)
*/
void opcontrol() {
  while(true){
  setIntakeMotors();
  setDriveMotors();
  setFlickerMotors();
  setFlywheelMotors();
  setRollerMotors();
	expansionOn();
  pros::delay(20);
 }
}
