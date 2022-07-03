#include<iostream>
#include<conio.h>
using namespace std;                                 //global namespace std 

template <class T>                                   //template syntax

T max(T &a , T &b)                                   // c++ function template
{                                                    //this function accept 2 parameters 
        return a>b ? a:b ;                           //and returns maximum of that 2 parameters
}

template <class T>                                   //template syntax

T min(T &x ,T &y)                                    // c++ function template
{                                                    //this function accept 2 parameters
        return x<y ? x:y ;                           //and returns minimum of that 2 parameters
}

int main()
{
          int i1 = 8,i2 = 2;                         //two integer numbers
          cout << "Maximum of two Integers :";
          cout << max(i1,i2) <<endl;                 //template instantiation
          
          int i3 = 8,i4 = 2;                         //two integer numbers
          cout << "Minimum of two Integers :";
          cout << min(i3,i4) <<endl;                //template instantiation
          
          float f1 = 10.5f,f2 = 3.5f;               //two float numbers
          cout << "Maximum of two Floats   :";
          cout << max(f1,f2) <<endl;                //template instantiation 
               
          float f3 = 10.5f,f4 = 3.5f;               //two float numbers
          cout << "Minimum of two Floats   :";
          cout << min(f3,f4) <<endl;                //template instantiation 
          
          double a =15.5,b = 5.5;                   //two double numbers
          cout<<"Maximum of two Double   :";
          cout << max(a,b) <<endl;                  //template instantiation
          
          double c =15.5,d = 5.5;                   //two double numbers
          cout<<"Minimum of two Double   :";
          cout << min(c,d) <<endl;                  //template instantiation
          
          char  x= 'p', y = 'q';                    //two charaters 
          cout<<"Maximum of two Chararcter :";
          cout << max(x,y) <<endl;                  //template instantiation
          
          char  w= 'p', z = 'q';                    //two characters
          cout<<"Minimum of two Chararcter :";
          cout << min(w,z) <<endl;                  //template instantiation
          
          getch();
          return 0;
}