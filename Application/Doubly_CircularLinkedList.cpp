//////////////////////////////////////////////////////////////////////////////////////////////////
//  Write a Program on Doubly Circular Linked List and all 8 fucntions
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
//  Structure of a Node of Doubly Circular Linked List
////////////////////////////////////////////////////////////////////////////////////////

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

////////////////////////////////////////////////////////////////////////////////////////
//  Using typedef to increase readablity of the program
////////////////////////////////////////////////////////////////////////////////////////

typedef struct node NODE;

typedef struct node * PNODE;

////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :     DoublyCLL
//  Description :    Has defination of all fucntions of a Doubly Circular Linked List
//  Date :           20/06/2022
//  Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

class DoublyCLL
{
    private:                //Charachteristics
        PNODE Head;
        PNODE Tail;
        int CountNode;

    public:                 //Behaviour
        DoublyCLL();
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        int Count();
        void Display();
};

////////////////////////////////////////////////////////////////////////////////////////
//      Default Constructor
////////////////////////////////////////////////////////////////////////////////////////

DoublyCLL::DoublyCLL()
{
    Head = NULL;
    Tail = NULL;
    CountNode = 0;
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertFirst
// Description :    Used to Insert First node in the Doubly Linear Linked List
// Input :          Integer
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertLast
// Description :    Used to Insert Last node in the Doubly Linear Linked List
// Input :          Integer
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertAtPos
// Description :    Used to Insert at specifed postion in the Doubly Linear Linked List
// Input :          Integer,Integer
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteFirst
// Description :    Used to Delete First node in the Doubly Linear Linked List
// Input :          NA
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteLast
// Description :    Used to Delete Last node in the Doubly Linear Linked List
// Input :          NA
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteAtPos
// Description :    Used to Delete at specifed postion in the Doubly Linear Linked List
// Input :          Integer
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

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
        temp = Head;
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


////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Count
// Description :    Used to Count the Doubly Linear Linked List
// Input :          NA
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

int DoublyCLL::Count()
{
    return CountNode;
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Display
// Description :    Used to Display the Doubly Linear Linked List
// Input :          NA
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////
//  Main fucntion
//////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int iRet = 0;

    DoublyCLL dobj;

    //Inserting Values
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    dobj.InsertFirst(10);
    dobj.InsertFirst(1);

    dobj.InsertLast(51);
    dobj.InsertLast(101);
    dobj.InsertLast(111);

    // Display the nodes of Linked List
    dobj.Display();
    // Counting the nodes of Linked List
    iRet = dobj.Count();
    cout<<"No of nodes are : "<<iRet<<endl;

    //Inserting Values at specfic position on a Linked List
    dobj.InsertAtPos(75,4);
    dobj.DeleteLast();
    dobj.DeleteFirst();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Count is : "<<iRet<<endl;

    dobj.DeleteAtPos(4);
    dobj.Display();

    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//              OUTPUT:
//
//    |1| ->|10| ->|11| ->|21| ->|51| ->|101| ->|111| ->
//    No of nodes are : 7
//
//    |10| ->|11| ->|75| ->|21| ->|51| ->|101| ->
//    Count is : 6
//
//    |10| ->|11| ->|75| ->|51| ->|101| ->
//
//////////////////////////////////////////////////////////////////////////////////////////////////