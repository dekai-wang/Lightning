/**
 * @file lt_queue.h
 * @brief 队列
 * @author dekai.wang
 * @version 
 */

#ifndef _LT_QUEUE_H_
#define _LT_QUEUE_H_

#include "base/lt_exception.h"
#include "base/lt_noncopyable.h"
#include "data_structures/lt_deque.h"

namespace lt
{

template<class T, class Container = lt::Deque<T> >
class Queue : public noncopyable
{
public:
    Queue();
    virtual ~Queue();

    const T& front();

    const T& back();

    void enqueue(const T& element);

    const T& dequeue();

    size_t size() { return _con.size(); }

    bool empty() { return _con.empty(); }

private:
    Container       _con;
};

template<class T, class Container>
Queue<T, Container>::Queue()
{

}

template<class T, class Container>
Queue<T, Container>::~Queue()
{
    
}

template<class T, class Container>
const T& Queue<T, Container>::front()
{
    _con.front();
}

template<class T, class Container>
const T& Queue<T, Container>::back()
{
    _con.back();    
}

template<class T, class Container>
void Queue<T, Container>::enqueue(const T& element)
{
    _con.push_back(element);
}

template<class T, class Container>
const T& Queue<T, Container>::dequeue()
{
    const T& element = _con.front();
    _con.pop_front();
    return element;
}
    
};

#endif

