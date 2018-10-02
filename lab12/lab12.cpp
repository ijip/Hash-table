// lab12.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "HashTable.h"

int main()
{
	setlocale(LC_CTYPE, "RUS");
	HashTable H;
	char f;
	cout << "Для работы с программой используются следующие команды: " << endl;
	cout << "'1' - Заполнение Хеш-таблицы." << endl;
	cout << "'2' - Вывод Хеш-таблицы." << endl;
	cout << "'3' - Нахождение ошибок в предложении." << endl;
	cout << "Для выхода из программы нажмите '0'." << endl;
	while (cin >> f)
	{
		switch (f) {
		case '1': { cout << "Какое кол-во слов хотите ввести в таблицу?: "; int i; cin >> i; string line;
			for ( i ; i > 0; i--)
			{
				cout << i << ": ";
				cin >> line;
				H.hashtable(line);
				line;
			} 
			break;
		}
		case '2': {cout << "Хеш-таблица содержит: " << endl;
			H.vivod(); break; }
		case '3': {char R[9] = " ,.?!:;-";
			char *s = new char[100]; string line; char *f;
			cout << "Введите предложение: "; cin.get();
			cin.getline(s, 100, '\n');
			cout << "Проверка: " << endl;
			f = strtok(s, R);
			line = f;
			while (f)
			{
				if (!H.searchword(line))
				{
					cout << "Слово " << line << " написано с ошибкой, либо не содержится в хеш-таблице!" << endl;
				}
				f = strtok(NULL, R);
				if (f)
				line = f;
			}
			cout << "Проверка завершена." << endl;
			break; }
		case '0': {return 0; }
		default: cout << "Неверный ввод!";  break;
		}
		cout << "Для работы с программой используются следующие команды: " << endl;
		cout << "'1' - Заполнение Хеш-таблицы." << endl;
		cout << "'2' - Вывод Хеш-таблицы." << endl;
		cout << "'3' - Нахождение ошибок в предложении." << endl;
		cout << "Для выхода из программы нажмите '0'." << endl;
	}
}

