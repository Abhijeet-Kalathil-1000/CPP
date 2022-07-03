#include<iostream>

namespace Marvellous
{
    void fun()
    {
        std::cout<<"Inside fun Marvellous\n";
    }
}

namespace Infosystems
{
    void fun()
    {
        std::cout<<"Inside fun Infosystems\n";
    }
}

int main ()
{

    std::cout<<"Jay Ganesh\n";
    using namespace Marvellous;
    using namespace Infosystems;
    Infosystems::fun();

    return 0;
}