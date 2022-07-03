#include<iostream>
using namespace std;

class Demo
{
    public:
        int i;
        const int j;

        Demo() : j(20) //member initialization 
        {
            i = 10;
            //j = 20;

        }

        Demo(int a,int b):j(b)
        {
            i =a
            cout<<"Inside Paramenterized \n";
        }

        void fun()
        {
            cout<<"Inside fun\n";
            i++;
            //j++;
        }

        void gun() const
        {
            cout<<"Inside fun\n";
            i++;
            j++;
        }
        
};

int main ()
{
    Demo obj(11,21);


    cout<<obj.i<<"\n";
    cout<<obj.j<<"\n";

    obj.j++;

    return 0;
}