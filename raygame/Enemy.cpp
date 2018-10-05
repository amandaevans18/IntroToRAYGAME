#include "Enemy.h"

enemy::enemy()
{
	pos = {(float)GetRandomValue(100, 750), (float)GetRandomValue(100, 400)};
	radius = GetRandomValue(10.0f, 20.0f);
	speed = GetRandomValue(1.0f, 5.0f);
	value = GetRandomValue(1, 5);
	preSetMovement = GetRandomValue(1, 4);
	enabled = true;
}

void enemy::update(float deltaTime, float screenX, float screenY)
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

void enemy::draw()
{
	if (enabled)
	{
		DrawCircleGradient(pos.x, pos.y, radius, BLACK,RED);
	}
}
