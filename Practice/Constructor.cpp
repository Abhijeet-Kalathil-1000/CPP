/* 
   THE FOLLOWING PROGRAM WILL ILLUSTRATES :
	   THE DEMO ON TYPES OF THE CONSTRUCTOR AND ALL THEIR POSSIBILITIES...
*/

#include<iostream>
#include<string.h>
// string.h included for memcpy()

using namespace std;

class base
{
	// declaration of the class goes from here...
	public:
	// public section starts from here...

		// data members section...
		int *p;		// 	one pointer variable is declared...

		// constructor's defination goes from here...

		base()
		{
			// zero-arg constructor OR default constructor defination...
			cout<<"Inside Default constructor"<<endl;
			// 
			p = new int[10];	// 'p' is pointing to 40 bytes of memory which is dynamically allocated by new...
		}

		base(int i)
		{	
			// constructor accepting one argument, defination...
			cout<<"Inside Parametrised constructor with one parameter"<<endl;

			p = new int[i];		// the i/p argument times memory allocated and 'p' will point to that memory...
		}
	
		base(int i, int j, int k = 10)
		{	
			//	constructor accepting three arguments, but one argument having default value defination...

			cout<<"Inside Parametrised constructor with default argument"<<endl;

			p = new int[i + k];		// i+k times the memory allocated and 'p' is pointing to that memory...
		}

		base(base &bref)
		{	
			// copy-constructor defination...
			cout<<"Inside copy constructor"<<endl;

			p = new int[40];
			//	160 bytes of memory is allocated and 'p' is pointing to that memory...
			memcpy(p,bref.p,40);
			//	The  memcpy()  function  copies 40 bytes from memory 'bref.p' to memory 'p'...
		}
		~base()
		{
			// destructor defination...
			cout<<"Inside Destructor"<<endl<<endl;
			// control of this program will come inside the destructor,
			// before the "}" of main() for the number of created objects... 
		}
};

int main()
{
	base obj1;
	// 	default constructor is called...

	base obj2(obj1);
	// 	copy constructor will get called...

	base obj3(10);
	//	one-arg constructor will get called...

	base obj4(10,20);
	//	the three-arg constructor gets called but 3rd argument will take default value...

	return 0;
}
