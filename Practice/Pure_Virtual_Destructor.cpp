/* 
   THE FOLLOWING PROGRAM WILL ILLUSTRATES :
	   THE EXPLANATION ABOUT THE 'pure virtual destructor'...
*/
#include<iostream>

using namespace std;

// class base2 and derived2 contains only defination for constructor and destructor...
// destructor of base2 is declared as virtual...

class base2
{
	public:
		base2()
		{
			cout<<"In base2 constructor\n";
		}

		// 	Pure virtual destructor declared as : 
		virtual ~base2() = 0;		// "=0" means base2 is unable to provide defination for it...
};

// we can provide Defination for the pure virtual destructor outside the respective class...
	base2::~base2()
	{	
		cout<<"base2 destructor\n";
	}


class derived2 : public base2
{
	public:
		derived2()
		{
			cout<<"In derived2 constructor\n";
		}

		~derived2()
		{
			cout<<"In derived2 destructor\n";
		}
};

int main()
{
	// Unable to create object of base class beacause it
	// contains pure virtual destructor which makes it abstract class...

	//base2 bobj;			// NOT ALLOWED : INVALID...


	// But object of derived2 gets created normally...

	derived2 obj;		
// 	constructors gets called in TOP TO BOTTOM and destructors in BOTTOM TO TOP manner...

	return 0;
}
