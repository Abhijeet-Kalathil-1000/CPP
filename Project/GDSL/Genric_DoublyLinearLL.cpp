//////////////////////////////////////////////////////////////////////////////////////////////////
//  Write a Program on Genric Doubly Linear Linked List and all 8 fucntions
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
//  Structure of a Node of Genric Doubly Linear Linked List
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct node
{
    T Data;
    struct node *Next;
    struct node *Prev;
};

////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :     GenricDoublyLLL
//  Description :    Has defination of all fucntions of a Genric Doubly Linear Linked List
//  Date :           20/06/2022
//  Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class GenricDoublyLLL
{   
    private:            //Charachteristics
        struct node<T> *Head;
        struct node<T> *Tail;
        int Count;

    public:             //Behaviour

        GenricDoublyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T ,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int CountNode();
};

////////////////////////////////////////////////////////////////////////////////////////
//      Default Constructor
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
GenricDoublyLLL<T>::GenricDoublyLLL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertFirst
// Description :    Used to Insert First node in the Genric Doubly Linear Linked List
// Input :          T
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void GenricDoublyLLL<T>::InsertFirst(T No)
{
    struct node<T> *NewNode = NULL;
    NewNode = new node<T>;

    NewNode -> Data =No;
    NewNode -> Next = NULL;
    NewNode -> Prev = NULL;

    if((Head == NULL)&&(Tail == NULL))
    {
        Head = NewNode;
        Tail = NewNode;
    }
    else
    {
        Head -> Prev = NewNode;
        NewNode -> Next = Head;
        Head = NewNode;
    }
    Count++;
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertLast
// Description :    Used to Insert Last node in the Genric Doubly Linear Linked List
// Input :          T
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void GenricDoublyLLL<T>::InsertLast(T No)
{
    struct node<T> *NewNode = NULL;
    NewNode = new node<T>;

    NewNode -> Data =No;
    NewNode -> Next = NULL;
    NewNode -> Prev = NULL;

    if(Head == NULL)
    {
        Head = NewNode;
    }
    else
    {
        struct node<T> *Temp = Head;

        while(Temp -> Next != NULL)
        {
            Temp = Temp -> Next;
        }
        Temp -> Next = NewNode;
        NewNode -> Prev = Temp;
    }
    Count++;
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertAtPos
// Description :    Used to Insert at specifed postion in the Genric Doubly Linear Linked List
// Input :          T,Integer
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void GenricDoublyLLL<T>::InsertAtPos(T No ,int iPos)  
{
    int iSize = 0,iCnt=0;

    struct node<T> *NewNode = NULL;
    struct node<T> *Temp = NULL;

    iSize = CountNode();
    if(( iPos> (iSize+1)) || ( iPos< 1))
    {
        cout<<"Enter a valid position";
        return;
    }
    if( iPos== 1)
    {
        InsertFirst(No);
    }
    else if( iPos== (iSize-1))
    {
        InsertLast(No);
    }
    else
    {

        NewNode = new node<T>;
        
        NewNode -> Data =No;
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

        Count++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteFirst
// Description :    Used to Delete First node in the Genric Doubly Linear Linked List
// Input :          NA
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void GenricDoublyLLL<T>::DeleteFirst()
{
    struct node<T> *Temp = NULL;
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

        Count--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteLast
// Description :    Used to Delete Last node in the Genric Doubly Linear Linked List
// Input :          NA
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void GenricDoublyLLL<T>::DeleteLast()
{
    struct node<T> *Temp = NULL;
    struct node<T> *tempDelete = NULL;
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
// Description :    Used to Delete at specifed postion in the Genric Doubly Linear Linked List
// Input :          Integer
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void GenricDoublyLLL<T>::DeleteAtPos(int iPos)
{
    int iSize = 0,iCnt=0;
    struct node<T> *NewNode = NULL;
    struct node<T> *Temp = NULL;
    struct node<T> *tempDelete = NULL;

    iSize = CountNode();
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

        Count--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Display
// Description :    Used to Display the Genric Doubly Linear Linked List
// Input :          NA
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void GenricDoublyLLL<T>::Display()
{
    struct node<T> *Temp = Head;

    if(Head == NULL)
    {
        cout<<"No node in the list";
        return;
    }
    cout<<"|NULL| ->";
    while(Temp != NULL)
    {
        cout<<"|"<<Temp->Data<<"| ->";
        Temp = Temp->Next;
    }
    cout<<"|NULL|";
    cout<<endl;
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Count
// Description :    Used to Count the Genric Doubly Linear Linked List
// Input :          NA
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int GenricDoublyLLL<T>::CountNode()
{
    return Count;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//  Main fucntion
//////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{   
    int iRet = 0;

    GenricDoublyLLL<int>obj;
    
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
    iRet = obj.CountNode();
    cout<<"Count is : "<<iRet<<"\n"<<endl;

    //Inserting Values at specfic position on a Linked List
    obj.InsertAtPos(75,4);
    obj.DeleteLast();
    obj.DeleteFirst();
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Count is : "<<iRet<<endl;

    obj.DeleteAtPos(4);
    obj.Display();

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//              OUTPUT:
//
// |NULL| ->|11| ->|21| ->|51| ->|101| ->|111| ->|121| ->|151| ->|201| ->|NULL|
// Count is : 8
//
// |NULL| ->|21| ->|51| ->|75| ->|101| ->|111| ->|121| ->|151| ->|NULL|
// Count is : 8
//
// |NULL| ->|21| ->|51| ->|75| ->|111| ->|121| ->|151| ->|NULL|
//
//////////////////////////////////////////////////////////////////////////////////////////////////