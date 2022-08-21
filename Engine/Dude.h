#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Dude
{
public:
	Dude(int in_x, int in_y, int in_v);
	void Update(const Keyboard& kbd);
	void Draw(Graphics& gfx);
	void ClampToScreen();
	int GetX() const;
	int GetY() const;
	int GetV() const;
	void SetV(int a);
	static int GetWidth();
	static int GetHeight();
	void IsFinished();
	bool GetHasEaten();
	void fixSpeed(int vDiagonal, int vStraight, Keyboard& kbd);
private:
	bool hasEaten = false;
	bool isNotFinished = true;
	int x;
	int y;
	int v;
	static constexpr int width = 20;
	static constexpr int height = 20;
};