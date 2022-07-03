//////////////////////////////////////////////////////////////////////////////////////////////////
//  Write a Program on Genric Singly Circular Linked List and all 8 fucntions
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
//  Structure of a Node of Genric Singly Circular Linked List
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
// Description :    Class contaimns functions of a Singly Circular Linked List
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

class SinglyLLL
{
    private:
        PNODE Head;
        PNODE Tail;
        int CountNode;

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
    CountNode = 0;
}


////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertFirst
// Description :    Used to Insert First node in the Singly Circular Linked List
// Input :          Integer
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

void SinglyLLL::InsertFirst(int iNo)
{
    PNODE NewNode = NULL;

    NewNode = new NODE;
    NewNode -> iData =iNo;
    NewNode -> Next = NULL;

    if((Head == NULL)&&(Tail == NULL))
    {
        Head = NewNode;
        Tail = NewNode;
    }
    else
    {
        NewNode -> Next = Head;
        Head = NewNode;
    }
    Tail->Next = Head;

    CountNode++;
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertLast
// Description :    Used to Insert Last node in the Singly Circular Linked List
// Input :          Integer
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

void SinglyLLL::InsertLast(int iNo)
{
    PNODE NewNode = NULL;

    NewNode = new NODE;
    NewNode -> iData =iNo;
    NewNode -> Next = NULL;

    if((Head == NULL)&&(Tail == NULL))
    {
        Head = NewNode;
        Tail = NewNode;
    }
    else
    {
        Tail->Next = NewNode;
        Tail = NewNode;
    }
    Tail->Next = Head;
    CountNode++;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertAtPosition
// Description :    Used to Insert node at speific Position in the Singly Circular Linked List
// Input :          Integer , Integer
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
///////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLLL::InsertAtPosition(int iNo ,int iPos)  
{
    int iSize = 0,iCnt=0;
    PNODE NewNode = NULL, Temp = NULL;

    iSize = CountNode;
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

        CountNode++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteFirst
// Description :    Used to Delete First node in the Singly Circular Linked List
// Input :          NA
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

void SinglyLLL::DeleteFirst()
{
    PNODE Temp = NULL;
    Temp = Head;

    if((Head == NULL)&&(Tail == NULL))
    {
        printf("Linked List already empty");
        return;
    }
    if(Head == Tail)
    {
        delete(Temp);
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Temp -> Next;
        delete(Temp);
        Tail->Next = Head;
    }
    CountNode--;
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteLast
// Description :    Used to Delete Last  node in the Singly Circular Linked List
// Input :          NA
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

void SinglyLLL::DeleteLast()
{
    PNODE Temp = NULL;
    Temp = Head;
    PNODE tempDelete;

    if((Head == NULL)&&(Tail == NULL))
    {
        printf("Linked List already empty");
        return;
    }
    if(Head == Tail)
    {
        delete(Temp);
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        while(Temp->Next != Tail)
        {
            Temp = Temp -> Next;
        }
        tempDelete = Tail;
        delete(tempDelete);

        Tail->Next = Head;
    }
    CountNode--;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteAtPosition
// Description :    Used to Delete node at specific Position in the Singly Circular Linked List
// Input :          Integer
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
///////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLLL::DeleteAtPosition(int iPos)
{
    int iSize = 0,iCnt=0;

    PNODE Temp = NULL,tempDelete = NULL;

    iSize = CountNode;
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
        Temp -> Next = tempDelete -> Next;
        delete(tempDelete);

        CountNode--;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Display
// Description :    Used to Display node Singly Circular Linked List
// Input :          NA
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
///////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLLL::Display()
{
    PNODE Temp = Head;

    if((Head == NULL)&&(Tail == NULL))
    {
        cout<<"No node in the list";
        return;
    }
    do
    {
        cout<<"|"<<Temp->iData<<"| ->";
        Temp = Temp->Next;
    }
    while(Temp != Tail->Next);

    cout<<endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Count
// Description :    Used to Count Node in Singly Circular Linked List
// Input :          NA
// Output :         Integer
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
///////////////////////////////////////////////////////////////////////////////////////////////

int SinglyLLL::Count()
{
    return CountNode;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//  Main fucntion
//////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{   
    int iRet = 0;
    SinglyLLL obj;
    
    //Inserting Values
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.InsertLast(201);
        
    // Displaying the Linked List
    obj.Display();
    
    // Counting the nodes of Linked List
    iRet = obj.Count();
    cout<<"Count is : "<<iRet<<"\n"<<endl;

    //Inserting Values at specfic position on a Linked List
    obj.InsertAtPosition(75,4);
    
    obj.Display();
    iRet = obj.Count();
    cout<<"Count is : "<<iRet<<endl;

    //Deleting Values at specfic position on a Linked List
    obj.DeleteAtPosition(4);
    obj.Display();

    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//              OUTPUT:
//
//  |11| ->|21| ->|51| ->|101| ->|111| ->|121| ->|151| ->|201| ->
//  Count is : 8
//  
//  |11| ->|21| ->|51| ->|75| ->|101| ->|111| ->|121| ->|151| ->|201| ->
//  Count is : 9
//
//  |11| ->|21| ->|51| ->|101| ->|111| ->|121| ->|151| ->|201| ->
//
//////////////////////////////////////////////////////////////////////////////////////////////////