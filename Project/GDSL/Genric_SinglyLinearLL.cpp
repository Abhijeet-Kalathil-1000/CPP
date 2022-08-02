//////////////////////////////////////////////////////////////////////////////////////////////////
//  Write a Program on Genric Singly Linear Linked List and all 8 fucntions
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;


////////////////////////////////////////////////////////////////////////////////////////
//  Structure of a Node of Genric Singly Linear Linked List
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct node
{
    T data;
    struct node *next;
};

////////////////////////////////////////////////////////////////////////////////////////
//
// Class Name :     SinglyLL
// Description :    Class contaimns functions of a Genric Singly Linear Linked List
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class SinglyLL
{
    public:
        struct node<T> *Head;
        int Count;

        SinglyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPosition(T, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int iPos);

        void Display();
        int CountNode();
};

////////////////////////////////////////////////////////////////////////////////////////
//      Default Constructor : SinglyLL
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
SinglyLL<T>::SinglyLL()
{
    Head = NULL;
    Count = 0;
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertFirst
// Description :    Used to Insert First node in the Singly Linear Linked List
// Input :          T (where T is genric placeholder)
// Output :         NA
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>; 

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Count++;
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertLast
// Description :    Used to Insert Last node in the Singly Linear Linked List
// Input :          T  (where T is genric placeholder)
// Output :         NA
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>; 

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct node<T> *temp = Head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertAtPosition
// Description :    Used to Insert node at speific Position in the Singly Linear Linked List
// Input :          T , Integer (where T is genric placeholder)
// Output :         NA
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertAtPosition(T no,int iPos)  
{
    int iSize = 0,iCnt=0;
    struct node<T> *newn = NULL;
    struct node<T> *temp = NULL;

    iSize = Count;
    if(( iPos> (iSize+1)) || ( iPos< 1))
    {
        cout<<"Enter a valid position";
        return;
    }
    if( iPos== 1)
    {
        InsertFirst(no);
    }
    else if( iPos== (iSize-1))
    {
        InsertLast(no);
    }
    else
    {
        newn = new node<T>;

        newn -> data =no;
        newn -> next = NULL;
        
        temp = Head;
        for(iCnt =1;iCnt<(iPos-1);iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
        
        Count++;
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

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct node<T> *Temp = NULL;
    Temp = Head;
    if(Head == NULL)
    {
        return;
    }
    else
    {
        Head = Head -> next;
        delete(Temp);
        Count--;
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

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct node<T> *Temp = NULL;
    struct node<T> *tempDelete = NULL;
    if((Head) == NULL)
    {
        cout<<"No node in the list";
        return;
    }
    else
    {
        Temp = Head;
        while(Temp -> next -> next !=NULL)
        {
            Temp = Temp -> next;
        }
        tempDelete = Temp -> next;
        Temp -> next = NULL;
        delete(tempDelete);
        Count--;
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

template <class T>
void SinglyLL<T>::DeleteAtPosition(int iPos)
{
    int iSize = 0,iCnt=0;
    struct node<T> *NewNode = NULL;
    struct node<T> *Temp = NULL;
    struct node<T> *tempDelete = NULL;


    iSize = Count;
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

        Count--;
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

template<class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements in Linked Lsit are : "<<endl;
    struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"| ->";
        temp = temp ->next;
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

template<class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}

int main()
{

//  Creating object for Integer value
    SinglyLL<int>obj1;

//  Creating object for Charachter value
    SinglyLL<char>obj2;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertLast(110);
    obj1.InsertLast(111);
    obj1.InsertAtPosition(75,3);
    obj1.DeleteFirst();
    obj1.DeleteLast();

    obj1.Display();
    cout<<"Number of node is : "<<obj1.CountNode()<<endl;


    obj2.InsertFirst('S');
    obj2.InsertFirst('T');
    obj2.InsertFirst('Q');
    obj2.InsertLast('A');
    obj2.InsertLast('B');
    obj2.InsertAtPosition('G',3);

    obj2.Display();
    cout<<"Number of node is : "<<obj2.CountNode()<<endl;

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//                      OUTPUT:
//
//      Elements in Linked Lsit are : 
//      |21| ->|75| ->|51| ->|110| ->
//
//      Number of node is : 4
//
//      Elements in Linked Lsit are : 
//      |Q| ->|T| ->|G| ->|S| ->|A| ->|B| ->
//
//      Number of node is : 6
//
///////////////////////////////////////////////////////////////////////////////////////////
