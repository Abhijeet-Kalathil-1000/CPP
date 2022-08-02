//////////////////////////////////////////////////////////////////////////////////////////////////
//  Write a Program on Genric Doubly Circular Linked List and all 8 fucntions
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
//  Structure of a Node of Genric Doubly Circular Linked List
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};


////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :     GenricDoublyCLL
//  Description :    Has defination of all fucntions of a Genric Doubly Circular Linked List
//  Date :           20/06/2022
//  Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class GenricDoublyCLL
{
    private:                //Charachteristics
        struct node<T> *Head;
        struct node<T> *Tail;
        int CountNode;

    public:                 //Behaviour
        GenricDoublyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int Count();
        void Display();
};

////////////////////////////////////////////////////////////////////////////////////////
//      Default Constructor
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
GenricDoublyCLL<T>::GenricDoublyCLL()
{
    Head = NULL;
    Tail = NULL;
    CountNode = 0;
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertFirst
// Description :    Used to Insert First node in the Genric Doubly Circular Linked List
// Input :          T
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void GenricDoublyCLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
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
// Description :    Used to Insert Last node in the Genric Doubly Circular Linked List
// Input :          T
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void GenricDoublyCLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
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
// Description :    Used to Insert at specifed postion in the Genric Doubly Circular Linked List
// Input :          T,Integer
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void GenricDoublyCLL<T>::InsertAtPos(T no,int iPos)
{
    int iCnt=0;

    struct node<T> *newn = NULL;
    struct node<T> *temp = NULL;
    
    if((iPos < 1) || (iPos > CountNode+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == CountNode+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new node<T>;

        newn->data = no;
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
// Description :    Used to Delete First node in the Genric Doubly Circular Linked List
// Input :          NA
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void GenricDoublyCLL<T>::DeleteFirst()
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
// Description :    Used to Delete Last node in the Genric Doubly Circular Linked List
// Input :          NA
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void GenricDoublyCLL<T>::DeleteLast()
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
// Description :    Used to Delete at specifed postion in the Genric Doubly Circular Linked List
// Input :          Integer
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void GenricDoublyCLL<T>::DeleteAtPos(int iPos)
{
    int iCnt =0;
    struct node<T> *temp = NULL;

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
// Description :    Used to Count the Genric Doubly Circular Linked List
// Input :          NA
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int GenricDoublyCLL<T>::Count()
{
    return CountNode;
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Display
// Description :    Used to Display the Genric Doubly Circular Linked List
// Input :          NA
// Output :         NA
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void GenricDoublyCLL<T>::Display()
{
    int iCnt=0;
    struct node<T> *temp = Head;

    if(Head == NULL)
    {
        cout<<"No node in the list";
        return;
    }
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

    GenricDoublyCLL<int>dobj;

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
//  |1| ->|10| ->|11| ->|21| ->|51| ->|101| ->|111| ->
//  No of nodes are : 7
//  
//  |10| ->|11| ->|75| ->|21| ->|51| ->|101| ->
//  Count is : 6
//  
//  |10| ->|11| ->|75| ->|51| ->|101| ->
//
//////////////////////////////////////////////////////////////////////////////////////////////////