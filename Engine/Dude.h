#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Vector2D.h"
#include "MainWindow.h"

class Dude
{
public:
	Dude(Vector2D& in_pos);
	void UpdateKbd(const Keyboard& kbd, float deltaTime);
	void UpdateMs(const Keyboard& kbd, float deltaTime, const Mouse& mouse);
	void Draw(Graphics& gfx);
	void ClampToScreen();
	Vector2D GetPos() const;
	float GetV() const;
	void SetV(float new_v);
	static float GetWidth();
	static float GetHeight();
	void IsFinished();
	bool GetHasEaten();
private:
	bool hasEaten = false;
	bool isNotFinished = true;
	Vector2D pos;
	float v = 200.0f;
	static constexpr float width = 20.0f;
	static constexpr float height = 20.0f;
};