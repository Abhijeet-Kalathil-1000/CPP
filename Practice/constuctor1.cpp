#include<iostream>

using namespace std;

class Demo
{
    public:
    int x;
    int y;

    Demo()
    {
        cout<<"Inside Default Constuctor\n";
    }

    Demo(int i, int j)
    {
        cout<<"Inside Parameterized Constuctor\n";
    }

    Demo(Demo &ref)
    {
        cout<<"Inside Copy Constuctor\n";
    }

    ~Demo()
    {
        cout<<"Inside Destructor\n";
    }
};

int main()
{
    cout<<"Inside main\n";
    Demo obj1(11,21);
    cout<<"End of main\n";
    return 0;
}