/**
 * @file lt_sort.h
 * @brief 
 * @author dekai.wang
 * @version 
 */
#ifndef _LT_QSORT_H_
#define _LT_QSORT_H_

#include <vector>
#include <algorithm>
#include "base/lt_exception.h"
#include "base/lt_noncopyable.h"

namespace lt
{

class Sort
{
public:
    template<class T, class Container = std::vector<T> >
    static void InsertSort(Container& con)
    {
        InsertSort<T>(con, std::less<T>() );
    }
    template<class T, class Container = std::vector<T>, class Compare>
    static void InsertSort(Container& con, Compare com)
    {
        for(size_t i = 1; i < con.size(); i++)
        {
            T temp = con[i];
            size_t j = i;
            for (; j > 0 && com(temp, con[j-1]); j--)
                con[j] = con[j-1];
            con[j] = temp;
        }
    }

    template<class T, class Container = std::vector<T> >
    static void HeapSort(Container& con)
    {
        HeapSort<T>(con, std::less<T>());
    }
    template<class T, class Container = std::vector<T>, class Compare>
    static void HeapSort(Container& con, Compare com)
    {
        for (size_t i = con.size() / 2; i >= 0; i--)
        {
            
        }
    }

    template<class T>
    static void MergeSort();

    template<class T>
    static void QuickSort();

    template<class T>
    static void ShellSort()
    {

    }
};

};

#endif

