#include<iostream>

using namespace std;

void struprX(char *str)
{
    int iCnt = 0;
    while(*str != '\0')
    {
        if((*str>='a') && (*str <= 'z'))
        {
            *str =*str-32;
        }
        str++;
    }
}

int main()
{
    int iRet = 0;
    char Arr[20];

    cout<<"Enter string"<<endl;
    cin.getline(Arr,20);


    struprX(Arr);
    cout<<"In Upperrcase : "<<Arr<<endl;

    return 0 ;
}