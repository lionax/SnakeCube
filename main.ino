/*
 * Main entrypoint for the NeoCube-Project.
 * 
 * Configuration of any modules and the main loop logic
 * is organizied within this file. Changes are most likely
 * not necessery here.
 *
 * Name:	main.ino
 * Created:	11/17/2016 4:26:13 PM
 * Author:	Lionax
*/

#include <Wire.h>
#include "Compass.h"
#include "Gyro.h"
#include "Accelero.h"
#include <TimerOne.h>
#include <MPU9250.h>
#include <I2Cdev.h>

#include <Adafruit_NeoPixel.h>
#include <gamma.h>
#include <Adafruit_NeoMatrix.h>
#include <gfxfont.h>
#include <Adafruit_GFX.h>

#define del 100
#define sample_num_mdate  5000

MPU9250 accelgyro;
I2Cdev   I2C_M;

uint8_t buffer_m[6];


void setup() {
	// Setup Loop-Timer
	// Setup Sensor-Modules
	// Setup Music-Module
	// Configure Menu-Module and create any sub-modules (game)
	// join I2C bus (I2Cdev library doesn't do this automatically)
	Wire.begin();

	// initialize serial communication
	// (38400 chosen because it works as well at 8MHz as it does at 16MHz, but
	// it's really up to you depending on your project)
	Serial.begin(38400);

	// initialize device
	Serial.println("Initializing I2C devices...");
	accelgyro.initialize();

	// verify connection
	Serial.println("Testing device connections...");
	Serial.println(accelgyro.testConnection() ? "MPU9250 connection successful" : "MPU9250 connection failed");

	delay(1000);
	Serial.println("     ");

	//  Mxyz_init_calibrated ();
}

void loop() {
	// TODO - Do cool stuff... really cool stuff.
}
