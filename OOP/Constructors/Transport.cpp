#include <iostream>
using namespace std;

class Transport {
public:
	Transport()
	{
		cout << "����������� ����� Transport\n";
	}
	~Transport() {
		cout << "���������� ����� Transport\n";
	}
};

class Car : public Transport {
public:
	Car()
	{
		cout << "����������� ����� Car\n";
	}
	~Car() {
		cout << "���������� ����� Car\n";
	}
};

class Truck : public Car {
public:
	Truck()
	{
		cout << "����������� ����� Truck\n";
	}
	~Truck() {
		cout << "���������� ����� Truck\n";
	}
};