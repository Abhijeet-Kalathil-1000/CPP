#include<iostream>
using namespace std;

struct node
{
    int Data;
    struct node *Next;
    struct node *Prev;
};

typedef struct node NODE;
typedef struct node * PNODE;

class DoubllyLLL
{   
    private:            //Charachteristics
        PNODE Head;

    public:             //Behaviour

        SinglyCLL();
        void InsertFirst(int no);
        void insertLast(int no);
        void InsertAtPosition(int no ,int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);
        void Display();
        int Count();
};

    SinglyCLL()
    {
        Head = NULL;
    }

    void InsertFirst(int no)
    {}
    void insertLast(int no)
    {}
    void InsertAtPosition(int no ,int ipos)
    {}
    void DeleteFirst()
    {}
    void DeleteLast()
    {}
    void DeleteAtPosition(int ipos)
    {}
    void Display()
    {}
    int Count()
    {
        
        
        return 0 ;
    }

int main()
{   
    SinglyCLL obj;

    return 0;
}