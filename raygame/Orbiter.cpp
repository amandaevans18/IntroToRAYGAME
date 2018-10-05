#include "Orbiter.h"
#include <math.h>   
void orbiter::update(float deltaTime, float screenX, float screenY, Vector2 player)
{
	posOfOrbiter = { player.x + (float)(cos(deltaTime * distanceFromPlayer) * 100),player.y + (float)(sin(deltaTime * distanceFromPlayer) * 100) };
}

void orbiter::draw()
{
	if (enabled) 
	{
		DrawCircle(posOfOrbiter.x, posOfOrbiter.y, radius, GOLD);
	}
}
