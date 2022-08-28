#pragma once
#include "Graphics.h"
#include "Dude.h"
class Target
{
public:
	Target(float in_x, float in_y, float in_width, float in_height);
	void Draw(Graphics& gfx);
	void ChangeColor();
	void ProcessConsumtion(const Dude& dude);
	bool GetIsEaten();
	void SetIsEaten(bool boolean);
	void SetX(float new_x);
	void SetY(float new_y);
	void targetCounter(Graphics& gfx);
	float GetCounterLength();
	void SetRelocated(bool boolean);
private:
	float counter_length = 0;
	bool relocated = false;
	bool isEaten = false;
	float x;
	float y;
	float width;
	float height;
	int r = 5;
	int g = 0;
	int b = 250;
	int colorIndex = 5;

};

