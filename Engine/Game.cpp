/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>
#include "Keyboard.h"
#include <assert.h>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	xDist(0, 770),
	yDist(0, 570),
	vxDist(-250, 250),
	vyDist(-250, 250),
	dude(Vector2D(390, 250)),
	target(Vector2D(xDist(rng), yDist(rng))),
	speeder(Vector2D(xDist(rng), yDist(rng))),
	immune(Vector2D(xDist(rng), yDist(rng)))
{
	poos[0].Init(Vector2D(xDist(rng), yDist(rng)), Vector2D(vxDist(rng), vyDist(rng)));
}

void Game::Go()
{
	gfx.BeginFrame();

	UpdateModel();

	ComposeFrame();

	gfx.EndFrame();
}

void Game::UpdateModel()
{
	// Calculating deltaTime
	float deltaTime = ft.Mark();

	// Checking if target is consumed
	// Spawning poo and the next target
	if (target.GetIsEaten())
	{
		target.SetPos(Vector2D(xDist(rng), yDist(rng)));
		poos[pooIndex].Init(Vector2D(xDist(rng), yDist(rng)), Vector2D(vxDist(rng), vyDist(rng)));
		poos[pooIndex].initialized = true;
		pooIndex += 1;
		target.SetIsEaten(false);
		target.SetRelocated(true);
	}

	// Checking if the game is paused
	if (GamePaused)
	{
		// Drawing title screen
		DrawStartGame(375, 275);

		// Starting the game if "RETURN" or "LEFT CLICK" is pressed
		if (wnd.mouse.LeftIsPressed())
		{
			GamePaused = false;
		}
		else if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			GamePaused = false;
		}
	}
	else
	{
		// Drawing the borders of target counter bar
		DrawTargetCounterLimits();

		// Speeding up the dude if the speeder is consumed
		if (speeder.GetIsEaten())
		{
			dude.SetV(400.0f);
		}
		else
		{
			// Keeping the speeder perk spawned for two rounds
			// Drawing the speeder perk, checking if it is colliding with dude and making it glow
			if (pooIndex >= 5 && pooIndex < 7)
			{
				speeder.ChangeColor();
				speeder.ProcessConsumption(dude);
				speeder.Draw(gfx);
			}
			dude.SetV(200.0f);
		}

		// Keeping the immunity perk spawned for one round
		// Drawing the immunity perk and checking if it is colliding with dude
		if (!immune.GetIsEaten())
		{
			if (pooIndex == immune.GetImmuneLevel())
			{
				immune.ProcessConsumption(dude);
				immune.Draw(gfx);
			}
		}

		// Checking if target is colliding with dude and making it glow
		target.ProcessConsumtion(dude);
		target.ChangeColor();

		// Activating the mouse controls for dude
		dude.UpdateMs(wnd.kbd, deltaTime, wnd.mouse);

		// Activating the keyboard controls for dude
		//dude.UpdateKbd(wnd.kbd, deltaTime);

		// Keeping the dude inside of the screen
		dude.ClampToScreen();

		// Checking if the dude consumed the target
		if (!dude.GetHasEaten())
		{
			for (int i = 0; i < pooIndex; ++i)
			{
				assert(poos[i].initialized == true);

				// Making the poos move
				poos[i].Update(deltaTime);

				// Checking if the immunity is activated
				if (!immune.GetIsEaten())
				{
					// Checking if poos are colliding with dude
					poos[i].ProcessConsumption(dude);
				}
				else
				{
					if (pooIndex != immune.GetImmuneLevel())
					{
						poos[i].ProcessConsumption(dude);
					}
				}


			}
		}
	}
}

// Drawing UI objects
void Game::DrawGameOver(int x, int y)
{
	gfx.PutPixel(3 + x, 8 + y, 12, 12, 12);
	gfx.PutPixel(4 + x, 8 + y, 92, 92, 92);
	gfx.PutPixel(5 + x, 8 + y, 195, 195, 195);
	gfx.PutPixel(6 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(7 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(8 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(9 + x, 8 + y, 195, 195, 195);
	gfx.PutPixel(10 + x, 8 + y, 122, 122, 122);
	gfx.PutPixel(11 + x, 8 + y, 38, 38, 38);
	gfx.PutPixel(16 + x, 8 + y, 64, 64, 64);
	gfx.PutPixel(17 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(19 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(20 + x, 8 + y, 38, 38, 38);
	gfx.PutPixel(25 + x, 8 + y, 107, 107, 107);
	gfx.PutPixel(26 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(29 + x, 8 + y, 12, 12, 12);
	gfx.PutPixel(33 + x, 8 + y, 38, 38, 38);
	gfx.PutPixel(34 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(35 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(36 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 8 + y, 107, 107, 107);
	gfx.PutPixel(40 + x, 8 + y, 174, 174, 174);
	gfx.PutPixel(41 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(42 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(44 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(45 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(46 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(47 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(48 + x, 8 + y, 51, 51, 51);
	gfx.PutPixel(2 + x, 9 + y, 12, 12, 12);
	gfx.PutPixel(3 + x, 9 + y, 195, 195, 195);
	gfx.PutPixel(4 + x, 9 + y, 255, 255, 255);
	gfx.PutPixel(5 + x, 9 + y, 195, 195, 195);
	gfx.PutPixel(6 + x, 9 + y, 51, 51, 51);
	gfx.PutPixel(8 + x, 9 + y, 12, 12, 12);
	gfx.PutPixel(9 + x, 9 + y, 107, 107, 107);
	gfx.PutPixel(10 + x, 9 + y, 255, 255, 255);
	gfx.PutPixel(11 + x, 9 + y, 174, 174, 174);
	gfx.PutPixel(16 + x, 9 + y, 139, 139, 139);
	gfx.PutPixel(17 + x, 9 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 9 + y, 255, 255, 255);
	gfx.PutPixel(19 + x, 9 + y, 255, 255, 255);
	gfx.PutPixel(20 + x, 9 + y, 122, 122, 122);
	gfx.PutPixel(25 + x, 9 + y, 107, 107, 107);
	gfx.PutPixel(26 + x, 9 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 9 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 9 + y, 255, 255, 255);
	gfx.PutPixel(29 + x, 9 + y, 78, 78, 78);
	gfx.PutPixel(33 + x, 9 + y, 139, 139, 139);
	gfx.PutPixel(34 + x, 9 + y, 255, 255, 255);
	gfx.PutPixel(35 + x, 9 + y, 255, 255, 255);
	gfx.PutPixel(36 + x, 9 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 9 + y, 107, 107, 107);
	gfx.PutPixel(40 + x, 9 + y, 174, 174, 174);
	gfx.PutPixel(41 + x, 9 + y, 255, 255, 255);
	gfx.PutPixel(42 + x, 9 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 9 + y, 51, 51, 51);
	gfx.PutPixel(2 + x, 10 + y, 195, 195, 195);
	gfx.PutPixel(3 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(5 + x, 10 + y, 25, 25, 25);
	gfx.PutPixel(10 + x, 10 + y, 38, 38, 38);
	gfx.PutPixel(11 + x, 10 + y, 156, 156, 156);
	gfx.PutPixel(16 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(17 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(19 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(20 + x, 10 + y, 218, 218, 218);
	gfx.PutPixel(25 + x, 10 + y, 107, 107, 107);
	gfx.PutPixel(26 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(29 + x, 10 + y, 195, 195, 195);
	gfx.PutPixel(32 + x, 10 + y, 12, 12, 12);
	gfx.PutPixel(33 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(34 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(35 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(36 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 10 + y, 107, 107, 107);
	gfx.PutPixel(40 + x, 10 + y, 174, 174, 174);
	gfx.PutPixel(41 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(42 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 10 + y, 51, 51, 51);
	gfx.PutPixel(1 + x, 11 + y, 64, 64, 64);
	gfx.PutPixel(2 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(3 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 11 + y, 139, 139, 139);
	gfx.PutPixel(15 + x, 11 + y, 64, 64, 64);
	gfx.PutPixel(16 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(17 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 11 + y, 195, 195, 195);
	gfx.PutPixel(19 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(20 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(21 + x, 11 + y, 38, 38, 38);
	gfx.PutPixel(25 + x, 11 + y, 107, 107, 107);
	gfx.PutPixel(26 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(29 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(30 + x, 11 + y, 25, 25, 25);
	gfx.PutPixel(32 + x, 11 + y, 78, 78, 78);
	gfx.PutPixel(33 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(34 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(35 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(36 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 11 + y, 107, 107, 107);
	gfx.PutPixel(40 + x, 11 + y, 174, 174, 174);
	gfx.PutPixel(41 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(42 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 11 + y, 51, 51, 51);
	gfx.PutPixel(1 + x, 12 + y, 139, 139, 139);
	gfx.PutPixel(2 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(3 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 12 + y, 78, 78, 78);
	gfx.PutPixel(15 + x, 12 + y, 139, 139, 139);
	gfx.PutPixel(16 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(17 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 12 + y, 51, 51, 51);
	gfx.PutPixel(19 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(20 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(21 + x, 12 + y, 122, 122, 122);
	gfx.PutPixel(25 + x, 12 + y, 107, 107, 107);
	gfx.PutPixel(26 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 12 + y, 156, 156, 156);
	gfx.PutPixel(29 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(30 + x, 12 + y, 122, 122, 122);
	gfx.PutPixel(32 + x, 12 + y, 174, 174, 174);
	gfx.PutPixel(33 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(34 + x, 12 + y, 139, 139, 139);
	gfx.PutPixel(35 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(36 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 12 + y, 107, 107, 107);
	gfx.PutPixel(40 + x, 12 + y, 174, 174, 174);
	gfx.PutPixel(41 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(42 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 12 + y, 51, 51, 51);
	gfx.PutPixel(1 + x, 13 + y, 174, 174, 174);
	gfx.PutPixel(2 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(3 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 13 + y, 51, 51, 51);
	gfx.PutPixel(15 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(16 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(17 + x, 13 + y, 195, 195, 195);
	gfx.PutPixel(19 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(20 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(21 + x, 13 + y, 218, 218, 218);
	gfx.PutPixel(25 + x, 13 + y, 107, 107, 107);
	gfx.PutPixel(26 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 13 + y, 78, 78, 78);
	gfx.PutPixel(29 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(30 + x, 13 + y, 218, 218, 218);
	gfx.PutPixel(31 + x, 13 + y, 25, 25, 25);
	gfx.PutPixel(32 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(33 + x, 13 + y, 195, 195, 195);
	gfx.PutPixel(34 + x, 13 + y, 107, 107, 107);
	gfx.PutPixel(35 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(36 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 13 + y, 107, 107, 107);
	gfx.PutPixel(40 + x, 13 + y, 174, 174, 174);
	gfx.PutPixel(41 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(42 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(44 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(45 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(46 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(47 + x, 13 + y, 174, 174, 174);
	gfx.PutPixel(1 + x, 14 + y, 174, 174, 174);
	gfx.PutPixel(2 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(3 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 14 + y, 51, 51, 51);
	gfx.PutPixel(6 + x, 14 + y, 108, 107, 107);
	gfx.PutPixel(7 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(8 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(9 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(10 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(11 + x, 14 + y, 174, 174, 174);
	gfx.PutPixel(14 + x, 14 + y, 64, 64, 64);
	gfx.PutPixel(15 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(16 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(17 + x, 14 + y, 107, 107, 107);
	gfx.PutPixel(19 + x, 14 + y, 156, 156, 156);
	gfx.PutPixel(20 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(21 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(22 + x, 14 + y, 38, 38, 38);
	gfx.PutPixel(25 + x, 14 + y, 107, 107, 107);
	gfx.PutPixel(26 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 14 + y, 51, 51, 51);
	gfx.PutPixel(29 + x, 14 + y, 218, 218, 218);
	gfx.PutPixel(30 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(31 + x, 14 + y, 195, 195, 195);
	gfx.PutPixel(32 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(33 + x, 14 + y, 92, 92, 92);
	gfx.PutPixel(34 + x, 14 + y, 107, 107, 107);
	gfx.PutPixel(35 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(36 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 14 + y, 107, 107, 107);
	gfx.PutPixel(40 + x, 14 + y, 174, 174, 174);
	gfx.PutPixel(41 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(42 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 14 + y, 51, 51, 51);
	gfx.PutPixel(1 + x, 15 + y, 139, 139, 139);
	gfx.PutPixel(2 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(3 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 15 + y, 78, 78, 78);
	gfx.PutPixel(8 + x, 15 + y, 51, 51, 51);
	gfx.PutPixel(9 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(10 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(11 + x, 15 + y, 174, 174, 174);
	gfx.PutPixel(14 + x, 15 + y, 139, 139, 139);
	gfx.PutPixel(15 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(16 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(17 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(19 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(20 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(21 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(22 + x, 15 + y, 122, 122, 122);
	gfx.PutPixel(25 + x, 15 + y, 107, 107, 107);
	gfx.PutPixel(26 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 15 + y, 51, 51, 51);
	gfx.PutPixel(29 + x, 15 + y, 122, 122, 122);
	gfx.PutPixel(30 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(31 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(32 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(33 + x, 15 + y, 25, 25, 25);
	gfx.PutPixel(34 + x, 15 + y, 107, 107, 107);
	gfx.PutPixel(35 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(36 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 15 + y, 107, 107, 107);
	gfx.PutPixel(40 + x, 15 + y, 174, 174, 174);
	gfx.PutPixel(41 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(42 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 15 + y, 51, 51, 51);
	gfx.PutPixel(1 + x, 16 + y, 78, 78, 78);
	gfx.PutPixel(2 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(3 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 16 + y, 139, 139, 139);
	gfx.PutPixel(8 + x, 16 + y, 51, 51, 51);
	gfx.PutPixel(9 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(10 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(11 + x, 16 + y, 174, 174, 174);
	gfx.PutPixel(14 + x, 16 + y, 218, 218, 218);
	gfx.PutPixel(15 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(16 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(19 + x, 16 + y, 25, 25, 25);
	gfx.PutPixel(20 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(21 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(22 + x, 16 + y, 218, 218, 218);
	gfx.PutPixel(25 + x, 16 + y, 107, 107, 107);
	gfx.PutPixel(26 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 16 + y, 51, 51, 51);
	gfx.PutPixel(29 + x, 16 + y, 38, 38, 38);
	gfx.PutPixel(30 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(31 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(32 + x, 16 + y, 195, 195, 195);
	gfx.PutPixel(34 + x, 16 + y, 107, 107, 107);
	gfx.PutPixel(35 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(36 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 16 + y, 107, 107, 107);
	gfx.PutPixel(40 + x, 16 + y, 174, 174, 174);
	gfx.PutPixel(41 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(42 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 16 + y, 51, 51, 51);
	gfx.PutPixel(2 + x, 17 + y, 195, 195, 195);
	gfx.PutPixel(3 + x, 17 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 17 + y, 255, 255, 255);
	gfx.PutPixel(5 + x, 17 + y, 38, 38, 38);
	gfx.PutPixel(8 + x, 17 + y, 51, 51, 51);
	gfx.PutPixel(9 + x, 17 + y, 255, 255, 255);
	gfx.PutPixel(10 + x, 17 + y, 255, 255, 255);
	gfx.PutPixel(11 + x, 17 + y, 174, 174, 174);
	gfx.PutPixel(13 + x, 17 + y, 38, 38, 38);
	gfx.PutPixel(14 + x, 17 + y, 255, 255, 255);
	gfx.PutPixel(15 + x, 17 + y, 255, 255, 255);
	gfx.PutPixel(16 + x, 17 + y, 156, 156, 156);
	gfx.PutPixel(20 + x, 17 + y, 195, 195, 195);
	gfx.PutPixel(21 + x, 17 + y, 255, 255, 255);
	gfx.PutPixel(22 + x, 17 + y, 255, 255, 255);
	gfx.PutPixel(23 + x, 17 + y, 38, 38, 38);
	gfx.PutPixel(25 + x, 17 + y, 107, 107, 107);
	gfx.PutPixel(26 + x, 17 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 17 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 17 + y, 51, 51, 51);
	gfx.PutPixel(30 + x, 17 + y, 218, 218, 218);
	gfx.PutPixel(31 + x, 17 + y, 255, 255, 255);
	gfx.PutPixel(32 + x, 17 + y, 92, 92, 92);
	gfx.PutPixel(34 + x, 17 + y, 107, 107, 107);
	gfx.PutPixel(35 + x, 17 + y, 255, 255, 255);
	gfx.PutPixel(36 + x, 17 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 17 + y, 107, 107, 107);
	gfx.PutPixel(40 + x, 17 + y, 174, 174, 174);
	gfx.PutPixel(41 + x, 17 + y, 255, 255, 255);
	gfx.PutPixel(42 + x, 17 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 17 + y, 51, 51, 51);
	gfx.PutPixel(2 + x, 18 + y, 38, 38, 38);
	gfx.PutPixel(3 + x, 18 + y, 218, 218, 218);
	gfx.PutPixel(4 + x, 18 + y, 255, 255, 255);
	gfx.PutPixel(5 + x, 18 + y, 255, 255, 255);
	gfx.PutPixel(6 + x, 18 + y, 78, 78, 78);
	gfx.PutPixel(8 + x, 18 + y, 51, 51, 51);
	gfx.PutPixel(9 + x, 18 + y, 255, 255, 255);
	gfx.PutPixel(10 + x, 18 + y, 255, 255, 255);
	gfx.PutPixel(11 + x, 18 + y, 174, 174, 174);
	gfx.PutPixel(13 + x, 18 + y, 122, 122, 122);
	gfx.PutPixel(14 + x, 18 + y, 255, 255, 255);
	gfx.PutPixel(15 + x, 18 + y, 255, 255, 255);
	gfx.PutPixel(16 + x, 18 + y, 78, 78, 78);
	gfx.PutPixel(20 + x, 18 + y, 107, 107, 107);
	gfx.PutPixel(21 + x, 18 + y, 255, 255, 255);
	gfx.PutPixel(22 + x, 18 + y, 255, 255, 255);
	gfx.PutPixel(23 + x, 18 + y, 122, 122, 122);
	gfx.PutPixel(25 + x, 18 + y, 107, 107, 107);
	gfx.PutPixel(26 + x, 18 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 18 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 18 + y, 51, 51, 51);
	gfx.PutPixel(34 + x, 18 + y, 107, 107, 107);
	gfx.PutPixel(35 + x, 18 + y, 255, 255, 255);
	gfx.PutPixel(36 + x, 18 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 18 + y, 107, 107, 107);
	gfx.PutPixel(40 + x, 18 + y, 174, 174, 174);
	gfx.PutPixel(41 + x, 18 + y, 255, 255, 255);
	gfx.PutPixel(42 + x, 18 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 18 + y, 51, 51, 51);
	gfx.PutPixel(3 + x, 19 + y, 12, 12, 12);
	gfx.PutPixel(4 + x, 19 + y, 107, 107, 107);
	gfx.PutPixel(5 + x, 19 + y, 195, 195, 195);
	gfx.PutPixel(6 + x, 19 + y, 255, 255, 255);
	gfx.PutPixel(7 + x, 19 + y, 255, 255, 255);
	gfx.PutPixel(8 + x, 19 + y, 255, 255, 255);
	gfx.PutPixel(9 + x, 19 + y, 174, 174, 174);
	gfx.PutPixel(10 + x, 19 + y, 122, 122, 122);
	gfx.PutPixel(11 + x, 19 + y, 38, 38, 38);
	gfx.PutPixel(13 + x, 19 + y, 218, 218, 218);
	gfx.PutPixel(14 + x, 19 + y, 255, 255, 255);
	gfx.PutPixel(15 + x, 19 + y, 255, 255, 255);
	gfx.PutPixel(16 + x, 19 + y, 12, 12, 12);
	gfx.PutPixel(20 + x, 19 + y, 38, 38, 38);
	gfx.PutPixel(21 + x, 19 + y, 255, 255, 255);
	gfx.PutPixel(22 + x, 19 + y, 255, 255, 255);
	gfx.PutPixel(23 + x, 19 + y, 218, 218, 218);
	gfx.PutPixel(25 + x, 19 + y, 107, 107, 107);
	gfx.PutPixel(26 + x, 19 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 19 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 19 + y, 51, 51, 51);
	gfx.PutPixel(34 + x, 19 + y, 107, 107, 107);
	gfx.PutPixel(35 + x, 19 + y, 255, 255, 255);
	gfx.PutPixel(36 + x, 19 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 19 + y, 107, 107, 107);
	gfx.PutPixel(40 + x, 19 + y, 174, 174, 174);
	gfx.PutPixel(41 + x, 19 + y, 255, 255, 255);
	gfx.PutPixel(42 + x, 19 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 19 + y, 255, 255, 255);
	gfx.PutPixel(44 + x, 19 + y, 255, 255, 255);
	gfx.PutPixel(45 + x, 19 + y, 255, 255, 255);
	gfx.PutPixel(46 + x, 19 + y, 255, 255, 255);
	gfx.PutPixel(47 + x, 19 + y, 255, 255, 255);
	gfx.PutPixel(48 + x, 19 + y, 51, 51, 51);
	gfx.PutPixel(5 + x, 27 + y, 92, 92, 92);
	gfx.PutPixel(6 + x, 27 + y, 195, 195, 195);
	gfx.PutPixel(7 + x, 27 + y, 255, 255, 255);
	gfx.PutPixel(8 + x, 27 + y, 255, 255, 255);
	gfx.PutPixel(9 + x, 27 + y, 218, 218, 218);
	gfx.PutPixel(10 + x, 27 + y, 122, 122, 122);
	gfx.PutPixel(11 + x, 27 + y, 12, 12, 12);
	gfx.PutPixel(14 + x, 27 + y, 78, 78, 78);
	gfx.PutPixel(15 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(16 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(17 + x, 27 + y, 78, 78, 78);
	gfx.PutPixel(22 + x, 27 + y, 107, 107, 107);
	gfx.PutPixel(23 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(24 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(25 + x, 27 + y, 51, 51, 51);
	gfx.PutPixel(27 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(28 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(29 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(30 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(31 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(32 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(33 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(34 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(37 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(38 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(39 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(40 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(41 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(42 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(43 + x, 27 + y, 122, 122, 122);
	gfx.PutPixel(44 + x, 27 + y, 38, 38, 38);
	gfx.PutPixel(49 + x, 27 + y, 1, 1, 1);
	gfx.PutPixel(3 + x, 28 + y, 12, 12, 12);
	gfx.PutPixel(4 + x, 28 + y, 195, 195, 195);
	gfx.PutPixel(5 + x, 28 + y, 255, 255, 255);
	gfx.PutPixel(6 + x, 28 + y, 255, 255, 255);
	gfx.PutPixel(7 + x, 28 + y, 78, 78, 78);
	gfx.PutPixel(8 + x, 28 + y, 64, 64, 64);
	gfx.PutPixel(9 + x, 28 + y, 195, 195, 195);
	gfx.PutPixel(10 + x, 28 + y, 255, 255, 255);
	gfx.PutPixel(11 + x, 28 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 28 + y, 38, 38, 38);
	gfx.PutPixel(14 + x, 28 + y, 38, 38, 38);
	gfx.PutPixel(15 + x, 28 + y, 255, 255, 255);
	gfx.PutPixel(16 + x, 28 + y, 255, 255, 255);
	gfx.PutPixel(17 + x, 28 + y, 174, 174, 174);
	gfx.PutPixel(22 + x, 28 + y, 218, 218, 218);
	gfx.PutPixel(23 + x, 28 + y, 255, 255, 255);
	gfx.PutPixel(24 + x, 28 + y, 255, 255, 255);
	gfx.PutPixel(25 + x, 28 + y, 12, 12, 12);
	gfx.PutPixel(27 + x, 28 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 28 + y, 255, 255, 255);
	gfx.PutPixel(29 + x, 28 + y, 255, 255, 255);
	gfx.PutPixel(30 + x, 28 + y, 51, 51, 51);
	gfx.PutPixel(31 + x, 28 + y, 51, 51, 51);
	gfx.PutPixel(32 + x, 28 + y, 51, 51, 51);
	gfx.PutPixel(33 + x, 28 + y, 51, 51, 51);
	gfx.PutPixel(34 + x, 28 + y, 51, 51, 51);
	gfx.PutPixel(37 + x, 28 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 28 + y, 255, 255, 255);
	gfx.PutPixel(39 + x, 28 + y, 255, 255, 255);
	gfx.PutPixel(40 + x, 28 + y, 51, 51, 51);
	gfx.PutPixel(41 + x, 28 + y, 51, 51, 51);
	gfx.PutPixel(42 + x, 28 + y, 195, 195, 195);
	gfx.PutPixel(43 + x, 28 + y, 255, 255, 255);
	gfx.PutPixel(44 + x, 28 + y, 255, 255, 255);
	gfx.PutPixel(45 + x, 28 + y, 64, 64, 64);
	gfx.PutPixel(48 + x, 28 + y, 1, 1, 1);
	gfx.PutPixel(49 + x, 28 + y, 3, 3, 3);
	gfx.PutPixel(3 + x, 29 + y, 122, 122, 122);
	gfx.PutPixel(4 + x, 29 + y, 255, 255, 255);
	gfx.PutPixel(5 + x, 29 + y, 255, 255, 255);
	gfx.PutPixel(6 + x, 29 + y, 51, 51, 51);
	gfx.PutPixel(9 + x, 29 + y, 12, 12, 12);
	gfx.PutPixel(10 + x, 29 + y, 255, 255, 255);
	gfx.PutPixel(11 + x, 29 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 29 + y, 195, 195, 195);
	gfx.PutPixel(15 + x, 29 + y, 218, 218, 218);
	gfx.PutPixel(16 + x, 29 + y, 255, 255, 255);
	gfx.PutPixel(17 + x, 29 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 29 + y, 12, 12, 12);
	gfx.PutPixel(21 + x, 29 + y, 25, 25, 25);
	gfx.PutPixel(22 + x, 29 + y, 255, 255, 255);
	gfx.PutPixel(23 + x, 29 + y, 255, 255, 255);
	gfx.PutPixel(24 + x, 29 + y, 156, 156, 156);
	gfx.PutPixel(27 + x, 29 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 29 + y, 255, 255, 255);
	gfx.PutPixel(29 + x, 29 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 29 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 29 + y, 255, 255, 255);
	gfx.PutPixel(39 + x, 29 + y, 255, 255, 255);
	gfx.PutPixel(42 + x, 29 + y, 25, 25, 25);
	gfx.PutPixel(43 + x, 29 + y, 255, 255, 255);
	gfx.PutPixel(44 + x, 29 + y, 255, 255, 255);
	gfx.PutPixel(45 + x, 29 + y, 218, 218, 218);
	gfx.PutPixel(49 + x, 29 + y, 1, 1, 1);
	gfx.PutPixel(2 + x, 30 + y, 12, 12, 12);
	gfx.PutPixel(3 + x, 30 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 30 + y, 255, 255, 255);
	gfx.PutPixel(5 + x, 30 + y, 218, 218, 218);
	gfx.PutPixel(10 + x, 30 + y, 139, 139, 139);
	gfx.PutPixel(11 + x, 30 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 30 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 30 + y, 64, 64, 64);
	gfx.PutPixel(15 + x, 30 + y, 122, 122, 122);
	gfx.PutPixel(16 + x, 30 + y, 255, 255, 255);
	gfx.PutPixel(17 + x, 30 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 30 + y, 64, 64, 64);
	gfx.PutPixel(21 + x, 30 + y, 92, 92, 92);
	gfx.PutPixel(22 + x, 30 + y, 255, 255, 255);
	gfx.PutPixel(23 + x, 30 + y, 255, 255, 255);
	gfx.PutPixel(24 + x, 30 + y, 78, 78, 78);
	gfx.PutPixel(27 + x, 30 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 30 + y, 255, 255, 255);
	gfx.PutPixel(29 + x, 30 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 30 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 30 + y, 255, 255, 255);
	gfx.PutPixel(39 + x, 30 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 30 + y, 255, 255, 255);
	gfx.PutPixel(44 + x, 30 + y, 255, 255, 255);
	gfx.PutPixel(45 + x, 30 + y, 255, 255, 255);
	gfx.PutPixel(2 + x, 31 + y, 64, 64, 64);
	gfx.PutPixel(3 + x, 31 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 31 + y, 255, 255, 255);
	gfx.PutPixel(5 + x, 31 + y, 139, 139, 139);
	gfx.PutPixel(10 + x, 31 + y, 78, 78, 78);
	gfx.PutPixel(11 + x, 31 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 31 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 31 + y, 122, 122, 122);
	gfx.PutPixel(15 + x, 31 + y, 38, 38, 38);
	gfx.PutPixel(16 + x, 31 + y, 255, 255, 255);
	gfx.PutPixel(17 + x, 31 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 31 + y, 122, 122, 122);
	gfx.PutPixel(21 + x, 31 + y, 156, 156, 156);
	gfx.PutPixel(22 + x, 31 + y, 255, 255, 255);
	gfx.PutPixel(23 + x, 31 + y, 255, 255, 255);
	gfx.PutPixel(24 + x, 31 + y, 12, 12, 12);
	gfx.PutPixel(27 + x, 31 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 31 + y, 255, 255, 255);
	gfx.PutPixel(29 + x, 31 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 31 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 31 + y, 255, 255, 255);
	gfx.PutPixel(39 + x, 31 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 31 + y, 255, 255, 255);
	gfx.PutPixel(44 + x, 31 + y, 255, 255, 255);
	gfx.PutPixel(45 + x, 31 + y, 255, 255, 255);
	gfx.PutPixel(2 + x, 32 + y, 107, 107, 107);
	gfx.PutPixel(3 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(5 + x, 32 + y, 107, 107, 107);
	gfx.PutPixel(10 + x, 32 + y, 51, 51, 51);
	gfx.PutPixel(11 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 32 + y, 174, 174, 174);
	gfx.PutPixel(16 + x, 32 + y, 218, 218, 218);
	gfx.PutPixel(17 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 32 + y, 218, 218, 218);
	gfx.PutPixel(21 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(22 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(23 + x, 32 + y, 156, 156, 156);
	gfx.PutPixel(27 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(29 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(30 + x, 32 + y, 174, 174, 174);
	gfx.PutPixel(31 + x, 32 + y, 174, 174, 174);
	gfx.PutPixel(32 + x, 32 + y, 174, 174, 174);
	gfx.PutPixel(33 + x, 32 + y, 174, 174, 174);
	gfx.PutPixel(34 + x, 32 + y, 78, 78, 78);
	gfx.PutPixel(37 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(39 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(42 + x, 32 + y, 12, 12, 12);
	gfx.PutPixel(43 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(44 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(45 + x, 32 + y, 174, 174, 174);
	gfx.PutPixel(2 + x, 33 + y, 107, 107, 107);
	gfx.PutPixel(3 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(5 + x, 33 + y, 107, 107, 107);
	gfx.PutPixel(10 + x, 33 + y, 51, 51, 51);
	gfx.PutPixel(11 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 33 + y, 174, 174, 174);
	gfx.PutPixel(16 + x, 33 + y, 122, 122, 122);
	gfx.PutPixel(17 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(19 + x, 33 + y, 25, 25, 25);
	gfx.PutPixel(20 + x, 33 + y, 51, 51, 51);
	gfx.PutPixel(21 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(22 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(23 + x, 33 + y, 78, 78, 78);
	gfx.PutPixel(27 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(29 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(30 + x, 33 + y, 51, 51, 51);
	gfx.PutPixel(31 + x, 33 + y, 51, 51, 51);
	gfx.PutPixel(32 + x, 33 + y, 51, 51, 51);
	gfx.PutPixel(33 + x, 33 + y, 51, 51, 51);
	gfx.PutPixel(34 + x, 33 + y, 25, 25, 25);
	gfx.PutPixel(37 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(39 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(42 + x, 33 + y, 107, 107, 107);
	gfx.PutPixel(43 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(44 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(45 + x, 33 + y, 38, 38, 38);
	gfx.PutPixel(2 + x, 34 + y, 92, 92, 92);
	gfx.PutPixel(3 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(5 + x, 34 + y, 107, 107, 107);
	gfx.PutPixel(10 + x, 34 + y, 51, 51, 51);
	gfx.PutPixel(11 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 34 + y, 156, 156, 156);
	gfx.PutPixel(16 + x, 34 + y, 38, 38, 38);
	gfx.PutPixel(17 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(19 + x, 34 + y, 78, 78, 78);
	gfx.PutPixel(20 + x, 34 + y, 122, 122, 122);
	gfx.PutPixel(21 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(22 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(23 + x, 34 + y, 12, 12, 12);
	gfx.PutPixel(27 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(29 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(39 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(40 + x, 34 + y, 174, 174, 174);
	gfx.PutPixel(41 + x, 34 + y, 195, 195, 195);
	gfx.PutPixel(42 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(44 + x, 34 + y, 25, 25, 25);
	gfx.PutPixel(2 + x, 35 + y, 38, 38, 38);
	gfx.PutPixel(3 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(5 + x, 35 + y, 174, 174, 174);
	gfx.PutPixel(10 + x, 35 + y, 92, 92, 92);
	gfx.PutPixel(11 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 35 + y, 92, 92, 92);
	gfx.PutPixel(17 + x, 35 + y, 218, 218, 218);
	gfx.PutPixel(18 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(19 + x, 35 + y, 156, 156, 156);
	gfx.PutPixel(20 + x, 35 + y, 195, 195, 195);
	gfx.PutPixel(21 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(22 + x, 35 + y, 156, 156, 156);
	gfx.PutPixel(27 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(29 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(39 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(40 + x, 35 + y, 51, 51, 51);
	gfx.PutPixel(41 + x, 35 + y, 195, 195, 195);
	gfx.PutPixel(42 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(44 + x, 35 + y, 139, 139, 139);
	gfx.PutPixel(3 + x, 36 + y, 218, 218, 218);
	gfx.PutPixel(4 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(5 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(6 + x, 36 + y, 12, 12, 12);
	gfx.PutPixel(10 + x, 36 + y, 174, 174, 174);
	gfx.PutPixel(11 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 36 + y, 25, 25, 25);
	gfx.PutPixel(17 + x, 36 + y, 122, 122, 122);
	gfx.PutPixel(18 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(19 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(20 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(21 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(22 + x, 36 + y, 78, 78, 78);
	gfx.PutPixel(27 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(29 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(39 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(41 + x, 36 + y, 38, 38, 38);
	gfx.PutPixel(42 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(44 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(45 + x, 36 + y, 92, 92, 92);
	gfx.PutPixel(3 + x, 37 + y, 51, 51, 51);
	gfx.PutPixel(4 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(5 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(6 + x, 37 + y, 139, 139, 139);
	gfx.PutPixel(9 + x, 37 + y, 78, 78, 78);
	gfx.PutPixel(10 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(11 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 37 + y, 107, 107, 107);
	gfx.PutPixel(17 + x, 37 + y, 38, 38, 38);
	gfx.PutPixel(18 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(19 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(20 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(21 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(22 + x, 37 + y, 12, 12, 12);
	gfx.PutPixel(27 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(29 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(39 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(42 + x, 37 + y, 64, 64, 64);
	gfx.PutPixel(43 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(44 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(45 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(46 + x, 37 + y, 64, 64, 64);
	gfx.PutPixel(4 + x, 38 + y, 64, 64, 64);
	gfx.PutPixel(5 + x, 38 + y, 255, 255, 255);
	gfx.PutPixel(6 + x, 38 + y, 255, 255, 255);
	gfx.PutPixel(7 + x, 38 + y, 218, 218, 218);
	gfx.PutPixel(8 + x, 38 + y, 195, 195, 195);
	gfx.PutPixel(9 + x, 38 + y, 255, 255, 255);
	gfx.PutPixel(10 + x, 38 + y, 255, 255, 255);
	gfx.PutPixel(11 + x, 38 + y, 107, 107, 107);
	gfx.PutPixel(18 + x, 38 + y, 218, 218, 218);
	gfx.PutPixel(19 + x, 38 + y, 255, 255, 255);
	gfx.PutPixel(20 + x, 38 + y, 255, 255, 255);
	gfx.PutPixel(21 + x, 38 + y, 156, 156, 156);
	gfx.PutPixel(27 + x, 38 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 38 + y, 255, 255, 255);
	gfx.PutPixel(29 + x, 38 + y, 255, 255, 255);
	gfx.PutPixel(30 + x, 38 + y, 174, 174, 174);
	gfx.PutPixel(31 + x, 38 + y, 174, 174, 174);
	gfx.PutPixel(32 + x, 38 + y, 174, 174, 174);
	gfx.PutPixel(33 + x, 38 + y, 174, 174, 174);
	gfx.PutPixel(34 + x, 38 + y, 174, 174, 174);
	gfx.PutPixel(37 + x, 38 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 38 + y, 255, 255, 255);
	gfx.PutPixel(39 + x, 38 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 38 + y, 107, 107, 107);
	gfx.PutPixel(44 + x, 38 + y, 255, 255, 255);
	gfx.PutPixel(45 + x, 38 + y, 255, 255, 255);
	gfx.PutPixel(46 + x, 38 + y, 255, 255, 255);
	gfx.PutPixel(47 + x, 38 + y, 38, 38, 38);
	gfx.PutPixel(6 + x, 39 + y, 64, 64, 64);
	gfx.PutPixel(7 + x, 39 + y, 107, 107, 107);
	gfx.PutPixel(8 + x, 39 + y, 107, 107, 107);
	gfx.PutPixel(9 + x, 39 + y, 78, 78, 78);
	gfx.PutPixel(10 + x, 39 + y, 12, 12, 12);
	gfx.PutPixel(18 + x, 39 + y, 38, 38, 38);
	gfx.PutPixel(19 + x, 39 + y, 51, 51, 51);
	gfx.PutPixel(20 + x, 39 + y, 51, 51, 51);
	gfx.PutPixel(21 + x, 39 + y, 25, 25, 25);
	gfx.PutPixel(27 + x, 39 + y, 51, 51, 51);
	gfx.PutPixel(28 + x, 39 + y, 51, 51, 51);
	gfx.PutPixel(29 + x, 39 + y, 51, 51, 51);
	gfx.PutPixel(30 + x, 39 + y, 51, 51, 51);
	gfx.PutPixel(31 + x, 39 + y, 51, 51, 51);
	gfx.PutPixel(32 + x, 39 + y, 51, 51, 51);
	gfx.PutPixel(33 + x, 39 + y, 51, 51, 51);
	gfx.PutPixel(34 + x, 39 + y, 51, 51, 51);
	gfx.PutPixel(37 + x, 39 + y, 51, 51, 51);
	gfx.PutPixel(38 + x, 39 + y, 51, 51, 51);
	gfx.PutPixel(39 + x, 39 + y, 51, 51, 51);
	gfx.PutPixel(44 + x, 39 + y, 51, 51, 51);
	gfx.PutPixel(45 + x, 39 + y, 51, 51, 51);
	gfx.PutPixel(46 + x, 39 + y, 51, 51, 51);
	gfx.PutPixel(47 + x, 39 + y, 38, 38, 38);

}
void Game::DrawStartGame(int x, int y)
{
	gfx.PutPixel(11 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(14 + x, 10 + y, 218, 218, 218);
	gfx.PutPixel(15 + x, 10 + y, 51, 51, 51);
	gfx.PutPixel(17 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(19 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(20 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(21 + x, 10 + y, 92, 92, 92);
	gfx.PutPixel(23 + x, 10 + y, 51, 51, 51);
	gfx.PutPixel(24 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(25 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(26 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 10 + y, 51, 51, 51);
	gfx.PutPixel(29 + x, 10 + y, 38, 38, 38);
	gfx.PutPixel(30 + x, 10 + y, 174, 174, 174);
	gfx.PutPixel(31 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(32 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(33 + x, 10 + y, 156, 156, 156);
	gfx.PutPixel(35 + x, 10 + y, 38, 38, 38);
	gfx.PutPixel(36 + x, 10 + y, 174, 174, 174);
	gfx.PutPixel(37 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 10 + y, 255, 255, 255);
	gfx.PutPixel(39 + x, 10 + y, 156, 156, 156);
	gfx.PutPixel(11 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 11 + y, 174, 174, 174);
	gfx.PutPixel(13 + x, 11 + y, 12, 12, 12);
	gfx.PutPixel(14 + x, 11 + y, 218, 218, 218);
	gfx.PutPixel(15 + x, 11 + y, 218, 218, 218);
	gfx.PutPixel(17 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 11 + y, 107, 107, 107);
	gfx.PutPixel(20 + x, 11 + y, 195, 195, 195);
	gfx.PutPixel(21 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(23 + x, 11 + y, 51, 51, 51);
	gfx.PutPixel(24 + x, 11 + y, 255, 255, 255);
	gfx.PutPixel(25 + x, 11 + y, 51, 51, 51);
	gfx.PutPixel(29 + x, 11 + y, 156, 156, 156);
	gfx.PutPixel(30 + x, 11 + y, 218, 218, 218);
	gfx.PutPixel(31 + x, 11 + y, 12, 12, 12);
	gfx.PutPixel(32 + x, 11 + y, 12, 12, 12);
	gfx.PutPixel(33 + x, 11 + y, 139, 139, 139);
	gfx.PutPixel(35 + x, 11 + y, 156, 156, 156);
	gfx.PutPixel(36 + x, 11 + y, 218, 218, 218);
	gfx.PutPixel(37 + x, 11 + y, 12, 12, 12);
	gfx.PutPixel(38 + x, 11 + y, 12, 12, 12);
	gfx.PutPixel(39 + x, 11 + y, 139, 139, 139);
	gfx.PutPixel(11 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 12 + y, 174, 174, 174);
	gfx.PutPixel(14 + x, 12 + y, 174, 174, 174);
	gfx.PutPixel(15 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(17 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 12 + y, 107, 107, 107);
	gfx.PutPixel(20 + x, 12 + y, 195, 195, 195);
	gfx.PutPixel(21 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(23 + x, 12 + y, 51, 51, 51);
	gfx.PutPixel(24 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(25 + x, 12 + y, 51, 51, 51);
	gfx.PutPixel(29 + x, 12 + y, 195, 195, 195);
	gfx.PutPixel(30 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(31 + x, 12 + y, 92, 92, 92);
	gfx.PutPixel(32 + x, 12 + y, 38, 38, 38);
	gfx.PutPixel(35 + x, 12 + y, 195, 195, 195);
	gfx.PutPixel(36 + x, 12 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 12 + y, 92, 92, 92);
	gfx.PutPixel(38 + x, 12 + y, 38, 38, 38);
	gfx.PutPixel(11 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 13 + y, 174, 174, 174);
	gfx.PutPixel(13 + x, 13 + y, 12, 12, 12);
	gfx.PutPixel(14 + x, 13 + y, 218, 218, 218);
	gfx.PutPixel(15 + x, 13 + y, 174, 174, 174);
	gfx.PutPixel(17 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(19 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(20 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(21 + x, 13 + y, 38, 38, 38);
	gfx.PutPixel(23 + x, 13 + y, 51, 51, 51);
	gfx.PutPixel(24 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(25 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(26 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(29 + x, 13 + y, 78, 78, 78);
	gfx.PutPixel(30 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(31 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(32 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(33 + x, 13 + y, 174, 174, 174);
	gfx.PutPixel(35 + x, 13 + y, 78, 78, 78);
	gfx.PutPixel(36 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 13 + y, 255, 255, 255);
	gfx.PutPixel(39 + x, 13 + y, 174, 174, 174);
	gfx.PutPixel(6 + x, 14 + y, 1, 0, 0);
	gfx.PutPixel(11 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(14 + x, 14 + y, 174, 174, 174);
	gfx.PutPixel(15 + x, 14 + y, 38, 38, 38);
	gfx.PutPixel(17 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 14 + y, 107, 107, 107);
	gfx.PutPixel(19 + x, 14 + y, 92, 92, 92);
	gfx.PutPixel(20 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(21 + x, 14 + y, 64, 64, 64);
	gfx.PutPixel(23 + x, 14 + y, 51, 51, 51);
	gfx.PutPixel(24 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(25 + x, 14 + y, 51, 51, 51);
	gfx.PutPixel(30 + x, 14 + y, 12, 12, 12);
	gfx.PutPixel(31 + x, 14 + y, 64, 64, 64);
	gfx.PutPixel(32 + x, 14 + y, 195, 195, 195);
	gfx.PutPixel(33 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(34 + x, 14 + y, 51, 51, 51);
	gfx.PutPixel(36 + x, 14 + y, 12, 12, 12);
	gfx.PutPixel(37 + x, 14 + y, 64, 64, 64);
	gfx.PutPixel(38 + x, 14 + y, 195, 195, 195);
	gfx.PutPixel(39 + x, 14 + y, 255, 255, 255);
	gfx.PutPixel(40 + x, 14 + y, 51, 51, 51);
	gfx.PutPixel(11 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 15 + y, 174, 174, 174);
	gfx.PutPixel(17 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 15 + y, 107, 107, 107);
	gfx.PutPixel(20 + x, 15 + y, 195, 195, 195);
	gfx.PutPixel(21 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(22 + x, 15 + y, 12, 12, 12);
	gfx.PutPixel(23 + x, 15 + y, 51, 51, 51);
	gfx.PutPixel(24 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(25 + x, 15 + y, 51, 51, 51);
	gfx.PutPixel(29 + x, 15 + y, 195, 195, 195);
	gfx.PutPixel(30 + x, 15 + y, 38, 38, 38);
	gfx.PutPixel(32 + x, 15 + y, 139, 139, 139);
	gfx.PutPixel(33 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(34 + x, 15 + y, 25, 25, 25);
	gfx.PutPixel(35 + x, 15 + y, 195, 195, 195);
	gfx.PutPixel(36 + x, 15 + y, 38, 38, 38);
	gfx.PutPixel(38 + x, 15 + y, 139, 139, 139);
	gfx.PutPixel(39 + x, 15 + y, 255, 255, 255);
	gfx.PutPixel(40 + x, 15 + y, 25, 25, 25);
	gfx.PutPixel(11 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 16 + y, 174, 174, 174);
	gfx.PutPixel(17 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 16 + y, 107, 107, 107);
	gfx.PutPixel(20 + x, 16 + y, 38, 38, 38);
	gfx.PutPixel(21 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(22 + x, 16 + y, 156, 156, 156);
	gfx.PutPixel(23 + x, 16 + y, 51, 51, 51);
	gfx.PutPixel(24 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(25 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(26 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(28 + x, 16 + y, 51, 51, 51);
	gfx.PutPixel(29 + x, 16 + y, 139, 139, 139);
	gfx.PutPixel(30 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(31 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(32 + x, 16 + y, 218, 218, 218);
	gfx.PutPixel(33 + x, 16 + y, 78, 78, 78);
	gfx.PutPixel(35 + x, 16 + y, 139, 139, 139);
	gfx.PutPixel(36 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(37 + x, 16 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 16 + y, 218, 218, 218);
	gfx.PutPixel(39 + x, 16 + y, 78, 78, 78);
	gfx.PutPixel(6 + x, 19 + y, 51, 51, 51);
	gfx.PutPixel(7 + x, 19 + y, 25, 25, 25);
	gfx.PutPixel(8 + x, 19 + y, 51, 51, 51);
	gfx.PutPixel(9 + x, 19 + y, 12, 12, 12);
	gfx.PutPixel(41 + x, 19 + y, 25, 25, 25);
	gfx.PutPixel(42 + x, 19 + y, 51, 51, 51);
	gfx.PutPixel(43 + x, 19 + y, 25, 25, 25);
	gfx.PutPixel(44 + x, 19 + y, 38, 38, 38);
	gfx.PutPixel(6 + x, 20 + y, 218, 218, 218);
	gfx.PutPixel(7 + x, 20 + y, 107, 107, 107);
	gfx.PutPixel(8 + x, 20 + y, 255, 255, 255);
	gfx.PutPixel(9 + x, 20 + y, 51, 51, 51);
	gfx.PutPixel(10 + x, 20 + y, 12, 12, 12);
	gfx.PutPixel(11 + x, 20 + y, 51, 51, 51);
	gfx.PutPixel(12 + x, 20 + y, 51, 51, 51);
	gfx.PutPixel(13 + x, 20 + y, 51, 51, 51);
	gfx.PutPixel(14 + x, 20 + y, 51, 51, 51);
	gfx.PutPixel(15 + x, 20 + y, 12, 12, 12);
	gfx.PutPixel(16 + x, 20 + y, 25, 25, 25);
	gfx.PutPixel(17 + x, 20 + y, 51, 51, 51);
	gfx.PutPixel(18 + x, 20 + y, 25, 25, 25);
	gfx.PutPixel(20 + x, 20 + y, 25, 25, 25);
	gfx.PutPixel(21 + x, 20 + y, 51, 51, 51);
	gfx.PutPixel(22 + x, 20 + y, 12, 12, 12);
	gfx.PutPixel(23 + x, 20 + y, 51, 51, 51);
	gfx.PutPixel(24 + x, 20 + y, 51, 51, 51);
	gfx.PutPixel(25 + x, 20 + y, 51, 51, 51);
	gfx.PutPixel(26 + x, 20 + y, 51, 51, 51);
	gfx.PutPixel(27 + x, 20 + y, 51, 51, 51);
	gfx.PutPixel(28 + x, 20 + y, 12, 12, 12);
	gfx.PutPixel(29 + x, 20 + y, 38, 38, 38);
	gfx.PutPixel(30 + x, 20 + y, 51, 51, 51);
	gfx.PutPixel(31 + x, 20 + y, 51, 51, 51);
	gfx.PutPixel(32 + x, 20 + y, 51, 51, 51);
	gfx.PutPixel(33 + x, 20 + y, 38, 38, 38);
	gfx.PutPixel(35 + x, 20 + y, 51, 51, 51);
	gfx.PutPixel(36 + x, 20 + y, 51, 51, 51);
	gfx.PutPixel(37 + x, 20 + y, 51, 51, 51);
	gfx.PutPixel(38 + x, 20 + y, 38, 38, 38);
	gfx.PutPixel(41 + x, 20 + y, 78, 78, 78);
	gfx.PutPixel(42 + x, 20 + y, 255, 255, 255);
	gfx.PutPixel(43 + x, 20 + y, 107, 107, 107);
	gfx.PutPixel(44 + x, 20 + y, 174, 174, 174);
	gfx.PutPixel(6 + x, 21 + y, 174, 174, 174);
	gfx.PutPixel(7 + x, 21 + y, 64, 64, 64);
	gfx.PutPixel(8 + x, 21 + y, 255, 255, 255);
	gfx.PutPixel(9 + x, 21 + y, 51, 51, 51);
	gfx.PutPixel(10 + x, 21 + y, 51, 51, 51);
	gfx.PutPixel(11 + x, 21 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 21 + y, 195, 195, 195);
	gfx.PutPixel(13 + x, 21 + y, 174, 174, 174);
	gfx.PutPixel(14 + x, 21 + y, 174, 174, 174);
	gfx.PutPixel(15 + x, 21 + y, 38, 38, 38);
	gfx.PutPixel(16 + x, 21 + y, 107, 107, 107);
	gfx.PutPixel(17 + x, 21 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 21 + y, 174, 174, 174);
	gfx.PutPixel(20 + x, 21 + y, 107, 107, 107);
	gfx.PutPixel(21 + x, 21 + y, 255, 255, 255);
	gfx.PutPixel(22 + x, 21 + y, 38, 38, 38);
	gfx.PutPixel(23 + x, 21 + y, 174, 174, 174);
	gfx.PutPixel(24 + x, 21 + y, 195, 195, 195);
	gfx.PutPixel(25 + x, 21 + y, 255, 255, 255);
	gfx.PutPixel(26 + x, 21 + y, 195, 195, 195);
	gfx.PutPixel(27 + x, 21 + y, 174, 174, 174);
	gfx.PutPixel(28 + x, 21 + y, 38, 38, 38);
	gfx.PutPixel(29 + x, 21 + y, 174, 174, 174);
	gfx.PutPixel(30 + x, 21 + y, 255, 255, 255);
	gfx.PutPixel(31 + x, 21 + y, 174, 174, 174);
	gfx.PutPixel(32 + x, 21 + y, 174, 174, 174);
	gfx.PutPixel(33 + x, 21 + y, 122, 122, 122);
	gfx.PutPixel(35 + x, 21 + y, 255, 255, 255);
	gfx.PutPixel(36 + x, 21 + y, 218, 218, 218);
	gfx.PutPixel(37 + x, 21 + y, 174, 174, 174);
	gfx.PutPixel(38 + x, 21 + y, 255, 255, 255);
	gfx.PutPixel(39 + x, 21 + y, 156, 156, 156);
	gfx.PutPixel(41 + x, 21 + y, 51, 51, 51);
	gfx.PutPixel(42 + x, 21 + y, 195, 195, 195);
	gfx.PutPixel(43 + x, 21 + y, 92, 92, 92);
	gfx.PutPixel(44 + x, 21 + y, 174, 174, 174);
	gfx.PutPixel(6 + x, 22 + y, 122, 122, 122);
	gfx.PutPixel(7 + x, 22 + y, 38, 38, 38);
	gfx.PutPixel(8 + x, 22 + y, 122, 122, 122);
	gfx.PutPixel(9 + x, 22 + y, 25, 25, 25);
	gfx.PutPixel(10 + x, 22 + y, 51, 51, 51);
	gfx.PutPixel(11 + x, 22 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 22 + y, 51, 51, 51);
	gfx.PutPixel(16 + x, 22 + y, 107, 107, 107);
	gfx.PutPixel(17 + x, 22 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 22 + y, 195, 195, 195);
	gfx.PutPixel(19 + x, 22 + y, 25, 25, 25);
	gfx.PutPixel(20 + x, 22 + y, 107, 107, 107);
	gfx.PutPixel(21 + x, 22 + y, 255, 255, 255);
	gfx.PutPixel(24 + x, 22 + y, 51, 51, 51);
	gfx.PutPixel(25 + x, 22 + y, 255, 255, 255);
	gfx.PutPixel(26 + x, 22 + y, 51, 51, 51);
	gfx.PutPixel(29 + x, 22 + y, 174, 174, 174);
	gfx.PutPixel(30 + x, 22 + y, 174, 174, 174);
	gfx.PutPixel(35 + x, 22 + y, 255, 255, 255);
	gfx.PutPixel(36 + x, 22 + y, 107, 107, 107);
	gfx.PutPixel(38 + x, 22 + y, 174, 174, 174);
	gfx.PutPixel(39 + x, 22 + y, 255, 255, 255);
	gfx.PutPixel(41 + x, 22 + y, 38, 38, 38);
	gfx.PutPixel(42 + x, 22 + y, 122, 122, 122);
	gfx.PutPixel(43 + x, 22 + y, 38, 38, 38);
	gfx.PutPixel(44 + x, 22 + y, 107, 107, 107);
	gfx.PutPixel(10 + x, 23 + y, 51, 51, 51);
	gfx.PutPixel(11 + x, 23 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 23 + y, 92, 92, 92);
	gfx.PutPixel(13 + x, 23 + y, 51, 51, 51);
	gfx.PutPixel(14 + x, 23 + y, 51, 51, 51);
	gfx.PutPixel(16 + x, 23 + y, 107, 107, 107);
	gfx.PutPixel(17 + x, 23 + y, 255, 255, 255);
	gfx.PutPixel(18 + x, 23 + y, 78, 78, 78);
	gfx.PutPixel(19 + x, 23 + y, 122, 122, 122);
	gfx.PutPixel(20 + x, 23 + y, 107, 107, 107);
	gfx.PutPixel(21 + x, 23 + y, 255, 255, 255);
	gfx.PutPixel(24 + x, 23 + y, 51, 51, 51);
	gfx.PutPixel(25 + x, 23 + y, 255, 255, 255);
	gfx.PutPixel(26 + x, 23 + y, 51, 51, 51);
	gfx.PutPixel(29 + x, 23 + y, 174, 174, 174);
	gfx.PutPixel(30 + x, 23 + y, 195, 195, 195);
	gfx.PutPixel(31 + x, 23 + y, 51, 51, 51);
	gfx.PutPixel(32 + x, 23 + y, 51, 51, 51);
	gfx.PutPixel(33 + x, 23 + y, 25, 25, 25);
	gfx.PutPixel(35 + x, 23 + y, 255, 255, 255);
	gfx.PutPixel(36 + x, 23 + y, 139, 139, 139);
	gfx.PutPixel(37 + x, 23 + y, 51, 51, 51);
	gfx.PutPixel(38 + x, 23 + y, 218, 218, 218);
	gfx.PutPixel(39 + x, 23 + y, 195, 195, 195);
	gfx.PutPixel(10 + x, 24 + y, 51, 51, 51);
	gfx.PutPixel(11 + x, 24 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 24 + y, 195, 195, 195);
	gfx.PutPixel(13 + x, 24 + y, 174, 174, 174);
	gfx.PutPixel(14 + x, 24 + y, 174, 174, 174);
	gfx.PutPixel(16 + x, 24 + y, 107, 107, 107);
	gfx.PutPixel(17 + x, 24 + y, 255, 255, 255);
	gfx.PutPixel(19 + x, 24 + y, 218, 218, 218);
	gfx.PutPixel(20 + x, 24 + y, 122, 122, 122);
	gfx.PutPixel(21 + x, 24 + y, 255, 255, 255);
	gfx.PutPixel(24 + x, 24 + y, 51, 51, 51);
	gfx.PutPixel(25 + x, 24 + y, 255, 255, 255);
	gfx.PutPixel(26 + x, 24 + y, 51, 51, 51);
	gfx.PutPixel(29 + x, 24 + y, 174, 174, 174);
	gfx.PutPixel(30 + x, 24 + y, 255, 255, 255);
	gfx.PutPixel(31 + x, 24 + y, 174, 174, 174);
	gfx.PutPixel(32 + x, 24 + y, 174, 174, 174);
	gfx.PutPixel(33 + x, 24 + y, 78, 78, 78);
	gfx.PutPixel(35 + x, 24 + y, 255, 255, 255);
	gfx.PutPixel(36 + x, 24 + y, 218, 218, 218);
	gfx.PutPixel(37 + x, 24 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 24 + y, 255, 255, 255);
	gfx.PutPixel(39 + x, 24 + y, 12, 12, 12);
	gfx.PutPixel(10 + x, 25 + y, 51, 51, 51);
	gfx.PutPixel(11 + x, 25 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 25 + y, 51, 51, 51);
	gfx.PutPixel(16 + x, 25 + y, 107, 107, 107);
	gfx.PutPixel(17 + x, 25 + y, 255, 255, 255);
	gfx.PutPixel(19 + x, 25 + y, 107, 107, 107);
	gfx.PutPixel(20 + x, 25 + y, 218, 218, 218);
	gfx.PutPixel(21 + x, 25 + y, 255, 255, 255);
	gfx.PutPixel(24 + x, 25 + y, 51, 51, 51);
	gfx.PutPixel(25 + x, 25 + y, 255, 255, 255);
	gfx.PutPixel(26 + x, 25 + y, 51, 51, 51);
	gfx.PutPixel(29 + x, 25 + y, 174, 174, 174);
	gfx.PutPixel(30 + x, 25 + y, 174, 174, 174);
	gfx.PutPixel(35 + x, 25 + y, 255, 255, 255);
	gfx.PutPixel(36 + x, 25 + y, 107, 107, 107);
	gfx.PutPixel(37 + x, 25 + y, 51, 51, 51);
	gfx.PutPixel(38 + x, 25 + y, 255, 255, 255);
	gfx.PutPixel(39 + x, 25 + y, 107, 107, 107);
	gfx.PutPixel(10 + x, 26 + y, 51, 51, 51);
	gfx.PutPixel(11 + x, 26 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 26 + y, 92, 92, 92);
	gfx.PutPixel(13 + x, 26 + y, 51, 51, 51);
	gfx.PutPixel(14 + x, 26 + y, 51, 51, 51);
	gfx.PutPixel(15 + x, 26 + y, 12, 12, 12);
	gfx.PutPixel(16 + x, 26 + y, 107, 107, 107);
	gfx.PutPixel(17 + x, 26 + y, 255, 255, 255);
	gfx.PutPixel(19 + x, 26 + y, 25, 25, 25);
	gfx.PutPixel(20 + x, 26 + y, 255, 255, 255);
	gfx.PutPixel(21 + x, 26 + y, 255, 255, 255);
	gfx.PutPixel(24 + x, 26 + y, 51, 51, 51);
	gfx.PutPixel(25 + x, 26 + y, 255, 255, 255);
	gfx.PutPixel(26 + x, 26 + y, 51, 51, 51);
	gfx.PutPixel(29 + x, 26 + y, 174, 174, 174);
	gfx.PutPixel(30 + x, 26 + y, 195, 195, 195);
	gfx.PutPixel(31 + x, 26 + y, 51, 51, 51);
	gfx.PutPixel(32 + x, 26 + y, 51, 51, 51);
	gfx.PutPixel(33 + x, 26 + y, 38, 38, 38);
	gfx.PutPixel(35 + x, 26 + y, 255, 255, 255);
	gfx.PutPixel(36 + x, 26 + y, 107, 107, 107);
	gfx.PutPixel(38 + x, 26 + y, 156, 156, 156);
	gfx.PutPixel(39 + x, 26 + y, 255, 255, 255);
	gfx.PutPixel(40 + x, 26 + y, 38, 38, 38);
	gfx.PutPixel(10 + x, 27 + y, 38, 38, 38);
	gfx.PutPixel(11 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(12 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(13 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(14 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(15 + x, 27 + y, 38, 38, 38);
	gfx.PutPixel(16 + x, 27 + y, 78, 78, 78);
	gfx.PutPixel(17 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(20 + x, 27 + y, 122, 122, 122);
	gfx.PutPixel(21 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(24 + x, 27 + y, 38, 38, 38);
	gfx.PutPixel(25 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(26 + x, 27 + y, 38, 38, 38);
	gfx.PutPixel(29 + x, 27 + y, 122, 122, 122);
	gfx.PutPixel(30 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(31 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(32 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(33 + x, 27 + y, 122, 122, 122);
	gfx.PutPixel(35 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(36 + x, 27 + y, 78, 78, 78);
	gfx.PutPixel(38 + x, 27 + y, 12, 12, 12);
	gfx.PutPixel(39 + x, 27 + y, 174, 174, 174);
	gfx.PutPixel(40 + x, 27 + y, 122, 122, 122);
	gfx.PutPixel(49 + x, 27 + y, 1, 1, 1);
	gfx.PutPixel(48 + x, 28 + y, 1, 1, 1);
	gfx.PutPixel(49 + x, 28 + y, 3, 3, 3);
	gfx.PutPixel(49 + x, 29 + y, 1, 1, 1);
	gfx.PutPixel(2 + x, 31 + y, 25, 25, 25);
	gfx.PutPixel(3 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(4 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(5 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(6 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(7 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(10 + x, 31 + y, 12, 12, 12);
	gfx.PutPixel(11 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(12 + x, 31 + y, 38, 38, 38);
	gfx.PutPixel(20 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(21 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(22 + x, 31 + y, 12, 12, 12);
	gfx.PutPixel(24 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(25 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(26 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(27 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(28 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(29 + x, 31 + y, 25, 25, 25);
	gfx.PutPixel(31 + x, 31 + y, 12, 12, 12);
	gfx.PutPixel(32 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(33 + x, 31 + y, 25, 25, 25);
	gfx.PutPixel(36 + x, 31 + y, 12, 12, 12);
	gfx.PutPixel(37 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(38 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(39 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(40 + x, 31 + y, 25, 25, 25);
	gfx.PutPixel(42 + x, 31 + y, 12, 12, 12);
	gfx.PutPixel(43 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(44 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(45 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(46 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(47 + x, 31 + y, 51, 51, 51);
	gfx.PutPixel(48 + x, 31 + y, 12, 12, 12);
	gfx.PutPixel(2 + x, 32 + y, 78, 78, 78);
	gfx.PutPixel(3 + x, 32 + y, 174, 174, 174);
	gfx.PutPixel(4 + x, 32 + y, 218, 218, 218);
	gfx.PutPixel(5 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(6 + x, 32 + y, 174, 174, 174);
	gfx.PutPixel(7 + x, 32 + y, 174, 174, 174);
	gfx.PutPixel(9 + x, 32 + y, 78, 78, 78);
	gfx.PutPixel(10 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(11 + x, 32 + y, 195, 195, 195);
	gfx.PutPixel(12 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 32 + y, 174, 174, 174);
	gfx.PutPixel(14 + x, 32 + y, 12, 12, 12);
	gfx.PutPixel(18 + x, 32 + y, 25, 25, 25);
	gfx.PutPixel(19 + x, 32 + y, 218, 218, 218);
	gfx.PutPixel(20 + x, 32 + y, 218, 218, 218);
	gfx.PutPixel(21 + x, 32 + y, 174, 174, 174);
	gfx.PutPixel(22 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(23 + x, 32 + y, 38, 38, 38);
	gfx.PutPixel(24 + x, 32 + y, 174, 174, 174);
	gfx.PutPixel(25 + x, 32 + y, 174, 174, 174);
	gfx.PutPixel(26 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 32 + y, 218, 218, 218);
	gfx.PutPixel(28 + x, 32 + y, 174, 174, 174);
	gfx.PutPixel(29 + x, 32 + y, 78, 78, 78);
	gfx.PutPixel(31 + x, 32 + y, 122, 122, 122);
	gfx.PutPixel(32 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(33 + x, 32 + y, 156, 156, 156);
	gfx.PutPixel(36 + x, 32 + y, 51, 51, 51);
	gfx.PutPixel(37 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 32 + y, 195, 195, 195);
	gfx.PutPixel(39 + x, 32 + y, 195, 195, 195);
	gfx.PutPixel(40 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(41 + x, 32 + y, 92, 92, 92);
	gfx.PutPixel(42 + x, 32 + y, 38, 38, 38);
	gfx.PutPixel(43 + x, 32 + y, 174, 174, 174);
	gfx.PutPixel(44 + x, 32 + y, 195, 195, 195);
	gfx.PutPixel(45 + x, 32 + y, 255, 255, 255);
	gfx.PutPixel(46 + x, 32 + y, 195, 195, 195);
	gfx.PutPixel(47 + x, 32 + y, 174, 174, 174);
	gfx.PutPixel(48 + x, 32 + y, 38, 38, 38);
	gfx.PutPixel(4 + x, 33 + y, 107, 107, 107);
	gfx.PutPixel(5 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(8 + x, 33 + y, 25, 25, 25);
	gfx.PutPixel(9 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(10 + x, 33 + y, 139, 139, 139);
	gfx.PutPixel(12 + x, 33 + y, 38, 38, 38);
	gfx.PutPixel(13 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(14 + x, 33 + y, 107, 107, 107);
	gfx.PutPixel(18 + x, 33 + y, 122, 122, 122);
	gfx.PutPixel(19 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(20 + x, 33 + y, 12, 12, 12);
	gfx.PutPixel(22 + x, 33 + y, 38, 38, 38);
	gfx.PutPixel(23 + x, 33 + y, 38, 38, 38);
	gfx.PutPixel(26 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 33 + y, 107, 107, 107);
	gfx.PutPixel(31 + x, 33 + y, 218, 218, 218);
	gfx.PutPixel(32 + x, 33 + y, 218, 218, 218);
	gfx.PutPixel(33 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(34 + x, 33 + y, 12, 12, 12);
	gfx.PutPixel(36 + x, 33 + y, 51, 51, 51);
	gfx.PutPixel(37 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 33 + y, 51, 51, 51);
	gfx.PutPixel(40 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(41 + x, 33 + y, 174, 174, 174);
	gfx.PutPixel(44 + x, 33 + y, 51, 51, 51);
	gfx.PutPixel(45 + x, 33 + y, 255, 255, 255);
	gfx.PutPixel(46 + x, 33 + y, 51, 51, 51);
	gfx.PutPixel(4 + x, 34 + y, 107, 107, 107);
	gfx.PutPixel(5 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(8 + x, 34 + y, 78, 78, 78);
	gfx.PutPixel(9 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(10 + x, 34 + y, 51, 51, 51);
	gfx.PutPixel(13 + x, 34 + y, 195, 195, 195);
	gfx.PutPixel(14 + x, 34 + y, 174, 174, 174);
	gfx.PutPixel(18 + x, 34 + y, 107, 107, 107);
	gfx.PutPixel(19 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(20 + x, 34 + y, 195, 195, 195);
	gfx.PutPixel(21 + x, 34 + y, 107, 107, 107);
	gfx.PutPixel(22 + x, 34 + y, 25, 25, 25);
	gfx.PutPixel(26 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 34 + y, 107, 107, 107);
	gfx.PutPixel(30 + x, 34 + y, 38, 38, 38);
	gfx.PutPixel(31 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(32 + x, 34 + y, 78, 78, 78);
	gfx.PutPixel(33 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(34 + x, 34 + y, 78, 78, 78);
	gfx.PutPixel(36 + x, 34 + y, 51, 51, 51);
	gfx.PutPixel(37 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 34 + y, 92, 92, 92);
	gfx.PutPixel(39 + x, 34 + y, 64, 64, 64);
	gfx.PutPixel(40 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(41 + x, 34 + y, 122, 122, 122);
	gfx.PutPixel(44 + x, 34 + y, 51, 51, 51);
	gfx.PutPixel(45 + x, 34 + y, 255, 255, 255);
	gfx.PutPixel(46 + x, 34 + y, 51, 51, 51);
	gfx.PutPixel(4 + x, 35 + y, 107, 107, 107);
	gfx.PutPixel(5 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(8 + x, 35 + y, 107, 107, 107);
	gfx.PutPixel(9 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(10 + x, 35 + y, 51, 51, 51);
	gfx.PutPixel(13 + x, 35 + y, 174, 174, 174);
	gfx.PutPixel(14 + x, 35 + y, 174, 174, 174);
	gfx.PutPixel(18 + x, 35 + y, 12, 12, 12);
	gfx.PutPixel(19 + x, 35 + y, 139, 139, 139);
	gfx.PutPixel(20 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(21 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(22 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(23 + x, 35 + y, 51, 51, 51);
	gfx.PutPixel(26 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 35 + y, 107, 107, 107);
	gfx.PutPixel(30 + x, 35 + y, 122, 122, 122);
	gfx.PutPixel(31 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(32 + x, 35 + y, 51, 51, 51);
	gfx.PutPixel(33 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(34 + x, 35 + y, 156, 156, 156);
	gfx.PutPixel(36 + x, 35 + y, 51, 51, 51);
	gfx.PutPixel(37 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 35 + y, 195, 195, 195);
	gfx.PutPixel(39 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(40 + x, 35 + y, 195, 195, 195);
	gfx.PutPixel(44 + x, 35 + y, 51, 51, 51);
	gfx.PutPixel(45 + x, 35 + y, 255, 255, 255);
	gfx.PutPixel(46 + x, 35 + y, 51, 51, 51);
	gfx.PutPixel(4 + x, 36 + y, 107, 107, 107);
	gfx.PutPixel(5 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(8 + x, 36 + y, 51, 51, 51);
	gfx.PutPixel(9 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(10 + x, 36 + y, 78, 78, 78);
	gfx.PutPixel(13 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(14 + x, 36 + y, 156, 156, 156);
	gfx.PutPixel(18 + x, 36 + y, 25, 25, 25);
	gfx.PutPixel(21 + x, 36 + y, 107, 107, 107);
	gfx.PutPixel(22 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(23 + x, 36 + y, 107, 107, 107);
	gfx.PutPixel(26 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 36 + y, 107, 107, 107);
	gfx.PutPixel(30 + x, 36 + y, 218, 218, 218);
	gfx.PutPixel(31 + x, 36 + y, 218, 218, 218);
	gfx.PutPixel(32 + x, 36 + y, 174, 174, 174);
	gfx.PutPixel(33 + x, 36 + y, 218, 218, 218);
	gfx.PutPixel(34 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(35 + x, 36 + y, 12, 12, 12);
	gfx.PutPixel(36 + x, 36 + y, 51, 51, 51);
	gfx.PutPixel(37 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 36 + y, 51, 51, 51);
	gfx.PutPixel(39 + x, 36 + y, 107, 107, 107);
	gfx.PutPixel(40 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(41 + x, 36 + y, 51, 51, 51);
	gfx.PutPixel(44 + x, 36 + y, 51, 51, 51);
	gfx.PutPixel(45 + x, 36 + y, 255, 255, 255);
	gfx.PutPixel(46 + x, 36 + y, 51, 51, 51);
	gfx.PutPixel(4 + x, 37 + y, 107, 107, 107);
	gfx.PutPixel(5 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(9 + x, 37 + y, 195, 195, 195);
	gfx.PutPixel(10 + x, 37 + y, 218, 218, 218);
	gfx.PutPixel(11 + x, 37 + y, 64, 64, 64);
	gfx.PutPixel(12 + x, 37 + y, 139, 139, 139);
	gfx.PutPixel(13 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(14 + x, 37 + y, 51, 51, 51);
	gfx.PutPixel(18 + x, 37 + y, 174, 174, 174);
	gfx.PutPixel(19 + x, 37 + y, 122, 122, 122);
	gfx.PutPixel(20 + x, 37 + y, 51, 51, 51);
	gfx.PutPixel(21 + x, 37 + y, 122, 122, 122);
	gfx.PutPixel(22 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(23 + x, 37 + y, 51, 51, 51);
	gfx.PutPixel(26 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(27 + x, 37 + y, 107, 107, 107);
	gfx.PutPixel(29 + x, 37 + y, 25, 25, 25);
	gfx.PutPixel(30 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(31 + x, 37 + y, 92, 92, 92);
	gfx.PutPixel(33 + x, 37 + y, 64, 64, 64);
	gfx.PutPixel(34 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(35 + x, 37 + y, 78, 78, 78);
	gfx.PutPixel(36 + x, 37 + y, 51, 51, 51);
	gfx.PutPixel(37 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(38 + x, 37 + y, 51, 51, 51);
	gfx.PutPixel(39 + x, 37 + y, 12, 12, 12);
	gfx.PutPixel(40 + x, 37 + y, 218, 218, 218);
	gfx.PutPixel(41 + x, 37 + y, 218, 218, 218);
	gfx.PutPixel(42 + x, 37 + y, 12, 12, 12);
	gfx.PutPixel(44 + x, 37 + y, 51, 51, 51);
	gfx.PutPixel(45 + x, 37 + y, 255, 255, 255);
	gfx.PutPixel(46 + x, 37 + y, 51, 51, 51);
	gfx.PutPixel(4 + x, 38 + y, 78, 78, 78);
	gfx.PutPixel(5 + x, 38 + y, 174, 174, 174);
	gfx.PutPixel(9 + x, 38 + y, 12, 12, 12);
	gfx.PutPixel(10 + x, 38 + y, 122, 122, 122);
	gfx.PutPixel(11 + x, 38 + y, 174, 174, 174);
	gfx.PutPixel(12 + x, 38 + y, 156, 156, 156);
	gfx.PutPixel(13 + x, 38 + y, 51, 51, 51);
	gfx.PutPixel(18 + x, 38 + y, 51, 51, 51);
	gfx.PutPixel(19 + x, 38 + y, 139, 139, 139);
	gfx.PutPixel(20 + x, 38 + y, 174, 174, 174);
	gfx.PutPixel(21 + x, 38 + y, 156, 156, 156);
	gfx.PutPixel(22 + x, 38 + y, 64, 64, 64);
	gfx.PutPixel(26 + x, 38 + y, 174, 174, 174);
	gfx.PutPixel(27 + x, 38 + y, 78, 78, 78);
	gfx.PutPixel(29 + x, 38 + y, 64, 64, 64);
	gfx.PutPixel(30 + x, 38 + y, 174, 174, 174);
	gfx.PutPixel(31 + x, 38 + y, 25, 25, 25);
	gfx.PutPixel(33 + x, 38 + y, 12, 12, 12);
	gfx.PutPixel(34 + x, 38 + y, 174, 174, 174);
	gfx.PutPixel(35 + x, 38 + y, 107, 107, 107);
	gfx.PutPixel(36 + x, 38 + y, 38, 38, 38);
	gfx.PutPixel(37 + x, 38 + y, 174, 174, 174);
	gfx.PutPixel(38 + x, 38 + y, 38, 38, 38);
	gfx.PutPixel(40 + x, 38 + y, 51, 51, 51);
	gfx.PutPixel(41 + x, 38 + y, 174, 174, 174);
	gfx.PutPixel(42 + x, 38 + y, 78, 78, 78);
	gfx.PutPixel(44 + x, 38 + y, 38, 38, 38);
	gfx.PutPixel(45 + x, 38 + y, 174, 174, 174);
	gfx.PutPixel(46 + x, 38 + y, 38, 38, 38);

}
void Game::DrawTargetCounterLimits()
{
	for (int x = 6; x < 10; ++x)
	{
		for (int y = 10; y < 20; ++y)
		{
			gfx.PutPixel(x, y, 0, 255, 0);
		}
	}
	for (int x = 790; x < 794; ++x)
	{
		for (int y = 10; y < 20; ++y)
		{
			gfx.PutPixel(x, y, 0, 255, 0);
		}
	}
}

void Game::ComposeFrame()
{
	// Drawing game objects
	dude.Draw(gfx);
	target.Draw(gfx);
	target.targetCounter(gfx);
	for (int i = 0; i < pooIndex; ++i)
	{
		assert(poos[i].initialized == true);
		if (!poos[i].GetIsEaten())
		{
			poos[i].Draw(gfx);
		}
	}

	for (int i = 0; i < pooIndex; ++i)
	{
		// Checking if the dude is dead or all the targets are consumed
		if ((poos[i].GetIsEaten()) || (target.GetCounterLength() >= 790))
		{
			// Drawing end screen
			DrawGameOver(375, 275);
			dude.IsFinished();
		}
	}




}