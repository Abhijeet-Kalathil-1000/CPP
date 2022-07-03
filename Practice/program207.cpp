#include<iostream>
using namespace std;

template <class T>
void SwapR(T &p,T &q)
{
    T temp;
    temp = p;
    p = q;
    q = temp;
}

int main()
{
    int No1 = 11,No2 =21;

    cout<<"Before swap : "<<No1<<" "<<No2<<endl;

    SwapR(No1,No2);

    cout<<"After swap : "<<No1<<" "<<No2<<endl;


    return 0;
}