#include<iostream>

using namespace std;

class Arithmetic
{


    public:
    int iNo1;
    int iNo2;

    Arithmetic() // Default Construtor
    {
        cout<<"Inside default Construtor\n";
        iNo1=0;
        iNo2=0;
    }

    Arithmetic(int A,int B) // Parameterised Construtor
    {
        cout<<"Inside Parameterised Construtor\n";
        iNo1=A;
        iNo2=B;
    }

    ~Arithmetic() // Destructor
    {
        cout<<"Inside Destructor\n";
    }

    int Addition()
    {
        int iAns = 0;
        iAns = iNo1 + iNo2;
        return iAns;
    }

    int Substraction()
    {
        int iAns = 0;
        iAns = iNo1 - iNo2;
        return iAns;
    }
};

int main()
{
    int iValue1=0, iValue2=0, iRet=0;

    cout<<"Enter first number\n";
    cin>>iValue1;

    cout<<"Enter second number\n";
    cin>>iValue2;

    Arithmetic obj1;
    Arithmetic obj2(iValue1,iValue2);

    iRet= obj2.Addition();
    cout<<"Addition is : "<<iRet<<"\n";

    iRet= obj2.Substraction();
    cout<<"Substraction is : "<<iRet<<"\n";

    return 0;
}