#include "Immune.h"

Immune::Immune(Vector2D& in_pos)
{
	pos = in_pos;
}

void Immune::Draw(Graphics& gfx)
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

void Immune::ChangeColor()
{
	if ((b == 0) || (b == 255))
	{
		colorIndex = -colorIndex;
	}

	b = b + colorIndex;
	r = r + colorIndex;
}

void Immune::ProcessConsumption(const Dude& dude)
{
	if (dude.GetPos().x <= pos.x + width &&
		dude.GetPos().x + dude.GetWidth() >= pos.x &&
		dude.GetPos().y <= pos.y + height &&
		dude.GetPos().y + dude.GetHeight() >= pos.y)
	{
		isEaten = true;
	}
}

bool Immune::GetIsEaten()
{
	return isEaten;
}

int Immune::GetImmuneLevel()
{
	return immuneLevel;
}
