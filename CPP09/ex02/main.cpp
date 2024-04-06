#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "PmergeMe.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " [list of positive integers]" << std::endl;
        return 1;
    }

    std::vector<int> numbersVector;
    for (int i = 1; i < argc; ++i)
    {
        int num = std::atoi(argv[i]);
        if (num < 0)
        {
            std::cerr << "Error: Input contains non-positive integers." << std::endl;
            return 1;
        }
        numbersVector.push_back(num);
    }

    std::cout << "Before sorting: ";
    for (std::vector<int>::iterator it = numbersVector.begin(); it != numbersVector.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::clock_t startVec = std::clock();
    fordJohnsonSort(numbersVector);
    std::clock_t endVec = std::clock();
    std::cout << "After sorting (vector): ";
    for (size_t i = 0; i < numbersVector.size(); ++i)
    {
        std::cout << numbersVector[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Sorting time (vector): " << (endVec - startVec) / (double)CLOCKS_PER_SEC << " seconds" << std::endl;
    std::list<int> numbersList(numbersVector.begin(), numbersVector.end());
    std::vector<int> tempList(numbersList.begin(), numbersList.end());
    startVec = std::clock();
    fordJohnsonSort(tempList);
    std::copy(tempList.begin(), tempList.end(), numbersList.begin());
    endVec = std::clock();
    std::cout << "After sorting (list): ";
    for (std::list<int>::iterator it = numbersList.begin(); it != numbersList.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "Sorting time (list): " << (endVec - startVec) / (double)CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}
