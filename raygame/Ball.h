#pragma once
#include "raylib.h"
class ball 
{
public:
//Visuals
	//size
	float radius;

	//position
	Vector2 pos;

//Movement

	//speed
	float speed;
	//player height is the pos.y
	bool hasMoved = false;
//functions

	void update(float deltaTime, float screenX, float screenY);
	void draw();

};