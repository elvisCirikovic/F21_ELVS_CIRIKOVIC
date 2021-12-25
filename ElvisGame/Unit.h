#pragma once

#include "Mirage.h"
class Unit
{
public:
	Unit() = delete;
	Unit(const std::string& imageFile, int xPos, int yPos, int speed);
	int GetUnitWidth() const;
	int GetUnitHeight() const;
	void SetPosX(int newX);
	void SetPosY(int newY);
	int GetPosX() const;
	int GetPosY() const;
	int GetSpeed() const;
	void SetSpeed(int newSpeed);

	bool CollideWith(const Unit &other) const;

	void Draw(Mirage::Shader & shader);
	enum class Direction
	{
		None,
		Up,
		Down,
		Left,
		Right,
	};

	Unit::Direction GetDirection() const;
	void SetDirection(Unit::Direction newDirection);

	void UpdatePosition();

private:
	bool IsPositionPossible(int newX, int newY) const;
	Mirage::Sprite mImage;
	int mPosX;
	int mPosY;
	int mSpeed;

	Direction mDirection;
};

