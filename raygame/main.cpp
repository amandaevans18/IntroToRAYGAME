/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include"Ball.h"
#include"Pickup.h"
#include<string>
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	int timer = 60;
	int oneSec = 0;
	//Controls the window size / makes the window
	InitWindow(screenWidth, screenHeight, "What a window");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	ball player;
	player.pos = {100, 100};
	player.speed = 10.0f;
	player.radius = 50.0f;
	//used for just one pick up
	//pickup myself;
	//myself.pos = {400,255};
	//myself.radius = 10.0f;
	//myself.value = 1;
	//myself.enabled = true;

	pickup pickups[3]
	{
		{ { 400,225 },10.0f,1,true},
		{ { 400,250 },10.0f,1,true},
		{ { 400,275 },10.0f,1,true}
	};
	// Main game loop

	int score = 0;
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		oneSec++;
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------
		player.update(GetFrameTime(), screenWidth, screenHeight);
		for (int i = 0; i < 3; ++i)
		{
			if (CheckCollisionCircles(player.pos, player.radius, pickups[i].pos, pickups[i].radius) && pickups[i].enabled == true)
			{
					pickups[i].enabled = false;
					score++;
			}
		}
		if (oneSec >= 60) 
		{
			oneSec = 0;
			timer--;
		}
		// Draw
		//drawings will draw in order, so in this case the background draws first then the players on top and the text on top of that!
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		player.draw();
		for (int i = 0; i < 3; i++)
		{
			pickups[i].draw();
		}
		//wo9w you can draw text 
		//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
		DrawText( ("Score: "+ (std::to_string(score))).c_str(), 100, 50, 20, BLACK);
		DrawText(("Timer: "+(std::to_string(timer))).c_str(), 100, 50, 20, BLACK);
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}