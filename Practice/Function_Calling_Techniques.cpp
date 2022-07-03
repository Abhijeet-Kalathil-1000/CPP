/* 
   THE FOLLOWING PROGRAM WILL ILLUSTRATES :
	   THE DEMO OF CALLING FUNCTION BY DIFFERENT WAYS,
			1. CALL BY VALUE
			2. CALL BY REFERENCE
			3. CALL BY ADDRESS
		INCREMENTATION CHANGES IN THE PASSED ARGUMENT REFLECTED BACK 
			IN CASE 2 AND 3 ONLY AND NOT IN 1...
*/
#include<iostream>
using namespace std;

// 	FUNCTION DEFINATION FOR ALL THE 3 TYPES OF CASES...

void CallByValue(int x)
{
	cout<<"CallByValue"<<endl;
	x++;
}	//	Scope for 'x' will get ends here only and hence,
	//	changes will not affect to original variable...


void CallByReference(int &x)
{
	cout<<"CallByreference"<<endl;
	x++;
}	// 'x' is a reference variable,
	// so but obviously changes will affect the original variable...


void CallByAddress(int *x)
{
	cout<<"CallByAddress"<<endl;
	(*x)++;
}	// 'x' containing the address of passed argument,
	// so but obviously changes will affect the original variable...

int main()
{
	int a = 10;
	cout<<"\nValue of variable before function call "<<a<<endl;
	CallByValue(a);
	cout<<"Value of variable before function call "<<a<<endl;

	int b = 10;			// c++ allows declaration anywhere in the code...
	cout<<"\nValue of variable before function call "<<b<<endl;
	CallByReference(b);
	cout<<"Value of variable before function call "<<b<<endl;

	int c = 10;
	cout<<"\nValue of variable before function call "<<c<<endl;
	CallByAddress(&c);
	cout<<"Value of variable before function call "<<c<<endl;

	return 0;
}
