#include"header163.h"

int main()
{
    int iRet = 0;

    DoublyCLL dobj;

    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    dobj.InsertFirst(10);
    dobj.InsertFirst(1);

    dobj.InsertLast(51);
    dobj.InsertLast(101);
    dobj.InsertLast(111);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"No of nodes are : "<<iRet<<endl;

    return 0;
}

