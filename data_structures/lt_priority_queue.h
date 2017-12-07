/**
 * @file lt_priority_queue.h
 * @brief 优先队列
 * @author dekai.wang
 * @version 
 */

#ifndef _LT_PRIORITY_QUEUE_H_
#define _LT_PRIORITY_QUEUE_H_

#include "base/lt_exception.h"
#include "base/lt_noncopyable.h"

namespace lt
{

template<class T>
class PriorityQueue : public noncopyable
{
public:
    PriorityQueue();
    PriorityQueue(size_t size);
    virtual ~PriorityQueue();

    void insert(const T& element);

    const T erase_min();
private:
    size_t  _capacity;
    size_t  _size;
    T*      _elements;
};


template<class T>
PriorityQueue<T>::PriorityQueue()
{
    _size = 0;
    _capacity = 128;
    _elements = new T[_capacity];
}

template<class T>
PriorityQueue<T>::PriorityQueue(size_t size)
{
    _capacity = size;
    _elements = new T[_capacity];
}

template<class T>
PriorityQueue<T>::~PriorityQueue()
{

}

template<class T>
void PriorityQueue<T>::insert(const T& element)
{
    size_t i = ++_size;
    for (; _elements[i / 2] > element; i /= 2)
        _elements[i] = _elements[i / 2];
    _elements[i] = element;
}

template<class T>
const T PriorityQueue<T>::erase_min()
{
    if (_size == 0)
        return _elements[0];
    size_t i = 1;
    size_t child;
    T element = _elements[i];
    T& last = _elements[_size--];
    for (; i * 2 <= _size; i = child) 
    {
        child = i * 2;
        if (child != _size && _elements[child + 1] < _elements[child])
            child++;
        if (last > _elements[child])
            _elements[i] = _elements[child];
        else
            break;
    }
    _elements[i] = last;

    return element;
}

}

#endif

