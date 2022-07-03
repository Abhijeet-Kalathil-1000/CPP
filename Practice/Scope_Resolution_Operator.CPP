// an eg. of scope resolution operator
// :: - it always refers to global variable
#include <iostream.h>
#include <conio.h>

int a = 10; // global variable

void main()
{
	int a = 20;  // local variable
	clrscr();
	cout << "Local var a = " << a << endl;
	cout << "Global var a = " << ::a << endl;
	// start a new scope
	{
		int a = 30;   // Nested variable
		cout << "Nested var a = " << a << endl;
		cout << "Global var a = " << ::a;
	}
	getch();
}