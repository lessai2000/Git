﻿/*
 Name:		Servo.ino
 Created:	2018-11-01 오후 4:41:08
 Author:	JK
*/

// the setup function runs once when you press reset or power the board
#include <Servo.h>

Servo myServo;

const int servo_APin = 0; //가변저항기에 연결한 아날로그의 핀
const int servo_DPin = 9;
const int DC_APin = 1;
const int DC_DPin = 11;

void setup()
{
	myServo.attach(9); // 서보를 사용하는 핀
	pinMode(DC_APin, INPUT);
	pinMode(DC_DPin, OUTPUT);
}

void loop()
{
	servo_control(analogRead(servo_APin)); // 가변저항의 값
	DC_control(analogRead(DC_APin));
	
}

// 서보모터 제어
void servo_control(int value)
{
	// map(value, 현재 최소값, 현재 최대값, 변경하고자 하는 최소 값, 변경하고자 하는 최대값)
	int angle = map(value, 0, 1023, 0, 179); // 읽어들인 값을 0에서 179까지 변환   

	myServo.write(angle);
	delay(15);
}

void DC_control(int value)
{
	int motor = map(value, 0, 1023, 0, 255);
	analogWrite(DC_DPin, motor);
}