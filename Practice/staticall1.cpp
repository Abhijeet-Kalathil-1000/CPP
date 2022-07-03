#include<iostream>
using namespace std;

class Demo
{
    public:
        int i,j;        //instance variable(non static)
        static int x;   //class variable(static)

        Demo(int a = 10, int b = 20)
        {
            cout<<"Inside Constructor\n";
            this->i =a;
            this->j =b;
        }
    //  void fun(Demo *this,int no)
        void fun(int no)
        {
            cout<<"inside non static fun\n";
            cout<<this->i<<"\n";
            cout<<this->j<<"\n";
        }
    //  static void gun(int value)
        static void gun(int value)
        {
            cout<<"Inside static gun\n";
        }
};

int Demo::x =3;

int main()
{
    cout<<Demo::x<<"\n";
    Demo::gun(11);

    Demo obj(11);

    obj.fun(21);
    cout<<sizeof(obj)<<"\n";
    cout<<obj.i<<"\n";
    cout<<obj.j<<"\n";
    

    return 0;
}