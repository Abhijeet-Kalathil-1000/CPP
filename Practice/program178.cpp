#include<iostream>

using namespace std;

int CountLowercase(char *str)
{
    int iCnt = 0;
    while(*str != '\0')
    {
        if((*str >= 'a') && (*str <= 'z'))
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


    iRet = CountLowercase(Arr);
    cout<<" Count of Lowercase is : "<<iRet<<endl;

    return 0 ;
}