#include<iostream>
using namespace std;

class Demo
{   
    public:
        int x;
        int y;

        Demo(int i = 10, int j = 20)
        {
            x = i;
            y = j;
        } 
};

Demo operator +(Demo op)
{
    return op;
}

Demo operator -(Demo op)
{
    return Demo(-op.x,-op.y);
    //return -op;
}

int main ()
{
    Demo obj1(11,-21);
    Demo obj2(51,-101);
    Demo robj1(0,0);
    Demo robj2(0,0);

    robj1 = +obj1;
    cout <<robj1.x<<"\n"<<robj1.y<<"\n";

    robj2 = -obj2;
    cout <<robj2.x<<"\n"<<robj2.y<<"\n";
    return 0 ;
}