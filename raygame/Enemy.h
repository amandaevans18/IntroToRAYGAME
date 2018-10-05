#pragma once
#include"raylib.h"
class enemy 
{
public:
	//location
	Vector2 pos;
	float radius;
	//speed
	float speed;
	//type of movement
	// 1 == move up
	//2 == move down
	//3 == move right
	// 4 == move left
	// 5 == random
	int preSetMovement;
	// is it there?
	bool enabled;
	void update(float deltaTime, float screenX, float screenY);

	void draw();

};