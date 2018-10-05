#include "Ball.h"

void ball::update(float deltaTime, float screenX, float screenY)
{
	//need to add an if player is on the ground
	if (IsKeyDown(KEY_W))
	{
		pos.y -= speed * deltaTime;
		hasMoved = true;
		if (pos.y < radius * -1)
		{
			pos.y = screenY + radius;
		}
	}

	//player moves down
	if (IsKeyDown(KEY_S))
	{
		pos.y += speed * deltaTime;
		hasMoved = true;
		if (pos.y > screenY + radius)
		{
			pos.y = radius * -1;
		}
	}
	//moves right
	if (IsKeyDown(KEY_A))
	{
		//stoping the player from moving that way
		pos.x -= speed * deltaTime;
		hasMoved = true;
		if (pos.x < radius * -1)
		{
			pos.x = screenX + radius;
		}
	}
	//moves left
	if (IsKeyDown(KEY_D))
	{
		pos.x += speed * deltaTime;
		hasMoved = true;
		if (pos.x > screenX + radius)
		{
			pos.x = radius * -1;
		}
	}
}

void ball::draw() 
{
	DrawCircleGradient(pos.x, pos.y, radius, YELLOW,ORANGE);
}