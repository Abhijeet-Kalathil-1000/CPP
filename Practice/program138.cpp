#include<iostream>

using namespace std;

class Number
{   
    private:
        int iNo;        //Caharachteristics

    public:             //Behaviours

        void Accept()
        {
            cout<<"Enter the value : "<<endl;
            cin>>this->iNo;
        }

        void Display()
        {
            cout<<"Value is : "<<this->iNo<<endl;    
        }

        int Fact()
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

    int iRet = 0;

    //cout<<nobj.iNo        unaccessbale as private in class 

    nobj.Accept();
    nobj.Display();

    iRet = nobj.Fact();
    cout<<"Factorial is : "<<iRet<<endl;

    return 0;
}
