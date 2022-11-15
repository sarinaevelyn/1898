#include "main.h"
#include "pros/rtos.hpp"
#include "subsystemFiles/drive.hpp"
#include "subsystemFiles/flywheel.hpp"
#include "subsystemFiles/rollers.hpp"
/*This is where I put all of my autonomous code
// */

// okapi::Motor leftFMotor(3);
// okapi::Motor rightFMotor(-5);
// okapi::Motor leftBMotor(-4);
// okapi::Motor rightBMotor(2); 
// okapi::Motor intakeMotor(-8);
// okapi::Motor flickerMotor(-11); 
// okapi::Motor flywheelMotor(-13); 
// okapi::Motor rollerMotor(-9); 
// //pros::Imu inertialSensor(15);

// void strafeRight(int voltage, int time){
//     leftFMotor.moveVoltage(voltage);
//     rightBMotor.moveVoltage(voltage);
//     rightFMotor.moveVoltage(-1*voltage);
//     leftBMotor.moveVoltage(-1*voltage);
//     pros::delay(time);
    
//  }


// void strafeLeft(int voltage, int time){
//     leftFMotor.moveVoltage(-1*voltage);
//     rightBMotor.moveVoltage(-1*voltage);
//     rightFMotor.moveVoltage(voltage);
//     leftBMotor.moveVoltage(voltage);
//     pros::delay(time);

// }

// void stop(){
//     leftFMotor.moveVoltage(0);
//     rightBMotor.moveVoltage(0);
//     rightFMotor.moveVoltage(0);
//     leftBMotor.moveVoltage(0);
   
// } 
void autonomous(){ 
   
    int turnUnit = 1800;
    
    int drivetrainVoltage = 800;
    
    int driveLeftUnit = 300;
    int driveForwardUnit = 1300;
    int driveBackUnit = -1300; 
    
    int rollerUnits = 100;
    int rollerPower = 7000;
     

// warm up flywheel and shoot twice
/*
    setFlywheel(12000);
    pros::delay(5000);
    for (int i=0;i<3;i++){
        setFlicker(1000);
        pros::delay(750);
        setFlicker(-1000);
        pros::delay(750);
        setFlicker(0);
    }
// tunrs flywheel off 
    setFlywheel(0);
    */

// align with the wall
   /* driveThing(-drivetrainVoltage, drivetrainVoltage, drivetrainVoltage, -drivetrainVoltage);
    pros::delay(1000);

// go forward (away from the wall)
    yAxis(driveForwardUnit/2.1, drivetrainVoltage*2);
        pros::delay(250);

//turn 
    gay(-turnUnit/4.5, -drivetrainVoltage);

// move forward
    yAxis(driveForwardUnit, -drivetrainVoltage);
        pros::delay(250); 
        */

// strafe right (towards the roller)
    // xAxis(600,-drivetrainVoltage);
    //     pros::delay(250);
         

// spin the roller
    // roller.move_velocity(-200);
    // pros::delay(250);
    // roller.move_velocity(0); 

   
    /* setRoller(rollerPower);
    pros::delay(500);
    setRoller(0);
    */
        yAxis(-driveForwardUnit*1.5,200);
        gay(turnUnit, 500);
        xAxis(driveForwardUnit*2, 200);
        xAxis(-driveForwardUnit*4, 500);
        gay(turnUnit, 500);
        yAxis(driveForwardUnit*3,500);
        gay(turnUnit, 500);
        xAxis(-driveForwardUnit*2,500);
        gay(-turnUnit, 500);
        xAxis(driveForwardUnit, 500);

        // // pros::delay(200);
        // gay(200,200);    
        // yAxis(1000,200);
        // gay(20,200);
}




// std::shared_ptr<okapi::ChassisController> drive = okapi::ChassisControllerBuilder()
//     .withMotors(leftFMotor, rightFMotor, rightBMotor, leftBMotor)
// 	.withDimensions(okapi::AbstractMotor::gearset::green, {{4_in, 7.5_in}, okapi::imev5GreenTPR})
// 	.build();

// auto autonDrive = okapi::AsyncMotionProfileControllerBuilder()
//     .withLimits({1.5, 1.0, 10.0})//{1.5, 1.0, 10.0}
//    	.withOutput(drive)
//    	.buildMotionProfileController();


// /**
//     inertialSensor.reset();
// 	while(inertialSensor.is_calibrating()){
// 		pros::delay(10);
// 	}
// **/ 
//     autonDrive->generatePath({{0_ft, 0_ft, 0_deg},{27_in, 0_ft, 0_deg}},"GO_FORWARD");
//     autonDrive->generatePath({{0_ft, 0_ft, 0_deg},{27_in, 27_ft, 0_deg}},"GO_LEFT")
// /** void turnClockwise(int angle){
 
//     double currAngle = inertialSensor.get_rotation();

//     while(fabs(angle - currAngle) > 5){
// 	  leftFrontMotor.moveVelocity(200);
// 	  leftBackMotor.moveVelocity(200);
// 	  rightFrontMotor.moveVelocity(-200);
// 	  rightBackMotor.moveVelocity(-200);	
//       currAngle = inertialSensor.get_rotation();
// 	}

// 	leftFrontMotor.moveVelocity(0);
// 	leftBackMotor.moveVelocity(0);
// 	rightFrontMotor.moveVelocity(0);
// 	rightBackMotor.moveVelocity(0);	
      
// }

// void turnCounterClockwise(int angle){
 
//     double currAngle = inertialSensor.get_rotation();

//     while(fabs(angle - currAngle) > 5){
// 	  leftFrontMotor.moveVelocity(-200);
// 	  leftBackMotor.moveVelocity(-200);
// 	  rightFrontMotor.moveVelocity(200);
// 	  rightBackMotor.moveVelocity(200);	
//       currAngle = inertialSensor.get_rotation();
// 	}

// 	leftFrontMotor.moveVelocity(0);
// 	leftBackMotor.moveVelocity(0);
// 	rightFrontMotor.moveVelocity(0);
// 	rightBackMotor.moveVelocity(0);	
    
// }

// */ 

//    autonDrive->setTarget("GO_FORWARD");
//    autonDrive->waitUntilSettled();
//    strafeLeft(200, 3); 
//    stop();
//    rollerMotor.moveVelocity(200);
//    rollerMotor.moveVelocity(0);
//    //turnCounterClockwise();
//    //turnClockwise();