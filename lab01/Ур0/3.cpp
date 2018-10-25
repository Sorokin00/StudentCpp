##include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int a;
	cout << "Write numeric\n";
	cin >> a;
	int b;
	b = a % 2;
	cout << "Modulo:" << b;
}
