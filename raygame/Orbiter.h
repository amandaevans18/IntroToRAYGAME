#pragma once
#include"raylib.h"
class orbiter 
{
public:
	//position
	Vector2 posOfOrbiter;
	//distance from player
	float distanceFromPlayer;
	//how big the orbiter is
	float radius;
	////speed
	//float speed;
	// is the orbiter there
	bool enabled;

	void update(float deltaTime, float screenX,float screenY,Vector2 player);
	void draw();
};