#include "Target.h"

Target::Target(int in_x, int in_y, int in_width, int in_height)
{
	x = in_x;
	y = in_y;
	width = in_width;
	height = in_height;
}

void Target::Draw(Graphics& gfx)
{
	for (int i = x; i < x + width; ++i)
	{
		for (int j = y; j < y + height; ++j)
		{
			gfx.PutPixel(i, j, r, g, b);
		}
	}
}

void Target::ChangeColor()
{
	if ((r == 0) || (r == 255))
	{
		colorIndex = -colorIndex;
	}

	r = r + colorIndex;
	b = b - colorIndex;
}

void Target::ProcessConsumtion(const Dude& dude)
{
	if (dude.GetX() <= x + width &&
		dude.GetX() + dude.GetWidth() >= x &&
		dude.GetY() <= y + height &&
		dude.GetY() + dude.GetHeight() >= y)
	{
		isEaten = true;
	}
}

bool Target::GetIsEaten()
{
	return isEaten;
}

void Target::SetIsEaten(bool boolean)
{
	isEaten = boolean;
}

void Target::SetX(int new_x)
{
	x = new_x;
}

void Target::SetY(int new_y)
{
	y = new_y;
}

void Target::targetCounter(Graphics& gfx)
{
	for (int i = 10; i < counter_length + 10; ++i)
	{
		for (int j = 10; j < 20; ++j)
		{
			gfx.PutPixel(i, j, 180, 255, 180);
		}
	}
	if (relocated)
	{
		counter_length += 39;
		relocated = false;
	}


}

int Target::GetCounterLength()
{
	return counter_length + 10;
}

void Target::SetRelocated(bool boolean)
{
	relocated = boolean;
}



