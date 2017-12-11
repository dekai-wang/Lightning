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
#include <iostream>
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
        for (size_t i = 1; i < con.size(); i++)
        {
            T temp = con[i];
            size_t j = i;
            for (; j > 0 && com(temp, con[j - 1]); j--)
                con[j] = con[j - 1];
            con[j] = temp;
        }
    }

    template<class T, class Container = std::vector<T>, class Compare>
    static void Heapify(Container& con, int start, int end, Compare com)
    {
        int dad = start; 
        int son = dad * 2 + 1;
        while( son <= end )
        {
            if (son + 1 <= end && con[son] < con[son + 1])
                son++;
            if (com(con[son], con[dad]))
            {
                return;
            }
            else
            {
                std::swap(con[dad], con[son]);
                dad = son; 
                son = dad * 2 + 1;
            }
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
        for (int i = (con.size() - 1) / 2; i >= 0; i--)
        {
            Heapify<T>(con, i, con.size() - 1, com);
        }
        for (int i = con.size() - 1; i > 0; i--)
        {
            std::swap(con[0], con[i]);
            Heapify<T>(con, 0, i - 1, com);
        }
    }

    template<class T, class Container = std::vector<T>, class Compare >
    static void Merge(Container& con, Container& temp, int lb, int rb, int re, Compare com)
    {
        int le = rb - 1;
        int pos = lb;
        int size = re - lb;
        while ( lb <= le && rb <= re )
        {
            if (com(con[lb], con[rb]))
                temp[pos++] = con[lb++];
            else 
                temp[pos++] = con[rb++];
        }
        while( lb <= le )
            temp[pos++] = con[lb++];
        while( rb <= re )
            temp[pos++] = con[rb++];

        for (size_t i = 0; i <= size; i++, re--)
            con[re] = temp[re];
    }

    template<class T, class Container = std::vector<T>, class Compare >
    static void MSort(Container& con, Container& temp, int left, int right, Compare com)
    {
        if (left >= right)
            return;

        int center = (left + right) / 2;
        MSort<T>(con, temp, left, center, com);
        MSort<T>(con, temp, center + 1, right, com);
        Merge<T>(con, temp, left, center + 1, right, com);
    }

    template<class T, class Container = std::vector<T> >
    static void MergeSort(Container& con)
    {
        MergeSort<T>(con, std::less<T>());
    }

    template<class T, class Container = std::vector<T>, class Compare>
    static void MergeSort(Container& con, Compare com)
    {
        Container temp = con; 
        MSort<T>(con, temp, 0, con.size() - 1, com);
    }

    template<class T, class Container = std::vector<T> >
    static void QuickSort()
    {

    }

};

};

#endif

