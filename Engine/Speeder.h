#pragma once
#include "Graphics.h"
#include "Dude.h"
class Speeder
{
public:
	Speeder(float in_x, float in_y, float in_width, float in_height);
	void Draw(Graphics& gfx);
	void ChangeColor();
	void ProcessConsumption(const Dude& dude);
	bool GetIsEaten();
private:
	float x;
	float y;
	float width;
	float height;
	int r = 5;
	int g = 255;
	int b = 5;
	int colorIndex = 5;
	bool isEaten = false;
};

