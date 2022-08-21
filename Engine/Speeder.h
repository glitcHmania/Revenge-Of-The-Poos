#pragma once
#include "Graphics.h"
#include "Dude.h"
class Speeder
{
public:
	Speeder(int in_x, int in_y, int in_width, int in_height);
	void Draw(Graphics& gfx);
	void ChangeColor();
	void ProcessConsumption(const Dude& dude);
	bool GetIsEaten();
private:
	int x;
	int y;
	int width;
	int height;
	int r = 5;
	int g = 255;
	int b = 5;
	int colorIndex = 5;
	bool isEaten = false;
};

