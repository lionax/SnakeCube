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

/**
 * @Singleton
 */
class Cube
{
public:
	Cube(Cube const&) = delete;
	void operator=(Cube const&) = delete;
	static Cube& getInstance();
	void clear();
	void clear(byte page);
	Vector * getVector(byte square, byte row, byte column);
	Cell * getCell(byte square, byte row, byte column);
	Cell * getCell(Vector vector);
private:
	Cell _cube[6][8][8];
	neighbours _neighbours_table[6];
	Cube() {}
};

#endif

