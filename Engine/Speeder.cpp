#include "Speeder.h"

Speeder::Speeder(float in_x, float in_y, float in_width, float in_height)
{
	x = in_x;
	y = in_y;
	width = in_width;
	height = in_height;
}

void Speeder::Draw(Graphics& gfx)
{
	for (float i = x; i < x + width; ++i)
	{
		for (float j = y; j < y + height; ++j)
		{
			int i_int = int(i);
			int j_int = int(j);
			gfx.PutPixel(i_int, j_int, r, g, b);
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
