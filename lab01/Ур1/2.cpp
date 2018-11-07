#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	char m = 'Y';
	while (m == 'Y')
	{
		int a;
		int b;
		cout << "\nДобрый день!Введите два числа\n";
		cin >> a;
		cin >> b;
		cout << "Вы ввели числа" << a << " и ";
		cout << b << "\n";
		cout << "Что вы хотите сделать?\n1.+\n2.-\n3.*\n4./\n5.Возвести первое число в квадрат\n6.Найти корень числа\n7.log с основанием a от числа b\n";
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
		if (t == 5)
		{
			c = a * a;
		}
		if (t == 6)
		{
			c = sqrt(a);
		}
		if (t == 7)
		{
			c = log10(b) / log10(a);
		}
		cout << "Результат:" << c;
		cout << "\nХотите повторить? Y/N";
		cin >> m;
	}
	 return 0;
}
