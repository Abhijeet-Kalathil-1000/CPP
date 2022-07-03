#include<iostream>

using namespace std;

void strRevX(char *str)
{
    int iCnt = 0;
    char *start = str;
    char *end = str;
    char temp;

    while(*end != '\0')
    {
        end++;
    }
    end--;

    while(start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main()
{
    int iRet = 0;
    char Arr[20];

    cout<<"Enter string"<<endl;
    cin.getline(Arr,20);


    strRevX(Arr);
    cout<<"Reversed string is : "<<Arr<<endl;

    return 0 ;
}