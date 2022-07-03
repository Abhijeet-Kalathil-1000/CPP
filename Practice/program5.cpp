#include<iostream>
using namespace std;

int Display(int iValue1,int iValue2)
{
    int iAns = 0;

    iAns = iValue1 + iValue2;
return iAns;
}

int main()
{
    int iNo1 = 0;
    int iNo2 = 0;
    int iNo3 = 0;

    cout<<"Enter value for iNo1 \n";
    cin>>iNo1;

    cout<<"Enter value for iNo2 \n";
    cin>>iNo2;

    iNo3 = Display(iNo1,iNo2);

    cout<<"Additon is : "<<iNo3<<"\n";

    return 0;

}
