#pragma once
#include "Graphics.h"
#include "Dude.h"
class Poo
{
public:
	void Init(float in_x, float in_y, float in_vx, float in_vy);
	void Draw(Graphics& gfx);
	void Update(float deltaTime);
	void ProcessConsumption(const Dude& dude);
	bool GetIsEaten();
	bool initialized = false;
private:
	float x;
	float y;
	float vx;
	float vy;
	static constexpr float width = 24;
	static constexpr float height = 24;
	bool isEaten = false;
};

