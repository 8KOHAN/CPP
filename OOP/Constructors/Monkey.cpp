#include <iostream>

using namespace std;

class Monkey {
private:
	char name[50];
	int age;
public:
	// ����������� ��� ���������
	Monkey() {
		// ����������� ���� ������������ ����������
		strcpy_s(name, 50, "Mr. Teeny");
		age = 10;
	}
	// ����������� � �����������
	Monkey(char* n) {
		SetName(n);
		age = 10;
	}
	// �������������� ����������� � �����������
	Monkey(char* n, int age) {
		SetName(n);
		SetAge(age);
	}

	~Monkey() {
		cout << name << " ���� � ������ ���.\n";
	}

	// ������������
	void SetName(char* value) {
		if (value != nullptr)
			strcpy_s(name, 50, value);
		else
			strcpy_s(name, 50, "Mr. Teeny");
	}
	void SetAge(int value) {
		if (value >= 0)
			age = value;
		else
			age = 10;
	}

	// ����������
	char* GetName() {
		return name;
	}
	int GetAge() {
		return age;
	}
};