/* ����������� ��������� (Copy Constructor) */

// ����������� ��������� - �� ����������� �����������, ���� ������� ����� ��'��� �� ���� ��������� ��'����.
// ³� �����������, ���� ��'��� ���������� �� ��������� ��� ������������ ����� ��'����� ���� � ����.
// ��������� ����������� ������� ����������� ���������, ���� �� �� ��������� ���� ���������.
// ������������ ����������� ��������� ������ "����������" ���������, �� ���� ��������� �� ������� � �������� �������� ���'����.

#include <iostream>
#include <Windows.h>

class Point {
private:
	double x, y;
public:
	Point(double x = 0, double y =0) : x(x), y(y) {
		std::cout << "������ ������������: (" << x << ", " << y << ")\n";
	}

	Point(const Point& other) {
		this->x = other.x;
		this->y = other.y;
	}

	void Print() const {
		std::cout << "Point(" << x << ", " << y << ")\n";
	}
};

class Person {
private:
	char* name;
	int age;
public:
	Person() : name(nullptr), age(0) {
		std::cout << "������ ������������ �� �������������\n";
	}
	Person(const char* name, int age) : age(age) {
		std::cout << "������ ������������ � �����������: " << name << ", " << age << "\n";
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	Person(const Person& other) : age(other.age) {
		std::cout << "������ ������������ ��������� ���: " << other.name << "\n";
		if (other.name) {
			name = new char[strlen(other.name) + 1];
			strcpy_s(name, strlen(other.name) + 1, other.name);
		} else {
			name = nullptr;
		}
	}
	~Person() {
		if (name) {
			delete[] name;
			std::cout << "���������� ��������� ���: " << name << "\n";
		}
	}

	void Print() const {
		if (name) {
			std::cout << "Person: " << name << ", Age: " << age << "\n";
		} else {
			std::cout << "Person: Unknown, Age: " << age << "\n";
		}
	}
};

int main()
{
	SetConsoleOutputCP(1251);

	{
		Point p1(3.0, 4.0); // ������ ������������
		
		Point p2(p1); // ������ ������������ ���������
		Point p3 = p1; // ����� ������� ����������� ���������

		std::cout << "p1: ";
		p1.Print();
		std::cout << "p2: ";
		p2.Print();
	}

	{
		Person person1("Alice", 30); // ������ ������������ � �����������
		Person person2 = person1; // ������ ������������ ��������� - �������� ���������

		person1.Print();
		person2.Print();
	}
}