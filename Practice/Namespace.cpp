/*
	THIS PROGRAM ILLUSTRATES ABOUT :
		the concept of user-defined namespace...
*/

#include<iostream>

using namespace std;

// Defining our own namespace
namespace first
{
	class demo
	{
		public:
			void fun()
			{
				cout<<"Inside function fun of class demo"<<endl;
			}
			void gun();
	};	// end of demo
}	// end of namespace 'first'

// 	correct way for defining any member function outside the class declaration included inside namespace...

void first::demo::gun()		// 'path' specification is must...
{
	cout<<"Inside function gun of class demo"<<endl;
}

int main()
{

//	demo obj;		// It generates an error because 'demo' class is inside namespace 'first'

	// We can access members of namespace by using :: (scope resolution) operator...

	first::demo obj;
	obj.fun();
	obj.gun();

	// We can also use namespace by writing 'using' keyword...
	using namespace first;

	// After this line there is no need to use namespace name explicitely...

	demo obj1;
	obj1.fun();
	obj1.gun();

	return 0;
}
