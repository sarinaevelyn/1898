#include "main.h"
#include "pros/misc.h"
/*This is where I put all of my initialization code
*/
#define DIGITAL_SENSOR_PORT 4
#define DIGITAL_SENSOR_PORT_2 2


void competition_initialize() {
inertialSensor.reset();
pros::ADIDigitalOut expansion (DIGITAL_SENSOR_PORT);
pros::ADIDigitalOut otherExpansion (DIGITAL_SENSOR_PORT_2);
pros::Optical optical_sensor(1);

while(inertialSensor.is_calibrating()){
		pros::delay(10);
	}
}
