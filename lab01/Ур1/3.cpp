#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	char m = 'Y';
	while (m == 'Y')
	{
		double a;
		double b;
		cout << "\nДобрый день! Введите два числа\n";
		cin >> a;
		cin >> b;
		cout << "Вы ввели" << a << "и";
		cout << b << "\n";
		cout << "Что вы хотите сделать?\n1.+\n2.-\n3.*\n4./\n";
		int t;
		cin >> t;
		cout << "Вы выбрали:" << t << "\n";
		int c;
		if (t == 1)
		{
			c = a + b;
		}
		if (t == 2)
		{
			c = a - b;
		}
		if (t == 3)
		{
			c = a * b;
		}
		if (t == 4)
		{
			c = a / b;
		}
		cout << "Результат:" << c;
		cout << "\Хотите повторить? Y/N";
		cin >> m;
	}
}
