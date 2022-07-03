/*
	THIS PROGRAM ILLUSTRATES ABOUT :
		the concept of 'inline' function 
*/
#include<iostream>

using namespace std;

class demo
{
	public:
		int i;

		// This function is by default considered as an inline function
		void fun()
		{
			cout<<"Inside function fun"<<endl;
		}

		inline void gun();
};

void demo::gun()
{
	cout<<"Inside function gun"<<endl;
}

int main()
{
	demo dobj;

	dobj.fun();
	dobj.gun();

	return 0;
}
