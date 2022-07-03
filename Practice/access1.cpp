#include<iostream>

using namespace std;

class Demo
{
    public:
        int x;

    private:
        int y;

    public:
        Demo()
        {
            x = 10;
            y = 20;
            i = 30;
        }

        void fun()
        {
            cout<<"Inside Public Function\n";
        }

    private:
        void gun()   
        {
            cout<<"Inside Private Function\n";
        }
};

int main()
{
    Demo obj;

    cout<<obj.x<<"\n";
    cout<<obj.y<<"\n";
    cout<<obj.i<<"\n";

    return 0;
}