//////////////////////////////////////////////////////////////////////////////////////////////////
//  Write a Program on Genric Singly Linear Linked List and all 8 fucntions
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
//  Structure of a Node of Genric Singly Linear Linked List
////////////////////////////////////////////////////////////////////////////////////////

struct sNode
{
    int iData;
    struct sNode *Next;
};

////////////////////////////////////////////////////////////////////////////////////////
//  Using typedef for better readablity
////////////////////////////////////////////////////////////////////////////////////////

typedef struct sNode NODE;
typedef struct sNode * PNODE;
typedef struct sNode ** PPNODE;

////////////////////////////////////////////////////////////////////////////////////////
//
// Class Name :  SinglyLLL
// Description :    Class contaimns functions of a Singly Linear Linked List
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

class SinglyLLL
{
    private:
        PNODE Head;
        PNODE Tail;

    public:
        SinglyLLL();
        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPosition(int iNo, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int iPos);
        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////
//      Default Constructor : SinglyLLL
////////////////////////////////////////////////////////////////////////////////////////

SinglyLLL::SinglyLLL()
{
    Head = NULL;
    Tail = NULL;
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertFirst
// Description :    Used to Insert First node in the Singly Linear Linked List
// Input :          Integer
// Output :         NA
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

void SinglyLLL::InsertFirst(int iNo)
{
    PNODE NewNode = NULL;

    NewNode = new NODE;
    NewNode -> iData =iNo;
    NewNode -> Next = NULL;

    if(Head == NULL)
    {
        Head = NewNode;
    }
    else
    {
        NewNode -> Next = Head;
        Head = NewNode;
    }
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertLast
// Description :    Used to Insert Last node in the Singly Linear Linked List
// Input :          Integer
// Output :         NA
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

void SinglyLLL::InsertLast(int iNo)
{
    PNODE NewNode = NULL,Temp =NULL;

    NewNode = new NODE;
    NewNode -> iData =iNo;
    NewNode -> Next = NULL;

    if(Head == NULL)
    {
        Head = NewNode;
    }
    else
    {
        Temp = Head;
        while(Temp -> Next != NULL)
        {
            Temp = Temp -> Next;
        }
        Temp -> Next = NewNode;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertAtPosition
// Description :    Used to Insert node at speific Position in the Singly Linear Linked List
// Input :          Integer , Integer
// Output :         NA
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
///////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLLL::InsertAtPosition(int iNo ,int iPos)  
{
    int iSize = 0,iCnt=0;
    PNODE NewNode = NULL, Temp = NULL;


    iSize = Count();
    if(( iPos> (iSize+1)) || ( iPos< 1))
    {
        cout<<"Enter a valid position";
        return;
    }
    if( iPos== 1)
    {
        InsertFirst(iNo);
    }
    else if( iPos== (iSize-1))
    {
        InsertLast(iNo);
    }
    else
    {
        NewNode = new NODE;
        
        NewNode -> iData =iNo;
        NewNode -> Next = NULL;
        
        Temp = Head;
        for(iCnt =1;iCnt<(iPos-1);iCnt++)
        {
            Temp = Temp -> Next;
        }
        NewNode -> Next = Temp -> Next;
        Temp -> Next = NewNode;
    }
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteFirst
// Description :    Used to Delete First node in the Singly Linear Linked List
// Input :          NA
// Output :         NA
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

void SinglyLLL::DeleteFirst()
{
    PNODE Temp = NULL;
    Temp = Head;
    if(Head == NULL)
    {
        return;
    }
    else
    {
        Head = Head -> Next;
        delete(Temp);
    }
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteLast
// Description :    Used to Delete Last  node in the Singly Linear Linked List
// Input :          NA
// Output :         NA
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

void SinglyLLL::DeleteLast()
{
    PNODE Temp = NULL,tempDelete = NULL;
    if((Head) == NULL)
    {
        cout<<"No node in the list";
        return;
    }
    else
    {
        Temp = Head;
        while(Temp -> Next -> Next !=NULL)
        {
            Temp = Temp -> Next;
        }
        tempDelete = Temp -> Next;
        Temp -> Next = NULL;
        delete(tempDelete);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteAtPosition
// Description :    Used to Delete node at specific Position in the Singly Linear Linked List
// Input :          Integer
// Output :         NA
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
///////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLLL::DeleteAtPosition(int iPos)
{
    int iSize = 0,iCnt=0;
    PNODE NewNode = NULL,Temp = NULL,tempDelete = NULL;


    iSize = Count();
    if(( iPos> (iSize+1)) || ( iPos< 1))
    {
        cout<<"Enter a valid position";
        return;
    }
    if( iPos== 1)
    {
        DeleteFirst();
    }
    else if( iPos== (iSize-1))
    {
        DeleteLast();
    }
    else
    {        
    Temp= Head;
        for(iCnt =1;iCnt<( iPos-1);iCnt++)
        {
            Temp = Temp -> Next;
        }
        tempDelete = Temp -> Next;
        Temp -> Next = Temp -> Next -> Next;
        delete(tempDelete);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Display
// Description :    Used to Display node Singly Linear Linked List
// Input :          NA
// Output :         NA
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
///////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLLL::Display()
{
    PNODE Temp = Head;

    if(Head == NULL)
    {
        cout<<"No node in the list";
        return;
    }

    while(Temp != NULL)
    {
        cout<<"|"<<Temp->iData<<"| ->";
        Temp = Temp->Next;
    }
    cout<<endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  CountNode
// Description :    Used to Count Node in Singly Linear Linked List
// Input :          NA
// Output :         Integer
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
///////////////////////////////////////////////////////////////////////////////////////////////

int SinglyLLL::Count()
{
    int iNodeCnt = 0;
    while(Head!= NULL)
    {
        iNodeCnt++;
        Head = Head -> Next;
    }
    return iNodeCnt;
}


int main()
{   
    int iRet = 0;
    SinglyLLL obj;
    
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