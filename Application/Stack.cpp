//////////////////////////////////////////////////////////////////////////////////////////////////
//  Write a Program on Genric Stack and all 8 fucntions
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;


////////////////////////////////////////////////////////////////////////////////////////
//  Structure of a Node of Genric Stack
////////////////////////////////////////////////////////////////////////////////////////


struct node
{
    int data;
    struct node *next;
};

////////////////////////////////////////////////////////////////////////////////////////
//  Adding typedef for better readablity
////////////////////////////////////////////////////////////////////////////////////////

typedef struct node NODE;

typedef struct node * PNODE;

////////////////////////////////////////////////////////////////////////////////////////
//
// Class Name :     Stack
// Description :    Class contaimns functions of a Genric Stack
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////


class Stack
{
    public:
        PNODE Head;
        int Count;

        Stack();
        void Push(int);
        void Pop();
        void Display();
        int CountNode();
};

////////////////////////////////////////////////////////////////////////////////////////
//      Default Constructor : Stack
////////////////////////////////////////////////////////////////////////////////////////


Stack::Stack()
{
    Head = NULL;
    Count = 0;
}

////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Push
// Description :    Used to Insert First node in the Stack
// Input :          Integer
// Output :         NA
// Date :           15/06/2022
// Author :         Abhijeet Saji Kalathil
//
////////////////////////////////////////////////////////////////////////////////////////


void Stack::Push(int no)
{
    PNODE newn = NULL;
    newn = new node; 

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

void Stack::Pop()
{
    int no;

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
        PNODE Temp = Head;
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


void Stack::Display()
{
    cout<<"Elements in Stack are : "<<endl;
    PNODE temp = Head;
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


int Stack::CountNode()
{
    return Count;
}

int main()
{

//  Creating object for Integer value
    Stack obj1;

    obj1.Push(10);
    obj1.Push(11);
    obj1.Push(21);
    obj1.Push(51);

    obj1.Display();
    cout<<"Number of node is : "<<obj1.CountNode()<<endl;

    obj1.Pop();
    obj1.Pop();
    obj1.Push(101);

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
// Elements in Stack are : 
// |51| ->|21| ->|11| ->|10| ->
//
// Number of node is : 4
//
// Removed element is : 51
// Removed element is : 21
//
// Elements in Stack are : 
// |101| ->|11| ->|10| ->
//
// Removed element is : 101
// Removed element is : 11
// Removed element is : 10
//
// Number of node is : 0
//           
////////////////////////////////////////////////////////////////////////////////////

