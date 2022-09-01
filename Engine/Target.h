#pragma once
#include "Graphics.h"
#include "Dude.h"
#include "Vector2D.h"
class Target
{
public:
	Target(Vector2D& in_pos, float in_width, float in_height);
	void Draw(Graphics& gfx);
	void ChangeColor();
	void ProcessConsumtion(const Dude& dude);
	bool GetIsEaten();
	void SetIsEaten(bool boolean);
	void SetPos(Vector2D& new_pos);
	void targetCounter(Graphics& gfx);
	float GetCounterLength();
	void SetRelocated(bool boolean);
private:
	float counter_length = 0;
	bool relocated = false;
	bool isEaten = false;
	Vector2D pos;
	float width;
	float height;
	int r = 5;
	int g = 0;
	int b = 250;
	int colorIndex = 5;

};

