#include<iostream>

using namespace std;

int strlenX(char *str)
{
    int strCount = 0;
    while(*str != '\0')
    {
        str++;
        strCount++;
    }
    return strCount;
}

int main()
{
    int iRet = 0;
    char Arr[20];

    cout<<"Enter string"<<endl;
    cin.getline(Arr,20);

    iRet = strlenX(Arr);
    cout<<"Length is : "<<iRet<<endl;

    return 0 ;
}