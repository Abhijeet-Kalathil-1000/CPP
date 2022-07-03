#include"header163.h"

DoublyCLL::DoublyCLL()
{
    Head = NULL;
    Tail = NULL;
    CountNode = 0;
}

void DoublyCLL::InsertFirst(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(CountNode == 0)  //if((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }

    Head->prev = Tail;
    Tail->next = Head;

    CountNode++;
}

void DoublyCLL::InsertLast(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(CountNode == 0)  //if((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        newn->prev = Tail;
        Tail = newn;
    }
    
    Head->prev = Tail;
    Tail->next = Head;

    CountNode++;
}

void DoublyCLL::InsertAtPos(int iNo,int iPos)
{
    if((iPos < 1) || (iPos > CountNode+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == CountNode+1)
    {
        InsertLast(iNo);
    }
    else
    {
        int iCnt=0;
        PNODE newn = NULL,temp = NULL;
        newn = new NODE;

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        temp = Head;

        for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp = temp->next;
        }
        newn->prev = temp;
        temp->next->prev = newn;
        newn->next = temp->next;
        temp->next = newn;

        CountNode++;
    }
}

void DoublyCLL::DeleteFirst()
{
    if(CountNode == 0)
    {
        return;
    }
    else if (CountNode == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head= Head->next;
        delete Head->prev; // delete Tail->next;
        
    }
    Tail->next = Head;
    Head->prev = Tail;

    CountNode--;
}

void DoublyCLL::DeleteLast()
{
    if(CountNode == 0)
    {
        return;
    }
    else if (CountNode == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Tail = Tail->prev;
        delete Head->prev; // delete Tail->next;
    }
    Tail->next = Head;
    Head->prev = Tail;

    CountNode--;
}

void DoublyCLL::DeleteAtPos(int iPos)
{
    int iCnt =0;
    PNODE temp = NULL;

    if((iPos < 1) || (iPos > CountNode))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == CountNode)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp = temp->next;
        }
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        CountNode--;
    }
}

int DoublyCLL::Count()
{
    return CountNode;
}

void DoublyCLL::Display()
{
    int iCnt=0;
    PNODE temp = Head;

    for(iCnt = 1;iCnt<=CountNode;iCnt++)
    {
        cout<<"|"<<temp->data<<"| ->";
        temp = temp->next;
    }
    cout<<endl;
}


