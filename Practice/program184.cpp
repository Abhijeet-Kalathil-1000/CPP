#include<iostream>

using namespace std;

void strlwrX(char *str)
{
    int iCnt = 0;
    while(*str != '\0')
    {
        if((*str>='A') && (*str <= 'Z'))
        {
            *str =*str+32;
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


    strlwrX(Arr);
    cout<<"in lowecase : "<<Arr<<endl;

    return 0 ;
}