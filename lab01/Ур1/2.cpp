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
		cout << "\n������ ����.������� ��� �����\n";
		cin >> a;
		cin >> b;
		cout << "�� ����� ����� " << a << " � ";
		cout << b << "\n";
		cout << "��� �� ������ �������?\n1.+\n2.-\n3.*\n4./\n5.�������� � ������� ������ �����\n6.������� ������\n7.log � ���������� a �� ����� b\n";
		int t;
		cin >> t;
		cout << "�� �������:" << t << "\n";
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
		cout << "���������:" << c;
		cout << "\n������ ����������? Y/N";
		cin >> m;
	}
}