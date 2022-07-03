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

Demo operator ++(Demo &op)  //PRE
{
    op.x++;
    op.y++;
    return op;
}

Demo operator ++(Demo &op,int)  //POST
{
    op.x++;
    op.y++;
    return Demo(op.x-1 , op.y-1);
}

Demo operator --(Demo &op)  //PRE
{
    op.x--;
    op.y--;
    return op;
}

Demo operator --(Demo &op,int)  //POST
{
    op.x--;
    op.y--;
    return Demo(op.x+1 , op.y+1);
}

int main ()
{
    Demo obj1(10,20);
    Demo obj2(10,20);
    Demo obj3(10,20);
    Demo obj4(10,20);

    Demo robj1(0,0);
    Demo robj2(0,0);
    Demo robj3(0,0);
    Demo robj4(0,0);

    robj1 = ++obj1;  //without dummy
    cout <<obj1.x<<" "<<obj1.y<<"\n";
    cout <<robj1.x<<" "<<robj1.y<<"\n";

    robj2 = obj2++;  //with dummy
    cout <<obj2.x<<" "<<obj2.y<<"\n";
    cout <<robj2.x<<" "<<robj2.y<<"\n";

    robj3 = --obj3;  //without dummy
    cout <<obj3.x<<" "<<obj3.y<<"\n";
    cout <<robj3.x<<" "<<robj3.y<<"\n";

    robj4 = obj4--;  //with dummy
    cout <<obj4.x<<" "<<obj4.y<<"\n";
    cout <<robj4.x<<" "<<robj4.y<<"\n";
    return 0 ;
}