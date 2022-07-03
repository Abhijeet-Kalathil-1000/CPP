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

        friend Demo operator + (Demo op1,Demo op2);

};

Demo operator + (Demo op1,Demo op2)
{
    cout<<"Inside + Operator\n";
    return Demo(op1.x + op2.x,op1.y + op2.y);
}

int main ()
{
    Demo obj1(11,21);
    Demo obj2(51,101);
    Demo robj(0,0);

    robj = obj1 + obj2;
    cout<<robj.x<<"\n"<<robj.y;

    return 0 ;
}