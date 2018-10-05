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
	//screen width
	int screenWidth = 800;
	// screen height
	int screenHeight = 450;
	float timer = 0.0f;
	//amt of starting pickups
	int pickupAmt = 6;
	//amt of pickup clones aka double of og pickups
	int pickupCloneAmt = 20;
	//amt of starting enemys
	int enemyAmt = 6;
	//amt of enemy clones
	int enemyCloneAmt = 20;
	//amt of orbites to be collected
	int orbitesAmt = 5;
	//health (amout of orbits collected by player)
	int health = 0;
	//Keeping tract of which clone to spawn PU == pickups EM == enemys
	int nextCloneToSpawnPU = 0;
	int nextCloneToSpawnEM = 0;
	//used to check for the win in order to display win screen!
	bool enemysAreDead = false;

	//Controls the window size / makes the window
	InitWindow(screenWidth, screenHeight, "Platformed");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	//Setting all of the gameobjects varibles 
	//pos.x is between 100-400
	//pos.y is between 100-750
	//speed is between 1-5
	//value is between 1-5
	//preset movement is between 1-4
	//Origs are enabled and clones are disabled to start

	//setting the player
	ball player;
	player.pos = {400, 225 };
	player.speed = 200.0f;
	player.radius = 25.0f;
	
	//setting pick ups and pick ups clones

	pickup pickups[6]{};
	
	pickup pickupsClone[20]{};
	//initialize all clones to be enabled false
	for (int i = 0; i < pickupCloneAmt; i++) 
	{
		pickupsClone[i].enabled = false;
	}
	//setting enemys and enemy clones
	enemy enemys[6]{};
	enemy enemysClone[20]{};
	//initialize all clones to be enabled false
	for (int i = 0; i < enemyCloneAmt; i++) 
	{
		enemysClone[i].enabled = false;
	}
	//Making objects not spawn on player
	//enemys
	for (int i = 0; i < enemyAmt; i++)
	{
		while (CheckCollisionCircles(player.pos, player.radius, enemys[i].pos, enemys[i].radius))
		{
			enemys[i].pos = { (float)GetRandomValue(100, 750), (float)GetRandomValue(100, 400) };
		}
	}
	for (int i = 0; i < enemyCloneAmt; i++)
	{
		while (CheckCollisionCircles(player.pos, player.radius, enemysClone[i].pos, enemysClone[i].radius))
		{
			enemysClone[i].pos = { (float)GetRandomValue(100, 750), (float)GetRandomValue(100, 400) };
		}
	}
	//pickups not on player
	for (int i = 0; i < pickupAmt; i++)
	{
		while (CheckCollisionCircles(player.pos, player.radius, pickups[i].pos, pickups[i].radius))
		{
			pickups[i].pos = { (float)GetRandomValue(100, 750), (float)GetRandomValue(100, 400) };
		}
	}
	for (int i = 0; i < pickupCloneAmt; i++)
	{
		while (CheckCollisionCircles(player.pos, player.radius, pickupsClone[i].pos, pickupsClone[i].radius))
		{
			pickupsClone[i].pos = { (float)GetRandomValue(100, 750), (float)GetRandomValue(100, 400) };
		}
	}
	//Settting them orbites
	orbiter orbites[5]
	{
		//orbites[0]
		{ 
		//posOfOrbiter
		{ player.pos.x,player.pos.y }
		//speed
		,5 
		//DistanceFromPlayer
		,40 
		//Radius
		,5.0f
		//enabled
		,false 
		//COLOR
		,LIGHTGRAY
		},
		//orbites[1]
		{
		//posOfOrbiter
		{ player.pos.x,player.pos.y }
		//speed
		,4
		//DistanceFromPlayer
		,50
		//Radius
		,5.0f
		//enabled
		,false
		//color
		,VIOLET
		},
		//orbites[2]
		{
		//posOfOrbiter
		{ player.pos.x,player.pos.y }
		//speed
		,3
		//DistanceFromPlayer
		,60
		//Radius
		,5.0f
		//enabled
		,false
		//color
		,DARKGREEN
		},
		//orbites[3]
		{
		//posOfOrbiter
		{ player.pos.x,player.pos.y }
		//speed
		,2
		//DistanceFromPlayer
		,70
		//Radius
		,5.0f
		//enabled
		,false
		//COLOR
		,ORANGE
		},
		//orbites[4]
		{
		//posOfOrbiter
		{ player.pos.x,player.pos.y }
		//speed
		,1
		//DistanceFromPlayer
		,80
		//Radius
		,5.0f
		//enabled
		,false
		//color
		,BLUE
		},

	};

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		timer += GetFrameTime();
		//checking for possible win or lose
		if (health >= 0 && health < 25)
		{
			// Update
			//----------------------------------------------------------------------------------
			// TODO: Update your variables here
			//----------------------------------------------------------------------------------
			//MOVEMENT
			player.update(GetFrameTime(), screenWidth, screenHeight);
			//locks enemy and pick up movement until player moves
			if (player.hasMoved)
			{
				//for orbites to move
				for (int i = 0; i < orbitesAmt; ++i)
				{
					orbites[i].update(timer, screenWidth, screenHeight, player.pos);
				}

				//for pick ups and there clones to move
				for (int i = 0; i < pickupAmt; ++i)
				{
					pickups[i].update(GetFrameTime(), screenWidth, screenHeight);
				}
				for (int i = 0; i < pickupCloneAmt; ++i)
				{
					pickupsClone[i].update(GetFrameTime(), screenWidth, screenHeight);
				}

				//for enemys and there clones to move
				for (int i = 0; i < enemyAmt; ++i)
				{
					enemys[i].update(GetFrameTime(), screenWidth, screenHeight);
				}
				for (int i = 0; i < enemyCloneAmt; ++i)
				{
					enemysClone[i].update(GetFrameTime(), screenWidth, screenHeight);
				}
			}


			//Collision!
			//pick up collision (and respawn)
			for (int i = 0; i < pickupAmt; ++i)
			{
				if (CheckCollisionCircles(player.pos, player.radius, pickups[i].pos, pickups[i].radius) && pickups[i].enabled == true)
				{
					pickups[i].enabled = false;
					health += pickups[i].value;
					pickupsClone[0 + nextCloneToSpawnPU ].enabled = true;
					if (nextCloneToSpawnPU < pickupCloneAmt) 
					{
						nextCloneToSpawnPU++;
					}
				}
			}
			//enemy collision
			for (int i = 0; i < enemyAmt; ++i)
			{
				if (CheckCollisionCircles(player.pos, player.radius, enemys[i].pos, enemys[i].radius) && enemys[i].enabled == true)
				{
					enemys[i].enabled = false;
					health -= enemys[i].value;
					enemysClone[0 + nextCloneToSpawnEM].enabled = true;
					if (nextCloneToSpawnEM < pickupCloneAmt)
					{
						nextCloneToSpawnEM++;
					}
				}
			}
			//enemy clone collision and respawn
			for (int i = 0; i < enemyCloneAmt; ++i)
			{
				if (CheckCollisionCircles(player.pos, player.radius, enemysClone[i].pos,enemysClone[i].radius) && enemysClone[i].enabled == true)
				{
					enemysClone[i].enabled = false;
					health-=enemysClone[i].value;
					enemysClone[0 + nextCloneToSpawnEM].enabled = true;
					if (nextCloneToSpawnEM < pickupCloneAmt)
					{
						nextCloneToSpawnEM++;
					}
				}
			}
			//pick up clone collision (and respawn)
			for (int i = 0; i < pickupCloneAmt; ++i)
			{
				if (CheckCollisionCircles(player.pos, player.radius, pickupsClone[i].pos, pickupsClone[i].radius) && pickupsClone[i].enabled == true)
				{
					pickupsClone[i].enabled = false;
					health += pickupsClone[i].value;
					pickupsClone[0 + nextCloneToSpawnPU].enabled = true;
					if (nextCloneToSpawnPU < pickupCloneAmt)
					{
						nextCloneToSpawnPU++;
					}
				}
			}

			//checking for the amt of ORBITES(enables or disables them)
			
			if (health >= 5) { orbites[0].enabled = true; }
			if (health >= 10) { orbites[1].enabled = true; }
			if (health >= 15) { orbites[2].enabled = true; }
			if (health >= 20) { orbites[3].enabled = true; }
			if (health >= 25) { orbites[4].enabled = true; }
			//disables
			
			if (health < 25) { orbites[4].enabled = false; }
			if (health < 20) { orbites[3].enabled = false; }
			if (health < 15) { orbites[2].enabled = false; }
			if (health < 10) { orbites[1].enabled = false; }
			if (health < 5) { orbites[0].enabled = false; }
			

			// Draw
			//drawings will draw in order, so in this case the background draws first then the players on top and the text on top of that!
			//----------------------------------------------------------------------------------
			BeginDrawing();

			ClearBackground({0, 1, 40});

			player.draw();
			for (int i = 0; i < pickupAmt; i++)
			{
				pickups[i].draw();
				pickupsClone[i].draw();
			}
			for (int i = 0; i < enemyAmt; i++)
			{
				enemys[i].draw();
				enemysClone[i].draw();
			}
			for (int i = 0; i < orbitesAmt; i++)
			{
				orbites[i].draw();
			}
			//wo9w you can draw text 
			//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
			DrawText(("Orbiters: " + (std::to_string(health))).c_str(), 25, 25, 20, LIGHTGRAY);
			EndDrawing();
			//----------------------------------------------------------------------------------
		}//another else if that checks for the winning screen ()
		else if (health >= 25) 
		{
			//winning screen YO
			bool notDone = true;
			while (notDone)
			{
				timer += GetFrameTime();
				player.update(GetFrameTime(), screenWidth, screenHeight);
				//for orbites to move
				for (int i = 0; i < orbitesAmt; ++i)
				{
					orbites[i].update(timer, screenWidth, screenHeight, player.pos);
				}
				BeginDrawing();
				ClearBackground(WHITE);
				DrawText("You won... press space to exit", 25, 100, 50, GREEN);
				player.draw();
				for (int i = 0; i < orbitesAmt; i++)
				{
					orbites[i].draw();
				}
				EndDrawing();
				if (IsKeyPressed(KEY_SPACE))
				{
					notDone = false;
					continue;
				}
			}
			break;
		}
		else if(health < 0)
		{
			//do the end scene!
			bool notDone = true;
			while (notDone)
			{
				BeginDrawing();
				ClearBackground(BLACK);
				DrawText("You're dead... press SPACE to exit", 50, 100, 30, RED);
				DrawText("ha get it...SPACE", 50, 150, 10, RED);
				EndDrawing();
				if (IsKeyPressed(KEY_SPACE))
				{
					notDone = false;
					continue;
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