// Template for probplems on Numbers

#include<iostream>
using namespace std;

class Number
{
    private:
        int iNo;        // Charactristics

    public:
        // Behaviours
        void Accept()       // Setter
        {
            cout<<"Enter the value : "<<endl;
            cin>>this->iNo;
        }

        void Display()      // Getter
        {
            cout<<"Value is : "<<this->iNo<<endl;
        }

        // Add function here with the the logic
};

int main()
{
    Number nobj;

    nobj.Accept();
    nobj.Display();

    nobj._____________();

    return 0;
}