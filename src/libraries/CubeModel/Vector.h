// Vector.h

#ifndef _VECTOR_h
#define _VECTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Cube.h"
#include "Cell.h"

typedef struct _vector {
	byte square : 3;
	byte row : 3;
	byte column : 3;
	byte free : 7; // not in use right now
} vector;

class Vector
{
private:
	Cube * _cube;
	vector _vector;
public:
	Vector(Cube cube);
	Cell * getCell();
	byte getSquareIdx();
	byte getRowIdx();
	byte getColumnIdx();
	Vector * getTopVector();
	Vector * getRightVector();
	Vector * getBottomVector();
	Vector * getLeftVector();
	void up();
	void right();
	void down();
	void left();
};

#endif

