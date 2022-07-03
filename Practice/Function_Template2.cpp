#include<iostream>
#include<conio.h>
using namespace std;                                //global namespace std 

template <class T>                                  //template syntax

T division(T num1,T num2)                           // c++ function template 
{
        T ans;                                      //this function accepts 2 parameters
        ans = num1 / num2;                          //and returns division of that 2 parameters
        return ans;
}

int main()
{
          int i1 = 8,i2 = 2;                        //two integer numbers
          cout << "Division of two Integers :";
          cout << division(i1,i2) <<endl;           //template instantiation
          
          float f1 = 10.5f,f2 = 3.5f;               //two float numbers
          cout << "Division of two Floats   :";
          cout << division(f1,f2) <<endl;           //template instantiation 
               
          double a =15.5,b = 5.5;                   //two double numbers
          cout<<"Division of two Double   :";
          cout << division(a,b) <<endl;             //template instantiation
          
          getch();
          return 0;
}