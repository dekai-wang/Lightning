/**
 * @file lt_stack.h
 * @brief 栈
 * @author dekai.wang
 * @version 
 * @date 2017-10-30
 */

#ifndef _LT_STACK_H_
#define _LT_STACK_H_

#include <iostream>
#include <sstream>
#include "base/lt_node.h"
#include "base/noncopyable.h"
#include "base/lt_exception.h"

namespace lt
{

template<class T>
class Stack : public noncopyable
{
    typedef LinkNode<T>* LinkedPtr;
public:
    Stack();
    virtual ~Stack();

    void push(const T& element);

    const T pop();

    const T top();

    size_t size();

    bool empty();

private:
    size_t          _size;
    LinkedPtr       _top;
};

template<class T>
Stack<T>::Stack()
{
    _size = 0;
    _top = nullptr;
}

template<class T>
Stack<T>::~Stack()
{
    while(_top->next)
    {
        LinkedPtr ptr = _top->next;
        _top->next = ptr->next;
        delete ptr;
    }
    delete _top;
}

template<class T>
void Stack<T>::push(const T& element)
{
    _top = new LinkNode<T>(element, _top);
    _size++;
}

template<class T>
const T Stack<T>::pop()
{
    if (empty())
        throw Exception("empty stack exception");
    LinkedPtr ptr = _top;
    _top = ptr->next;
    T element = ptr->data;
    delete ptr;
    _size--;
    return element;
}

template<class T>
const T Stack<T>::top()
{
    if (empty())
        throw Exception("empty stack exception");
    return _top->data;
}

template<class T>
size_t Stack<T>::size()
{
    return _size;
}

template<class T>
bool Stack<T>::empty()
{
    if (_size == 0)
        return true;
    return false;
}

};

#endif
