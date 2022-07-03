#include<iosteam>

using namespace std;

#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct node
{
    int Data;
    node *Next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class Singly_linkedList
{
    private:
        PNODE Head;

    public:
        Singly_linkedList();
        ~Singly_linkedList();
        BOOL InsertFirst(int);
        BOOL insertLast(int);
        BOOL InsertAtPosition(int,int);
        inline void Display();
        inline int Count();
        BOOL DeleteFirst();
        BOOL DeleteAtPosition(int)
        BOOL DeleteLast();
};

Singly_linkedList :: Singly_linkedList()
{
    Head = NULL;
}

Singly_linkedList :: !Singly_linkedList()
{
    PNODE Temp,Navigate;

    if(Head !=NULL)
    {
        Navigate = Head ;
            while(Navigate!=NULL)
    }
}