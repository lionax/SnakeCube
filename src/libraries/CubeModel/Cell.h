// Cell.h

#ifndef _CELL_h
#define _CELL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

typedef struct _cell_data {
	byte data : 16;
} cell_data;



class Cell
{
private:
	cell_data _data;
	Cell();
public:
	unsigned int getUnformatedData();
	class CellFactory
	{
	private:

	public:
		Cell * createCell();
	};
	static CellFactory getFactory();
};

#endif

