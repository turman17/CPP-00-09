#include "PmergeMe.h"

int main(int argc, char **argv)
{
    PmergeMe p;

    if (argc < 2)
    {
        error();
    }
    p.loadList(argv + 1);
    p.printList();
    return 0;
}