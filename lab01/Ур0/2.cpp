#include <iostream>
using namespace std;

int main()
{
	char a;
	cout << "Write your name\n";
	cin >> a;
	cout << "Write year, when you was born\n";
	int b;
	cin >> b;
	cout << "Write month, when you was born\n";
	int c;
	cin >> c;
	cout << "Write day, when you was born\n";
	int d;
	cin >> d;
	cout << "Hello, "<<a<<". You're "<<b<<"/"<<c<<"/"<<d<<" years old.";
}
