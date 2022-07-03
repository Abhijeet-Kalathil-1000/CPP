#include<iostream>

using namespace std;

int cntLetter(char *str,char letter)
{
    int strCount = 0;
    while(*str != '\0')
    {
        str++;
        if(*str == letter)
        {
            strCount++;
        }
    }
    return strCount;
}

int main()
{
    int iRet = 0;
    char Arr[20];
    char letter ='\0' ;

    cout<<"Enter string"<<endl;
    cin.getline(Arr,20);

    cout<<"Enter the letter for count "<<endl;
    cin>>letter;


    iRet = cntLetter(Arr,letter);
    cout<<" repetation is : "<<iRet<<endl;

    return 0 ;
}