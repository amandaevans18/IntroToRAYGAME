#include "Orbiter.h"
#include <math.h> 
//MAKES THEM ORBITES ORBIT
void orbiter::update(float deltaTime, float screenX, float screenY, Vector2 player)
{
	//sin and cos together make a circle they follow that circle
	posOfOrbiter = { player.x + (float)(cos(deltaTime * speed) * distanceFromPlayer),
		player.y + (float)(sin(deltaTime * speed) * distanceFromPlayer) };
}

void orbiter::draw()
{
	if (enabled) 
	{
		DrawCircle(posOfOrbiter.x, posOfOrbiter.y, radius, color);
	}
}
