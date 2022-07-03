//PPA chi punyayi (15 wasool)

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyCLL
{   
    private:            //Charachteristics
        PNODE Head;
        PNODE Tail;

    public:             //Behaviour

        SinglyCLL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPosition(int no ,int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);
        void Display();
        int Count();
};

SinglyCLL::SinglyCLL()
{
    Head = NULL;
    Tail = NULL;
}

void SinglyCLL::InsertFirst(int no)
{
    PNODE newn = NULL;
    
    newn= new NODE;

    newn->data = no;
    newn->next = NULL;

    if((Head == NULL) && (Tail == NULL))       //If LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else        //if LL contains atlest 1 node
    {
        newn->next = Head;
        Head =newn;
    }
    Tail->next = Head;
}
void SinglyCLL::InsertLast(int no)
{
    PNODE newn = NULL;
    
    newn= new NODE;

    newn->data = no;
    newn->next = NULL;

    if((Head == NULL) && (Tail == NULL))       //If LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else        //if LL contains atlest 1 node
    {
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head;
}

void SinglyCLL::InsertAtPosition(int no ,int ipos)
{
    PNODE temp = Head;

    int iSize = 0,iCnt = 0;
    iSize =Count();

    if((ipos<1)||(ipos >iSize+1))
    {
        cout<<"Invlaid posostion\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == iSize+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = NULL;
        
        newn= new NODE;

        newn->data = no;
        newn->next = NULL; 

        for(iCnt=1;iCnt<(ipos-1);iCnt++)
        {
            temp = temp->next;
        }
        newn->next=temp->next;
        temp->next = newn;
    }

}
void SinglyCLL::DeleteFirst()
{
    PNODE temp;

    if((Head ==NULL) && (Tail==NULL))
    {
        return;
    }
    else if(Head == Tail)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head ->next;
        delete Tail->next;
        Tail->next = Head;
    }

}
void SinglyCLL::DeleteLast()
{

    if((Head ==NULL) && (Tail==NULL))
    {
        return;
    }
    else if(Head == Tail)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        PNODE temp = Head;
        while(temp->next != Tail)
        {
            temp = temp->next;
        }

        delete(Tail);
        Tail = temp;

        Tail->next = Head;
    }

}
void SinglyCLL::DeleteAtPosition(int ipos)
{
    PNODE temp1 = Head;
    PNODE temp2 = Head;

    int iSize = 0,iCnt = 0;
    iSize =Count();

    if((ipos<1)||(ipos >iSize))
    {
        cout<<"Invlaid posostion\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iSize)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt=1;iCnt<(ipos-1);iCnt++)
        {
            temp1 = temp1->next;
        }    
        temp2 = temp1 -> next;
        temp1->next = temp2->next;
        delete temp2;
    }
}

void SinglyCLL::Display()
{
    PNODE temp = Head;

    if((Head == NULL) && (Tail == NULL))       //If LL is empty
    {
        cout<<"No node in the list";
        return;
    }
        do 
    {
        cout<<"|"<<temp->data<<"| ->";
        temp = temp->next;
    }
    while(temp != Tail->next);
    
    cout<<endl;
}

int SinglyCLL::Count()
{
    int iSize = 0;
    PNODE temp = Head;

    if((Head == NULL) && (Tail == NULL))       //If LL is empty
    {
        cout<<"No node in the list";
        return 0;
    }
    do 
    {
        iSize++;
        temp = temp->next;
    }
    while(temp != Tail->next);
    
    return iSize;
}

int main()
{   
    int iRet = 0;
    SinglyCLL obj;
    
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.InsertLast(201);
        
    obj.Display();
    iRet = obj.Count();
    cout<<"Count is : "<<iRet<<"\n"<<endl;

    obj.InsertAtPosition(75,4);
    
    obj.Display();
    iRet = obj.Count();
    cout<<"Count is : "<<iRet<<endl;

    obj.DeleteAtPosition(4);
    obj.Display();

    return 0;
}