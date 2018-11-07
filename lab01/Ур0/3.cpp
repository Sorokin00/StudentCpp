#include <iostream>
using namespace std;

int main()
{
	int a;
	int b=50;
	cout << "Hi. Try to guess a number.\n";
 	do-while (!a==b)
	{
 	  cin >> a;
	  if (a==b)
	   {
	     cout << "YES\n";
	   }
	  if (a>b)
	   {
	     cout << "No. Less\n";
	   }
	  if(a<b)
	   {
	     cout << "No. Greater";
	   }
	}
}
