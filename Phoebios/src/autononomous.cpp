#include "main.h"
/*This is where I put all of my autonomous code
*/
void autonomous(){ 

/** okapi::Motor leftFMotor(3);
okapi::Motor rightFMotor(-5);
okapi::Motor leftBMotor(-4);
okapi::Motor rightBMotor(2); 
okapi::Motor intakeMotor(-8);
okapi::Motor flickerMotor(-11); 
okapi::Motor flywheelMotor(-13); 
okapi::Motor rollerMotor(-9); 
//pros::Imu inertialSensor(15);

std::shared_ptr<okapi::ChassisController> drive = okapi::ChassisControllerBuilder()
    .withMotors(leftFMotor, rightFMotor, rightBMotor, leftBMotor)
	.withDimensions(okapi::AbstractMotor::gearset::green, {{4_in, 7.5_in}, okapi::imev5GreenTPR})
	.build();

auto autonDrive = okapi::AsyncMotionProfileControllerBuilder()
    .withLimits({1.5, 1.0, 10.0})//{1.5, 1.0, 10.0}
   	.withOutput(drive)
   	.buildMotionProfileController();


/**
    inertialSensor.reset();
	while(inertialSensor.is_calibrating()){
		pros::delay(10);
	}
**/ 

/**void strafeRight(int voltage, int time){
    leftFMotor.moveVoltage(voltage);
    rightBMotor.moveVoltage(voltage);
    rightFMotor.moveVoltage(-1*voltage);
    leftBMotor.moveVoltage(-1*voltage);
    pros::delay(time);
    
 }


void strafeLeft(int voltage, int time){
    leftFMotor.moveVoltage(-1*voltage);
    rightBMotor.moveVoltage(-1*voltage);
    rightFMotor.moveVoltage(voltage);
    leftBMotor.moveVoltage(voltage);
    pros::delay(time);

}

void stop(){
    leftFrontMotor.moveVoltage(0);
    rightBackMotor.moveVoltage(0);
    rightFrontMotor.moveVoltage(0);
    leftBackMotor.moveVoltage(0);
   
} 

    autonDrive->generatePath({{0_ft, 0_ft, 0_deg},{27_in, 0_ft, 0_deg}},"GO_FORWARD");
    autonDrive->generatePath({{0_ft, 0_ft, 0_deg},{27_in, 27_ft, 0_deg}},"GO_LEFT");


/** void turnClockwise(int angle){
 
    double currAngle = inertialSensor.get_rotation();

    while(fabs(angle - currAngle) > 5){
	  leftFrontMotor.moveVelocity(200);
	  leftBackMotor.moveVelocity(200);
	  rightFrontMotor.moveVelocity(-200);
	  rightBackMotor.moveVelocity(-200);	
      currAngle = inertialSensor.get_rotation();
	}

	leftFrontMotor.moveVelocity(0);
	leftBackMotor.moveVelocity(0);
	rightFrontMotor.moveVelocity(0);
	rightBackMotor.moveVelocity(0);	
      
}

void turnCounterClockwise(int angle){
 
    double currAngle = inertialSensor.get_rotation();

    while(fabs(angle - currAngle) > 5){
	  leftFrontMotor.moveVelocity(-200);
	  leftBackMotor.moveVelocity(-200);
	  rightFrontMotor.moveVelocity(200);
	  rightBackMotor.moveVelocity(200);	
      currAngle = inertialSensor.get_rotation();
	}

	leftFrontMotor.moveVelocity(0);
	leftBackMotor.moveVelocity(0);
	rightFrontMotor.moveVelocity(0);
	rightBackMotor.moveVelocity(0);	
    
}

*/ 

   /**autonDrive->setTarget("GO_FORWARD");
   autonDrive->waitUntilSettled();
   autonDrive->setTarget("GO_LEFT");
   autonDrive->waitUntilSettled();
   rollerMotor.moveVelocity(200);
   rollerMotor.moveVelocity(0);
   //turnCounterClockwise();
   //turnClockwise();
   
    

	

*/ 

}

