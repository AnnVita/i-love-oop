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
	������������ ��������� ������� CountIf(first, last, pred), ������������ ���������� ���������
	� ��������� [first, last), ��� ������� �������� pred �������.
	first � last - ���������, �������� ��������� � �������� ������� ������������������ ���������.
	�������� [first, last) �������� � ���� ��� �������� ����� first � last, ������� ������� � ������� first,
	� �� ������� ������� � ������� last
	pred - ������� �������-��������, ���������� ������� �������� ������� �� ���������
	������� ���������� ��������, ������� ����� ���� ������������� � ���� bool
	������� �� ������ ������ ����� ����������
	� �������� ��������� ����� �������� ��������� �� �������, �������������� ������, ���� lambda-���������
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
	//assert(evenNumbersCount == 4); // ���������� ������ �����

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
	//����������� � ������� ������� CountIf ���������� ������ ����� ��������� (���� Student),
	//������������ � ��������� std::list:
	//���� ���� (�)
	//������ �������� (�)
	//�������� ��������� (�)
	//����� ����� (�)
	//��� ����� (�)
	//������ �������� (�)
	//���� ����� (�)
	//������ �������� (�)
	//���� ����� (�)
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