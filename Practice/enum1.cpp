#include<iostream>
using namespace std;

int main ()
{
    enum Marvellous_Batches {PPA = 0,LB = 1,LSP = 2} ;
    const int Fees[] = {15000,16000,17000,18000};
    const float Duration[] = {3.5,4.0,3.5,4.5};
    int choice = 0;

    cout<<"Select the batch your want to join\n";
    cout<<"0 : PPA\n";
    cout<<"1 : LB\n";
    cout<<"2 : LSP\n";
    cin>>choice;
    switch(choice)
    {
        case PPA:
            cout<<"Welcome to PPA \n";
            cout<<"Duration is :"<<Duration[PPA]<<"\n";
            cout<<"Fee is :"<<Fees[PPA]<<"\n";
            break;
            
        case LB:
            cout<<"Welcome to LB \n";
            cout<<"Duration is :"<<Duration[LB]<<"\n";
            cout<<"Fee is :"<<Fees[LB]<<"\n";
            break;
        
        case LSP:
            cout<<"Welcome to LSP \n";
            cout<<"Duration is :"<<Duration[LSP]<<"\n";
            cout<<"Fee is :"<<Fees[LSP]<<"\n";
            break;

        default:
            cout<<"Sorry no such batch \n";
            cout<<"Contact admin\n";
            break;
    }
    return 0;
}