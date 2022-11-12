#include "main.h"
#include "pros/misc.h"
/*This is where I put all of my initialization code
*/
#define DIGITAL_SENSOR_PORT 4

void competition_initialize() {
inertialSensor.reset();
pros::ADIDigitalOut expansion (DIGITAL_SENSOR_PORT);
while(inertialSensor.is_calibrating()){
		pros::delay(10);
	}
}
