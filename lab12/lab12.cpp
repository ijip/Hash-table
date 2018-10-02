// lab12.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "HashTable.h"

int main()
{
	setlocale(LC_CTYPE, "RUS");
	HashTable H;
	char f;
	cout << "��� ������ � ���������� ������������ ��������� �������: " << endl;
	cout << "'1' - ���������� ���-�������." << endl;
	cout << "'2' - ����� ���-�������." << endl;
	cout << "'3' - ���������� ������ � �����������." << endl;
	cout << "��� ������ �� ��������� ������� '0'." << endl;
	while (cin >> f)
	{
		switch (f) {
		case '1': { cout << "����� ���-�� ���� ������ ������ � �������?: "; int i; cin >> i; string line;
			for ( i ; i > 0; i--)
			{
				cout << i << ": ";
				cin >> line;
				H.hashtable(line);
				line;
			} 
			break;
		}
		case '2': {cout << "���-������� ��������: " << endl;
			H.vivod(); break; }
		case '3': {char R[9] = " ,.?!:;-";
			char *s = new char[100]; string line; char *f;
			cout << "������� �����������: "; cin.get();
			cin.getline(s, 100, '\n');
			cout << "��������: " << endl;
			f = strtok(s, R);
			line = f;
			while (f)
			{
				if (!H.searchword(line))
				{
					cout << "����� " << line << " �������� � �������, ���� �� ���������� � ���-�������!" << endl;
				}
				f = strtok(NULL, R);
				if (f)
				line = f;
			}
			cout << "�������� ���������." << endl;
			break; }
		case '0': {return 0; }
		default: cout << "�������� ����!";  break;
		}
		cout << "��� ������ � ���������� ������������ ��������� �������: " << endl;
		cout << "'1' - ���������� ���-�������." << endl;
		cout << "'2' - ����� ���-�������." << endl;
		cout << "'3' - ���������� ������ � �����������." << endl;
		cout << "��� ������ �� ��������� ������� '0'." << endl;
	}
}

