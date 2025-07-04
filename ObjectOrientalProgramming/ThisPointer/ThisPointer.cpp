/* �������� this */

#include <iostream>

class Student {
private:
    char* name;
    char* groupName;
    int age;
public:
	Student() : name(nullptr), groupName(nullptr), age(0) {}

    Student(const char* name, const char* groupName, int age)
    {
		// ������������ 'this' ��� ������� �� ����� �����
		this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
        this->groupName = new char[strlen(groupName) + 1];
        strcpy_s(this->groupName, strlen(groupName) + 1, groupName);
		this->age = age;
    }

    //void setThis(Student student) {
		//this = &student; // �� �� ��������, 'this' �� ���� ���� ������
    //}

    Student& SetAge(int age) {
		// ������������ 'this' ��� ������� �� ����� ����� - �������� �������� ����
        this->age = age;
		return *this; // ��������� ��������� �� �������� ��'���
	}
    Student& SetName(const char* name) {
        // ������������ 'this' ��� ������� �� ����� �����
        if (this->name) {
            delete[] this->name;
        }
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
		return *this; // ��������� ��������� �� �������� ��'���
	}
    Student& SetGroupName(const char* groupName) {
        // ������������ 'this' ��� ������� �� ����� �����
        if (this->groupName) {
            delete[] this->groupName;
        }
        this->groupName = new char[strlen(groupName) + 1];
        strcpy_s(this->groupName, strlen(groupName) + 1, groupName);
		return *this; // ��������� ��������� �� �������� ��'���
	}

    void print() {
        std::cout << "Name: " << name << ", Group: " << groupName << ", Age: " << age << std::endl;
    }
};

int main()
{
	Student student;

    student.SetName("John Doe").SetGroupName("CS101").SetAge(20);

	student.print();


}
