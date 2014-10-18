#include "RedBot.h"
#include <Arduino.h>

#define LEFTMOTOR A0
#define RIGHTMOTOR A1 
#define STOP 3

RedBotMotor botMotor;




void setup()
{
	
}

int getMotorValue(int);
void loop()
{
	if(digitalRead(STOP) == HIGH) 
	{
		botMotor.brake();
	}
	else{
		int rightMotorIn = analogRead(LEFTMOTOR);	
		int leftMotorIn = analogRead(RIGHTMOTOR);
		botMotor.leftDrive(getMotorValue(rightMotorIn));
		botMotor.rightDrive(getMotorValue(leftMotorIn));
	}
}

/*
 * USAGE: 551 is about stop, 1023 is full forward, 0 is full backward
 * Regression based so it's a bit off
 */ 
int getMotorValue(int analogValue){
	return ((1/2) * analogValue - 255);
}
