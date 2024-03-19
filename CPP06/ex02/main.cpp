#include "Base.h"

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "A.h"
#include "B.h"
#include "C.h"

Base *generate(void)
{
    std::srand(time(NULL));
    int random = std::rand() % 3;

    switch(random)
    {
        case 0:
            return(new A());
        case 1:
            return (new B());
        case 2:
            return (new C());
        default:
            std::cout << "Was not able to generate a class\n";
    }
    return NULL;
}

void identify(Base *p)
{
    if(dynamic_cast<A*>(p) != NULL)
        std::cout << "A\n";
    if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B\n";
    if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C\n";
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception &)
    {
        std::cout << "Exception caught: cast failed on A\n";
    };
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception &)
    {
        std::cout << "Exception caught: cast failed on B\n";
    };
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception &)
    {
        std::cout << "Exception caught: cast failed on C\n";
    };
}

int main(void)
{
    Base *p;
    srand(time(NULL));

    p = generate();
    identify(p);
    identify(*p);
    delete p;
    return (0);
}
