/*
	Use of the Friend function : 
		=> To access the private member of a class outside of class...
		   Steps :
			 	1.declare a global function as a friend
	   			2.declare member of another structure
    			3.declare an entire structure as a friend
*/

#include<iostream>
using namespace std;

class friend_class;		//forward declaration of 'friend_class' class

class fun_class
{
	public:
		void fun(friend_class *fc);
};

class friend_class
{
	private: int i;
	public:
		friend_class()
		{
			i=50;
		}

		//Fun function in fun_class class is member of friend_class
		friend void fun_class::fun(friend_class *fc);

		//Global function gun() is member of friend_class
		friend void gun(friend_class *fc,int j);

		//Entire sun_class is member of friend_class
		friend class sun_class;

		//Global function mun is member of friend_class
		friend void mun();
};

//Global function which is not part of any class
void fun_class::fun(friend_class *fc)
{
	//Modifying the value of 'i' which is private member of friend_class
	fc->i=30;
	cout<<"\n In fun_class of fun function :";
	cout<<"\n i :"<<fc->i;
	
}

void gun(friend_class *fc, int j)
{
	fc->i += j;
	cout<<"\n In global gun function :";
	cout<<"\n i :"<<fc->i;
}

class sun_class
{
	private :
		int x;

	public:
		sun_class()
		{
			x=80;
		}

		void sun(friend_class * fc);
};

// Function of friend class sun_class
void sun_class::sun(friend_class *fc)
{
	fc->i+=x;
	cout<<"\n In sun_class of sun function :";
	cout<<"\n i :"<<fc->i;
}

void mun()
{
	//Create an object of friend_class inside the function mun
	friend_class fc;

	//It is valid bcz the function mun() in sun_class which is member of frined_class
	cout<<"\n In global mun function :";
	cout<<"\n i :"<<fc.i;
}

int main()
{
	friend_class fc;

	fun_class fobj;
	fobj.fun(&fc);

	gun(&fc,70);

	sun_class sobj;
	sobj.sun(&fc);

	mun();
	return 0;
}
