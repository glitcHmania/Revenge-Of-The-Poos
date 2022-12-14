#include "Target.h"

Target::Target(Vector2D&in_pos)
{
	pos = in_pos;
}

void Target::Draw(Graphics& gfx)
{
	for (float i = pos.x; i < pos.x + width; ++i)
	{
		for (float j = pos.y; j < pos.y + height; ++j)
		{
			int i_int = int(i);
			int j_int = int(j);
			gfx.PutPixel(i_int, j_int, r, g, b);
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
	if (dude.GetPos().x <= pos.x + width &&
		dude.GetPos().x + dude.GetWidth() >= pos.x &&
		dude.GetPos().y <= pos.y + height &&
		dude.GetPos().y + dude.GetHeight() >= pos.y)
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

void Target::SetPos(Vector2D& new_pos)
{
	pos = new_pos;
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

float Target::GetCounterLength()
{
	return counter_length + 10;
}

void Target::SetRelocated(bool boolean)
{
	relocated = boolean;
}



