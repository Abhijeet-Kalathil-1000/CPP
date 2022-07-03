#include<iostream>

using namespace std;

void strcpyX(char *src,char *dest)
{
    while(*src != '\0')
    {
        *dest=*src;
        src++;
        dest++;
    }   
    *dest = '\0';
}

int main()
{
    int iRet = 0;
    char Arr[20];
    char Brr[20];

    cout<<"Enter string"<<endl;
    cin.getline(Arr,20);


    strcpyX(Arr,Brr);
    cout<<"Copied string is : "<<Brr<<endl;

    return 0 ;
}