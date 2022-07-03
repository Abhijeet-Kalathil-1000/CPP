#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;

class DoublyCLL
{
    private:
        PNODE Head;
        PNODE Tail;
        int CountNode;

    public:
        DoublyCLL();
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        int Count();
        void Display();
};

DoublyCLL::DoublyCLL()
{
    Head = NULL;
    Tail = NULL;
}

void DoublyCLL::InsertFirst(int iNo)
{}

void DoublyCLL::InsertLast(int iNo)
{}

void DoublyCLL::InsertAtPos(int iNo,int iPos)
{}

void DoublyCLL::DeleteFirst()
{}

void DoublyCLL::DeleteLast()
{}

void DoublyCLL::DeleteAtPos(int iPos)
{}

int DoublyCLL::Count()
{
    return CountNode;
}

void DoublyCLL::Display()
{}

int main()
{

    DoublyCLL dobj;

    return 0;
}

