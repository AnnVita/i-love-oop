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

bool CCar::SetSpeed(int speed)
{
	if (m_engineOn && IsSpeedInRange(speed, m_gear) && !((m_gear == Gear::NEUTRAL) && (speed >= m_speed)))
	{
		if (speed == 0)
		{
			m_direction = Direction::NONE;
		}
		else if (m_gear == Gear::REVERSE)
		{
			m_direction = Direction::BACKWARD;
		}
		else
		{
			m_direction = Direction::FORWARD;
		}
		m_speed = speed;
		return true;
	}
	return false;
}

bool CCar::SetGear(Gear newGear)
{
	if (!m_engineOn || !IsSpeedInRange(m_speed, newGear) || !IsDirectionCorrect(m_direction, newGear))
		return false;

	if (newGear == Gear::REVERSE)
	{
		if (m_gear > Gear::FIRST || m_speed != 0)
			return false;
	}

	if (newGear == Gear::FIRST && m_gear < Gear::FIRST)
	{
		if (m_speed != 0)
			return false;
	}

	m_gear = newGear;
	return true;
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
		isInRange = (speed >= 0);
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
	return isInRange;
}

bool CCar::IsDirectionCorrect(Direction direction, Gear gear) const
{
	return !(((direction == Direction::FORWARD) && (gear == Gear::REVERSE)) || ((direction == Direction::BACKWARD) && (gear > Gear::NEUTRAL)));
}