#include "pch.h"
#include <iostream>
using namespace std;

int сheck()
{
	int x;
	while (!(cin >> x))
	{
		cout << "Неверное значение";
		cin.clear();
		cin.ignore(3000000, '\n');
	}
	return x;
}

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
		a = сheck();
		b = сheck();
		cout << "Вы ввели числа " << a << " и ";
		cout << b << "\n";
		bool L = false;
		while (L==false)
		{
		   cout << "Что вы хотите сделать?\n1.+\n2.-\n3.*\n4./\n";
		   int t;
		   cin >> t;
		   if (t==1 || t==2 || t==3 ||t==4)
		   {
			   L=true;
		   }  
		   else
		   {
			   cout << "/nНевозможная операция/n";
		   }
		}
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
		L = false;
		while (L == false)
		{ 
			cout << "\nХотите продолжить? Y/N\n";
		    cin >> m;
			if (m == Y || m == N)
			{
				L = true;
			}
			else
			{
				cout << "/nНевозможная операция/n";
			}
		}

	}
	 return 0;
}
