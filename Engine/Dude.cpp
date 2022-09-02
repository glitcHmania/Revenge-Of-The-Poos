#include "Dude.h"
#include <math.h>


Dude::Dude(Vector2D& in_pos)
{
	pos = in_pos;
}

void Dude::UpdateKbd(const Keyboard& kbd, float deltaTime)
{
	Vector2D vel = Vector2D(0.0f, 0.0f);
	if (isNotFinished)
	{
		if (kbd.KeyIsPressed(VK_RIGHT))
		{
			vel.x += 1.0f;
		}
		if (kbd.KeyIsPressed(VK_LEFT))
		{
			vel.x -= 1.0f;
		}
		if (kbd.KeyIsPressed(VK_UP))
		{
			vel.y -= 1.0f;
		}
		if (kbd.KeyIsPressed(VK_DOWN))
		{
			vel.y += 1.0f ;
		}
		pos += vel.GetNormalized() * v * deltaTime;
	}
}

void Dude::UpdateMs(const Keyboard& kbd, float deltaTime, const Mouse& mouse)
{
	if (isNotFinished)
	{
		if (mouse.LeftIsPressed())
		{
			const Vector2D center = pos + Vector2D(width / 2.0f, height / 2.0f);
			Vector2D targetPos = Vector2D(float(mouse.GetPosX()), float(mouse.GetPosY()));
			if (!(center.x > targetPos.x - 2.0f &&
				center.x < targetPos.x + 2.0f &&
				center.y > targetPos.y - 2.0f &&
				center.y < targetPos.y + 2.0f ))
			{
				const Vector2D distance = targetPos - center;
				pos += distance.GetNormalized() * deltaTime * v;
			}
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

