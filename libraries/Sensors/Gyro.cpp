// 
// 
// 

#include "Gyro.h"

void getGyro_Data(void)
{
	accelgyro.getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
	Gxyz[0] = (double)gx * 250 / 32768;
	Gxyz[1] = (double)gy * 250 / 32768;
	Gxyz[2] = (double)gz * 250 / 32768;
}