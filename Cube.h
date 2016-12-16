// Cube.h

#ifndef _CUBE_h
#define _CUBE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Cell.h"
#include "Vector.h"

typedef struct _neighbours {
	byte top : 3;
	byte right : 3;
	byte bottom : 3;
	byte left : 3;
	byte free : 4; // not in use right now
} neighbours;

class Cube
{
private:
	Cell _cube[6][8][8];
	neighbours _neighbours_table[6];

public:
	Vector * getVector(byte square, byte row, byte column);
	Cell * getCell(byte square, byte row, byte column);
	Cell * getCell(Vector vector);
};

#endif

