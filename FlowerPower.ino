//#include"WIFi.h"
/*
 Name:		FlowerPower.ino
 Created:	1/13/2020 2:35:42 PM
 Author:	Arman
*/

// the setup function runs once when you press reset or power the board
//void setup() {
	//defines the pin as output, connects the lcd
	//pinMode(A0, OUTPUT);


//}

int soil = 0;
int soilMoistureValue;
bool thirteen;
bool two;
void setup() {
	
	pinMode(13, OUTPUT);
	pinMode(2, OUTPUT);
	
	Serial.begin(9600);
	Serial.println("SOIL MOISTURE SENSOR");
	Serial.println("-----------------------------");
}
void loop() {
	
		
		Serial.println(digitalRead(13));
		Serial.println(digitalRead(2));

		thirteen = digitalRead(13);
		two = digitalRead(2);
		if (thirteen == 1 && two == 1) {
			thirteen = 1;
			two = 1;
		}
		if (thirteen == 1 && two == 0) {
			thirteen = 0;
			two = 0;
		}
		if (thirteen == 0 && two == 0) {
			thirteen = 0;
			two = 0;
		}
		if (thirteen == 0 && two == 1)
		{
			thirteen=0;
			two = 0;
			
		}
		Serial.println(digitalRead(13));
		Serial.println(digitalRead(2));
		
		soil = analogRead(A0);
		Serial.println(soil);
		
		soil = map(soil, 915, 1023, 0, 100);
		Serial.print(soil);
	Serial.print("%");
	Serial.print("\n");


	delay(2000);
}

