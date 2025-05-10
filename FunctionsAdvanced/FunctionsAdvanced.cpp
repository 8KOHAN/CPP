#include <iostream>
#include <Windows.h>

using namespace std;

// ��������� ��������������
// ������, �� ������ ��������� � ���� ������������ ���� ������� �������������
#define SQR(X) ((X) * (X))
#define CUBE(X) (SQR(X) * (X))

// ���������� ��������� ������� - ���� ���������� � ���� ������� �� ��� ���������
inline int add(int a, int b) { return a + b; }

// �������� �������
template <typename T> T Multiply(T left, T right) {
	return left * right;
}

// ������� - ���������� ���������
int factorial(int n) {
	if (n == 0) return 1;			// ������� �������
	return n * factorial(n - 1);	// ����������� ������
}

// ������� - ����� Գ�������
int fibonacci(int n) {
	if (n <= 1) return n;						// ������� �������
	return fibonacci(n - 1) + fibonacci(n - 2); // ����������� ������
}

int main()
{
	SetConsoleOutputCP(1251);

	// ������������ inline-�������
	add(10, 12);

	// ������������ ��������������
	cout << SQR(10) - CUBE(5) << endl;

	// ������������ �������� �������
	Multiply(10, 12);		// int
	Multiply(10.5, 14.6);	// double
	Multiply('3', 'y');		// char
	Multiply(true, false);	// bool

	// ����� Գ������� - ������� ������
	cout << "����� Գ������� " << 6 << " = " << fibonacci(6) << '\n';
}