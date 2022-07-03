#include<iostream>
using namespace std;

#define MAX 10;

int main()
{
    typedef int NUMBER;
    typedef char LETTER;
    NUMBER no = 10;
    LETTER ch = 'M';

    cout<<sizeof(no)<<"\n";
    cout<<no<<"\n";

    cout<<sizeof(ch)<<"\n";
    cout<<ch<<"\n";

    typedef const int * CPTR;
    //const int *p = NULL;
    CPTR p = &no;

    cout<<*p<<"\n";

    return 0;
}
