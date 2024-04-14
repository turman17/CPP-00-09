#ifndef PMERGEME_H
#define PMERGEME_H

#include <list>
#include <deque>
#include <set>
#include <iostream>
#include <sys/time.h>
#include <cstdlib>
#include <algorithm>
#include <cctype>

class PmergeMe
{
public:
    PmergeMe();
    ~PmergeMe();
    void printList();
    void loadList(char **argv);

private:
    std::list<int> _list;
    std::deque<int> _deque;
    std::set<long long> unique_numbers;
    bool validNum(const std::string &num);
    long double getTime();
    bool itemContains(int num);
};

void error();

#endif
