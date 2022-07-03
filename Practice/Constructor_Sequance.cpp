/* 
   THE FOLLOWING PROGRAM WILL ILLUSTRATES :
	   THE DEMO OF CONSTRUCTOR CALLING SEQUENCE FOR THE BASE CLASS AND 
			DERIVED CLASS DEPENDING ON THEIR TYPES OF INHERITANCE...
*/
#include<iostream>

using namespace std;

/*
	The Program includes total 6 classes :
		'base' : parent class for 'derived1'
		'derived1' : parent class for derived2 and child class of 'base'
		'derived2' : child class of 'derived1'
		'multibase1' and 'multibase2' : parent classes for 'multiderived'
		'multiderived' : inherited with multiple inheritance from 'multibase1' and 'multibase2'
*/

// 	All the below classes contains only constructor and destructor definations...

class base
{
	public:
		base()
		{
			cout<<"In constructor of base\n";
		}
		~base()
		{
			cout<<"In destructor of base\n";
		}
};

class derived1 : public base
{
	public:
		derived1()
		{
			cout<<"In constructor of derived1\n";
		}
		~derived1()
		{
			cout<<"In destructor of derived1\n";
		}
};

class derived2 : public derived1
{
	public:
		derived2()
		{
			cout<<"In constructor of derived2\n";
		}
		~derived2()
		{
			cout<<"In destructor of derived2\n";
		}
};

class multibase1
{
	public:
		multibase1()
		{
			cout<<"In constructor of multibase1\n";
		}
		~multibase1()
		{
			cout<<"In destructor of multibase1\n";
		}
};

class multibase2
{
	public:
		multibase2()
		{
			cout<<"In constructor of multibase2\n";
		}
		~multibase2()
		{
			cout<<"In destructor of multibase2\n";
		}
};

class multiDerived : public multibase1,public multibase2
{
	public:
		multiDerived()
		{
			cout<<"In constructor of multiDerived\n";
		}
		~multiDerived()
		{
			cout<<"In destructor of multiDerived\n";
		}
};

int main()
{
	/* 
		Constructors gets called from TOP TO BOTTOM manner 
		AND  
		Destructors gets called in BOTTOM TO TOP manner...
	*/

	cout<<"\n************************************************************************";
	cout<<"\nConstructor and destructor calling sequance of single level inheritance\n";	
	cout<<"************************************************************************\n";

	derived1 *obj1 = new derived1;		// constructors gets called...
	delete obj1;						// destructors gets called...

	cout<<"\n************************************************************************";
	cout<<"\nConstructor and destructor calling sequance of multi-level inheritance\n";
	cout<<"************************************************************************\n";

	derived2 *obj2 = new derived2;		// constructors gets called...
	delete obj2;						// destructors gets called...

	cout<<"\n************************************************************************";
	cout<<"\nConstructor and destructor calling sequance of multiple inheritance\n";
	cout<<"************************************************************************\n";

	multiDerived *obj3 = new multiDerived;		// constructors gets called...
	delete obj3;								// destructors gets called...

	return 0;
}
