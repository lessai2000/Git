﻿/*
 Name:		DC.ino
 Created:	2018-11-06 오후 5:21:20
 Author:	JK
*/

//https://www.kocoafab.cc/tutorial/view/70

/* DC 모터 돌리기 */

const int motorPin = 9;     //상수 선언 : 모터와 연결된 핀 번호 저장

void setup()
{
	pinMode(motorPin, OUTPUT);      //9번핀을 출력용으로 설정
	Serial.begin(9600);             //시리얼 초기화
}

void loop()
{
	spiningMotor();              //모터 작동시키는 함수 호출
}
/*
 모터 작동시키는 함수
 : 입력받은 값을 시리얼 포트를 이용해 보내고 그에 맞는 속도로 모터가 돕니다.
*/
void spiningMotor()
{
	int speed;       //변수 선언 : 입력된 속도 저장
	Serial.println("Write speed : 0 ~ 255 and click send");    //속도 입력하고 send 버튼을 클릭하라고 알려줌

	while (true)    //무한반복
	{
		while (Serial.available() > 0)     //입력된 문자가 있으면
		{
			speed = Serial.parseInt();     //문자를 숫자로 변환하고 변수에 저장
			speed = constrain(speed, 0, 255);     //속도를 PWM 출력 값 범위로 고정
			analogWrite(motorPin, speed);         //speed만큼으로 모터 돌리기
			//speed : 값을 출력
			Serial.print("speed : ");
			Serial.println(speed);
		}
	}
}