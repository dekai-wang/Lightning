/**
 * @file lt_deque.h
 * @brief 双端队列
 * @author dekai.wang
 * @version 
 */

#ifndef _LT_DEQUE_H_
#define _LT_DEQUE_H_

#include "base/lt_exception.h"
#include "base/lt_noncopyable.h"

namespace lt
{

template<class T>
class Deque : public noncopyable
{
public:
    Deque();
    virtual ~Deque();

    void push_front(const T& element);

    void push_back(const T& element);

    const T& front();

    const T& back();

    void pop_front();

    void pop_back();

    void insert(size_t pos, const T& element);

    void erase(size_t pos);

    void clear();

    bool empty() { return _size == 0; }

    size_t size() { return _size; }
private:
    typedef struct Node
    {
        Node()
            : data(), prev(nullptr), next(nullptr) {}
        Node(const T& element) 
            : data(element), prev(nullptr), next(nullptr) {}
        Node(const T& element, Node* prev_ptr, Node* next_ptr) 
            : data(element), prev(prev_ptr), next(next_ptr) {}
        Node*   next;
        Node*   prev;
        T       data;
    }*LinkPtr;
    LinkPtr     _front;
    LinkPtr     _back;
    size_t      _size;
};

template<class T>
Deque<T>::Deque()
{
    _front = _back = nullptr;
}

template<class T>
Deque<T>::~Deque()
{
    
}

template<class T>
const T& Deque<T>::front()
{
    if (empty())
        throw Exception("");

    return _front->data;
}

template<class T>
void Deque<T>::push_front(const T& element)
{
    if (!_front)
    {
        _front = _back = new Node(element);
    }
    else
    {
        _front->prev = new Node(element, _front->prev, _front);
        _front = _front->prev;
    }
    _size++;
}

template<class T>
void Deque<T>::pop_front()
{
    if (empty())
        throw Exception("");

    LinkPtr ptr = _front;
    if (_front == _back)
    {
        _front = _back = nullptr; 
    }
    else
    {
        _front->next->prev = _front->prev;
        _front = _front->next;
    }
    delete ptr;
    _size--;
}

template<class T>
const T& Deque<T>::back()
{
    if (empty()) 
        throw Exception("");
    return _back->data;
}

template<class T>
void Deque<T>::push_back(const T&element)
{
    if (!_back)
    {
        _front = _back = new Node(element);
    }
    else
    {
        _back->next = new Node(element, _back, _back->next);
        _back = _back->next;
    }
    _size++;
}

template<class T>
void Deque<T>::pop_back()
{
    if(empty())    
        throw Exception("");

    LinkPtr ptr = _back;
    if (_back == _front)
    {
        _back = _front = nullptr; 
    }
    else
    {
        _back->prev->next = _back->next;
        _back = _back->prev;
    }
    delete ptr;
}

template<class T>
void Deque<T>::insert(size_t pos, const T& element)
{
    
}

template<class T>
void Deque<T>::erase(size_t pos)
{
    
}

template<class T>
void Deque<T>::clear()
{
     
}

}

#endif

