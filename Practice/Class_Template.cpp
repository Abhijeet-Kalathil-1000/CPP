/*
	Class Template:-
		=> allows to create "generic classes".
		=> also called as "Parameterized class".
		=> The class which create as template ,all member of that class are generic member.
		=> If we write a class template the each and every member function of that class is considered as function but still template is required.
		=> When we create object of that class template then each & every object of different source code created by the compiler.
	Syntax:-
		template <class valid_identifier(eg T)>class class_name
		{
			//body of class
		};
	Example:- Stack,Queue,Linked List,Tree 
*/

#include<iostream>
using namespace std;

template <class T>		//creating class template for class stack 
class stack
{
	private:
		int size;
		T * ptr;
		int top;

	public:
		stack();
		void push(T);			//Function for Pushing the element into stack...
		void display();			//Function for Displaying element from the stack...
		T pop();				//Function for poping the element from the stack...
		~stack();
};

template <class T>void //Template function push
stack<T>::push(T val)
{
	if(top<size)
		ptr[++top]=val;
}

template <class T>void //Template function display
stack<T>::display()
{
	for(int i=0;i<=top;i++)
		cout<<endl<<ptr[i]<<endl; 
}

template<class T>T //Template function pop
stack<T>::pop()
{
	if(top>-1)
		return(ptr[top--]);
}

template<class T>stack 		//Template function constructor 
<T>::stack() 	
{
	//Initialization of stack...
	size=10;
	ptr=new T[size];
	top=-1;
}

template <class T>stack 	//Template function Destructor
<T>::~stack() 
{
	if(ptr)
		delete []ptr;		// mentioning '[]' is MUST for deleting whole memory allocated...
}

int main()
{
	stack<int>st1;			//stack implementation of integer element
	stack<char>st2;			//stack implementation of character element

	//pushinng integer element
	st1.push(10); 
	st1.push(20);
	st1.push(30); 	
	st1.push(40);

	//Display pushed integer element
	st1.display();

	//poping interger element & display
	cout<<"\nPoped Element:\n"<<st1.pop();

	//pushinng character element
	st2.push('a'); 
	st2.push('b');
	st2.push('c');
	st2.push('e');

	//Display pushed character element
	st2.display();

	//poping character element & display
	cout<<"\nPoped Element:\n"<<st2.pop();

	return 0;
}
