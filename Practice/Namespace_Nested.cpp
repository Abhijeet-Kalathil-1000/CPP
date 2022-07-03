/*
	THIS PROGRAM ILLUSTRATES ABOUT :
		the concept of "NESTED NAMESPACE"...
*/

#include<iostream>

using namespace std;

// 	defining our own namespace...
namespace outer
{
	class demo
	{
		public:
			int i,j;
			demo()
			{	i=j=10;
				cout<<"Constructing object of outer demo class"<<endl;		
			}
			~demo()
			{
				cout<<"Destructing object of outer demo class"<<endl;
			}
	};

	namespace inner
	{
		class demo
		{
			public:
				int x,y;
				demo()
				{	
					cout<<"Constructing object of inner demo class"<<endl;		
				}
				~demo()
				{
					cout<<"Destructing object of inner demo class"<<endl;
				}
		};
	}
}

int main()
{
	// 	correct way to access members from both the user-defined namespaces...

	outer::inner::demo obj1;
	// 	using 'obj1' we can access 'x' and 'y' only and not 'i' and 'j'...

	outer::demo obj2;
	// using 'obj2' we only access 'i' and 'j'...

	using namespace outer;

	demo obj3;
	// 	using 'obj3' we can access 'i' and 'j'...

/*
	using namespace outer::inner;
	demo obj4;		// ALLOWED But under a single namespace...
*/

	return 0;
}
