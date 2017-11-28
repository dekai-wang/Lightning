/**
 * @file lt_stack.h
 * @brief 栈
 * @author dekai.wang
 * @version 
 */

#ifndef _LT_STACK_H_
#define _LT_STACK_H_

#include "base/lt_exception.h"
#include "base/lt_noncopyable.h"
#include "data_structures/lt_deque.h"

namespace lt
{

template<class T, class Container = lt::Deque<T> >
class Stack : public noncopyable
{
public:
    Stack();
    virtual ~Stack();

    void push(const T& element);

    const T& pop();

    const T& top();

    size_t size() { return _con.size(); }

    bool empty() { return _con.empty(); }
private:
    Container   _con;
};

template<class T, class Container>
Stack<T, Container>::Stack()
{

}

template<class T, class Container>
Stack<T, Container>::~Stack()
{
    
}

template<class T, class Container>
void Stack<T, Container>::push(const T& element)
{
    _con.push_front(element);
}

template<class T, class Container>
const T& Stack<T, Container>::pop()
{
    const T ele = _con.front();
    _con.pop_front();
    return ele;
}

template<class T, class Container>
const T& Stack<T, Container>::top()
{
    const T ele = _con.front();
    _con.pop_front();
    return ele;
}

};

#endif
