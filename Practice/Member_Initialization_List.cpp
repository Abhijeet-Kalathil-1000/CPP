/*
	THIS PROGRAM ILLUSTRATES ABOUT :
		the concept of 'member initialization list' in c++ 
*/
#include<iostream>

using namespace std;

// Initialisation list is used for initialising "non-static constant members..."

class First_Use
{
	public:
		const int i;
		const int j;
		int k;
		int l;

		// 	We have provided hard-coded values to constant members.
		First_Use():i(10),j(20),k(30)	// i(10) => i=10
		{
			cout<<"In zero-arg constructor of First_Use"<<endl;
		}

		// 	We can also initialise the user defined value
		First_Use(int x,int y,int z):i(x),j(y),k(z)
		{
			cout<<"In parameterized constructor of First_Use"<<endl;
		}

		// 	Members must get initialised in order in which they are declared in class...
		First_Use(int x):j(++x),k(x),i(++x)
		{
			cout<<"In constructor of First_Use"<<endl;
		}

		// 	If we use member initialisation list and again initialised inside
		// 	constructor then value which is initialised in constructor is considered...
		First_Use(int x,int y):k(x),l(y),i(10),j(20)
		{
			k = 60;
			l = 70;
		}
};

// Member initialisation is used when class contains reference variable as a data member.
class Second_Use
{
	public:
		int &ref;
	
		Second_Use(int x):ref(x)
		{
			cout<<"Inside the conatructor which initialises reference variable :"<<ref<<endl;
		}
};

class base
{
	public:
		int i;

		base(int x)
		{
			cout<<"Inside base class constructor"<<endl;
			i = x;
		}
};

//For initialization of member objects which do not have default constructor

class Third_Use
{
	public :
		base bobj;
	
		Third_Use(int a):bobj(a)
		{
			cout<<"Inside Third_Use class"<<endl;
		}
};

/*
	You can also verify whether values get assigned or not?
	 	by displaying them inside constructor itself or 
			after calling the constructor inside main...
*/
int main()
{
	// 	Calling way of constructors to illustrate the use of "member initialisation list"...
	
	First_Use obj1();
	First_Use obj2(10,20,30);
	First_Use obj3(10);

	cout<<obj3.i<<obj3.j<<obj3.k<<endl;

	int i = 40;
	Second_Use obj4(i);

	Third_Use tobj(10);
	return 0;
}
