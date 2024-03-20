
#include "MutantStack.h"
#include <list>

template <typename T>
void printContainer(T &container)
{
    for (typename T::iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << std::endl;
}

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "here we begin the iteration\n";
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "here we end the iteration\n";
    std::stack<int> s(mstack);

    // Now with std::list
    std::cout << "Test with std::list" << std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    list.pop_back();
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    printContainer(list);
    return (0);
}