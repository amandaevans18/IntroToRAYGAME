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
	int value;
	//type of movement
	// 1 == move up
	//2 == move down
	//3 == move right
	// 4 == move left
	int preSetMovement;
	// is it there?
	bool enabled;

	pickup();
	void update(float deltaTime, float screenX, float screenY);

	void draw();
};