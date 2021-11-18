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
	stroke(0, 0, 255, 255);
	strokeWeight(4);
	ellipse(50, 50, 50, 150);
}

// code ends here
END