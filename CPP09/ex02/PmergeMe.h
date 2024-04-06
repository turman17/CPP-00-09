#ifndef PMERGEME_H
#define PMERGEME_H


#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void merge(std::vector<int> &array, int start, int mid, int end)
{
    int totalElements = end - start + 1;
    std::vector<int> temp(totalElements);
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end)
    {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid)
        temp[k++] = array[i++];

    while (j <= end)
        temp[k++] = array[j++];

    for (i = start, k = 0; i <= end; ++i, ++k)
        array[i] = temp[k];
}

void fordJohnsonSortRecursive(std::vector<int> &array, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;

    fordJohnsonSortRecursive(array, start, mid);
    fordJohnsonSortRecursive(array, mid + 1, end);

    merge(array, start, mid, end);
}

void fordJohnsonSort(std::vector<int> &array)
{
    fordJohnsonSortRecursive(array, 0, array.size() - 1);
}

#endif