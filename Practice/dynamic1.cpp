#include<iostream>

using namespace std;

int main()
{
    int Arr[10];

    int *p = NULL;

    //p =(int *)malloc(sizeof(int)*10);

    p = new int[10];
    if (p==NULL)
    {
        cout<<"Not memory allocated";
    }
    else
    {
        cout<<"Memory gets allocated for "<<p<<"\n";
    }

    delete []p;

    return 0;
}