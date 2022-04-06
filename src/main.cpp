#include "Arduino.h"
// Sort.h currently includes the loadable_functions.h file in it's header
#include "sort.h";
void setup()
{
	Serial.begin(9600);
	side_effect_test();
	side_effect_test();
}

void loop()
{
	Serial.println("File Uploaded");
	delay(2500);
}