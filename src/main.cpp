
#include <Arduino.h>
#include "WiFiClient.h"

extern int _load_lib_start;
extern int _heap_end;
void setup()
{
	Serial.begin(9600);
}

void loop()
{
	uint8_t *p, *end;

	p = (uint8_t *)&_load_lib_start;
	Serial.println("File Uploaded");
	Serial.println(_heap_end);
	Serial.println(_load_lib_start);
	delay(2500);
}