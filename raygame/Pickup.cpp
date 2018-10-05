#include "Pickup.h"

pickup::pickup()
{
	pos = { (float)GetRandomValue(100, 750), (float)GetRandomValue(100, 400) };
	radius = GetRandomValue(10, 20);
	speed = GetRandomValue(1.0f, 5.0f);
	value = GetRandomValue(1, 5);
	preSetMovement = GetRandomValue(1, 4);
	enabled = true;
}

//The pickups movement(differs by 4 diff types)
void pickup::update(float deltaTime, float screenX, float screenY)
{
	//moves up
	if (preSetMovement == 1) 
	{
		pos.y -= speed;

		if (pos.y < radius * -1)
		{
			pos.y = screenY + radius;
		}
	}
	//moves down
	else if (preSetMovement == 2) 
	{
		pos.y += speed;

		if (pos.y > screenY + radius)
		{
			pos.y = radius * -1;
		}
	}
	//moves right
	else if (preSetMovement == 3)
	{
		pos.x -= speed;

		if (pos.x < radius * -1)
		{
			pos.x = screenX + radius;
		}
	}
	//moves left
	else if (preSetMovement == 4)
	{
		pos.x += speed;

		if (pos.x > screenX + radius)
		{
			pos.x = radius * -1;
		}
	}

}

//if enabled draw the pickup
void pickup::draw()
{
	if (enabled)
	{
		DrawCircleGradient(pos.x, pos.y, radius, LIGHTGRAY, DARKBROWN);
	}
}
