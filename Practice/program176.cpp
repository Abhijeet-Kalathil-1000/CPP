#include<iostream>

using namespace std;

int CountUppercase(char *str,char letter)
{
    int iCnt = 0;
    while(*str != '\0')
    {
        if((*str >= 'A') && (*str <= 'Z'))
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
    char letter ='\0' ;

    cout<<"Enter string"<<endl;
    cin.getline(Arr,20);


    iRet = CountUppercase(Arr,letter);
    cout<<" Count of Uppercase is : "<<iRet<<endl;

    return 0 ;
}