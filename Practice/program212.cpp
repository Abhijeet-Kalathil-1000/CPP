#include<iostream>
using namespace std;

template <class T>
void Display(T Arr[],int size)
{
    int iCnt = 0;
    for(iCnt = 0;iCnt<size;iCnt++)
    {
        cout<<Arr[iCnt]<<endl;
    }
}

int main()
{
    int  Brr[] = {10,20,30,40,50};
    Display(Brr,5);

    float  crr[] = {10.11,20.11,30.11,40.11,50.11};
    Display(crr,5);

    return 0;
}