#include "Processing.h"
START
// code starts here
#include <math.h>
float offsetX = 256;
float offsetY = 256;
float circleX = 0;
float circleY = 0;
float timer = 0;
float movementScale = 100;
void setup()
{
	size(500, 500);
}

void draw()
{
	background(200);
	fill(255, 0, 255, 255);
	rectMode(CORNERS);
	stroke(0, 0, 255, 255);
	strokeWeight(4);
	timer += 0.001;
	circleX = offsetX;
	circleY = offsetY;
	rect(circleX + cos(timer) * movementScale, circleY + sin(timer) * movementScale, 50, 50);
	rect(circleX + cos(timer + 0.5f) * movementScale, circleY + sin(timer + 0.5f) * movementScale, 50, 50);
	rect(circleX + cos(timer + 1.f) * movementScale, circleY + sin(timer + 1.f) * movementScale, 50, 50);
	rect(circleX + cos(timer + 1.5f) * movementScale, circleY + sin(timer + 1.5f) * movementScale, 50, 50);
	rect(circleX + cos(timer + 2.f) * movementScale, circleY + sin(timer + 2.f) * movementScale, 50, 50);
	rect(circleX + cos(timer + 2.5f) * movementScale, circleY + sin(timer + 2.5f) * movementScale, 50, 50);
	
}

// code ends here
END