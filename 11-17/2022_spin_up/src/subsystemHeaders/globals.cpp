#include "main.h"
/*this file is where I am setting all of the physical components as variables.
All of these variables are global variables, meaning, I can refrence them
anywhere in the code.*/

//CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//DRIVETRAIN
pros::Motor driveLeftBack(4, pros::E_MOTOR_GEARSET_18,true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLeftFront(3, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightFront(5, pros::E_MOTOR_GEARSET_18,true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightBack(2, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_COUNTS);

//INTAKE
pros::Motor intake(8, pros::E_MOTOR_GEARSET_36,true, pros::E_MOTOR_ENCODER_COUNTS);

//ROLLER
pros::Motor roller(9, pros::E_MOTOR_GEARSET_36,true, pros::E_MOTOR_ENCODER_COUNTS);

//FLICKER
pros::Motor flicker(11, pros::E_MOTOR_GEARSET_36,true, pros::E_MOTOR_ENCODER_COUNTS);

//FLYWHEEL
pros::Motor flywheel(13, pros::E_MOTOR_GEARSET_36,true, pros::E_MOTOR_ENCODER_COUNTS);
