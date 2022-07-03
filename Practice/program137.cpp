#include<iostream>

using namespace std;

class Number
{   
    public:
    int Fact(int iNo)
    {
        int iCnt = 0,iFact=1;

        for(iCnt=1;iCnt<=iNo;iCnt++)
        {
            iFact = iFact*iCnt;
        }
        return iFact;
    }
};

int main()
{
    Number nobj;

    int iValue = 0,iRet = 0;

    cout<<"Enter a value : \n";
    cin>>iValue;

    iRet = nobj.Fact(iValue);

    cout<<"Factorial is : "<<iRet<<endl;

    return 0;
}
