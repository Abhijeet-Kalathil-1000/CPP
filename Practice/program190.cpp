#include<iostream>

using namespace std;

void strcatX(char *str1,char *str2)
{
    while(*str1 != '\0')
    {
        str1++;
    }

    while(*str2 != '\0')
    {
        *str1=*str2;
        str1++;
        str2++;
    }   
    *str1 = '\0';
}

int main()
{
    int iRet = 0;
    char Arr[20];
    char Brr[20];

    cout<<"Enter 1st string"<<endl;
    cin.getline(Arr,20);

    cout<<"Enter 2nd string"<<endl;
    cin.getline(Brr,20);

    strcatX(Arr,Brr);
    cout<<"Concatinated string is : "<<Arr<<endl;

    return 0 ;
}