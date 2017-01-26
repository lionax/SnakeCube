// Accelero.h

#ifndef _ACCELERO_h
#define _ACCELERO_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Sensor.h"

void getAccel_Data(void);


#endif

