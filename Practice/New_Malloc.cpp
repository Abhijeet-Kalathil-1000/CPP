/*
	THIS PROGRAM ILLUSTRATES ABOUT :
		the concept of 'new' and 'delete' operator from c++ 
*/
#include<malloc.h>
#include<iostream>

using namespace std;

class demo
{
	public:
		int i;
		demo(int x)
		{
			i = x;
			cout<<"Inside constructor"<<endl;
		}

		~demo()
		{
			cout<<"Inside Destructor"<<endl;
		}
};

int main()
{
	cout<<"Allocating memory for object using malloc"<<endl;

	// 	As constructor is not called member i contains garbage value...
	demo *p1 = (demo*) malloc (sizeof(demo));

	cout<<"Freeing the memory allocated by malloc"<<endl<<endl;
	free(p1);

	cout<<"In case of malloc and free constructor and destructor is not called"<<endl;

	// 	As constructor & destructor is called when we allocate memory by "new"...
	cout<<"\nAllocating memory for object using new"<<endl;

	// 	we can initialise the object while creation.
	demo *p2 = new demo(10);

	cout<<"Freeing the memory allocated by new"<<endl;
	delete p2;

	return 0;
}
