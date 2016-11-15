#include "stdafx.h"
#include "car.h"
#include "carController.h"
#include <string>
#include <sstream>

using namespace std;
using namespace std::placeholders;

CCarControl::CCarControl(CCar &car, std::istream &input, std::ostream &output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "EngineOn", bind(&CCarControl::EngineOn, this, std::placeholders::_1) },
		{ "EngineOff", bind(&CCarControl::EngineOff, this, std::placeholders::_1) },
		{ "SetGear", bind(&CCarControl::SetGear, this, std::placeholders::_1) },
		{ "SetSpeed", bind(&CCarControl::SetSpeed, this, std::placeholders::_1) },
		{ "Info", bind(&CCarControl::Info, this, std::placeholders::_1) }
})
{
}

bool CCarControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CCarControl::EngineOn(std::istream & /*args*/)
{
	if (m_car.TurnOnEngine())
	{
		m_output << "Car engine is turned on\n";
		return true;
	}

	return false;
}

bool CCarControl::EngineOff(std::istream & /*args*/)
{
	if (m_car.TurnOffEngine())
	{
		m_output << "Car engine is turned off\n";
		return true;
	}

	return false;
}

bool CCarControl::Info(std::istream & /*args*/)
{
	std::string info;

	if (m_car.IsTurnedOn())
	{
		info = "Car engine is on\nGear: " + std::to_string(m_car.GetGear()) +
			"\nSpeed: " + std::to_string(m_car.GetSpeed()) +
			"\nDirection: " + std::to_string(static_cast<int>(m_car.GetDirection())) + '\n';
	}
	else
	{
		info = "Car engine is off\n";
	}

	m_output << info;

	return true;
}

bool CCarControl::SetGear(std::istream &args)
{
	int gear;
	args >> gear;

	if (m_car.SetGear(static_cast<Gear>(gear)))
	{
		std::string msg = "Gear was switched on " + std::to_string(gear) + '\n';
		m_output << msg;
	}
	else
	{
		std::string alert = "Gear doesn't match current car speed or car engine is turned off\n";
		m_output << alert;
	}

	return true;
}

bool CCarControl::SetSpeed(std::istream &args)
{
	int speed;
	args >> speed;

	if (m_car.SetSpeed(speed))
	{
		std::string alert = "Speed was successfully changed on " + std::to_string(speed) + "\n";
		m_output << alert;
	}
	else
	{
		std::string alert = "Speed is out of range for current gear or car engine is turned off\n";
		m_output << alert;
	}

	return true;
}