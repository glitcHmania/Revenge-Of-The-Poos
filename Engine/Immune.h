#pragma once
#include "Graphics.h"
#include "Dude.h"
class Immune
{
public:
	Immune(float in_x, float in_y, float in_width, float in_height);
	void Draw(Graphics& gfx);
	void ChangeColor();
	void ProcessConsumption(const Dude& dude);
	bool GetIsEaten();
	int GetImmuneLevel();
private:
	float x;
	float y;
	float width;
	float height;
	int r = 228;
	int g = 208;
	int b = 10;
	int colorIndex = 5;
	bool isEaten = false;
	static constexpr int immuneLevel = 19;
};

