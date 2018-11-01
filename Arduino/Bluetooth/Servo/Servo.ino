/*
 Name:		Servo.ino
 Created:	2018-11-01 오후 4:41:08
 Author:	JK
*/

// the setup function runs once when you press reset or power the board
#include <Servo.h>

Servo myServo;
int pinNum = 7;

void setup() {
	//pinMode(pinNum, OUTPUT);
	myServo.attach(pinNum);
	//Serial.begin(9600);

}

// the loop function runs over and over again until power down or reset
void loop() {
	/*if (Serial.available())
	{

  }*/
	myServo.write(0);
	delay(1000);
	myServo.write(90);
	delay(1000);
	myServo.write(0);
	delay(10000);
	myServo.write(180);
}
