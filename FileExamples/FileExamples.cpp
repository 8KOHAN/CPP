#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <io.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "�������� ������ � ������� ������������� �������� stdio\n";

    {
        cout << '\n';
        // �������� �� ������� ���������
        FILE* f;
        // ³������� �����
        errno_t err = fopen_s(&f, "test.bin", "wb");

        // �������� �������� �������� �����
        if (err) {
            cout << "�� ������ ������� ����\n";
        }
        else {
            cout << "�������� � ����...\n";

            char str[] = "some text that will be written to the file";
            // ����� ���������� �� �����
            fwrite(&str, sizeof(char), strlen(str), f);

            cout << "����� ������� ������!\n";
            // �������� �����
            fclose(f);
        }
        cout << '\n';
    }

    {
        cout << '\n';

        FILE* f;
        auto err = fopen_s(&f, "test.txt", "a");

        int i = 123;
        double d = 43.567;

        if (err) {
            cout << "�� ������ ������� ����\n";
        }
        else {

            fprintf_s(f, "\n");
            fprintf_s(f, "integer: %d", i);
            fprintf_s(f, "\n");
            fprintf_s(f, "double: %.2f", d);

            fclose(f);
        }

        cout << '\n';
    }

    {
        cout << '\n';

        FILE* f;
        auto err = fopen_s(&f, "test.txt", "r"); // ��������� ��� �������

        if (err || !f) {
            cout << "�� ������ ������� ���� ��� �������\n";
        }
        else {
            int i;
            double d;

            fscanf_s(f, "integer: %d\n", &i);
            fscanf_s(f, "double: %lf\n", &d);

            cout << "������� �����: " << i << '\n';
            cout << "������� �������: " << d << '\n';

            fclose(f);
        }

        cout << '\n';
    }

    {
        cout << "\n";

        FILE* f;
        auto err = fopen_s(&f, "test.txt", "r");

        if (err) {
            cout << "�� ������� ������� ����\n";
        }
        else {

            while (!feof(f)) {

                int i;
                double d;

                fscanf_s(f, "integer: %d\n", &i);
                fscanf_s(f, "double: %lf\n", &d);

                cout << "������� �����: " << i << '\n';
                cout << "������� �������: " << d << '\n';

            }

            fclose(f);
        }

        cout << "\n";
    }

    {
        struct Player {
            int health;
            int level;
            char nickname[10];
        };

        Player p = { 100, 2, "bear2004" };

        FILE* f;
        
        fopen_s(&f, "player.txt", "w");

        if (!f) {
            cout << "�� ������ ������� ����\n";
        }
        else {

            fprintf_s(f, "%d : %d : %s", p.health, p.level, p.nickname);

            fclose(f);

            fopen_s(&f, "player.txt", "r");

            if (!f) {
                cout << "�� ������ ������� ����\n";
            }
            else {
                Player pl;

                fscanf_s(f, "%d : %d : %s", &pl.health, &pl .level, &pl.nickname, sizeof(pl.nickname));

                fclose(f);

                cout << "���������:\n";
                cout << "Health: " << pl.health << "\n";
                cout << "Level: " << pl.level << "\n";
                cout << "Nickname: " << pl.nickname << "\n";
            }
        }
    }

    {
        cout << '\n';
        // �������� �� ������� ���������
        FILE* f;
        // ³������� �����
        auto err = fopen_s(&f, "cbyc.txt", "w"); // ��������� ��� ������

        // �������� �������� �������� �����
        if (err) {
            cout << "�� ������ ������� ����\n";
        }
        else {
            cout << "�������� � ����...\n";

            char str[] = "some text that will be written to the file";
            // ����� ���������� �� �����
            for (int i = 0; i < strlen(str); i++) {
                fputc(str[i], f);
            }

            cout << "����� ������� ������!\n";
            // �������� �����
            fclose(f);
        }
        cout << '\n';
    }
    
    {
        cout << '\n';
        // �������� �� ������� ���������
        FILE* f;
        // ³������� �����
        auto err = fopen_s(&f, "cbyc.txt", "r"); // ��������� ��� �������

        // �������� �������� �������� �����
        if (err) {
            cout << "�� ������ ������� ����\n";
        }
        else {
            // ����������� �������
            while (!feof(f)) {
                cout << (char)fgetc(f);
            }

            // �������� �����
            fclose(f);
        }
        cout << '\n';
    }

    {
        cout << '\n';
        // �������� �� ������� ���������
        FILE* f;
        // ³������� �����
        auto err = fopen_s(&f, "sbys.txt", "w"); // ��������� ��� ������

        // �������� �������� �������� �����
        if (err) {
            cout << "�� ������ ������� ����\n";
        }
        else {
            cout << "�������� � ����...\n";

            char str[] = "some text that will be written to the file\n";
            char str2[] = "another line of text\n";
            char str3[] = "and another one line for writing into file\n";
            
            fputs(str, f);
            fputs(str2, f);
            fputs(str3, f);

            cout << "����� ������� ������!\n";
            // �������� �����
            fclose(f);
        }
        cout << '\n';
    }

    {
        cout << '\n';
        // �������� �� ������� ���������
        FILE* f;
        // ³������� �����
        auto err = fopen_s(&f, "sbys.txt", "r"); // ��������� ��� �������

        // �������� �������� �������� �����
        if (err) {
            cout << "�� ������ ������� ����\n";
        }
        else {
            char buffer[50];

            // ��������� �������
            while (fgets(buffer, sizeof(buffer), f)) {
                cout << buffer;
            }

            // �������� �����
            fclose(f);
        }
        cout << '\n';
    }

    {
        cout << '\n';

        // ����� ��� ������
        int arr[] = { 10, 20, 30, 40, 50 };
        int size = sizeof(arr) / sizeof(arr[0]);

        FILE* f;
        fopen_s(&f, "array.bin", "wb"); // ��������� ���� � �������� ����� ��� ������

        if (!f) {
            cout << "�� ������� ������� ���� ��� ������.\n";
        }
        else {
            // �������� ����� � ����
            fwrite(arr, sizeof(int), size, f);

            // �������� �����
            fclose(f);

            cout << "����� �������� � ������� ����.\n";
        }
        cout << '\n';
    }

    {
        cout << '\n';
        int arr[5];  // ����� ��� ����������
        int size = sizeof(arr) / sizeof(arr[0]);

        FILE* f;
        fopen_s(&f, "array.bin", "rb"); // ��������� ���� � �������� ����� ��� �������

        if (!f) {
            cout << "�� ������� ������� ���� ��� �������.\n";
        }
        else {
            // ������� ������ � �����
            fread(arr, sizeof(int), size, f);

            // �������� �����
            fclose(f);

            cout << "����� ��������� � �������� �����:\n";
            for (int i = 0; i < size; ++i) {
                cout << arr[i] << " ";
            }
        }
        cout << '\n';
    }

    {
        cout << '\n';
        FILE* f;

        auto err = fopen_s(&f, "test.bin", "r");

        if (!err) {
            // ������� ������ ������
            char ch = fgetc(f);
            cout << "������ ������: " << ch << endl;

            // �������� ������� ������� �� ��������� fgetpos
            fpos_t pos;
            fgetpos(f, &pos);
            cout << "������� ���� ������� �������: " << pos << endl;

            // ����������� ����� �� ������� �����
            fseek(f, 0, SEEK_SET);
            cout << "������� ���� ���������� �����: 0" << endl;

            // ������� ������ ������
            ch = fgetc(f);
            cout << "������ ������: " << ch << endl;

            // ����������� �� ��������� �������
            fsetpos(f, &pos);
            ch = fgetc(f);
            cout << "������ ���� ���������� �� ��������� �������: " << ch << endl;

            fclose(f);
        }
        cout << '\n';
    }

    {
        struct _finddata_t myfileinfo;
        long done = _findfirst("*.cpp", &myfileinfo);
        cout << myfileinfo.name << '\n';
    }

    {
        struct _finddata_t info;
        char path[255];
        char mask[20];

        cout << "������ ����: ";
        cin >> path;
        cin.ignore(); // �������� ������� ����� ���� cin >> path

        cout << "������ ����� (���������, *.txt): ";
        cin.getline(mask, 20);

        strcat_s(path, mask);

        auto handle = _findfirst(path, &info);
        if (handle == -1) {
            cout << "����� �� ��������.\n";
        }
        else {
            do {
                cout << info.name << '\n';
            } while (_findnext(handle, &info) == 0);
            _findclose(handle);
        }
    }
}