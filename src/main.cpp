#include <Arduino.h>
void setup()
{
	Serial.begin(9600);
}

void loop()
{
	Serial.println("File Uploaded");
	delay(2500);
}