#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Dude
{
public:
	Dude(float in_x, float in_y, float in_v);
	void Update(const Keyboard& kbd, float deltaTime);
	void Draw(Graphics& gfx);
	void ClampToScreen();
	float GetX() const;
	float GetY() const;
	float GetV() const;
	void SetV(float new_v);
	static float GetWidth();
	static float GetHeight();
	void IsFinished();
	bool GetHasEaten();
	void fixSpeed(Keyboard& kbd, float new_v);
private:
	bool hasEaten = false;
	bool isNotFinished = true;
	float x;
	float y;
	float v;
	static constexpr float width = 20;
	static constexpr float height = 20;
};