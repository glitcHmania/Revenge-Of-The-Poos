#pragma once
#include "Graphics.h"
#include "Dude.h"
#include "Vector2D.h"
class Immune
{
public:
	Immune(Vector2D& in_pos);
	void Draw(Graphics& gfx);
	void ChangeColor();
	void ProcessConsumption(const Dude& dude);
	bool GetIsEaten();
	int GetImmuneLevel();
private:
	Vector2D pos;
	float width = 15.0f;
	float height = 15.0f;
	int r = 228;
	int g = 208;
	int b = 10;
	int colorIndex = 5;
	bool isEaten = false;
	static constexpr int immuneLevel = 19;
};

