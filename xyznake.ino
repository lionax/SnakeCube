/*
 Name:		xyznake.ino
 Created:	11/17/2016 4:26:13 PM
 Author:	alex
*/

#include <MPU9250.h>
#include <I2Cdev.h>
#include <BMP180.h>
#include <Adafruit_NeoPixel.h>
#include <gamma.h>
#include <Adafruit_NeoMatrix.h>
#include <gfxfont.h>
#include <Adafruit_GFX.h>
const short led = 10;
const short button = 8;
#define delay 100

void setup() {
	pinMode(button, INPUT);
	pinMode(led, OUTPUT);
}

void loop() {
	digitalWrite(led, !digitalRead(button));
	_delay_ms(delay);
}
