#include<iostream>

using namespace std;

class base
{
	public:
		int i;
		int j;
		int k;

		base()
		{
			i = j = k = 10;
		}
	// 	3 member functions for the class 'base'
		void fun()
		{
			cout<<"Inside fun of base"<<endl;
		}
		void gun()
		{
			cout<<"Inside gun of base"<<endl;
		}
		void sun()
		{
			cout<<"Inside sun of base"<<endl;
		}
};

class derived : public base
{
	public:
		int i;
		int j;

		derived()
		{
			i = j = 20;
		}

	// Redefining functions due to which definations 
	// provided by base class is gets replaced...

		void fun()
		{
			cout<<"Inside redefined function fun by derived"<<endl;
		}

		void gun()
		{
			cout<<"Inside redefined function gun by derived"<<endl;

			// We can call base class function by using scope resolution operator
			base::gun();
		}

	// We are not redefinig sun() because of which base class defination is used...
};

int main()
{
	base bobj;		// 	base class object is created...
	derived dobj;	//	derived class object is created...

	dobj.fun();
	dobj.gun();
	dobj.sun();		// derived class not having sun() so, base class sun() gets called...

	cout<<"Value of k which is not redefined in derived class is : "<<dobj.k<<endl;
	return 0;
}
