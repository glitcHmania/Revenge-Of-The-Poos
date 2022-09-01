#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Vector2D.h"

class Dude
{
public:
	Dude(Vector2D& in_pos, float in_v);
	void Update(const Keyboard& kbd, float deltaTime);
	void Draw(Graphics& gfx);
	void ClampToScreen();
	Vector2D GetPos() const;
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
	Vector2D pos;
	float v;
	static constexpr float width = 20;
	static constexpr float height = 20;
};