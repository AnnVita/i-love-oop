#include "stdafx.h"
#include "car.h"

CCar::CCar()
{
	m_engineOn = false;
	m_speed = 0;
	m_direction = Direction::NONE;
	m_gear = Gear::NEUTRAL;
}

bool CCar::IsTurnedOn() const
{
	return m_engineOn;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

Direction CCar::GetDirection() const
{
	return m_direction;
}

Gear CCar::GetGear() const
{
	return m_gear;
}

bool CCar::TurnOnEngine()
{
	if (!m_engineOn)
	{
		m_engineOn = true;
		return true;
	}

	return false;
}

bool CCar::TurnOffEngine()
{
	if ((m_engineOn) && (m_direction == Direction::NONE) && (m_gear == Gear::NEUTRAL))
	{
		m_engineOn = false;
		return true;
	}

	return false;
}

bool CCar::IsSpeedInRange(int speed, Gear gear) const
{
	bool isInRange;
	switch (gear)
	{
	case Gear::REVERSE:
		isInRange = ((speed >= 0) && (speed <= 20));
		break;
	case Gear::NEUTRAL:
		isInRange = true;
		break;
	case Gear::FIRST:
		isInRange = ((speed >= 0) && (speed <= 30));
		break;
	case Gear::SECOND:
		isInRange = ((speed >= 20) && (speed <= 50));
		break;
	case Gear::THIRD:
		isInRange = ((speed >= 30) && (speed <= 60));
		break;
	case Gear::FOURTH:
		isInRange = ((speed >= 40) && (speed <= 90));
		break;
	case Gear::FIFTH:
		isInRange = ((speed >= 50) && (speed <= 150));
		break;
	}
}

bool CCar::IsDirectionCorrect(Direction direction, Gear gear) const
{

}