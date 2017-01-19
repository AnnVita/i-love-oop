#include "stdafx.h"
#include "countif.h"
#include <iostream>

using namespace std;

class SmartPtr
{
public:
	SmartPtr() = default;

	SmartPtr(string * ptr)
	{
		m_ptr = ptr;
	}

	~SmartPtr()
	{
		delete(m_ptr);
		cout << "deleted" << std::endl;
	}

	bool IsEmpty() const
	{
		return m_ptr == nullptr;
	}

	string & operator *() const 
	{ 
		return *m_ptr;
	}

	SmartPtr & operator=(SmartPtr const & r) = delete;
	SmartPtr(const SmartPtr &) = delete;

	string * operator ->() const
	{
		return m_ptr;
	}

private:
	string * m_ptr = nullptr;
};

bool IsEven(int x)
{
	return (x % 2) == 0;
}

enum class Gender
{
	MALE,
	FEMALE
};

struct Student
{
	string name;
	Gender gender;
};

int main()
{
	{
		SmartPtr ptr;
		cout << ptr.IsEmpty() << std::endl;
	}

	{
		auto stringPtr = new string("hello");
		SmartPtr ptr(stringPtr);
		cout << ptr.IsEmpty() << std::endl;
		cout << *ptr << std::endl;
		cout << "Size of string: " << ptr->size() << std::endl;
	}

	/*
	Разработайте шаблонную функцию CountIf(first, last, pred), возвращающую количество элементов
	в диапазоне [first, last), для которых значение pred истинно.
	first и last - итераторы, задающие начальную и конечную позиции последовательности элементов.
	Диапазон [first, last) включает в себя все элементы между first и last, включая элемент в позиции first,
	и не включая элемент в позиции last
	pred - унарная функция-предикат, аргументом которой является элемент из диапазона
	Функция возвращает значение, которое может быть преобразовано к типу bool
	Функция не должна менять своих аргументов
	В качестве параметра можно передать указатель на функцию, функциональный объект, либо lambda-выражение
	*/
	//CMyClass::f();

	//string fileNames[] = { "Lecture 1.docx", "Report1.xlsx", "Report 2.xlsx", "hometask.cpp" };

	//size_t numberOfExcelFiles = CountIf(begin(fileNames), end(fileNames), [](const string & name) {
	//	string ext = ".xlsx";
	//	return (name.length() > ext.length()) && (name.substr(name.length() - ext.length()) == ext);
	//});
	//assert(numberOfExcelFiles == 2);

	//vector<int> numbers = { 3, 8, 17, -4, 16, 24, 5 };
	//size_t evenNumbersCount = CountIf(numbers.begin(), numbers.end(), IsEven);
	//assert(evenNumbersCount == 4); // Количество четных чисел

	//list<Student> starngeStudents = { {"John Snow", Gender::MALE}, 
	//						 { "Tirion Lannister", Gender::MALE },
	//						 { "Daineris Targarien", Gender::FEMALE },
	//						 { "Sansa Stark", Gender::FEMALE }, 
	//						 { "Ned Stark", Gender::MALE },
	//						 { "Sersey Lannister", Gender::FEMALE },
	//						 { "Aria Stark", Gender::FEMALE },
	//						 { "Joffrey Baratheon", Gender::MALE },
	//						 { "Khal Drogo", Gender::MALE }};
	///*
	//Подсчитайте с помощью функции CountIf количество мужчин среди студентов (типа Student),
	//содержащихся в контейнер std::list:
	//Джон Сноу (м)
	//Тирион Ланистер (м)
	//Дайнерис Таргариен (ж)
	//Санса Старк (ж)
	//Нэд Старк (м)
	//Серсея Ланистер (ж)
	//Арья Старк (ж)
	//Джофри Баратеон (м)
	//Кхал Дрого (м)
	//*/
	//size_t numberOfMaleStudents = CountIf(starngeStudents.begin(), starngeStudents.end(), [](const auto& student) {
	//	return (student.gender == Gender::MALE);
	//});

	//assert(numberOfMaleStudents == 5);

	//vector<int> empty{};
	//size_t handleEmptyVector = CountIf(empty.begin(), empty.end(), IsEven);

	//assert(handleEmptyVector == 0);

	return 0;
}