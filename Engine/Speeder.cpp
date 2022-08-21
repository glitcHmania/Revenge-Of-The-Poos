#include "Speeder.h"

Speeder::Speeder(int in_x, int in_y, int in_width, int in_height)
{
	x = in_x;
	y = in_y;
	width = in_width;
	height = in_height;
}

void Speeder::Draw(Graphics& gfx)
{
	for (int i = x; i < x + width; ++i)
	{
		for (int j = y; j < y + height; ++j)
		{
			gfx.PutPixel(i, j, r, g, b);
		}
	}
}

void Speeder::ChangeColor()
{
	if ((b == 0) || (b == 255))
	{
		colorIndex = -colorIndex;
	}

	b = b + colorIndex;
	r = r + colorIndex;
}

void Speeder::ProcessConsumption(const Dude& dude)
{
	if (dude.GetX() <= x + width &&
		dude.GetX() + dude.GetWidth() >= x &&
		dude.GetY() <= y + height &&
		dude.GetY() + dude.GetHeight() >= y)
	{
		isEaten = true;
	}
}

bool Speeder::GetIsEaten()
{
	return isEaten;
}
