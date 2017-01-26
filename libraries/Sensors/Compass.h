// Compass.h

#ifndef _COMPASS_h
#define _COMPASS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Sensor.h"

void getHeading(void);

void getTiltHeading(void);

void Mxyz_init_calibrated();

void get_calibration_Data();

void get_one_sample_date_mxyz();

void getCompass_Data(void);

void getCompassDate_calibrated();

#endif

