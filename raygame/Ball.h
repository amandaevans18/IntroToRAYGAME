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

//functions

	void update(float deltaTime, float screenX, float screenY);
	void draw();

};