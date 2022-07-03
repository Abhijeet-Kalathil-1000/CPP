/*
	THIS PROGRAM ILLUSTRATES THE USE OF : 
		DEFINING 'constant data-member' in the class...
*/
#include<iostream>

using namespace std;

class demo
{
	public:
		const int i;
	/*
		// 	Constant members must be initialised
		// 		otherwise compiler generate error.
		demo()
		{
		
		}
	*/

	/*
		// 	We can not initialise constant membres 
		// 		inside the constuctor
		demo()
		{
			i = 10;	//Error
		}
	*/

		// 	CORRECT WAY TO DEFINE constant members...
		// 		To initialise the constant members we have to use the member initialisation list concept

		demo():i(10)		// THIS IS concept of 'initialisation list'...
		{
			cout<<"Successfully initialised the constant members..."<<endl;
		}
};

int main()
{
	demo dobj;

	// We can not change value of constant member...
	// dobj.i++;		// NOT ALLOWED...

	return 0;
}
