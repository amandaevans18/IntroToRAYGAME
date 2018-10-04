#include "Ball.h"

void ball::update(float deltaTime, float screenX, float screenY)
{
	if (IsKeyDown(KEY_W))
	{
		pos.y -= speed;

		if (pos.y < radius * -1)
		{
			pos.y = screenY + radius;
		}
	}
	if (IsKeyDown(KEY_S))
	{


	}
	if (IsKeyDown(KEY_A))
	{
		pos.x -= speed;

		if (pos.x < radius * -1)
		{
			pos.x = screenX + radius;
		}
	}
	if (IsKeyDown(KEY_D))
	{
		pos.x += speed;

		if (pos.x > screenX + radius)
		{
			pos.x = radius * -1;
		}
	}
}

void ball::draw() 
{
	DrawCircle(pos.x, pos.y, radius, RED);
}