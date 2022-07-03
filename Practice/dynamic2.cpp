#include<iostream>

using namespace std;

class Demo
{
    public:
    int x;
    int y;

    Demo()
    {
        cout<<"Default const\n";
    }

    ~Demo()
    {
        cout<<"Dest\n";
    }

    void fun()
    {
        cout<<"Inside fun\n";
    }
};

int main()
{
    Demo obj;   //Static Object creation

    Demo *ptr = NULL;

    ptr = new Demo; //Dynamic Object creation

    obj.fun();

    ptr->fun();

    delete ptr;

    return 0;
}