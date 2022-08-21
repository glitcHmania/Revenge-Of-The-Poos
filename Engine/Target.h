#pragma once
#include "Graphics.h"
#include "Dude.h"
class Target
{
public:
	Target(int in_x, int in_y, int in_width, int in_height);
	void Draw(Graphics& gfx);
	void ChangeColor();
	void ProcessConsumtion(const Dude& dude);
	bool GetIsEaten();
	void SetIsEaten(bool boolean);
	void SetX(int new_x);
	void SetY(int new_y);
	void targetCounter(Graphics& gfx);
	int GetCounterLength();
	void SetRelocated(bool boolean);
private:
	int counter_length = 0;
	bool relocated = false;
	bool isEaten = false;
	int x;
	int y;
	int width;
	int height;
	int r = 5;
	int g = 0;
	int b = 250;
	int colorIndex = 5;

};

