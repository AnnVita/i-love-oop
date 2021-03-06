#include "stdafx.h"
#include "../MyArray/MyArray.h"

using namespace std;

struct ArrayItem
{
	ArrayItem(int value = 0) : value(value)
	{}
	int value;
};

struct EmptyStringArray
{
	CMyArray<ArrayItem> arr;
};

BOOST_FIXTURE_TEST_SUITE(MyArray, EmptyStringArray)
	BOOST_AUTO_TEST_SUITE(by_default)
		BOOST_AUTO_TEST_CASE(is_empty)
		{
			BOOST_CHECK_EQUAL(arr.GetSize(), 0u);
		}
		BOOST_AUTO_TEST_CASE(has_0_capacity)
		{
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 0u);
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(after_appending_an_item)
		BOOST_AUTO_TEST_CASE(increases_its_size_and_capacity)
		{
			arr.Append(ArrayItem());
			BOOST_CHECK_EQUAL(arr.GetSize(), 1u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 1u);
			arr.Append(ArrayItem());
			BOOST_CHECK_EQUAL(arr.GetSize(), 2u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 2u);
			arr.Append(ArrayItem());
			BOOST_CHECK_EQUAL(arr.GetSize(), 3u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 4u);
			arr.Append(ArrayItem());
			BOOST_CHECK_EQUAL(arr.GetSize(), 4u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 4u);
		}
		BOOST_AUTO_TEST_CASE(it_becomes_available_at_the_back)
		{
			arr.Append(1);
			BOOST_CHECK_EQUAL(arr.GetBack().value, 1);
			arr.Append(2);
			BOOST_CHECK_EQUAL(arr.GetBack().value, 2);
			arr.Append(3);
			BOOST_CHECK_EQUAL(arr.GetBack().value, 3);
			arr.Append(4);
			BOOST_CHECK_EQUAL(arr.GetBack().value, 4);
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(after_copy_construction)
		BOOST_AUTO_TEST_CASE(has_size_capacity_equal_to_size_of_original_array)
		{
			for (auto i = 0; i < 6; ++i)
			{
				arr.Append(i);
			}
			BOOST_CHECK_NE(arr.GetSize(), arr.GetCapacity());

			auto copy(arr);
			BOOST_CHECK_EQUAL(copy.GetSize(), arr.GetSize());
			BOOST_CHECK_EQUAL(copy.GetCapacity(), arr.GetSize());
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(has_indexed_access)
		BOOST_AUTO_TEST_CASE(that_returns_element_by_index)
		{
			for (auto i = 0; i < 3; ++i)
			{
				arr.Append(i);
			}
			BOOST_CHECK_EQUAL(arr[2].value, 2);

			const CMyArray<ArrayItem> newArr(arr);
			BOOST_CHECK_EQUAL(newArr[0].value, 0);
			BOOST_CHECK_EQUAL(newArr[1].value, 1);
			BOOST_CHECK_EQUAL(newArr[2].value, 2);
		}
		BOOST_AUTO_TEST_CASE(or_throws_out_of_range)
		{
			for (auto i = 0; i < 6; ++i)
			{
				arr.Append(i);
			}
			BOOST_CHECK_THROW(arr[7], std::out_of_range);
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(after_resize)
		BOOST_AUTO_TEST_CASE(can_be_decreased)
		{
			for (auto i = 0; i < 6; ++i)
			{
				arr.Append(i);
			}
			size_t prevSize = arr.GetSize();
			arr.Resize(prevSize - 3);
			BOOST_CHECK(arr.GetSize() < prevSize);
		}
		BOOST_AUTO_TEST_CASE(can_be_increased)
		{
			size_t prevSize = arr.GetSize();
			arr.Resize(prevSize + 3);
			BOOST_CHECK(arr.GetSize() > prevSize);
			BOOST_CHECK_EQUAL(arr[0].value, 0);
			BOOST_CHECK_EQUAL(arr[1].value, 0);
			BOOST_CHECK_EQUAL(arr[2].value, 0);
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_CASE(can_be_assigned)
	{
		for (auto i = 0; i < 3; ++i)
		{
			arr.Append(i);
		}
		CMyArray<ArrayItem> newArr = arr;
		BOOST_CHECK_EQUAL(newArr[0].value, 0);
		BOOST_CHECK_EQUAL(newArr[1].value, 1);
		BOOST_CHECK_EQUAL(newArr[2].value, 2);
	}
	BOOST_AUTO_TEST_SUITE(after_clearing)
		BOOST_AUTO_TEST_CASE(has_no_size)
		{
			arr.Clear();
			BOOST_CHECK_EQUAL(arr.GetSize(), 0);
		}
		BOOST_AUTO_TEST_CASE(has_no_elements)
		{
			arr.Clear();
			BOOST_CHECK_THROW(arr[0], std::out_of_range);
		}
		BOOST_AUTO_TEST_CASE(empty)
		{
			arr.Append(2);
			arr.Append(1);
			arr.Clear();
			BOOST_CHECK_EQUAL(arr.GetSize(), 0u);
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_CASE(can_be_moved)
    {
		for (auto i = 0; i < 3; ++i)
		{
			arr.Append(i);
		}
		CMyArray<ArrayItem> newArr;
		newArr = CMyArray<ArrayItem>(arr);
		BOOST_CHECK_EQUAL(newArr[0].value, 0);
		BOOST_CHECK_EQUAL(newArr[1].value, 1);
		BOOST_CHECK_EQUAL(newArr[2].value, 2);
    }
BOOST_AUTO_TEST_SUITE_END()