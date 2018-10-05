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
#include"Enemy.h"
#include"Orbiter.h"
#include<string>
#include<iostream>
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	
	int screenWidth = 800;
	int screenHeight = 450;
	float timer = 0.0f;
	int pickupAmt = 3;
	int enemyAmt = 3;
	int orbitesAmt = 5;
	int health = 0;
	bool won = false;
	//Controls the window size / makes the window
	InitWindow(screenWidth, screenHeight, "Platformed");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	ball player;
	player.pos = {100, 210};
	player.speed = 100.0f;
	player.radius = 50.0f;
	pickup pickups[3]
	{
		//Pos{x,y},radius,speed,value,presetmovement,enabled
		{ { 400,225 },10.0f,1.0f,1,4,true},
		{ { 400,250 },10.0f,1.0f,4,3,true},
		{ { 400,275 },10.0f,1.0f,1,2,true}
	};
	
	enemy enemys[3]
	{
		//pos{x,y},radius,speed,presetMovement,enabled
		{ { 300,225 },10.0f,1,2,true },
		{ { 300,250 },10.0f,1,3,true },
		{ { 300,275 },10.0f,1,4,true }
	};
	orbiter orbites[5]
	{
		{ { player.pos.x,player.pos.y },1,5.0f,false },
		{ { player.pos.x,player.pos.y },2,5.0f,false },
		{ { player.pos.x,player.pos.y },3,5.0f,false },
		{ { player.pos.x,player.pos.y },4,5.0f,false },
		{ { player.pos.x,player.pos.y },5,5.0f,false }

	};

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		timer += GetFrameTime();
		if (health >= 0 && health <= 30)
		{
			// Update
			//----------------------------------------------------------------------------------
			// TODO: Update your variables here
			//----------------------------------------------------------------------------------
			player.update(GetFrameTime(), screenWidth, screenHeight);
			//for orbites
			for (int i = 0; i < orbitesAmt; ++i)
			{
				orbites[i].update(timer, screenWidth, screenHeight, player.pos);
			}
			//for pick ups
			for (int i = 0; i < pickupAmt; ++i)
			{
				pickups[i].update(GetFrameTime(), screenWidth, screenHeight);
			}
			//for enemys
			for (int i = 0; i < enemyAmt; ++i)
			{
				enemys[i].update(GetFrameTime(), screenWidth, screenHeight);
			}
			//Checking to see if the other game objects collide with the player!
			for (int i = 0; i < pickupAmt; ++i)
			{
				if (CheckCollisionCircles(player.pos, player.radius, pickups[i].pos, pickups[i].radius) && pickups[i].enabled == true)
				{
					pickups[i].enabled = false;
					health += pickups[i].value;
;
				}
			}
			for (int i = 0; i < enemyAmt; ++i)
			{
				if (CheckCollisionCircles(player.pos, player.radius, enemys[i].pos, enemys[i].radius) && enemys[i].enabled == true)
				{
					enemys[i].enabled = false;
					health--;
				}
			}
			//checking for the amt of ORBITES(enables or disables them)
			for (int i = 0; i < orbitesAmt; i++)
			{

				if (health ==  5) {orbites[0].enabled = true;}
				if (health == 10) {orbites[1].enabled = true;}
				if (health == 15) {orbites[2].enabled = true;}
				if (health == 20) {orbites[3].enabled = true;}
				if (health == 25) {orbites[4].enabled = true;}
				//disables
				if (health < 25) {orbites[4].enabled = false;}
				if (health < 20) {orbites[3].enabled = false;}
				if (health < 15) {orbites[2].enabled = false;}
				if (health < 10) {orbites[1].enabled = false;}
				if (health <  5) {orbites[0].enabled = false;}
			}
			// Draw
			//drawings will draw in order, so in this case the background draws first then the players on top and the text on top of that!
			//----------------------------------------------------------------------------------
			BeginDrawing();

			ClearBackground(RAYWHITE);

			player.draw();
			for (int i = 0; i < pickupAmt; i++)
			{
				pickups[i].draw();
			}
			for (int i = 0; i < enemyAmt; i++)
			{
				enemys[i].draw();
			}
			for (int i = 0; i < orbitesAmt; i++)
			{
				orbites[i].draw();
			}
			//wo9w you can draw text 
			//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
			DrawText(("Orbiters: " + (std::to_string(health))).c_str(), 100, 50, 20, BLACK);
			EndDrawing();
			//----------------------------------------------------------------------------------
		}//another else if that checks for the winning screen
		else if (health >= 30) 
		{
			std::cout << "WINNING SCREEN" << std::endl;
			//winning screen YO
		}
		else if(health < 0)
		{
			//do the end scene!
			bool notDone = true;
			while (notDone)
			{
				BeginDrawing();
				ClearBackground(BLACK);
				DrawText("You're dead... press space to exit", 100, 100, 50, RED);
				EndDrawing();
				if (IsKeyPressed(KEY_SPACE))
				{
					notDone = false;
				}
			}
			break;
		}
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------
	return 0;
}