#pragma once
#include "Graphics.h"
#include "Dude.h"
#include "Vector2D.h"
class Speeder
{
public:
	Speeder(Vector2D& in_pos);
	void Draw(Graphics& gfx);
	void ChangeColor();
	void ProcessConsumption(const Dude& dude);
	bool GetIsEaten();
private:
	Vector2D pos;
	float width = 15.0f;
	float height = 15.0f;
	int r = 5;
	int g = 255;
	int b = 5;
	int colorIndex = 5;
	bool isEaten = false;
};

