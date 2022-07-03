/*
	THIS PROGRAM ILLUSTRATES ABOUT :
		the concept of 'pure virtual function' in c++ 
*/
#include<iostream>

using namespace std;

class Abstract_Base
{
	public:
		void fun()
		{
			cout<<"Inside fun of Abstract_Base"<<endl;
		}

		virtual void gun()=0;		// pure virtual function declaration

		virtual void sun() = 0;		// pure virtual function declaration

	// 	We can not provide defination for pure irtual function 
	// 		at the time of declaration (Some compilers allow this)

	/*	
		virtual void mun() = 0
		{
			cout<<"Inside partial defination for function mun";
		}		// NOT ALLOWED
	*/
};

// 	Partial defination for pure virtual function by 'base class' itself is provided...

void Abstract_Base :: sun()
{
		cout<<"Inside sun of Abstract_Base"<<endl;
}

// derived class declaration...
//	it must need to provide definations for all the 'pure virtual functions'
//		which are declared in "Abstract_Base" class

class Abstract_Derived : public Abstract_Base
{
	public:
		// provided defination for 'sun'
		//	(since base class also provided so this is example of "function overriding")
		void sun()
		{
			cout<<"Inside sun of Abstract_Derived"<<endl;
			cout<<"Calling partial defination of sun provided by base class"<<endl;
			Abstract_Base::sun();	// explicitly calling the method of base class...
		}

		void gun()
		{
			cout<<"Inside gun of Abstract_Derived"<<endl;
		}
};

int main()
{
	// 	We can not create object of an abstact class...
	//	Abstract_Base bobj;		//Error

	Abstract_Derived dobj;		// ALLOWED

	dobj.fun();
	dobj.gun();
	dobj.sun();

// We can not create object of abstacr class but
// we can create pointer of abstact class and using that we can easily call the functions of it...

	cout<<"\nCalling functions through pointer of base class pointing to derived class"<<endl;

	Abstract_Base *bp = new Abstract_Derived;
	// 	base class pointer pointing to derived class object...
	//		this is the example which illustrates use of "VIRTUAL IN C++"
	
	// 	in case of "VIRTUAL FUNCTION" concept....
	//	 'pointed class' functions gets called but,
	//	   if it doesn't provided defination for it then, 
	//		 in that case 'pointer class' functions get called...

	bp->fun();
	bp->gun();
	bp->sun();

	return 0;
}
