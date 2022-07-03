//////////////////////////////////////////////////////////////////////////////////////////////////
//  Write a Program on Genric Stack and all 8 fucntions
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;


////////////////////////////////////////////////////////////////////////////////////////
//  Structure of a Node of Genric Stack
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct node
{
    T data;
    struct node *next;
};

////////////////////////////////////////////////////////////////////////////////////////
//
// Class Name :     Stack
// Description :    Class contaimns functions of a Genric Stack
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Stack
{
    public:
        struct node<T> *Head;
        int Count;

        Stack();
        void Push(T);
        void Pop();
        void Display();
        int CountNode();
};

////////////////////////////////////////////////////////////////////////////////////////
//      Default Constructor : Stack
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Stack<T>::Stack()
{
    Head = NULL;
    Count = 0;
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Push
// Description :    Used to Insert First node in the Stack
// Input :          T (where T is genric placeholder)
// Output :         NA
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T>::Push(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>; 

    newn->data = no;
    newn->next = NULL;

    newn->next = Head;
    Head = newn;
    Count++;
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Pop
// Description :    Used to Delete First node in the Stack
// Input :          NA
// Output :         NA
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Pop()
{
    T no;

    if(Count == 0)
    {
        cout<<"Stack is empty"<<endl;
        return;
    }
    if(Count == 1)
    {
        no = Head->data;
        delete Head;
        Head = NULL;
    }
    else
    {
        no = Head ->data;
        struct node<T> *Temp = Head;
        Head = Head -> next;
        delete(Temp);
    }
    Count--;
    cout<<"Removed element is : "<<no<<endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Display
// Description :    Used to Display node Stack
// Input :          NA
// Output :         NA
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
///////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T>::Display()
{
    cout<<"Elements in Stack are : "<<endl;
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
// Description :    Used to Count Node in Stack
// Input :          NA
// Output :         Integer
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
///////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int Stack<T>::CountNode()
{
    return Count;
}

int main()
{

//  Creating object for Integer value
    Stack<char>obj1;

    obj1.Push('A');
    obj1.Push('B');
    obj1.Push('C');
    obj1.Push('D');

    obj1.Display();
    cout<<"Number of node is : "<<obj1.CountNode()<<endl;

    obj1.Pop();
    obj1.Pop();
    obj1.Push('Z');

    obj1.Display();
    
    obj1.Pop();
    obj1.Pop();
    obj1.Pop();

    cout<<"Number of node is : "<<obj1.CountNode()<<endl;

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////
//                  Output:
//
//      Elements in Stack are : 
//      |D| ->|C| ->|B| ->|A| ->
//
//      Number of node is : 4
//      Removed element is : D
//      Removed element is : C
//
//      Elements in Stack are : 
//      |Z| ->|B| ->|A| ->
//      Removed element is : Z
//      Removed element is : B
//      Removed element is : A
//      Number of node is : 0
//           
////////////////////////////////////////////////////////////////////////////////////

