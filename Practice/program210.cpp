#include<iostream>
using namespace std;

int Addition(int A,int B)
{
    int Ans;
    Ans = A + B;
    return Ans;
}

int main()
{
    int No1 = 11, No2 =21;
    int ret = 0;

    ret = Addition(No1,No2);

    cout<<"Addition is : "<<ret<<endl;
    
    return 0;
}