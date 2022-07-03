#include<iostream>

using namespace std;

int CountVowels(char *str)
{
    int iCnt = 0;
    while(*str != '\0')
    {
        if((*str == 'a') || (*str == 'e') || (*str == 'i') || (*str == 'o') || (*str == 'u'))
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


    iRet = CountVowels(Arr);
    cout<<"no of Vowels are : "<<iRet<<endl;

    return 0 ;
}