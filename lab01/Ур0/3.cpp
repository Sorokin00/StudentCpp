##include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int a;
	cout << "Введите число\n";
	cin >> a;
	int b;
	b = a % 2;
	cout << "Остаток:" << b;
}