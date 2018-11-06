/*
 Name:		Servo.ino
 Created:	2018-11-01 오후 4:41:08
 Author:	JK
*/

// the setup function runs once when you press reset or power the board
#include <Servo.h>

Servo myServo;

//int rotate_Angle;
//
//int pinNum = 7;
//int rotate_Speed = 100;
//
//void setup() {
//	//pinMode(pinNum, OUTPUT);
//	myServo.attach(pinNum);
//	Serial.begin(9600);
//	rotate_Angle = 90;
//	myServo.write(rotate_Angle);
//}
//void loop() {
//
//	if (Serial.available)
//	{
//		if (Serial.read() == 97) // 아스키(d)
//		{
//			rotate(false);
//		}
//		if (Serial.read() == 100) // 아스키(a)
//		{
//			rotate(true);
//		}
//	}
//}
//
//void rotate(boolean r_value)
//{
//	// RIGHT
//	if (r_value) 
//	{
//		myServo.write(rotate_Angle + 1);
//		delay(rotate_Speed);
//	}
//	//LEFT
//	else { 
//		myServo.write(rotate_Angle - 1);
//		delay(rotate_Speed);
//	}
//}


const int potentiometerPin = 0; //가변저항기에 연결한 아날로그의 핀

Servo myServo;

void setup()
{
	myServo.attach(9); // 서보를 사용하는 핀
}

void loop()
{
	int value = analogRead(potentiometerPin); // 가변저항의 값

	// map(value, 현재 최소값, 현재 최대값, 변경하고자 하는 최소 값, 변경하고자 하는 최대값)
	int angle = map(value, 0, 1023, 0, 179); // 읽어들인 값을 0에서 179까지 변환   

	myServo.write(angle);
	delay(15);
}