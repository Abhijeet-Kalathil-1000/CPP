#include<iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   DisplayNonFactors
//  Description         :   Displays Non-factors of given decimal number
//  Input               :   Integer
//  Output              :   Integer
//  Author              :   Abhijeet Saji Kalathil
//  Date                :   26/04/2022
//
//////////////////////////////////////////////////////////////////////////////////

void DisplayNonFactors(int iNo)
{
    int iCnt = 0;
    
    for(iCnt = 1;iCnt <(iNo);iCnt++)

//  Time complexity : N
        {
            if ((iNo % iCnt) != 0)
            {
                cout<<iCnt<<" ";
            }
        }
}

//////////////////////////////////////////////////////////////////////////////////
//Accept number from user and display its factors
//////////////////////////////////////////////////////////////////////////////////

int main()
{
    int iValue = 0;
        
    cout<<"Enter a number to check its non-factors : ";
    cin>>iValue;

    DisplayNonFactors(iValue);

    return 0;
}


//////////////////////////////////////////////////////////////////////////////////
//
//  Input       :       5
//  Output      :       2   3   4
//
//////////////////////////////////////////////////////////////////////////////////