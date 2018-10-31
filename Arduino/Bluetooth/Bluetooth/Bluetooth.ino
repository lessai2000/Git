/*
 Name:		Bluetooth.ino
 Created:	2018-10-31 오후 3:05:50
 Author:	JK
*/

// the setup function runs once when you press reset or power the board
#include <SoftwareSerial.h>

#define BT_RXD 8
#define BT_TXD 7
SoftwareSerial bluetooth(BT_RXD, BT_TXD);

void setup() {
	Serial.begin(9600);
	bluetooth.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
	if (bluetooth.available()) {
		// 값이 있을경우,
		Serial.write(bluetooth.read());
	}
	if (Serial.available()) {
		bluetooth.write(Serial.read());

	}
}
