/*
	THIS PROGRAM ILLUSTRATES ABOUT :
		the concept of template class
*/
#include<stdlib.h>
#include<iostream>

using namespace std;

// 	swap_element() is a function which is used for swapping purpose.
// 		As it is a function template we can swap any data type since, 
//			TEMPLATE IS USED TO ACHIEVE GENERICNESS...

template <class T>				//declares that "swap_element()" is a function template
void swap_element(T &a,T &b)	// for preserving the values needs to 'pass by reference'
{
	T temp;	//	need to declare 'temp' as of type 'T' 
			//	since it is used in swapping so need to match with appropriate data type...
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	int choice;
	// Menu driven program for swapping two elements of different data types 
	do
	{
		cout<<"Choice :(1-4)"<<endl<<"1.Integer swapping\n2.Charachter swapping\n3.Float swapping\n4.Exit"<<endl;

		cin>>choice;
		switch(choice)
		{
			case 1 :
				cout<<"Applied on integer data type."<<endl<<endl;

				int int1,int2;  

				// Accepting two integers from the user 
				cout<<"Enter two integers for swapping :";
				cin>>int1>>int2;

				cout<<"Before swapping 1st int:"<<int1<<" and 2nd int:"<<int2;
				cout<<endl;

				swap_element(int1,int2);//passing addresses of accepted integers

				cout<<"after swapping 1st int:"<<int1<<" and 2nd int:"<<int2;
				cout<<"\n";
				break;

			case 2 :
				cout<<"Applied on charachter data type."<<endl<<endl;

				char ch1,ch2;

				// Accepting two charachters from the user
				cout<<"Enter two charachters for swapping :";
				cin>>ch1>>ch2;

				cout<<"Before swapping 1st char:"<<ch1<<" and 2nd char:"<<ch2;
				cout<<endl;

				swap_element(ch1,ch2);//passing addresses of accepted chars

				cout<<"after swapping 1st char:"<<ch1<<" and 2nd char:"<<ch2;
				cout<<endl;
				break;

			case 3:
				cout<<"Applied on float data type."<<endl<<endl;

				float flt1,flt2;

				// Accepting two floats from the user
				cout<<"Enter two charachters for swapping :";
				cin>>flt1>>flt2;//passing addresses of accepted floats

				cout<<"Before swapping 1st float:"<<flt1<<" and 2nd float:"<<flt2;
				cout<<endl;

				swap_element(flt1,flt2);

				cout<<"after swapping 1st float:"<<flt1<<" and 2nd float:"<<flt2;
				cout<<endl;
				break;

			case 4:
					exit(0);
		}
	}while(choice!=4);

	return 0;
}
