#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Addition
//  Description     : Used to perform additojn of 2 numbers
//  Input           : Integer,Integer
//  Output          : Integer
//  Date            : 24/04/2022
//  Author          : Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////
int Addition(int iValue1,int iValue2)
{
    int iAns = 0;
    iAns = iValue1 + iValue2;
    return iAns;
}

////////////////////////////////////////////////////////////////////////
//  Write a Program to perfom addition of 2 numbers
////////////////////////////////////////////////////////////////////////
int main()
{
    int iNo1 = 0;
    int iNo2 = 0;
    int iNo3 = 0;

    cout<<"Enter value for iNo1 \n";
    cin>>iNo1;

    cout<<"Enter value for iNo2 \n";
    cin>>iNo2;

    iNo3 = Addition(iNo1,iNo2);
    cout<<"Additon is : "<<iNo3<<"\n";

    return 0;
}

////////////////////////////////////////////////////////////////////////
//
//  Input   :   11        10
//  Output  :   21
//
////////////////////////////////////////////////////////////////////////