/*
	THIS PROGRAM ILLUSTRATES ABOUT :
		the concept of Function overloading.
		Function Overloading can be achieved in :
			=> By varying number of parameters.
			=> By changing sequence of parameters.
		Depend upon the return value NO FUNCTION OVERLOADING achieved...
*/
#include<iostream>

using namespace std;

class demo
{
	public:
		// Oveloading by changing number of parameters
		void fun()
		{
			cout<<"Inside fun with no parameters"<<endl;
		}
		void fun(int i)
		{
			cout<<"Inside fun with one parameters"<<endl;
		}
		void fun(int i, int j)
		{
			cout<<"Inside fun with two parameters"<<endl;
		}

		// Oveloading by changing sequance of parameters
		void gun(char c,int i)
		{
			cout<<"Inside gun with char & int as parameters"<<endl;
		}
		void gun(int i, char c)
		{
			cout<<"Inside gun with int & char as parameters"<<endl;
		}

		// We can not overload the function by changing return value
	/*
		int sun()
		{
			// Error
		}
		float sun()
		{
			// Error
		}
	*/

		// We can not overload the function with default arguments
		// Both this functions are considered as functions which accept one parameter
	/*
		void mun(int i)
		{
	
		}
		void mun(int i = 10)		// mun();		mun(110);
		{

		}
	*/

		// 	We can overload the functions depend upon data type modifier
		void mun(signed int i)
		{
			cout<<"In function mun which accept signed int"<<endl;
		}

		void mun(unsigned int i)
		{
			cout<<"In function mun which accept unsigned int"<<endl;
		}

		// 	We can overload the function by using reference but while calling that function by
		// 		passing variable it generates ambiguty
		void run(int &r)	// run(i);
		{
			cout<<"In function run which accept integer reference"<<endl;
		}

		void run(int r)	// run(i); run(10);
		{
			cout<<"In function run which accept integer"<<endl;
		}

		// We can overload the function by using pointers
		void corn(int *p)
		{
			cout<<"In function corn which accept address of integer"<<endl;
		}
	
		void corn(int p)
		{
			cout<<"In function corn which accept integer"<<endl;
		}

		// If appropriate defination is not found then the defination
		// with nearest data type gets binded.
		void born(char c)
		{
			cout<<"In function born which accept character"<<endl;
		}
};

int main()
{
	demo obj;

	obj.fun();
	obj.fun(10);
	obj.fun(10,20);

	obj.gun(10,'A');
	obj.gun('A',10);

	obj.mun(10);
	obj.mun((unsigned)10);

	obj.run(10);
//	obj.run(x); 		//Error

	int x = 10;
	obj.corn(x);
	obj.corn(&x);

// 	By using typecasting we can change the call
	obj.corn((int *)x);

	obj.born(x);

	return 0;
}


void corn(int *p)	
void corn(int p)
		
int i = 10;
fun(i);			//2
fun(&i);		//1
fun((int*)i);	//1
fun((int)&i);	//2






