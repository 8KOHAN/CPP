/*
* 
����������� - ����������� ����� �����, ���� ����������� ����������� ��� �������� �ᒺ��� �� 
������������ �� ����������� ���� ����������� ����� (����).
*/

#include <iostream>
#include <Windows.h>
#include "Monkey.cpp"
#include "Dog.cpp"
#include "Transport.cpp"
#include "Student.h"

int main()
{
    SetConsoleOutputCP(1251);

    {
        // ������ ������������ ��� ���������
        Monkey monkey;

        cout << "Name: " << monkey.GetName() << '\n';
        cout << "Age: " << monkey.GetAge() << '\n';
    }

    {
        char name[] = "Koko";
        // ������ ������������ � �����������
        Monkey monkey(name);

        cout << "Name: " << monkey.GetName() << '\n';
        cout << "Age: " << monkey.GetAge() << '\n';
    }

    {
        char name[] = "Evil Monkey";
        int age = 15;
        // ������ ������������ � �����������
        Monkey monkey(name, age);

        cout << "Name: " << monkey.GetName() << '\n';
        cout << "Age: " << monkey.GetAge() << '\n';
    }

    {
        // ������������ �� ����������� 
        // ���������� ���������
        Dog dog;

        // ���� �� �������������!
        // ����: �����!
        cout << dog.GetName() << '\n';
    }

    {
        // ��������� ��'����
        // ������ ������������
        Truck truck;
    }

    {
        char name1[] = "����";
        char name2[] = "������";
        Monkey mn1(name1);
        Monkey* mn2 = new Monkey(name2);

        // ������ ����������� ����� delete
        delete mn2;
        // ���������� ��� mn1 ����������� ����������� 
        // ��� ����� � ������ ��������
    }

    {
        char name[] = "����� �������";
        int grades[] = { 4, 6, 10, 5, 1 };
        Student student(name, grades, 5);

        cout << "������� ������ �������� " 
            << student.GetName() << ": " 
            << student.avgGrade() << '\n';
    }

    {
        // ������������ ��������� �� ��'��� (�����)
        int size = 3;
        int g1[] = { 5, 6, 2 };
        int g2[] = { 10, 4, 5 };
        int g3[] = { 10, 11, 12 };

        Student* students = new Student[size]
        {
            { "����� �������", g1, 3 },
            { "����� �����", g2, 3 },
            { "³���� ������", g3, 3 }
        };

        for (int i = 0; i < size; i++) {
            cout << "������� ������ �������� "
                << students[i].GetName() << ": "
                << students[i].avgGrade() << '\n';
        }

        delete[] students;
    }
}