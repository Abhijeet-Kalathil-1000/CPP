#include<iostream>

using namespace std;

int CountSpace(char *str)
{
    int iCnt = 0;
    while(*str != '\0')
    {
        if((*str == ' '))
        {
            iCnt++;
        }
        str++;
    }
    return iCnt;
}

int main()
{
    int iRet = 0;
    char Arr[20];

    cout<<"Enter string"<<endl;
    cin.getline(Arr,20);


    iRet = CountSpace(Arr);
    cout<<"no of white spcaces are : "<<iRet<<endl;

    return 0 ;
}