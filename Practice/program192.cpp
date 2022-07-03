#include<iostream>

using namespace std;

bool strcmpX(char *src,char *dest)
{

    while((*src != '\0') && (*dest != '\0'))
    {
        if((*src == *dest) || (*src == *dest+32) || (*src == *dest-32) || (*src+32 == *dest) || ((*src-32 == *dest)))
        {
        src++;
        dest++;
        }
        else
        {
            break;
        }
    }
        
    if(*src == '\0' && *dest=='\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    bool bRet = false;
    char Arr[20];
    char Brr[20];

    cout<<"Enter 1st string"<<endl;
    cin.getline(Arr,20);

    cout<<"Enter 2nd string"<<endl;
    cin.getline(Brr,20);

    bRet =strcmpX(Arr,Brr);
    
    if(bRet == true)
    {
        cout<<"String is same"<<endl;
    }
    else
    {
        cout<<"String is not same"<<endl;
    }

    return 0 ;
}