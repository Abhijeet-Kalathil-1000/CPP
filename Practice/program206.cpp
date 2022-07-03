#include<iostream>
using namespace std;

void SwapR(int &p,int &q)
{
    int temp;
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