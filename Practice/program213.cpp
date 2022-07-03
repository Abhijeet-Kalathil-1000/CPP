#include<iostream>
using namespace std;

/*
int Max(int Arr[],int size)
{
    int Max = Arr[0];
    int iCnt = 0;

    for(iCnt=0;iCnt<size;iCnt++)
    {
        if(Arr[iCnt] > Max)
        {
            Max = Arr[iCnt];
        }
    }
    return Max;
}
*/

template<class T>
T Max(T Arr[],int size)
{
    T Max = Arr[0];
    int iCnt = 0;

    for(iCnt=0;iCnt<size;iCnt++)
    {
        if(Arr[iCnt] > Max)
        {
            Max = Arr[iCnt];
        }
    }
    return Max;
}

int main()
{
    int  Brr[] = {100,20,70,40,50};
    int Ret;

    Ret = Max(Brr,5);

    cout<<Ret<<endl;

    return 0;
}