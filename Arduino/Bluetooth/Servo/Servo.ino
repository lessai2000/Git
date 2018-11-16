/*
 Name:		Servo.ino
 Created:	2018-11-01 오후 4:41:08
 Author:	JK
*/

// the setup function runs once when you press reset or power the board
#include <SoftwareSerial.h>
#include <Servo.h>

Servo myServo;

const int servo_APin = 0;	//Servo motor connetion potentiometer Pin number
const int servo_DPin = 9;	//Servo motor Pin number
const int DC_APin = 1;		//DC motor connetion potentiometer Pin number
const int DC_DPin = 11;		//DC motor Pin number

#define BT_RXD 8
#define BT_TXD 7
SoftwareSerial bluetooth(BT_RXD, BT_TXD);

void setup()
{
	myServo.attach(servo_DPin); 
	pinMode(DC_APin, INPUT);	
	pinMode(DC_DPin, OUTPUT);
	Serial.begin(9600);
	bluetooth.begin(9600);
}

void loop()
{
	Bluetooth_connect();					// Bluetooth Connect
	Servo_control(analogRead(servo_APin));	// Servo motor potentiometer
	DC_control(analogRead(DC_APin));		// DC motor potentiometer
	
}

// 블루투스 제어
void Bluetooth_connect()
{
	if (bluetooth.available()) {
		// 값이 있을경우,
		Serial.write(bluetooth.read());
	}
	if (Serial.available()) {
		bluetooth.write(Serial.read());
	}
}

// 서보모터 제어
void Servo_control(int value)
{
	// map(value, 현재 최소값, 현재 최대값, 변경하고자 하는 최소 값, 변경하고자 하는 최대값)
	int angle = map(value, 0, 1023, 0, 170); // 읽어들인 값을 0에서 170까지 변환   

	myServo.write(angle);
	delay(15);
}

// DC모터 제어
void DC_control(int value)
{
	int motor = map(value, 0, 1023, 0, 255);
	analogWrite(DC_DPin, motor);
}