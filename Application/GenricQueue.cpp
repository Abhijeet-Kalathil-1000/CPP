//////////////////////////////////////////////////////////////////////////////////////////////////
//  Write a Program on Queue and all 4 fucntions
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;


////////////////////////////////////////////////////////////////////////////////////////
//  Structure of a Node of Queue
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct node
{
    T data;
    struct node *next;
};

////////////////////////////////////////////////////////////////////////////////////////
//
// Class Name :     Queue
// Description :    Class contaimns functions of a Queue
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Queue
{
    public:
        struct node<T> *Head;
        int Count;

        Queue();
        void Enqueue(T);
        void Dequeue();
        void Display();
        int CountNode();
};

////////////////////////////////////////////////////////////////////////////////////////
//      Default Constructor : Queue
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Queue<T>::Queue()
{
    Head = NULL;
    Count = 0;
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Enqueue
// Description :    Used to Insert Last node in the Queue
// Input :          T  (where T is genric placeholder)
// Output :         NA
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T>::Enqueue(T no)
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

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Dequeue
// Description :    Used to Delete First node in the Queue
// Input :          NA
// Output :         NA
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T>::Dequeue()
{
    T no;
    
    if(Count == 0)
    {
        cout<<"Queue is empty"<<endl;
        return ;
    }
    if(Count == 1)
    {
        no = Head->data;
        delete Head;
        Head = NULL;
    }
    else
    {
        no = Head -> data;
        struct node<T> *temp = Head;
        Head = Head->next;
        delete(temp);
    }
    Count--;
    cout<<"Removed element is : "<<no<<endl;

}
///////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Display
// Description :    Used to Display node Queue
// Input :          NA
// Output :         NA
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
///////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T>::Display()
{
    cout<<"Elements in Queue are : "<<endl;
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
// Description :    Used to Count Node in Queue
// Input :          NA
// Output :         Integer
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
///////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int Queue<T>::CountNode()
{
    return Count;
}

int main()
{
//  Creating object for Integer value
    Queue<int>obj1;

    obj1.Enqueue(11);
    obj1.Enqueue(21);
    obj1.Enqueue(51);
    obj1.Enqueue(110);

    obj1.Display();
    cout<<"Number of node is : "<<obj1.CountNode()<<endl;

    obj1.Dequeue();
    obj1.Dequeue();
    obj1.Dequeue();

    obj1.Display();
    cout<<"Number of node is : "<<obj1.CountNode()<<endl;

    obj1.Dequeue();
    obj1.Dequeue();

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//                      OUTPUT:
//
//      Elements in Queue are : 
//      |11| ->|21| ->|51| ->|110| ->
//      Number of node is : 4
//
//      Removed element is : 11
//      Removed element is : 21
//      Removed element is : 51
//
//      Elements in Queue are : 
//      |110| ->
//      Number of node is : 1
//
//      Removed element is : 110
//      Queue is empty
//
///////////////////////////////////////////////////////////////////////////////////////////
