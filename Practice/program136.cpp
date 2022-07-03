#include<iostream>

using namespace std;

int Fact(int iNo)
{
    int iCnt = 0,iFact=1;

    for(iCnt=1;iCnt<=iNo;iCnt++)
    {
        //iFact = iFact*iCnt;

        // Using short hand operator
        iFact *= iCnt;  //fancy coding 
    }
    return iFact;
}

int main()
{
    int iValue = 0,iRet = 0;

    cout<<"Enter a value : \n";
    cin>>iValue;

    iRet = Fact(iValue);

    cout<<"Factorial is : "<<iRet<<endl;

    return 0;
}
