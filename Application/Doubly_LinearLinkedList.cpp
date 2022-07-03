//////////////////////////////////////////////////////////////////////////////////////////////////
//  Write a Program on Doubly Linear Linked List and all 8 fucntions
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
//  Structure of a Node of Doubly Linear Linked List
////////////////////////////////////////////////////////////////////////////////////////

struct sNode
{
    int iData;
    struct sNode *Next;
    struct sNode *Prev;
};

////////////////////////////////////////////////////////////////////////////////////////
//  Using typedef to increase readablity of the program
////////////////////////////////////////////////////////////////////////////////////////

typedef struct sNode NODE;

typedef struct sNode * PNODE;

////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :     DoubllyLLL
//  Description :    Has defination of all fucntions of a Doubly Linear Linked List
//  Date :           20/06/2022
//  Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

class DoubllyLLL
{   
    private:            //Charachteristics
        PNODE Head;

    public:             //Behaviour

        DoubllyLLL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no ,int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////
//      Default Constructor
////////////////////////////////////////////////////////////////////////////////////////

    DoubllyLLL::DoubllyLLL()
    {
        Head = NULL;
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

    void DoubllyLLL::InsertFirst(int iNo)
    {
        PNODE NewNode = NULL;

        NewNode = new NODE;
        NewNode -> iData =iNo;
        NewNode -> Next = NULL;
        NewNode->Prev = NULL;

        if(Head == NULL)
        {
            Head = NewNode;
        }
        else
        {
            Head -> Prev = NewNode;
            NewNode -> Next = Head;
            Head = NewNode;
        }
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

    void DoubllyLLL::InsertLast(int iNo)
    {
        PNODE NewNode = NULL,Temp =NULL;

        NewNode = new NODE;
        NewNode -> iData =iNo;
        NewNode -> Next = NULL;
        NewNode -> Prev = NULL;

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
            NewNode -> Prev = Temp;
        }
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

    void DoubllyLLL::InsertAtPos(int iNo ,int iPos)  
    {
        int iSize = 0,iCnt=0;

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
            PNODE NewNode = NULL, Temp = NULL;

            NewNode = new NODE;
            
            NewNode -> iData =iNo;
            NewNode -> Next = NULL;
            NewNode -> Prev = NULL;
            
            Temp = Head;
            for(iCnt =1;iCnt<(iPos-1);iCnt++)
            {
                Temp = Temp -> Next;
            }
            NewNode -> Next = Temp -> Next;
            Temp -> Next -> Prev = NewNode;
            NewNode -> Prev = Temp;
            Temp -> Next = NewNode;
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

    void DoubllyLLL::DeleteFirst()
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
            Head -> Prev = NULL;

            delete(Temp);
        }
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

    void DoubllyLLL::DeleteLast()
    {
        PNODE Temp = NULL,tempDelete = NULL;
        if((Head) == NULL)
        {
            cout<<"No node in the list";
            return;
        }
        else if(Head->Next == NULL)
        {
            delete Head;
            Head = NULL;
        }
        else
        {
            Temp = Head;
            while(Temp -> Next !=NULL)
            {
                Temp = Temp -> Next;
            }
            Temp->Prev->Next = NULL ;
            delete Temp;
        }
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

    void DoubllyLLL::DeleteAtPos(int iPos)
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
            Temp -> Next = Temp -> Next -> Next;
            delete Temp -> Next -> Prev;
            Temp -> Next -> Prev = Temp;
        }
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

    void DoubllyLLL::Display()
    {
        PNODE Temp = Head;

        if(Head == NULL)
        {
            cout<<"No node in the list";
            return;
        }
        cout<<"|NULL| ->";
        while(Temp != NULL)
        {
            cout<<"|"<<Temp->iData<<"| ->";
            Temp = Temp->Next;
        }
        cout<<"|NULL|";
        cout<<endl;
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

    int DoubllyLLL::Count()
    {
        int iNodeCnt = 0;
        PNODE Temp = Head;
        while(Temp!= NULL)
        {
            iNodeCnt++;
            Temp = Temp -> Next;
        }
        return iNodeCnt;
    }

//////////////////////////////////////////////////////////////////////////////////////////////////
//  Main fucntion
//////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{   
    int iRet = 0;
    DoubllyLLL obj;
    
    //Inserting Values
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.InsertLast(201);
        
    // Display the nodes of Linked List
    obj.Display();
    // Counting the nodes of Linked List
    iRet = obj.Count();
    cout<<"Count is : "<<iRet<<"\n"<<endl;

    //Inserting Values at specfic position on a Linked List
    obj.InsertAtPos(75,4);
    obj.DeleteLast();
    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout<<"Count is : "<<iRet<<endl;

    obj.DeleteAtPos(4);
    obj.Display();

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//              OUTPUT:
//
//  |NULL| ->|11| ->|21| ->|51| ->|101| ->|111| ->|121| ->|151| ->|201| ->|NULL|
//  Count is : 8
//
//  |NULL| ->|21| ->|51| ->|75| ->|101| ->|111| ->|121| ->|151| ->|NULL|
//  Count is : 7
//
//  |NULL| ->|21| ->|51| ->|75| ->|111| ->|121| ->|151| ->|NULL|
//
//////////////////////////////////////////////////////////////////////////////////////////////////