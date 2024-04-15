#include "PmergeMe.h"
#include <cstring> // For strlen

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void error()
{
    std::cerr << "Error\n";
    exit(1);
}

bool PmergeMe::validNum(const std::string &num)
{
    if (num.empty())
        return false;

    size_t start = 0;
    if (num[0] == '-' || num[0] == '+')
    {
        if (num[0] == '-')
            return false;
        start = 1;
        if (num.size() == 1)
            return false;
    }
    for (size_t i = start; i < num.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(num[i])))
            return false;
    }
    return true;
}

void PmergeMe::loadList(char **argv)
{
    std::set<long long> unique_numbers;

    while (argv && *argv)
    {
        std::string n = *argv;

        if (!validNum(n))
        {
            error();
        }

        char *end;
        long long number = strtol(n.c_str(), &end, 10);
        if (*end != '\0' || number < 0 || number > 2147483647)
            error();

        if (!unique_numbers.insert(number).second)
            error();
        this->_list.push_back(number);
        this->_deque.push_back(number);
        argv++;
    }
}

long double PmergeMe::getTime()
{
    timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)(tv.tv_sec) * 1000000 + (long long)(tv.tv_usec);
}

void PmergeMe::printList()
{
    long double listTime;
    long double dequeTime;

    std::list<int>::iterator ptr;
    std::cout << "Before:";
    for (ptr = _list.begin(); ptr != _list.end(); ++ptr)
        std::cout << " " << *ptr << "";
    std::cout << "\n";
    listTime = getTime();
    this->_list.sort();
    listTime = (getTime() - listTime);
    std::cout << "After: ";
    for (ptr = _list.begin(); ptr != _list.end(); ++ptr)
        std::cout << " " << *ptr << "";
    std::cout << "\n";
    dequeTime = getTime();
    std::sort(this->_deque.begin(), this->_deque.end());
    dequeTime = getTime() - dequeTime;
    std::cout << "Time to process a range of elements with std::list : " << listTime << " milliseconds\n";
    std::cout << "Time to process a range of elements with std::deque: " << dequeTime << " milliseconds\n";
}
