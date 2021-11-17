#include "Processing.h"
START


float x = 50.0f;

void setup()
{
	size(500, 500);
}

void update()
{
	x += 0.01f;
}

void draw()
{
	background(200);
	rectMode(CENTER);
	fill(255, 0, 0);
	strokeWeight(3);
	rect(x, 50, 50, 50);
}


END