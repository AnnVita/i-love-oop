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

