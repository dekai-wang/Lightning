/**
 * @file lt_sort.h
 * @brief 
 * @author dekai.wang
 * @version 
 */
#ifndef _LT_QSORT_H_
#define _LT_QSORT_H_

#include "base/lt_exception.h"
#include "base/lt_noncopyable.h"

namespace lt
{

class Sort
{
public:
    template<class T>
    static void InsertSort();

    template<class T>
    static void HeapSort();

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

