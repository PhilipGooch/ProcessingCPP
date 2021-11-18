#include "Processing.h"
START
// code starts here

void setup()
{
	size(500, 500);
}

void draw()
{
	background(200);
	fill(255, 255, 255);
	stroke(0, 0, 255);
	strokeWeight(4);
	rectMode(CORNERS);
	for (int i = 0; i < 100; i++)
	{
		rect(50, 50, 350, 350, 25, 50, 75, 100);
	}
}

// code ends here
END