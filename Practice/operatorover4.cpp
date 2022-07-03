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

bool operator ==(Demo op1 , Demo op2)
{
    if((op1.x == op2.x) && (op1.y == op2.y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator <=(Demo op1 , Demo op2)
{
    if((op1.x <= op2.x) && (op1.y <= op2.y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator >=(Demo op1 , Demo op2)
{
    if((op1.x >= op2.x) && (op1.y >= op2.y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator <(Demo op1 , Demo op2)
{
    if((op1.x < op2.x) && (op1.y < op2.y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator >(Demo op1 , Demo op2)
{
    if((op1.x > op2.x) && (op1.y > op2.y))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main ()
{
    Demo obj1(113,22);
    Demo obj2(111,21);

    if(obj1 == obj2)
    {
        cout<<"Objects are same\n";
    }
    else
    {
        cout<<"Objects are not same\n";
    }

    if(obj1 <= obj2)
    {
        cout<<"Object1 is greater than Object2\n";
    }
    else
    {
        cout<<"Object1 is not greater than Object2\n";
    }

    return 0 ;
}