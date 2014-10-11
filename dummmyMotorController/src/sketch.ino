#include "RedBot.h"
#include <Arduino.h>

#define LEFTMOTOR A0
#define RIGHTMOTOR A1 
#define STOP 3

RedBotMotor botMotor;

void setup()
{
	
}

void loop()
{
	if(digitalRead(STOP) == HIGH) 
	{
		botMotor.brake();
	}
	else{
		int rightMotorIn = analogRead(LEFTMOTOR);	
		int leftMotorIn = analogRead(RIGHTMOTOR);
		botMotor.leftDrive(rightMotorIn);
		botMotor.rightDrive(leftMotorIn);
	}
}
