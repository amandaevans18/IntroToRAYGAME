#pragma once
#include"raylib.h"
class orbiter 
{
public:
	//position
	Vector2 posOfOrbiter;
	//speed
	float speed;
	//distance from player
	float distanceFromPlayer;
	//how big the orbiter is
	float radius;
	// is the orbiter there
	bool enabled;
	Color color;

	void update(float deltaTime, float screenX,float screenY,Vector2 player);
	void draw();
};