#pragma config(Hubs,  S2, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Hubs,  S3, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     irs,            sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S2_C1_1,     motorD,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S2_C1_2,     motorE,        tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S2_C2_1,     motorF,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S2_C2_2,     motorG,        tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S2_C3_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C3_2,     motorI,        tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S2_C4_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S2_C4_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S2_C4_3,    servo3,               tServoStandard)
#pragma config(Servo,  srvo_S2_C4_4,    servo4,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S2_C4_5,    servo5,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S2_C4_6,    servo6,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S3_C1_1,    servo7,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_2,    servo8,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_3,    servo9,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_4,    servo10,              tServoNone)
#pragma config(Servo,  srvo_S3_C1_5,    servo11,              tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servo12,              tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

void initializeRobot()
{
	servo[servo1] = 0;
	servo[servo2] = 256;
	servo[servo3] = 256;

	motor[motorH] = 3;
	motor[motorI] = 3;
	wait1Msec(30);

	return;
}

void ereset() //reset the encoder
{
	nMotorEncoder[motorD] = 0;
	nMotorEncoder[motorE] = 0;
	nMotorEncoder[motorF] = 0;
	nMotorEncoder[motorG] = 0;

	return;
}

void moveforward() //move the robot forward
{
	motor[motorD] = 50;
	motor[motorE] = 50;
	motor[motorF] = 50;
	motor[motorG] = 50;

	return;
}

void turnleft() //make the robot turn left
{
	motor[motorD] = -10;
	motor[motorE] = 50;
	motor[motorF] = -10;
	motor[motorG] = 50;

	return;
}

void turnright() //make the robot turn right
{
	motor[motorD] = 50;
	motor[motorE] = -10;
	motor[motorF] = 50;
	motor[motorG] = -10;

	return;
}

void movebackward() //make the robot move backwards
{
	motor[motorD] = -50;
	motor[motorE] = -50;
	motor[motorF] = -50;
	motor[motorG] = -50;

	return;
}

void brake()
{
	motor[motorD] = 0;
	motor[motorE] = 0;
	motor[motorF] = 0;
	motor[motorG] = 0;

	return;
}

int ch;

bool yesir = SensorValue(irs) >= 3 && SensorValue(irs) <= 7;

task main()
{
	initializeRobot();

	ereset();

	waitForStart();

	ch = 1;

	while(ch == 1)
	{
		moveforward();
		wait1Msec(3900);

		turnleft();
		wait1Msec(1500);

		movebackward();
		wait1Msec(700);

		brake();
		wait1Msec(1000);

		moveforward();
		wait1Msec(1900);

		turnright();
		wait1Msec(1500);

		movebackward();
		wait1Msec(1500);

		if (SensorValue(irs) >= 3 && SensorValue(irs) <= 7)
		{
			while(SensorValue(irs) < 5)
			{
				moveforward();
			}

			while(SensorValue(irs) > 5)
			{
				movebackward();
			}

			moveforward();
			wait1Msec(1000);

			turnleft();
			wait1Msec(1600);

			moveforward();
			wait1Msec(1500);

			ch = 0;
		}

		if(yesir == false)
		{
			moveforward();
			wait1Msec(1000);

			turnleft();
			wait1Msec(200);
		}

		else if (yesir == true)
		{
			turnleft();
			wait1Msec(800);

			moveforward();
			wait1Msec(1500);
		}

		else
		{
			turnleft();
			wait1Msec(2000);

			moveforward();
			wait1Msec(1200);
		}
	}
}

//The Metal Magicians
//Jeffles
