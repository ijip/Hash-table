#pragma once
#include "iostream"
#include "string"
#include "stdlib.h"
using namespace std;
class HashTable
{
private:
	struct Tnode
	{
		string word;
		bool flag = 0;
	};
	Tnode H[100];

public:
	HashTable() {};
	~HashTable() {};

	int strtoi(string key)
	{
		int sum = 0;
		for (int i = 0; i < key.length(); i++)
		{
			sum += int(key[i]);
		}
		return sum;
	}
	
	int hash(string key)//������� ����������� �����
	{
		int i = strtoi(key); i %= 100;
		if (!H[i].flag)
		{
			return i;
		}
		else
		{
			int k = strtoi(key), n; k /= 100;
			n = i + k;
			while (H[n % 100].flag)
			{
				n += k;
			}
			return n % 100;
		}
	}
	void hashtable(string key) //������� ����� � ����������
	{
		int i = hash(key); //����� ���������� ����� � �������
		H[i].word = key;
		H[i].flag = 1; //����� ������
	}
	bool searchword(string key)//����� ����� � �������
	{
		if ((H[strtoi(key) % 100].flag) && (H[strtoi(key) % 100].word == key))
		{
			return 1; //���� ���������� � ��������
		}
		if (H[strtoi(key) % 100].flag)
		{
			int k = strtoi(key) / 100, n;
			n = strtoi(key) + k;
			while ((H[n % 100].flag) && !(H[strtoi(key) % 100].word == key))
			{
				n +=k;
			}
			if (H[strtoi(key) % 100].flag)
			{
				return 1; //���� ���������� � ��������
			}
			else
			{
				return 0; //��� ���������� � ��������
			}
		}
		else
		{
			return 0; //��� ���������� � ��������
		}
	}
	void vivod()//����� ����������
	{
		for (int i = 0; i < 100; i++)
		{
			if (H[i].flag)
				cout << i << ": " << H[i].word << endl; 
		}
	}
};

