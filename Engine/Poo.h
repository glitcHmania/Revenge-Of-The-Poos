#pragma once
#include "Graphics.h"
#include "Dude.h"
#include "Vector2D.h"
class Poo
{
public:
	void Init(Vector2D& in_pos, Vector2D& in_vel);
	void Draw(Graphics& gfx);
	void Update(float deltaTime);
	void ProcessConsumption(const Dude& dude);
	bool GetIsEaten();
	bool initialized = false;
private:
	Vector2D pos;
	Vector2D vel;
	static constexpr float width = 24.0f;
	static constexpr float height = 24.0f;
	bool isEaten = false;
};

