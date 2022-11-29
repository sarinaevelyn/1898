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
//    skillsAuton();
    // colorRolor(-1);
    // closeAuton();
    farAuton();
}

void spinRollerMatchAuton(){
    pros::Optical optical_sensor(1);
    int timeNow = pros::millis();
    if(optical_sensor.get_hue()<50){
        while(optical_sensor.get_hue()<50 && (200-timeNow)<8000){
            rollerAuton(100,100);
            pros::delay(25);
        }
        while(optical_sensor.get_hue()>50 && (200-timeNow)<9500){
            rollerAuton(100,-100);
            pros::delay(25);
        }
    }else if(optical_sensor.get_hue()>150 && optical_sensor.get_hue()<280){
        while(optical_sensor.get_hue()>150 && optical_sensor.get_hue()<280 && (pros::millis()-timeNow)<8000){
            rollerAuton(100,100);
            pros::delay(25);
        }
        while(!(optical_sensor.get_hue()>150 && optical_sensor.get_hue()<280) && (pros::millis()-timeNow)<9500){
            rollerAuton(100,-100);
            pros::delay(25);
        }
    }

}

void closeAuton(){
    int distance = 200;
    int rollerUnit = 150;
    // strafe to roller
    xAxis(distance,200);
    // spin roller    
    spinRollerMatchAuton();
    // strafe away
    xAxis(distance,-200);
}

void farAuton(){
    int travelDistance = 1500;
    int strafeDistance = 500;
    int rollerUnit = 150;
    // drive backwards
    yAxis(travelDistance,50);
    // strafe to roller
    xAxis(strafeDistance,50);
    // spin roller
    spinRollerMatchAuton();
    // strafe away
    xAxis(strafeDistance/5,-200);

}

void colorRolorSkills(){
    pros::Optical optical_sensor(1);
    if(optical_sensor.get_hue()<50){
        while(optical_sensor.get_hue()<50){
            rollerAuton(100,-100);
            pros::delay(25);
        }
    }else if(optical_sensor.get_hue()>150 && optical_sensor.get_hue()<280){
        while(optical_sensor.get_hue()>150 && optical_sensor.get_hue()<280){
            rollerAuton(100,-100);
            pros::delay(25);
        }
    }
}

void cornerRollers(){
    int turnUnit = 1800;
    int driveLeftUnit = 300;
    int driveForwardUnit = 1300;
    int driveBackUnit = -1300; 
    int rollerPower = 7000;
    int tile = 1000;
    int ninety = 400;
    int rollerUnit = 250;
    // strafe towards roller (right)
        xAxis(tile/4,50);
        rollerAuton(rollerUnit,-600);
        // spin roller
        // strafe away from roller (left)
        xAxis(tile,-50);
        // turn 90 degrees clockwise
        gay(ninety, 50);
        xAxis(tile*2,50);
        rollerAuton(rollerUnit,600);
}

void cornerRollerInverse(){
    int turnUnit = 1800;
    int driveLeftUnit = 300;
    int driveForwardUnit = 1300;
    int driveBackUnit = -1300; 
    int rollerPower = 7000;
    int tile = 1000;
    int ninety = 400;
    int rollerUnit = 250;
    // strafe towards roller (right)
        rollerAuton(rollerUnit,-600);
        // spin roller
        // strafe away from roller (left)
        xAxis(tile,-50);
        // turn 90 degrees counterclockwise
        gay(ninety, -50);
        xAxis(tile*2,50);
        rollerAuton(rollerUnit,600);
}

void goToOtherRollers(){
    gay(200, 50);
    driveThing(50 ,50 , -50, -50);
    pros::delay(15000);
    driveThing(0,0,0,0);
    // gay(500,-50);
    // driveThing(-50 ,-50 , 50, 50);
    // pros::delay(2000);
    // driveThing(0,0,0,0);
    yAxis(1000,50); // exact
    gay(1250,50); // 90 degree turn
    driveThing(50 ,-50 , 50, -50);
    pros::delay(8000);
    driveThing(0,0,0,0);
}

void skillsAuton(){
    cornerRollers();
    xAxis(1000,-50);
    goToOtherRollers();
    cornerRollerInverse();
    // xAxis(700,-200);
    // yAxis(250,-200);
    while(true){
        if(pros::millis()>59000){
            // expansion.set_value(true);
            pneumaticsAuton();
        }
    }
        // strafe towards roller (right)
        // spin roller
        // strafe away from roller (left)
        // spin to align with other side
}
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

        // yAxis(-driveForwardUnit*1.5,200);
        // gay(turnUnit, 500);
        // xAxis(driveForwardUnit*2, 200);
        // xAxis(-driveForwardUnit*4, 500);
        // gay(turnUnit, 500);
        // yAxis(driveForwardUnit*3,500);
        // gay(turnUnit, 500);
        // xAxis(-driveForwardUnit*2,500);
        // gay(-turnUnit, 500);
        // xAxis(driveForwardUnit, 500);

        // // pros::delay(200);
        // gay(200,200);    
        // yAxis(1000,200);
        // gay(20,200);




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