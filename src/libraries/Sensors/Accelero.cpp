// 
// 
// 

#include "Accelero.h"

void getAccel_Data(void)
{
	accelgyro.getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
	Axyz[0] = (double)ax / 16384;
	Axyz[1] = (double)ay / 16384;
	Axyz[2] = (double)az / 16384;
}