/* ������� ����� ����� (Static members) */

// ������� ����� ����� - �� �����, �� ����� ��� ��� ��'���� �����.
// ���� ����������� � ���'�� ���� ���� ���, ��������� �� ������� ��'���� �����.
// ���� ��� ���� ��������� �����: 
// - ������� ����
// - ������� ������.

#include <iostream>
#include <Windows.h>

// ���� � ��������� �����
class User {
private:
	int id;   // ��������� ������������� �����������
    char* name;
public:
	// public ����� ��� �������� ������ ���������� ����
    static int nextId; // �������� ���� ��� ��������� ���������� ID

    User(const char* name) : 
        id(nextId++), // ���������� id �� �������� ��������
        name(new char[strlen(name) + 1]) {
        strcpy_s(this->name, strlen(name) + 1, name);
	}
    ~User() {
        delete[] name; // ��������� ���'���
	}

    void ShowInfo() const {
        std::cout << "ID: " << id << ", ��'�: " << name << std::endl;
	}

    // ��������� ����� ��� ��������� ���������� ID
    static int GetNextId() {
        //std::cout << this.name // ��������� ����� �� ���� ��������������� this

		return nextId; 
    }
};



// ����������� ���������� ����4
int User::nextId = 1; 

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    {
        // ��������� ���� ������������
        User user1("VibeCoder3000");
		std::cout << "User 1:\n";
		user1.ShowInfo(); // �������� ���������� ��� ������� �����������
        
		std::cout << "��������� ID: " << User::GetNextId() << '\n'; // �������� ��������� ID

        User user2("������ ���");
		std::cout << "User 2:\n";
		user2.ShowInfo(); // �������� ���������� ��� ������� �����������

        std::cout << "��������� ID: " << User::GetNextId() << '\n'; // �������� ��������� ID

		// ��������� �� ���������� ���� ����� ��'���
		std::cout << "������ ����� ��'��� user1: " << user1.GetNextId() << '\n';
		std::cout << "������ ����� ��'��� user2: " << user2.GetNextId() << '\n';

		// ������ ���������� ���� ��� ������ ����� ��'��� - ������ ��������
        std::cout << "������ ����� ��'��� user1: " << &(user1.nextId) << '\n';
        std::cout << "������ ����� ��'��� user2: " << &(user2.nextId) << '\n';
    }
}