#include "pch.h"
#include <iostream>
using namespace std;

char сheckchar()
{
	char x;
	while (!(cin >> x))
	{
		cout << "Неверное значение";
		cin.clear();
		cin.ignore(3000000, '\n');
	}
	return x;
}

char operation()
{
	char t;
	bool l = false;
	while (l == false)
	{
		t = сheckchar();
		if (t == '+' || t == '-' || t == '*' || t == '/')
		{
			l = true;
		}
		else
		{
			cout << "/nНевозможная операция/n";
		}
	}
	return t;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int e = 0;
	int i = 0;
	float a;
	float chisla[1000];
	int n;
	while (e == 0)
	{
		if (cin >> a)
		{
			chisla[i] = a;
			i++;
		}
		else
		{
			cin.clear();
			char en[256];
			cin.getline(en, 255);
			if ((en[0] == 'e')&(en[1] == 'n')&(en[2] == 'd'))
			{
				e = 1;
			}
			else
			{
				cout << 'Stop';
			}

		}

	}
	char *znaky = new char[i];
	for (n = 0; n < i; n++)
	{
		znaky[n] = operation();
	}
	for (n = 0; n < i; n++)
	{
		if (znaky[n] == '+')
		{
			chisla[n + 1] = chisla[n] + chisla[n + 1];
		}
		if (znaky[n] == '-')
		{
			chisla[n + 1] = chisla[n] - chisla[n + 1];
		}
		if (znaky[n] == '*')
		{
			chisla[n + 1] = chisla[n] * chisla[n + 1];
		}
		if (znaky[n] == '/')
		{
			chisla[n + 1] = chisla[n] / chisla[n + 1];
		}
	}
	cout << chisla[i - 1];
	return 0;
}
