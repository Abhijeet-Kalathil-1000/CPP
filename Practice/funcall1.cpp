#include<iostream>

using namespace std;

void CallValue(int no)
{
    no++;
}

void CallAddress(int *p)
{
    (*p)++;
}

void CallReference(int &ref)
{
    ref++;
}

int main()
{
    int a=10, b=10, c=10;

    CallValue(a);
    cout<<a<<"\n";
    
    CallAddress(&b);
    cout<<b<<"\n";
    
    CallReference(c);
    cout<<c<<"\n";

    return 0;
}