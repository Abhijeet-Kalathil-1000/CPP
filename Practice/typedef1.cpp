#include<iostream>
using namespace std;
int main()
{
    struct Demo 
    {
        int no1;
        int no2;
    };

    typedef struct Demo DEMO;  //typedef for Demo

// Below is just an example of representation that can be used while coding not for printing vlaue.
// Reason : To print values we need '*p' but PDEMO has * included in it so cannot expecitly use the * to print ,PFB line 27,28 for solution.

    typedef struct Demo * PDEMO;    
    typedef struct Demo ** PPDEMO; 
    
//  struct Demo obj;
    DEMO obj;
    obj.no1 = 10;
    obj.no2 = 11;
    cout<<"Demo elements :\n"<<obj.no1<<"\n"<<obj.no2<<"\n";
    
   
//  struct Demo *p = &obj.no1;
    DEMO *p = &obj;         //To prnt value us can use DEMO in the mentioned format
    cout<<"Pointer P :"<<(*p).no1<<"\n";

//  struct Demo **q = &p;
    DEMO **q = &p;
    cout<<"Pointer q :"<<(**q).no2<<"\n";

    return 0;
}
