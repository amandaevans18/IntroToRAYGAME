#pragma once
#include"raylib.h"

class pickup 
{
public:
	//location
	Vector2 pos;
	float radius;
	//speed
	float speed;
	//how much it adds or takes away!
	int value;
	// is it there?
	bool enabled;


	void moveToTheRight(float deltaTime, float screenX, float screenY);
	void moveToTheLeft(float deltaTime, float screenX, float screenY);
	void moveDown(float deltaTime, float screenX, float screenY);
	void moveUp(float deltaTime, float screenX, float screenY);
	void moveRandomly(float deltaTime, float screenX, float screenY);
	void draw();
};