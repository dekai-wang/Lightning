/**
 * @file lt_queue.h
 * @brief 队列
 * @author dekai.wang
 * @version 
 * @date 2017-11-07
 */

#ifndef _LT_QUEUE_H_
#define _LT_QUEUE_H_

#include <iostream>
#include <sstream>
#include "base/lt_node.h"
#include "base/noncopyable.h"
#include "base/lt_exception.h"

namespace lt
{

template<class T>
class Queue : public noncopyable
{
    typedef LinkNode<T>* LinkedPtr;
public:
    Queue();
    virtual ~Queue();

    void enqueue(const T& element);

    const T dequeue();

    size_t size() { return _size; }

    bool empty() { return _size == 0; }

private:
    LinkedPtr       _front;
    LinkedPtr       _rear;
    size_t          _size;
};

template<class T>
Queue<T>::Queue()
{
    _front = _rear = new LinkNode<T>();
    _size = 0;
}

template<class T>
Queue<T>::~Queue()
{
    while(_front->next)
    {
        LinkedPtr ptr = _front->next;
        _front->next = ptr->next; 
        delete ptr;
    }
    delete _front;
}

template<class T>
void Queue<T>::enqueue(const T& element)
{
    LinkedPtr ptr = new LinkNode<T>(element);
    _rear->next = ptr;
    _rear = ptr;
    _size++;
}

template<class T>
const T Queue<T>::dequeue()
{
    if (_size == 0)
        throw Exception("");

    LinkedPtr ptr = _front->next;
    _front->next = ptr->next; 
    T element = ptr->data;
    delete ptr;
    _size--;

    if (ptr == _rear)
        _rear = _front;

    return element;
}
    
};

#endif

