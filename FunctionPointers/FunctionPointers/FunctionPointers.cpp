#include <iostream>
#include <Windows.h>

using namespace std;

void Foo() {
    // ����� �������
}

int sum(int, int);

double sum(double, double);
double substruct(double, double);
double multiply(double, double);
double divide(double, double);

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "������ ������� Foo: " << Foo << endl;

    // ����� ������� ����� ��������� ����'�����
    // ��� ����� ��������� ����������� ����� 
    // �� �������� �������, �� ������� �������� �� int
    int (*sumptr) (int, int) = sum;

    // ������ ������� ����� ��������
    cout << sumptr(10, 12) << endl;


    // ����� ��������� �� �������, 
    // �� ���������� ��� double �� ��������� ��� ��������� ���� double
    double (*calcptr[])(double, double) = { sum, substruct, multiply, divide };

    double a, b;
    int choice;

    cout << "������ ����� a: ";
    cin >> a;
    cout << "������ ����� b: ";
    cin >> b;

    cout << "������ ��������:\n";
    cout << "1. ����\n";
    cout << "2. г�����\n";
    cout << "3. �������\n";
    cout << "4. ĳ�����\n";
    cout << "������ ����� ��������: ";
    cin >> choice;

    cout << (*calcptr[choice - 1])(a, b) << "\n";

    // auto �� decltype
    auto a1 = 0; //int
    decltype (a1) a2 = a1; // �� ����, �� � auto a2=a1;
    typedef decltype (a1) �TYPE; //�TYPE � �������� int
    ATYPE �3 = 5;

}

int sum(int a, int b) {
    return a + b;
}

double sum(double a, double b) {
    return a + b;
}

double substruct(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) return NULL;
    return a / b;
}
