/*
	THIS PROGRAM ILLUSTRATES ABOUT :
		the concept of 'virtual function' in c++ 
*/
#include<iostream>

using namespace std;

// base class containing no virtual function...
class Normal_Base
{
	public:
		void fun()
		{
			cout<<"In fun of Normal_Base"<<endl;
		}
		void gun()
		{
			cout<<"In gun of Normal_Base"<<endl;
		}
};

//	derived class containing no virtual function...
class Normal_Derived : public Normal_Base
{
	public:
		void fun()
		{
			cout<<"In fun of Normal_Derived"<<endl;
		}
		void gun()
		{
			cout<<"In gun of Normal_Derived"<<endl;
		}
};

// 	base class containing virtual function...
class Virtual_Base
{
	public:
		virtual void fun()
		{
			cout<<"In Virtual function fun of Virtual_Base"<<endl;
		}
		void gun()
		{
			cout<<"In Non Virtual function gun of Virtual_Base"<<endl;
		}
};

//	derived class inherited from the above base class which contains virtual function...
class Virtual_Derived : public Virtual_Base
{
	public:
		// Base class defined the "virtual method fun()" and
		//	 derived class also provided defination for fun() and
		//		This is known as "overriding of function" 
		void fun()
		{
			cout<<"In overrided function fun of Virtual_Derived"<<endl;
		}
		// This is redefination of function gun	since it is not defined in base class as a 'virtual'
		void gun()
		{
			cout<<"In Redefined function gun of Virtual_Derived"<<endl;
		}
};

int main()
{
	cout<<"\nFunction calling without use of virtual"<<endl;

	cout<<"\nCalling functions by creating base class object"<<endl;

	Normal_Base nbobj;
	nbobj.fun();
	nbobj.gun();

	cout<<"\nCalling functions by creating derived class object"<<endl;

	Normal_Derived ndobj;
	ndobj.fun();
	ndobj.gun();

	cout<<"\nCalling functions by creating pointer of base class pointing to derived class"<<endl;

	Normal_Base *nbp = new Normal_Derived;

	nbp->fun();		//	normal base class fun() is called...
	nbp->gun();		//	normal base class gun() is called...

	cout<<"\nFunction calling with using Virtual"<<endl;

	cout<<"\nCalling functions by creating base class object"<<endl;

	Virtual_Base vbobj;
	vbobj.fun();
	vbobj.gun();

	cout<<"\nCalling functions by creating derived class object"<<endl;

	Virtual_Derived vdobj;
	vdobj.fun();
	vdobj.gun();

	cout<<"\nCalling functions by creating pointer of base class pointing to derived class"<<endl;

	// 	Actual virtual concept starts from here...
	//	Base class pointer pointing to derived class... 
	// 		Virtual concept is only applicable on pointer and reference concept and not on object...
	Virtual_Base *vbp = new Virtual_Derived;

	vbp->fun();
	vbp->gun();

	cout<<"\nSize of Virtual_Base class is "<<sizeof(Virtual_Base)<<" Because it contains VPTR"<<endl;

	return 0;
}
