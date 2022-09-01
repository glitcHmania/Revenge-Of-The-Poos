#include "Dude.h"
#include <math.h>


Dude::Dude(Vector2D& in_pos, float in_v)
{
	pos = in_pos;
	v = in_v;
}

void Dude::Update(const Keyboard& kbd, float deltaTime)
{
	if (isNotFinished)
	{
		if (kbd.KeyIsPressed(VK_RIGHT))
		{
			pos.x += v * deltaTime;
		}
		if (kbd.KeyIsPressed(VK_LEFT))
		{
			pos.x -= v * deltaTime;
		}
		if (kbd.KeyIsPressed(VK_UP))
		{
			pos.y -= v * deltaTime;
		}
		if (kbd.KeyIsPressed(VK_DOWN))
		{
			pos.y += v * deltaTime;
		}
	}
}

void Dude::Draw(Graphics& gfx)
{
	int x_int = int(pos.x);
	int y_int = int(pos.y);
	gfx.PutPixel(7 + x_int, 0 + y_int, 0, 0, 0);
	gfx.PutPixel(8 + x_int, 0 + y_int, 0, 0, 0);
	gfx.PutPixel(9 + x_int, 0 + y_int, 0, 0, 0);
	gfx.PutPixel(10 + x_int, 0 + y_int, 0, 0, 0);
	gfx.PutPixel(11 + x_int, 0 + y_int, 0, 0, 0);
	gfx.PutPixel(12 + x_int, 0 + y_int, 0, 0, 0);
	gfx.PutPixel(5 + x_int, 1 + y_int, 0, 0, 0);
	gfx.PutPixel(6 + x_int, 1 + y_int, 0, 0, 0);
	gfx.PutPixel(7 + x_int, 1 + y_int, 254, 221, 88);
	gfx.PutPixel(8 + x_int, 1 + y_int, 254, 221, 88);
	gfx.PutPixel(9 + x_int, 1 + y_int, 254, 221, 88);
	gfx.PutPixel(10 + x_int, 1 + y_int, 254, 221, 88);
	gfx.PutPixel(11 + x_int, 1 + y_int, 254, 221, 88);
	gfx.PutPixel(12 + x_int, 1 + y_int, 254, 221, 88);
	gfx.PutPixel(13 + x_int, 1 + y_int, 0, 0, 0);
	gfx.PutPixel(14 + x_int, 1 + y_int, 0, 0, 0);
	gfx.PutPixel(3 + x_int, 2 + y_int, 0, 0, 0);
	gfx.PutPixel(4 + x_int, 2 + y_int, 0, 0, 0);
	gfx.PutPixel(5 + x_int, 2 + y_int, 254, 221, 88);
	gfx.PutPixel(6 + x_int, 2 + y_int, 254, 221, 88);
	gfx.PutPixel(7 + x_int, 2 + y_int, 254, 221, 88);
	gfx.PutPixel(8 + x_int, 2 + y_int, 254, 221, 88);
	gfx.PutPixel(9 + x_int, 2 + y_int, 254, 221, 88);
	gfx.PutPixel(10 + x_int, 2 + y_int, 254, 221, 88);
	gfx.PutPixel(11 + x_int, 2 + y_int, 254, 221, 88);
	gfx.PutPixel(12 + x_int, 2 + y_int, 254, 221, 88);
	gfx.PutPixel(13 + x_int, 2 + y_int, 254, 221, 88);
	gfx.PutPixel(14 + x_int, 2 + y_int, 254, 221, 88);
	gfx.PutPixel(15 + x_int, 2 + y_int, 0, 0, 0);
	gfx.PutPixel(16 + x_int, 2 + y_int, 0, 0, 0);
	gfx.PutPixel(2 + x_int, 3 + y_int, 0, 0, 0);
	gfx.PutPixel(3 + x_int, 3 + y_int, 254, 221, 88);
	gfx.PutPixel(4 + x_int, 3 + y_int, 254, 221, 88);
	gfx.PutPixel(5 + x_int, 3 + y_int, 254, 221, 88);
	gfx.PutPixel(6 + x_int, 3 + y_int, 254, 221, 88);
	gfx.PutPixel(7 + x_int, 3 + y_int, 254, 221, 88);
	gfx.PutPixel(8 + x_int, 3 + y_int, 254, 221, 88);
	gfx.PutPixel(9 + x_int, 3 + y_int, 254, 221, 88);
	gfx.PutPixel(10 + x_int, 3 + y_int, 254, 221, 88);
	gfx.PutPixel(11 + x_int, 3 + y_int, 254, 221, 88);
	gfx.PutPixel(12 + x_int, 3 + y_int, 254, 221, 88);
	gfx.PutPixel(13 + x_int, 3 + y_int, 254, 221, 88);
	gfx.PutPixel(14 + x_int, 3 + y_int, 254, 221, 88);
	gfx.PutPixel(15 + x_int, 3 + y_int, 254, 221, 88);
	gfx.PutPixel(16 + x_int, 3 + y_int, 254, 221, 88);
	gfx.PutPixel(17 + x_int, 3 + y_int, 0, 0, 0);
	gfx.PutPixel(2 + x_int, 4 + y_int, 0, 0, 0);
	gfx.PutPixel(3 + x_int, 4 + y_int, 254, 221, 88);
	gfx.PutPixel(4 + x_int, 4 + y_int, 254, 221, 88);
	gfx.PutPixel(5 + x_int, 4 + y_int, 254, 221, 88);
	gfx.PutPixel(6 + x_int, 4 + y_int, 254, 221, 88);
	gfx.PutPixel(7 + x_int, 4 + y_int, 254, 221, 88);
	gfx.PutPixel(8 + x_int, 4 + y_int, 254, 221, 88);
	gfx.PutPixel(9 + x_int, 4 + y_int, 254, 221, 88);
	gfx.PutPixel(10 + x_int, 4 + y_int, 254, 221, 88);
	gfx.PutPixel(11 + x_int, 4 + y_int, 254, 221, 88);
	gfx.PutPixel(12 + x_int, 4 + y_int, 254, 221, 88);
	gfx.PutPixel(13 + x_int, 4 + y_int, 254, 221, 88);
	gfx.PutPixel(14 + x_int, 4 + y_int, 254, 221, 88);
	gfx.PutPixel(15 + x_int, 4 + y_int, 254, 221, 88);
	gfx.PutPixel(16 + x_int, 4 + y_int, 254, 221, 88);
	gfx.PutPixel(17 + x_int, 4 + y_int, 0, 0, 0);
	gfx.PutPixel(1 + x_int, 5 + y_int, 0, 0, 0);
	gfx.PutPixel(2 + x_int, 5 + y_int, 254, 221, 88);
	gfx.PutPixel(3 + x_int, 5 + y_int, 0, 0, 0);
	gfx.PutPixel(4 + x_int, 5 + y_int, 0, 0, 0);
	gfx.PutPixel(5 + x_int, 5 + y_int, 254, 221, 88);
	gfx.PutPixel(6 + x_int, 5 + y_int, 254, 221, 88);
	gfx.PutPixel(7 + x_int, 5 + y_int, 254, 221, 88);
	gfx.PutPixel(8 + x_int, 5 + y_int, 254, 221, 88);
	gfx.PutPixel(9 + x_int, 5 + y_int, 254, 221, 88);
	gfx.PutPixel(10 + x_int, 5 + y_int, 254, 221, 88);
	gfx.PutPixel(11 + x_int, 5 + y_int, 0, 0, 0);
	gfx.PutPixel(12 + x_int, 5 + y_int, 0, 0, 0);
	gfx.PutPixel(13 + x_int, 5 + y_int, 0, 0, 0);
	gfx.PutPixel(14 + x_int, 5 + y_int, 0, 0, 0);
	gfx.PutPixel(15 + x_int, 5 + y_int, 254, 221, 88);
	gfx.PutPixel(16 + x_int, 5 + y_int, 254, 221, 88);
	gfx.PutPixel(17 + x_int, 5 + y_int, 254, 221, 88);
	gfx.PutPixel(18 + x_int, 5 + y_int, 0, 0, 0);
	gfx.PutPixel(1 + x_int, 6 + y_int, 0, 0, 0);
	gfx.PutPixel(2 + x_int, 6 + y_int, 0, 0, 0);
	gfx.PutPixel(3 + x_int, 6 + y_int, 255, 255, 255);
	gfx.PutPixel(4 + x_int, 6 + y_int, 0, 0, 0);
	gfx.PutPixel(5 + x_int, 6 + y_int, 0, 0, 0);
	gfx.PutPixel(6 + x_int, 6 + y_int, 254, 221, 88);
	gfx.PutPixel(7 + x_int, 6 + y_int, 254, 221, 88);
	gfx.PutPixel(8 + x_int, 6 + y_int, 254, 221, 88);
	gfx.PutPixel(9 + x_int, 6 + y_int, 254, 221, 88);
	gfx.PutPixel(10 + x_int, 6 + y_int, 0, 0, 0);
	gfx.PutPixel(11 + x_int, 6 + y_int, 255, 255, 255);
	gfx.PutPixel(12 + x_int, 6 + y_int, 255, 255, 255);
	gfx.PutPixel(13 + x_int, 6 + y_int, 0, 0, 0);
	gfx.PutPixel(14 + x_int, 6 + y_int, 0, 0, 0);
	gfx.PutPixel(15 + x_int, 6 + y_int, 0, 0, 0);
	gfx.PutPixel(16 + x_int, 6 + y_int, 254, 221, 88);
	gfx.PutPixel(17 + x_int, 6 + y_int, 254, 221, 88);
	gfx.PutPixel(18 + x_int, 6 + y_int, 0, 0, 0);
	gfx.PutPixel(0 + x_int, 7 + y_int, 0, 0, 0);
	gfx.PutPixel(1 + x_int, 7 + y_int, 0, 0, 0);
	gfx.PutPixel(2 + x_int, 7 + y_int, 255, 255, 255);
	gfx.PutPixel(3 + x_int, 7 + y_int, 255, 255, 255);
	gfx.PutPixel(4 + x_int, 7 + y_int, 0, 0, 0);
	gfx.PutPixel(5 + x_int, 7 + y_int, 0, 0, 0);
	gfx.PutPixel(6 + x_int, 7 + y_int, 254, 221, 88);
	gfx.PutPixel(7 + x_int, 7 + y_int, 254, 221, 88);
	gfx.PutPixel(8 + x_int, 7 + y_int, 254, 221, 88);
	gfx.PutPixel(9 + x_int, 7 + y_int, 254, 221, 88);
	gfx.PutPixel(10 + x_int, 7 + y_int, 0, 0, 0);
	gfx.PutPixel(11 + x_int, 7 + y_int, 255, 255, 255);
	gfx.PutPixel(12 + x_int, 7 + y_int, 255, 255, 255);
	gfx.PutPixel(13 + x_int, 7 + y_int, 0, 0, 0);
	gfx.PutPixel(14 + x_int, 7 + y_int, 0, 0, 0);
	gfx.PutPixel(15 + x_int, 7 + y_int, 0, 0, 0);
	gfx.PutPixel(16 + x_int, 7 + y_int, 254, 221, 88);
	gfx.PutPixel(17 + x_int, 7 + y_int, 254, 221, 88);
	gfx.PutPixel(18 + x_int, 7 + y_int, 254, 221, 88);
	gfx.PutPixel(19 + x_int, 7 + y_int, 0, 0, 0);
	gfx.PutPixel(0 + x_int, 8 + y_int, 0, 0, 0);
	gfx.PutPixel(1 + x_int, 8 + y_int, 0, 0, 0);
	gfx.PutPixel(2 + x_int, 8 + y_int, 255, 255, 255);
	gfx.PutPixel(3 + x_int, 8 + y_int, 255, 255, 255);
	gfx.PutPixel(4 + x_int, 8 + y_int, 255, 255, 255);
	gfx.PutPixel(5 + x_int, 8 + y_int, 0, 0, 0);
	gfx.PutPixel(6 + x_int, 8 + y_int, 254, 221, 88);
	gfx.PutPixel(7 + x_int, 8 + y_int, 254, 221, 88);
	gfx.PutPixel(8 + x_int, 8 + y_int, 254, 221, 88);
	gfx.PutPixel(9 + x_int, 8 + y_int, 254, 221, 88);
	gfx.PutPixel(10 + x_int, 8 + y_int, 0, 0, 0);
	gfx.PutPixel(11 + x_int, 8 + y_int, 255, 255, 255);
	gfx.PutPixel(12 + x_int, 8 + y_int, 255, 255, 255);
	gfx.PutPixel(13 + x_int, 8 + y_int, 255, 255, 255);
	gfx.PutPixel(14 + x_int, 8 + y_int, 255, 255, 255);
	gfx.PutPixel(15 + x_int, 8 + y_int, 0, 0, 0);
	gfx.PutPixel(16 + x_int, 8 + y_int, 254, 221, 88);
	gfx.PutPixel(17 + x_int, 8 + y_int, 254, 221, 88);
	gfx.PutPixel(18 + x_int, 8 + y_int, 254, 221, 88);
	gfx.PutPixel(19 + x_int, 8 + y_int, 0, 0, 0);
	gfx.PutPixel(0 + x_int, 9 + y_int, 0, 0, 0);
	gfx.PutPixel(1 + x_int, 9 + y_int, 254, 221, 88);
	gfx.PutPixel(2 + x_int, 9 + y_int, 0, 0, 0);
	gfx.PutPixel(3 + x_int, 9 + y_int, 0, 0, 0);
	gfx.PutPixel(4 + x_int, 9 + y_int, 0, 0, 0);
	gfx.PutPixel(5 + x_int, 9 + y_int, 0, 0, 0);
	gfx.PutPixel(6 + x_int, 9 + y_int, 254, 221, 88);
	gfx.PutPixel(7 + x_int, 9 + y_int, 254, 221, 88);
	gfx.PutPixel(8 + x_int, 9 + y_int, 254, 221, 88);
	gfx.PutPixel(9 + x_int, 9 + y_int, 254, 221, 88);
	gfx.PutPixel(10 + x_int, 9 + y_int, 254, 221, 88);
	gfx.PutPixel(11 + x_int, 9 + y_int, 0, 0, 0);
	gfx.PutPixel(12 + x_int, 9 + y_int, 0, 0, 0);
	gfx.PutPixel(13 + x_int, 9 + y_int, 0, 0, 0);
	gfx.PutPixel(14 + x_int, 9 + y_int, 0, 0, 0);
	gfx.PutPixel(15 + x_int, 9 + y_int, 254, 221, 88);
	gfx.PutPixel(16 + x_int, 9 + y_int, 254, 221, 88);
	gfx.PutPixel(17 + x_int, 9 + y_int, 254, 221, 88);
	gfx.PutPixel(18 + x_int, 9 + y_int, 254, 221, 88);
	gfx.PutPixel(19 + x_int, 9 + y_int, 0, 0, 0);
	gfx.PutPixel(0 + x_int, 10 + y_int, 0, 0, 0);
	gfx.PutPixel(1 + x_int, 10 + y_int, 254, 221, 88);
	gfx.PutPixel(2 + x_int, 10 + y_int, 254, 221, 88);
	gfx.PutPixel(3 + x_int, 10 + y_int, 254, 221, 88);
	gfx.PutPixel(4 + x_int, 10 + y_int, 254, 221, 88);
	gfx.PutPixel(5 + x_int, 10 + y_int, 254, 221, 88);
	gfx.PutPixel(6 + x_int, 10 + y_int, 254, 221, 88);
	gfx.PutPixel(7 + x_int, 10 + y_int, 254, 221, 88);
	gfx.PutPixel(8 + x_int, 10 + y_int, 254, 221, 88);
	gfx.PutPixel(9 + x_int, 10 + y_int, 254, 221, 88);
	gfx.PutPixel(10 + x_int, 10 + y_int, 254, 221, 88);
	gfx.PutPixel(11 + x_int, 10 + y_int, 254, 221, 88);
	gfx.PutPixel(12 + x_int, 10 + y_int, 254, 221, 88);
	gfx.PutPixel(13 + x_int, 10 + y_int, 254, 221, 88);
	gfx.PutPixel(14 + x_int, 10 + y_int, 254, 221, 88);
	gfx.PutPixel(15 + x_int, 10 + y_int, 254, 221, 88);
	gfx.PutPixel(16 + x_int, 10 + y_int, 254, 221, 88);
	gfx.PutPixel(17 + x_int, 10 + y_int, 254, 221, 88);
	gfx.PutPixel(18 + x_int, 10 + y_int, 254, 221, 88);
	gfx.PutPixel(19 + x_int, 10 + y_int, 0, 0, 0);
	gfx.PutPixel(0 + x_int, 11 + y_int, 0, 0, 0);
	gfx.PutPixel(1 + x_int, 11 + y_int, 254, 221, 88);
	gfx.PutPixel(2 + x_int, 11 + y_int, 254, 221, 88);
	gfx.PutPixel(3 + x_int, 11 + y_int, 254, 221, 88);
	gfx.PutPixel(4 + x_int, 11 + y_int, 254, 221, 88);
	gfx.PutPixel(5 + x_int, 11 + y_int, 254, 221, 88);
	gfx.PutPixel(6 + x_int, 11 + y_int, 254, 221, 88);
	gfx.PutPixel(7 + x_int, 11 + y_int, 20, 14, 18);
	gfx.PutPixel(8 + x_int, 11 + y_int, 18, 11, 14);
	gfx.PutPixel(9 + x_int, 11 + y_int, 18, 12, 14);
	gfx.PutPixel(10 + x_int, 11 + y_int, 18, 12, 14);
	gfx.PutPixel(11 + x_int, 11 + y_int, 21, 13, 16);
	gfx.PutPixel(12 + x_int, 11 + y_int, 24, 11, 15);
	gfx.PutPixel(13 + x_int, 11 + y_int, 0, 0, 0);
	gfx.PutPixel(14 + x_int, 11 + y_int, 254, 221, 88);
	gfx.PutPixel(15 + x_int, 11 + y_int, 254, 221, 88);
	gfx.PutPixel(16 + x_int, 11 + y_int, 254, 221, 88);
	gfx.PutPixel(17 + x_int, 11 + y_int, 254, 221, 88);
	gfx.PutPixel(18 + x_int, 11 + y_int, 254, 221, 88);
	gfx.PutPixel(19 + x_int, 11 + y_int, 0, 0, 0);
	gfx.PutPixel(0 + x_int, 12 + y_int, 0, 0, 0);
	gfx.PutPixel(1 + x_int, 12 + y_int, 254, 221, 88);
	gfx.PutPixel(2 + x_int, 12 + y_int, 254, 221, 88);
	gfx.PutPixel(3 + x_int, 12 + y_int, 254, 221, 88);
	gfx.PutPixel(4 + x_int, 12 + y_int, 254, 221, 88);
	gfx.PutPixel(5 + x_int, 12 + y_int, 254, 221, 88);
	gfx.PutPixel(6 + x_int, 12 + y_int, 23, 9, 23);
	gfx.PutPixel(7 + x_int, 12 + y_int, 135, 26, 68);
	gfx.PutPixel(8 + x_int, 12 + y_int, 135, 26, 68);
	gfx.PutPixel(9 + x_int, 12 + y_int, 135, 26, 68);
	gfx.PutPixel(10 + x_int, 12 + y_int, 135, 26, 68);
	gfx.PutPixel(11 + x_int, 12 + y_int, 135, 26, 68);
	gfx.PutPixel(12 + x_int, 12 + y_int, 135, 26, 68);
	gfx.PutPixel(13 + x_int, 12 + y_int, 135, 26, 68);
	gfx.PutPixel(14 + x_int, 12 + y_int, 0, 0, 0);
	gfx.PutPixel(15 + x_int, 12 + y_int, 254, 221, 88);
	gfx.PutPixel(16 + x_int, 12 + y_int, 254, 221, 88);
	gfx.PutPixel(17 + x_int, 12 + y_int, 254, 221, 88);
	gfx.PutPixel(18 + x_int, 12 + y_int, 254, 221, 88);
	gfx.PutPixel(19 + x_int, 12 + y_int, 0, 0, 0);
	gfx.PutPixel(1 + x_int, 13 + y_int, 0, 0, 0);
	gfx.PutPixel(2 + x_int, 13 + y_int, 254, 221, 88);
	gfx.PutPixel(3 + x_int, 13 + y_int, 254, 221, 88);
	gfx.PutPixel(4 + x_int, 13 + y_int, 254, 221, 88);
	gfx.PutPixel(5 + x_int, 13 + y_int, 0, 0, 0);
	gfx.PutPixel(6 + x_int, 13 + y_int, 135, 26, 68);
	gfx.PutPixel(7 + x_int, 13 + y_int, 135, 26, 68);
	gfx.PutPixel(8 + x_int, 13 + y_int, 135, 26, 68);
	gfx.PutPixel(9 + x_int, 13 + y_int, 135, 26, 68);
	gfx.PutPixel(10 + x_int, 13 + y_int, 135, 26, 68);
	gfx.PutPixel(11 + x_int, 13 + y_int, 135, 26, 68);
	gfx.PutPixel(12 + x_int, 13 + y_int, 135, 26, 68);
	gfx.PutPixel(13 + x_int, 13 + y_int, 135, 26, 68);
	gfx.PutPixel(14 + x_int, 13 + y_int, 135, 26, 68);
	gfx.PutPixel(15 + x_int, 13 + y_int, 0, 0, 0);
	gfx.PutPixel(16 + x_int, 13 + y_int, 254, 221, 88);
	gfx.PutPixel(17 + x_int, 13 + y_int, 254, 221, 88);
	gfx.PutPixel(18 + x_int, 13 + y_int, 0, 0, 0);
	gfx.PutPixel(1 + x_int, 14 + y_int, 0, 0, 0);
	gfx.PutPixel(2 + x_int, 14 + y_int, 254, 221, 88);
	gfx.PutPixel(3 + x_int, 14 + y_int, 254, 221, 88);
	gfx.PutPixel(4 + x_int, 14 + y_int, 0, 0, 0);
	gfx.PutPixel(5 + x_int, 14 + y_int, 135, 26, 68);
	gfx.PutPixel(6 + x_int, 14 + y_int, 135, 26, 68);
	gfx.PutPixel(7 + x_int, 14 + y_int, 135, 26, 68);
	gfx.PutPixel(8 + x_int, 14 + y_int, 135, 26, 68);
	gfx.PutPixel(9 + x_int, 14 + y_int, 251, 192, 224);
	gfx.PutPixel(10 + x_int, 14 + y_int, 251, 192, 224);
	gfx.PutPixel(11 + x_int, 14 + y_int, 251, 192, 224);
	gfx.PutPixel(12 + x_int, 14 + y_int, 251, 192, 224);
	gfx.PutPixel(13 + x_int, 14 + y_int, 135, 26, 68);
	gfx.PutPixel(14 + x_int, 14 + y_int, 135, 26, 68);
	gfx.PutPixel(15 + x_int, 14 + y_int, 0, 0, 0);
	gfx.PutPixel(16 + x_int, 14 + y_int, 254, 221, 88);
	gfx.PutPixel(17 + x_int, 14 + y_int, 254, 221, 88);
	gfx.PutPixel(18 + x_int, 14 + y_int, 0, 0, 0);
	gfx.PutPixel(2 + x_int, 15 + y_int, 0, 0, 0);
	gfx.PutPixel(3 + x_int, 15 + y_int, 254, 221, 88);
	gfx.PutPixel(4 + x_int, 15 + y_int, 0, 0, 0);
	gfx.PutPixel(5 + x_int, 15 + y_int, 135, 26, 68);
	gfx.PutPixel(6 + x_int, 15 + y_int, 135, 26, 68);
	gfx.PutPixel(7 + x_int, 15 + y_int, 135, 26, 68);
	gfx.PutPixel(8 + x_int, 15 + y_int, 251, 192, 224);
	gfx.PutPixel(9 + x_int, 15 + y_int, 251, 192, 224);
	gfx.PutPixel(10 + x_int, 15 + y_int, 251, 192, 224);
	gfx.PutPixel(11 + x_int, 15 + y_int, 251, 192, 224);
	gfx.PutPixel(12 + x_int, 15 + y_int, 251, 192, 224);
	gfx.PutPixel(13 + x_int, 15 + y_int, 251, 192, 224);
	gfx.PutPixel(14 + x_int, 15 + y_int, 135, 26, 68);
	gfx.PutPixel(15 + x_int, 15 + y_int, 0, 0, 0);
	gfx.PutPixel(16 + x_int, 15 + y_int, 254, 221, 88);
	gfx.PutPixel(17 + x_int, 15 + y_int, 0, 0, 0);
	gfx.PutPixel(2 + x_int, 16 + y_int, 0, 0, 0);
	gfx.PutPixel(3 + x_int, 16 + y_int, 254, 221, 88);
	gfx.PutPixel(4 + x_int, 16 + y_int, 0, 0, 0);
	gfx.PutPixel(5 + x_int, 16 + y_int, 135, 26, 68);
	gfx.PutPixel(6 + x_int, 16 + y_int, 135, 26, 68);
	gfx.PutPixel(7 + x_int, 16 + y_int, 135, 26, 68);
	gfx.PutPixel(8 + x_int, 16 + y_int, 251, 192, 224);
	gfx.PutPixel(9 + x_int, 16 + y_int, 251, 192, 224);
	gfx.PutPixel(10 + x_int, 16 + y_int, 251, 192, 224);
	gfx.PutPixel(11 + x_int, 16 + y_int, 251, 192, 224);
	gfx.PutPixel(12 + x_int, 16 + y_int, 251, 192, 224);
	gfx.PutPixel(13 + x_int, 16 + y_int, 251, 192, 224);
	gfx.PutPixel(14 + x_int, 16 + y_int, 135, 26, 68);
	gfx.PutPixel(15 + x_int, 16 + y_int, 0, 0, 0);
	gfx.PutPixel(16 + x_int, 16 + y_int, 254, 221, 88);
	gfx.PutPixel(17 + x_int, 16 + y_int, 0, 0, 0);
	gfx.PutPixel(3 + x_int, 17 + y_int, 0, 0, 0);
	gfx.PutPixel(4 + x_int, 17 + y_int, 0, 0, 0);
	gfx.PutPixel(5 + x_int, 17 + y_int, 0, 0, 0);
	gfx.PutPixel(6 + x_int, 17 + y_int, 0, 0, 0);
	gfx.PutPixel(7 + x_int, 17 + y_int, 0, 0, 0);
	gfx.PutPixel(8 + x_int, 17 + y_int, 0, 0, 0);
	gfx.PutPixel(9 + x_int, 17 + y_int, 0, 0, 0);
	gfx.PutPixel(10 + x_int, 17 + y_int, 0, 0, 0);
	gfx.PutPixel(11 + x_int, 17 + y_int, 0, 0, 0);
	gfx.PutPixel(12 + x_int, 17 + y_int, 0, 0, 0);
	gfx.PutPixel(13 + x_int, 17 + y_int, 0, 0, 0);
	gfx.PutPixel(14 + x_int, 17 + y_int, 0, 0, 0);
	gfx.PutPixel(15 + x_int, 17 + y_int, 0, 0, 0);
	gfx.PutPixel(16 + x_int, 17 + y_int, 0, 0, 0);
	gfx.PutPixel(5 + x_int, 18 + y_int, 0, 0, 0);
	gfx.PutPixel(6 + x_int, 18 + y_int, 0, 0, 0);
	gfx.PutPixel(7 + x_int, 18 + y_int, 254, 221, 88);
	gfx.PutPixel(8 + x_int, 18 + y_int, 254, 221, 88);
	gfx.PutPixel(9 + x_int, 18 + y_int, 254, 221, 88);
	gfx.PutPixel(10 + x_int, 18 + y_int, 254, 221, 88);
	gfx.PutPixel(11 + x_int, 18 + y_int, 254, 221, 88);
	gfx.PutPixel(12 + x_int, 18 + y_int, 254, 221, 88);
	gfx.PutPixel(13 + x_int, 18 + y_int, 0, 0, 0);
	gfx.PutPixel(14 + x_int, 18 + y_int, 0, 0, 0);
	gfx.PutPixel(7 + x_int, 19 + y_int, 0, 0, 0);
	gfx.PutPixel(8 + x_int, 19 + y_int, 0, 0, 0);
	gfx.PutPixel(9 + x_int, 19 + y_int, 0, 0, 0);
	gfx.PutPixel(10 + x_int, 19 + y_int, 0, 0, 0);
	gfx.PutPixel(11 + x_int, 19 + y_int, 0, 0, 0);
	gfx.PutPixel(12 + x_int, 19 + y_int, 0, 0, 0);
}

void Dude::ClampToScreen()
{
	//For X Axis
	if (pos.x > Graphics::ScreenWidth - width)
	{
		pos.x = Graphics::ScreenWidth - width;
	}
	else if (pos.x <= 0)
	{
		pos.x = 0;
	}

	//For Y Axis
	if (pos.y > Graphics::ScreenHeight - height)
	{
		pos.y = Graphics::ScreenHeight - height;
	}
	else if (pos.y < 0)
	{
		pos.y = 0;
	}
}

Vector2D Dude::GetPos() const
{
	return pos;
}

float Dude::GetV() const
{
	return v;
}

void Dude::SetV(float new_v)
{
	v = new_v;
}

float Dude::GetWidth()
{
	return width;
}

float Dude::GetHeight()
{
	return height;
}

void Dude::IsFinished()
{
	isNotFinished = false;
	hasEaten = true;
}

bool Dude::GetHasEaten()
{
	return hasEaten;
}

void Dude::fixSpeed(Keyboard& kbd, float new_v)
{
	if ((kbd.KeyIsPressed(VK_DOWN) && kbd.KeyIsPressed(VK_RIGHT)) ||
		(kbd.KeyIsPressed(VK_DOWN) && kbd.KeyIsPressed(VK_LEFT)) ||
		(kbd.KeyIsPressed(VK_UP) && kbd.KeyIsPressed(VK_RIGHT)) ||
		(kbd.KeyIsPressed(VK_UP) && kbd.KeyIsPressed(VK_LEFT)))
	{
		v = new_v / float(sqrt(2));
	}
	else
	{
		v = new_v ;
	}
}


