#include "stdafx.h"
#include "../Car/car.h"

struct CarFixture
{
	CCar car;
};

BOOST_FIXTURE_TEST_SUITE(Car, CarFixture)

    BOOST_AUTO_TEST_SUITE(when_the_newly_constructed)

		BOOST_AUTO_TEST_CASE(engine_is_turned_off_by_default)
		{
			BOOST_CHECK(!car.IsTurnedOn());
		}

		BOOST_AUTO_TEST_CASE(speed_is_zero_by_default)
		{
			BOOST_CHECK(car.GetSpeed() == 0);
		}

		BOOST_AUTO_TEST_CASE(direction_is_NONE_by_default)
		{
			BOOST_CHECK(car.GetDirection() == Direction::NONE);
		}

		BOOST_AUTO_TEST_CASE(gear_is_NEUTRAL_by_default)
		{
			BOOST_CHECK(car.GetGear() == Gear::NEUTRAL);
		}
	BOOST_AUTO_TEST_SUITE_END()


	BOOST_AUTO_TEST_SUITE(if_car_engine_is_turned_off)
		BOOST_AUTO_TEST_CASE(engine_can_be_turned_on)
		{
			BOOST_CHECK(car.TurnOnEngine());
		}

		BOOST_AUTO_TEST_CASE(engine_cannot_be_turned_off_when_it_already_off)
		{
			BOOST_CHECK(!car.TurnOffEngine());
		}

		BOOST_AUTO_TEST_CASE(impossible_to_change_speed_when_engine_off)
		{
			BOOST_CHECK(!car.SetSpeed(20));
		}

		BOOST_AUTO_TEST_CASE(impossible_to_change_gear_when_engine_off)
		{
			BOOST_CHECK(!car.SetGear(Gear::FIRST));
		}

	BOOST_AUTO_TEST_SUITE_END()

	struct when_engine_turned_on_ : CarFixture
	{
		when_engine_turned_on_()
		{
			car.TurnOnEngine();
		}
	};

	BOOST_FIXTURE_TEST_SUITE(when_engine_turned_on, when_engine_turned_on_)
		BOOST_AUTO_TEST_CASE(speed_is_zero_immediately_after_turning_on)
		{
			BOOST_CHECK(car.GetSpeed() == 0);
		}

		BOOST_AUTO_TEST_CASE(direction_is_NONE_immediately_after_turning_on)
		{
			BOOST_CHECK(car.GetDirection() == Direction::NONE);
		}

		BOOST_AUTO_TEST_CASE(gear_is_NEUTRAL_immediately_after_turning_on)
		{
			BOOST_CHECK(car.GetGear() == Gear::NEUTRAL);
		}

		BOOST_AUTO_TEST_CASE(engine_can_be_turned_off_immediately_after_turning_on)
		{
			BOOST_CHECK(car.TurnOffEngine());
		}

		BOOST_AUTO_TEST_CASE(gear_can_be_changed_to_REVERSE_immediately_after_turning_on)
		{
			BOOST_CHECK(car.SetGear(Gear::REVERSE));
		}

		BOOST_AUTO_TEST_CASE(gear_can_be_changed_to_FIRST_immediately_after_turning_on)
		{
			BOOST_CHECK(car.SetGear(Gear::FIRST));
		}

		BOOST_AUTO_TEST_CASE(gear_cant_be_changed_for_more_than_FIRST_gear_value_immediately_after_turning_on)
		{
			BOOST_CHECK(!car.SetGear(Gear::SECOND));
		}

		BOOST_AUTO_TEST_CASE(engine_cannot_be_turned_on_when_it_already_on)
		{
			BOOST_CHECK(!car.TurnOnEngine());
		}

		BOOST_AUTO_TEST_CASE(impossible_to_change_speed_to_negative_value)
		{
			BOOST_CHECK(!car.SetSpeed(-2));
		}

		BOOST_AUTO_TEST_CASE(impossible_to_accelerate_if_gear_is_NEUTRAL)
		{
			BOOST_CHECK(!car.SetSpeed(20));
		}

		BOOST_AUTO_TEST_CASE(gear_can_be_changed_to_REVERSE_if_speed_is_zero_and_gear_is_NEUTRAL)
		{
			BOOST_CHECK(car.GetSpeed() == 0);
			BOOST_CHECK(car.SetGear(Gear::REVERSE));
		}

		BOOST_AUTO_TEST_CASE(gear_can_be_changed_to_FIRST_from_NEUTRAL)
		{
			BOOST_CHECK(car.SetGear(Gear::FIRST));
		}

		BOOST_AUTO_TEST_CASE(accelerate_if_gear_is_not_NEUTRAL)
		{
			BOOST_CHECK(car.SetGear(Gear::FIRST));
			BOOST_CHECK(car.SetSpeed(30));
			BOOST_CHECK(car.GetSpeed() == 30);
		}

		BOOST_AUTO_TEST_CASE(slow_down_if_gear_is_not_NEUTRAL)
		{
			BOOST_CHECK(car.SetGear(Gear::FIRST));
			BOOST_CHECK(car.SetSpeed(30));
			BOOST_CHECK(car.GetSpeed() == 30);
			BOOST_CHECK(car.SetSpeed(10));
			BOOST_CHECK(car.GetSpeed() == 10);
		}

		BOOST_AUTO_TEST_CASE(slow_down_if_gear_NEUTRAL)
		{
			BOOST_CHECK(car.SetGear(Gear::FIRST));
			BOOST_CHECK(car.SetSpeed(30));
			BOOST_CHECK(car.GetSpeed() == 30);
			BOOST_CHECK(car.SetGear(Gear::NEUTRAL));
			BOOST_CHECK(car.SetSpeed(10));
			BOOST_CHECK(car.GetSpeed() == 10);
		}

		BOOST_AUTO_TEST_CASE(impossible_accelerate_to_the_appropriate_gear_speed)
		{
			BOOST_CHECK(car.SetGear(Gear::FIRST));
			BOOST_CHECK(!car.SetSpeed(50));
		}

		BOOST_AUTO_TEST_CASE(impossible_slow_down_to_the_appropriate_gear_speed)
		{
			BOOST_CHECK(car.SetGear(Gear::FIRST));
			BOOST_CHECK(car.SetSpeed(30));
			BOOST_CHECK(car.SetGear(Gear::SECOND));
			BOOST_CHECK(!car.SetSpeed(19));
		}

		BOOST_AUTO_TEST_CASE(impossible_change_gear_to_REVERSE_if_speed_is_not_zero)
		{
			BOOST_CHECK(car.SetGear(Gear::FIRST));
			BOOST_CHECK(car.SetSpeed(30));
			BOOST_CHECK(!car.SetGear(Gear::REVERSE));
		}

	BOOST_AUTO_TEST_SUITE_END();

	

BOOST_AUTO_TEST_SUITE_END()