#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // ��������� ���� �������
    cout << "��� ������� 'B': " << (int)'B' << '\n';
    cout << "��� ������� '+': " << (int)'+' << '\n';
    cout << "��� ������� '?': " << (int)'?' << '\n';
    
}