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


    float fNo1 = 11.1,fNo2 =21.2;
    cout<<"Before swap : "<<fNo1<<" "<<fNo2<<endl;
    SwapR(fNo1,fNo2);
    cout<<"After swap : "<<fNo1<<" "<<fNo2<<endl;


    char char1 = 'A',char2 = 'B';
    cout<<"Before swap : "<<char1<<" "<<char2<<endl;
    SwapR(char1,char2);
    cout<<"After swap : "<<char1<<" "<<char2<<endl;

    return 0;
}