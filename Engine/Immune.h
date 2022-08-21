#pragma once
#include "Graphics.h"
#include "Dude.h"
class Immune
{
public:
	Immune(int in_x, int in_y, int in_width, int in_height);
	void Draw(Graphics& gfx);
	void ChangeColor();
	void ProcessConsumption(const Dude& dude);
	bool GetIsEaten();
	int GetImmuneLevel();
private:
	int x;
	int y;
	int width;
	int height;
	int r = 228;
	int g = 208;
	int b = 10;
	int colorIndex = 5;
	bool isEaten = false;
	static constexpr int immuneLevel = 19;
};

