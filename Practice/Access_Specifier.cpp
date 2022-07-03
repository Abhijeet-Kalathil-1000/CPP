/* 
   THE FOLLOWING PROGRAM WILL ILLUSTRATES :
   THE DEMO OF ACCESS SPECIFIERS INSIDE A SINGLE CLASS...
*/

#include<iostream>

using namespace std;

class demo				// "class" keyword followed by name of the class...
{
	// declaration of class goes from here...

	public :
		// members declared inside public will be accessible to anyone...
			int pub;
    static int i;

	private :
		// members declared inside private will no more accessible outside the class...
			int pri;

	protected :
		// members declared inside protected will be accessible in immediate derived class
		// and no more outside the class...
			int pro;

	public :
		// Need to access the constructor of the class from outside the class
		// hence, declared again inside the public section...

			demo()			// constructor defination goes here...
			{
				// constructor allows to initialise the members of class...
				pub = 10;
				pri = 20;
				pro = 30;
			}

			void fun()
			{
				// fun is a member function which will access
				// all the members without any restriction...
				cout<<endl<<"public member : "<<pub<<endl<<"Private member : "<<pri<<endl<<"Protected member : "<<pro<<endl;
			}
};	// class declaration ends here hence ";" is must at the end of class...
int demo::i = 10;

int main()
{
	// entry point function definaton goes from here...

	demo obj;		// 'obj' is declared of type demo class i.e. object declaration done ...
					// using the above declared object you can access it's charachteristics and behaviours...
    cout<<demo::i;
    
/*  
	The operations which you can perform on the declared object will goes from here...
*/	

	//	cout<<obj.pri;
	// 	Unable to access the private members outside the class...
	
	//cout<<obj.pro;
	// Unable to access the protected members outside the class...
	
	cout<<"Accessing public members inside main ... "<<endl;
	cout<<"Public member : "<<obj.pub; 		// output : Public member : 10


	cout<<endl<<endl<<"Accessing all the class members using the fun..";
	obj.fun();				// output : public member : 10
							//			Private member : 20
							//			Protected member : 30

	return 0;
}
