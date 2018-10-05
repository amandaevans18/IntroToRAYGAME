#include "Pickup.h"


void pickup::update(float deltaTime, float screenX, float screenY)
{
	if (preSetMovement == 1) 
	{
		pos.y -= speed;

		if (pos.y < radius * -1)
		{
			pos.y = screenY + radius;
		}
	}
	else if (preSetMovement == 2) 
	{
		pos.y += speed;

		if (pos.y > screenY + radius)
		{
			pos.y = radius * -1;
		}
	}
	else if (preSetMovement == 3)
	{
		pos.x -= speed;

		if (pos.x < radius * -1)
		{
			pos.x = screenX + radius;
		}
	}
	else if (preSetMovement == 4)
	{
		pos.x += speed;

		if (pos.x > screenX + radius)
		{
			pos.x = radius * -1;
		}
	}

}

void pickup::draw()
{
	if (enabled)
	{
		DrawCircle(pos.x, pos.y, radius, GOLD);
	}
}
