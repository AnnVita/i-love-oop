﻿#include "stdafx.h"
#include "Rational.h"
#include <utility>
#include <stdexcept>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator must not be equal to zero");
	}
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
//////////////////////////////////////////////////////////////////////////
double CRational::ToDouble() const
{
	return static_cast<double>(m_numerator) / m_denominator;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
//////////////////////////////////////////////////////////////////////////
const CRational CRational::operator+() const
{
	return *this;
}

const CRational CRational::operator-() const
{
	return CRational(-m_numerator, m_denominator);
}



//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный +
//////////////////////////////////////////////////////////////////////////
const CRational operator+(const CRational & lRational, const CRational & rRational)
{
	int resultNumerator = lRational.GetNumerator() * rRational.GetDenominator() + rRational.GetNumerator() * lRational.GetDenominator();
	int resultDenominator = lRational.GetDenominator() * rRational.GetDenominator();
	return CRational(resultNumerator, resultDenominator);
}



//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
//////////////////////////////////////////////////////////////////////////
const CRational operator-(const CRational & lRational, const CRational & rRational)
{
	int resultNumerator = lRational.GetNumerator() * rRational.GetDenominator() - rRational.GetNumerator() * lRational.GetDenominator();
	int resultDenominator = lRational.GetDenominator() * rRational.GetDenominator();
	return CRational(resultNumerator, resultDenominator);
}



//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
//////////////////////////////////////////////////////////////////////////
const CRational & CRational::operator+=(const CRational & summand)
{
	if (summand.GetNumerator() == 0)
	{
		return *this;
	}
	m_numerator = m_numerator * summand.GetDenominator() + summand.GetNumerator() * m_denominator;
	m_denominator = m_denominator * summand.GetDenominator();
	Normalize();
	return *this;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
//////////////////////////////////////////////////////////////////////////
const CRational & CRational::operator-=(const CRational & sub)
{
	if (sub.GetNumerator() == 0)
	{
		return *this;
	}
	m_numerator = m_numerator * sub.GetDenominator() - sub.GetNumerator() * m_denominator;
	m_denominator = m_denominator * sub.GetDenominator();
	Normalize();
	return *this;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
//////////////////////////////////////////////////////////////////////////
const CRational operator*(const CRational & lRational, const CRational & rRational)
{
	int resultNumerator = lRational.GetNumerator() * rRational.GetNumerator();
	int resultDenominator = lRational.GetDenominator() * rRational.GetDenominator();
	return CRational(resultNumerator, resultDenominator);
}



//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
//////////////////////////////////////////////////////////////////////////
const CRational operator/(const CRational & lRational, const CRational & rRational)
{
	int resultNumerator = lRational.GetNumerator() * rRational.GetDenominator();
	int resultDenominator = lRational.GetDenominator() * rRational.GetNumerator();
	return CRational(resultNumerator, resultDenominator);
}



//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
//////////////////////////////////////////////////////////////////////////
const CRational & CRational::operator*=(const CRational & multiplier)
{
	m_numerator *= multiplier.GetNumerator();
	m_denominator *= multiplier.GetDenominator();
	Normalize();
	return *this;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
//////////////////////////////////////////////////////////////////////////
const CRational & CRational::operator/=(const CRational & divider)
{
	if (divider.GetNumerator() != 0)
	{
		m_numerator *= divider.GetDenominator();
		m_denominator *= divider.GetNumerator();
		Normalize();
	}
	return *this;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
//////////////////////////////////////////////////////////////////////////
const bool operator ==(CRational const & lRational, CRational const & rRational)
{
	return (lRational.GetNumerator() == rRational.GetNumerator() && lRational.GetDenominator() == rRational.GetDenominator());
}

const bool operator !=(CRational const & lRational, CRational const & rRational)
{
	return !(lRational == rRational);
}


//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//////////////////////////////////////////////////////////////////////////


