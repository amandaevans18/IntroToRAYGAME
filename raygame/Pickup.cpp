#include "Pickup.h"



void pickup::moveToTheRight(float deltaTime, float screenX, float screenY)
{
	pos.x += speed;

	if (pos.x > screenX + radius)
	{
		pos.x = radius * -1;
	}
}

void pickup::moveToTheLeft(float deltaTime, float screenX, float screenY)
{
	pos.x -= speed;

	if (pos.x < radius * -1)
	{
		pos.x = screenX + radius;
	}
}

void pickup::moveDown(float deltaTime, float screenX, float screenY)
{
	pos.y += speed;

	if (pos.y > screenY + radius)
	{
		pos.y = radius * -1;
	}
}

void pickup::moveUp(float deltaTime, float screenX, float screenY)
{
	pos.y -= speed;

	if (pos.y < radius * -1)
	{
		pos.y = screenY + radius;
	}
}

void pickup::moveRandomly(float deltaTime, float screenX, float screenY)
{

}

void pickup::draw()
{
	if (enabled)
	{
		DrawCircle(pos.x, pos.y, radius, GOLD);
	}
}
