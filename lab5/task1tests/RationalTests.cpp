﻿// task1tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../task1/Rational.h"

BOOST_AUTO_TEST_CASE(Test_Greates_Common_Denominator)
{
	BOOST_CHECK_EQUAL(GCD(2, 3), 1u);
	BOOST_CHECK_EQUAL(GCD(3, 2), 1u);
	BOOST_CHECK_EQUAL(GCD(12, 8), 4u);
	BOOST_CHECK_EQUAL(GCD(8, 12), 4u);
	BOOST_CHECK_EQUAL(GCD(0, 2), 2u);
	BOOST_CHECK_EQUAL(GCD(2, 0), 2u);
	BOOST_CHECK_EQUAL(GCD(0, 0), 1u);
}



/*
  Рациональное число:
	равно нулю по умолчанию (0/1)
	может быть созданно из целого в формате (n / 1)
	может быть задано с указанием числителя и знаменателя
	хранится в нормализованном виде
	*/

void VerifyRational(const CRational & r, int expectedNumerator, int expectedDenominator)
{
	BOOST_CHECK_EQUAL(r.GetNumerator(), expectedNumerator);
	BOOST_CHECK_EQUAL(r.GetDenominator(), expectedDenominator);
}

BOOST_AUTO_TEST_SUITE(Rational_number)
	BOOST_AUTO_TEST_CASE(is_0_by_default)
	{
		VerifyRational(CRational(), 0, 1);
	}
	BOOST_AUTO_TEST_CASE(can_be_constructed_from_integer)
	{
		VerifyRational(CRational(10), 10, 1);
		VerifyRational(CRational(-10), -10, 1);
		VerifyRational(CRational(0), 0, 1);
	}
	BOOST_AUTO_TEST_CASE(can_be_constructed_with_numerator_and_denominator)
	{
		VerifyRational(CRational(5, 2), 5, 2);
		VerifyRational(CRational(-5, 2), -5, 2);
		VerifyRational(CRational(5, -2), -5, 2);
		VerifyRational(CRational(-5, -2), 5, 2);
	}
	BOOST_AUTO_TEST_CASE(is_normalized_after_construction)
	{
		VerifyRational(CRational(6, 8), 3, 4);
		VerifyRational(CRational(6, -8), -3, 4);
		VerifyRational(CRational(-6, 8), -3, 4);
		VerifyRational(CRational(-6, -8), 3, 4);
		VerifyRational(CRational(-10, 20), -1, 2);
	}
	BOOST_AUTO_TEST_CASE(cant_have_zero_denominator)
	{
		BOOST_REQUIRE_THROW(CRational(1, 0), std::invalid_argument);
	}




//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
// Возвращает отношение числителя и знаменателя в виде числа double
// Пример использования:
//	CRational r(3, 5)
//	cout << r.ToDouble(); // Должно вывести 0.6
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_CASE(can_be_translated_to_double)
	{
		BOOST_CHECK_CLOSE_FRACTION(CRational(7, 8).ToDouble(), 0.875, 0.00001);
		BOOST_CHECK_CLOSE_FRACTION(CRational(8, 5).ToDouble(), 1.6, 0.00001);
		BOOST_CHECK_CLOSE_FRACTION(CRational(0).ToDouble(), 0, 0.00001);
	}



//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
// Указание: см. материалы к лекции
// Пример использования:
//	const CRational r1(3, 5);
//	CRational r2 = -r1; // r2 должно стать -3/5
//	assert(r2.GetNumerator(), -3);
//	assert(r2.GetDenominator(), 5);
//	CRational r3 = +r2; // r3 также равно -3/5
//	assert(r3.GetNumerator(), -3);
//	assert(r3.GetDenominator(), 5);
// Унарный минус возвращает раицональное число без знака
// Унарный плюс возвращает рациональное число, равное текущему
// Реализация не должна допускать операции вроде:
//  -someRational = someOtherRational;
//	+someRational = someOtherRational;
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_CASE(has_unary_plus_that_returns_itself_without_changes)
	{
		VerifyRational(CRational(1, 2), 1, 2);
		VerifyRational(CRational(4, 3), 4, 3);
		VerifyRational(CRational(0), 0, 1);
	}

	BOOST_AUTO_TEST_SUITE(has_unary_minus)

		BOOST_AUTO_TEST_CASE(that_returns_itself_with_inverted_sign)
		{
			VerifyRational(-CRational(7, 8), -7, 8);
			VerifyRational(-CRational(-7, 8), 7, 8);
			VerifyRational(-CRational(7, -8), 7, 8);
			VerifyRational(-CRational(-7, -8), -7, 8);
		}

		BOOST_AUTO_TEST_CASE(that_correctly_handles_0)
		{
			VerifyRational(-CRational(0), +0, 1);
			VerifyRational(-CRational(0), -0, 1);
		}

	BOOST_AUTO_TEST_SUITE_END()



//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный +
// Возвращает результат сложения двух рациональных чисел, 
//	рационального числа с целым, целого числа с рациональным.
//	(1/2) + (1/6) = (2/3)
//	(1/2) + 1     = (3/2)
//	1 + (1/2)     = (3/2)
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_SUITE(has_operation_of_addition)

		BOOST_AUTO_TEST_CASE(with_rational)
			{
				VerifyRational(CRational(1, 2) + CRational(1, 2), 1, 1);
				VerifyRational(CRational(1, 3) + CRational(1, 3), 2, 3);
				VerifyRational(CRational(1, 2) + CRational(1, 6), 2, 3);
				VerifyRational(CRational(1, 6) + CRational(1, 2), 2, 3);
				VerifyRational(CRational(1, 2) + CRational(1, 2), 1, 1);
				VerifyRational(CRational(1, 3) + CRational(1, 3) + CRational(1, 3), 1, 1);
			}

			BOOST_AUTO_TEST_CASE(with_integer)
			{
				VerifyRational(CRational(1, 3) + 1, 4, 3);
				VerifyRational(1 + CRational(1, 3), 4, 3);
			}

			BOOST_AUTO_TEST_CASE(with_0)
			{
				VerifyRational(CRational(0) + CRational(1, 3), 1, 3);
				VerifyRational(CRational(1, 3) + CRational(0), 1, 3);
			}

	BOOST_AUTO_TEST_SUITE_END()



//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
// Возвращает разность двух рациональных чисел, 
//	рационального числа и целого, либо целого числа и рационального:
//	(1/2) - (1/6) = (1/3)
//	(1/2) - 1     = (-1/2)
//	1 - (1/2)     = (1/2)
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_SUITE(has_operation_of_subtraction)
		BOOST_AUTO_TEST_CASE(with_rational)
		{
			VerifyRational(CRational(1, 2) - CRational(1, 2), 0, 1);
			VerifyRational(CRational(1, 2) - CRational(1, 6), 1, 3);
			VerifyRational(CRational(1, 6) - CRational(1, 2), -1, 3);
		}

		BOOST_AUTO_TEST_CASE(with_integer)
		{
			VerifyRational(CRational(1) - CRational(1, 3) - CRational(1, 3), 1, 3);
			VerifyRational(CRational(1, 3) - 1, -2, 3);
			VerifyRational(1 - CRational(1, 3), 2, 3);
		}

		BOOST_AUTO_TEST_CASE(with_0)
		{
			VerifyRational(CRational(0) - CRational(0), 0, 1);
			VerifyRational(CRational(1, 3) - CRational(0), 1, 3);
		}
	BOOST_AUTO_TEST_SUITE_END()



//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
// Выполняет увеличение рационального числа на величину второго рационального,
//	либо целого числа:
//	(1/2) += (1/6)  → (2/3)
//	(1/2) += 1      → (3/2)
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_CASE(has_operation_of_addition_combined_with_assignment)
	{
		CRational rational(8, 1000);
		VerifyRational(rational += rational, 2, 125);
		VerifyRational(rational += rational, 4, 125);

		VerifyRational(CRational(1, 3) += 0, 1, 3);

		VerifyRational(CRational(1, 2) += CRational(1, 6), 2, 3);
		VerifyRational(CRational(1, 2) += 1, 3, 2);
	}



//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
// Выполняет уменьшение рационального числа на величину второго рационального либо целого числа :
// (1/2) -= (1/6)  → (1/3)
// (1/2) -= 1      → (-1/2)
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_CASE(has_operation_of_substraction_combined_with_assignment)
	{
		CRational rational(8, 1000);
		VerifyRational(rational -= rational, 0, 1);
		VerifyRational(rational -= rational, 0, 1);

		VerifyRational(CRational(1, 3) -= 0, 1, 3);

		VerifyRational(CRational(1, 2) -= CRational(1, 6), 1, 3);
		VerifyRational(CRational(1, 2) -= 1, -1, 2);
	}




//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
// Возвращает результат произведения рациональных чисел, 
//	рационального и целого, либо целого и рационального :
//	(1/2) * (2/3) = (1/3)
//	(1/2) * (-3)  = (-3/2)
//	7 * (2/3)     = (14/3)
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_CASE(has_operation_of_multiplication)
	{
		VerifyRational(CRational(1, 3) * 0, 0, 1);
		VerifyRational(0 * CRational(1, 3), 0, 1);

		VerifyRational(CRational(1, 6) * 2, 1, 3);
		VerifyRational(2 * CRational(1, 6), 1, 3);

		VerifyRational(CRational(1, 6) * -2, -1, 3);
		VerifyRational(-2 * CRational(1, 6), -1, 3);

		VerifyRational(CRational(3, 6) * CRational(3, 5), 3, 10);
		VerifyRational(CRational(3, 5) * CRational(3, 6), 3, 10);
	}




//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
// Возвращает частное двух рациональных чисел, 
//	рационального и целого, целого и рационального :
//	(1/2) ⁄ (2/3) = (3/4)
//	(1/2) ⁄ 5     = (1/10)
//	7 ⁄ (2/3)     = (21/2)
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_CASE(has_operation_of_division)
	{
		VerifyRational(CRational(1, 6) / 2, 1, 12);
		VerifyRational(2 / CRational(1, 6), 12, 1);

		VerifyRational(CRational(1, 6) / -2, -1, 12);
		VerifyRational(-2 / CRational(1, 6), -12, 1);

		VerifyRational(CRational(3, 6) / CRational(3, 5), 5, 6);
		VerifyRational(CRational(3, 5) / CRational(3, 6), 6, 5);
	}




//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
// Умножает значение первого рационального числа на другое рациональное, 
//	либо целое:
//	(1/2) *= (2/3) → (1/3)
//	(1/2) *= 3     → (3/2)
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_CASE(has_operation_of_multiplication_combined_with_assignment)
	{
		VerifyRational(CRational(1, 3) *= 0, 0, 1);

		VerifyRational(CRational(1, 2) *= CRational(1, 6), 1, 12);
		VerifyRational(CRational(1, 2) *= 1, 1, 2);

		CRational rational(2, 3);
		VerifyRational(rational *= rational, 4, 9);
		VerifyRational(rational *= rational, 16, 81);

	}




//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
// Делит первое рациональное число на другое рациональное, 
//	либо целое:
//	(1/2) /= (2/3) → (3/4)
//	(3/4) /= (3/8) → (2/1)
//	(1/2) /= 3     → (1/6)
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_CASE(has_operation_of_division_combined_with_assignment)
	{
		VerifyRational(CRational(1, 2) /= CRational(2, 3), 3, 4);
		VerifyRational(CRational(1, 2) /= 1, 1, 2);

		VerifyRational(CRational(1, 2) /= CRational(1, 2), 1, 1);
	}

	BOOST_AUTO_TEST_CASE(cant_be_divided_on_0)
	{
		BOOST_REQUIRE_THROW(CRational(1, 1) / 0, std::invalid_argument);
		BOOST_REQUIRE_THROW(CRational(1, 1) /= CRational(1, 0), std::invalid_argument);
	}


//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
// Проверяют равенство (и неравенство) двух рациональных чисел, 
//	целого и рационального, рационального и целого:
//	(1/2) == (1/2) → true
//	(4/1) == 4     → true
//	3 == (3/1)     → true
//	(1/2) != (2/3) → true
//	(1/2) != 7     → true
//	3 != (2/3)     → true
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_SUITE(can_be_checked_for_equality)
		BOOST_AUTO_TEST_CASE(with_rational)
		{
			BOOST_CHECK(CRational(1, 2) == CRational(1, 2));
			BOOST_CHECK(!(CRational(1, 2) == CRational(3, 2)));
			BOOST_CHECK(CRational(-3, 2) != CRational(3, 2));
			BOOST_CHECK(!(CRational(1, 2) != CRational(2, 4)));
		}
		BOOST_AUTO_TEST_CASE(with_integer)
		{
			BOOST_CHECK(CRational(2, 1) == 2);
			BOOST_CHECK(!(CRational(1, 2) == 1));
			BOOST_CHECK(CRational(-3, 1) != 3);
			BOOST_CHECK(!(CRational(-4, 1) != -4));
		}
	BOOST_AUTO_TEST_SUITE_END()



//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
// Сравнивают два рациональных числа, рациональное с целым, 
//	целое с рациональным:
//	(1/2) >= (1/3) → true
//	(1/2) <= (1/3) → false
//	(3/1) > 2      → true
//	(1/2) < 7      → true
//	3 <= (7/2)     → true
//	3 >= (8/2)     → false
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_SUITE(can_be_compared_with_operator_smaller)
		BOOST_AUTO_TEST_CASE(with_rational)
		{
			BOOST_CHECK(CRational(1, 3) < CRational(1, 2));
			BOOST_CHECK(!(CRational(1, 3) < CRational(1, 3)));
			BOOST_CHECK(!(CRational(1, 3) < CRational(1, 4)));

		}
		
		BOOST_AUTO_TEST_CASE(with_integer)
		{
			BOOST_CHECK(CRational(1, 3) < 1);
			BOOST_CHECK(!(CRational(1, 1) < 1));
			BOOST_CHECK(!(CRational(3, 2) < 1));
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(can_be_compared_with_operator_bigger)
		BOOST_AUTO_TEST_CASE(with_rational)
		{
			BOOST_CHECK(CRational(1, 2) > CRational(1, 3));
			BOOST_CHECK(!(CRational(1, 2) > CRational(1, 2)));
			BOOST_CHECK(!(CRational(1, 3) > CRational(1, 2)));
		}

		BOOST_AUTO_TEST_CASE(with_integer)
		{
			BOOST_CHECK(1 > CRational(1, 2));
			BOOST_CHECK(!(CRational(1, 1) > 1));
			BOOST_CHECK(!(CRational(3, 2) > 3));
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(can_be_compared_with_operator_less_or_equal)
		BOOST_AUTO_TEST_CASE(with_rational)
		{
			BOOST_CHECK(CRational(1, 3) <= CRational(1, 2));
			BOOST_CHECK(CRational(1, 3) <= CRational(1, 3));
			BOOST_CHECK(!(CRational(1, 3) <= CRational(1, 4)));
		}

		BOOST_AUTO_TEST_CASE(with_integer)
		{
			BOOST_CHECK(CRational(1, 3) <= 1);
			BOOST_CHECK(CRational(1, 1) <= 1);
			BOOST_CHECK(!(CRational(3, 2) <= 1));
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(can_be_compared_with_operator_greater_or_equal)
		BOOST_AUTO_TEST_CASE(with_rational)
		{
			BOOST_CHECK(CRational(1, 2) > CRational(1, 3));
			BOOST_CHECK(!(CRational(1, 2) > CRational(1, 2)));
			BOOST_CHECK(!(CRational(1, 3) > CRational(1, 2)));
		}

		BOOST_AUTO_TEST_CASE(with_integer)
		{
			BOOST_CHECK(1 >= CRational(1, 2));
			BOOST_CHECK(CRational(1, 1) >= 1);
			BOOST_CHECK(!(CRational(3, 2) >= 3));
		}
	BOOST_AUTO_TEST_SUITE_END()

//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//	std::ostream в формате <числитель>/<знаменатель>, 
//	например: 7/15
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_CASE(can_be_writed_to_ostream)
	{
		{
			std::ostringstream output;
			output << CRational(-3, 14);
			BOOST_CHECK_EQUAL(output.str(), "-3/14");
		}
		{
			std::ostringstream output;
			output << "Rational = " << CRational(1, 14) << ".";
			BOOST_CHECK_EQUAL(output.str(), "Rational = 1/14.");
		}
		{
			std::ostringstream output;
			output << CRational(4);
			BOOST_CHECK_EQUAL(output.str(), "4/1");
		}
	}



//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//	std::istream в формате <числитель>/<знаменатель>, 
//	например: 7/15
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_CASE(can_be_readed_from_istream)
	{
		{
			CRational rational;

			std::istringstream input("0");
			input >> rational;
			VerifyRational(rational, 0, 1);
		}
		{
			CRational rational;

			std::istringstream input("7/15");
			input >> rational;
			VerifyRational(rational, 7, 15);
		}
		{
			CRational rational;

			std::istringstream input("-1/1");
			input >> rational;
			VerifyRational(rational, -1, 1);
		}
		{
			CRational rational;

			std::istringstream input("not numeric string");
			input >> rational;
			BOOST_CHECK(input.fail());
		}
	}


BOOST_AUTO_TEST_SUITE_END()
