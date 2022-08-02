//////////////////////////////////////////////////////////////////////////////////////////////////
//  Write a Program on Genric Singly Circular Linked List and all 8 fucntions
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
//  Structure of a Node of Genric Singly Circular Linked List
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct node
{
    T Data;
    struct node *Next;
};


////////////////////////////////////////////////////////////////////////////////////////
//
// Class Name :     GenricSinglyCLL
// Description :    Class contaimns functions of a Singly Circular Linked List
// Date :           20/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class GenricSinglyCLL
{
    private:
        struct node<T> *Head;
        struct node<T> *Tail;
        int CountNode;

    public:
        GenricSinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPosition(T ,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int iPos);

        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////
//      Default Constructor : GenricSinglyCLL
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
GenricSinglyCLL<T>::GenricSinglyCLL()
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

template<class T>
void GenricSinglyCLL<T>::InsertFirst(T no)
{
    struct node<T> *NewNode = NULL;

    NewNode = new node<T>;
    NewNode -> Data =no;
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

template<class T>
void GenricSinglyCLL<T>::InsertLast(T no)
{
    struct node<T> *NewNode = NULL;

    NewNode = new node<T>;
    NewNode -> Data =no;
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

template<class T>
void GenricSinglyCLL<T>::InsertAtPosition(T no ,int iPos)  
{
    int iSize = 0,iCnt=0;
    struct node<T> *NewNode = NULL;
    struct node<T> *Temp = NULL;

    iSize = CountNode;
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
        NewNode = new node<T>;
        
        NewNode -> Data =no;
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

template<class T>
void GenricSinglyCLL<T>::DeleteFirst()
{
    struct node<T> *Temp = NULL;
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

template<class T>
void GenricSinglyCLL<T>::DeleteLast()
{
    struct node<T> *Temp = NULL;
    Temp = Head;
    struct node<T> *tempDelete;

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

template<class T>
void GenricSinglyCLL<T>::DeleteAtPosition(int iPos)
{
    int iSize = 0,iCnt=0;

    struct node<T> *Temp = NULL;
    struct node<T> *tempDelete = NULL;

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

template<class T>
void GenricSinglyCLL<T>::Display()
{
    struct node<T> *Temp = Head;

    if((Head == NULL)&&(Tail == NULL))
    {
        cout<<"No node in the list";
        return;
    }
    do
    {
        cout<<"|"<<Temp->Data<<"| ->";
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

template<class T>
int GenricSinglyCLL<T>::Count()
{
    return CountNode;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//  Main fucntion
//////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{   
    int iRet = 0;
    GenricSinglyCLL<int>obj;
    
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
//    |11| ->|21| ->|51| ->|101| ->|111| ->|121| ->|151| ->|201| ->
//    Count is : 8
//
//    |11| ->|21| ->|51| ->|75| ->|101| ->|111| ->|121| ->|151| ->|201| ->
//    Count is : 9
//
//    |11| ->|21| ->|51| ->|101| ->|111| ->|121| ->|151| ->|201| ->
//    
//
//////////////////////////////////////////////////////////////////////////////////////////////////