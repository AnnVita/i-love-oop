#pragma once

enum Direction
{
	NONE,
	FORWARD, 
	BACKWARD
};

enum Gear
{
	REVERSE = -1,
	NEUTRAL = 0,
	FIRST = 1,
	SECOND = 2,
	THIRD = 3,
	FOURTH = 4,
	FIFTH = 5
};

class CCar
{
public:
	CCar();
	~CCar() {};

	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(Gear gear);
	bool SetSpeed(int speed);

	bool IsTurnedOn() const;
	Direction GetDirection() const;
	int GetSpeed() const;
	Gear GetGear() const;

private:
	bool IsDirectionCorrect(Direction direction, Gear gear) const;
	bool CCar::IsSpeedInRange(int speed, Gear gear) const;

	bool m_engineOn = false;
	Direction m_direction;
	Gear m_gear;
	int m_speed = 0;
};