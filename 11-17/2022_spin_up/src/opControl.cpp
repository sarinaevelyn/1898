#include "main.h"
#include "subsystemFiles/drive.hpp"
#include "subsystemFiles/flicker.hpp"
#include "subsystemFiles/flywheel.hpp"
#include "subsystemFiles/globals.hpp"
#include "subsystemFiles/intake.hpp"
#include "subsystemFiles/rollers.hpp"

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
		
 }
}
