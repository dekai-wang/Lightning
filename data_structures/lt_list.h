/**
 * @file lt_list.h
 * @brief 
 * @author dekai.wang
 * @version 
 */

#ifndef _LT_LIST_H_
#define _LT_LIST_H_

#include "base/lt_exception.h"
#include "base/lt_noncopyable.h"
#include "algorithm/lt_algo.h"
#include "algorithm/lt_sort.h"

#include <list>

namespace lt
{

template<class T>
class List : public noncopyable
{
public:
    List();
    virtual ~List();

    const T& front();

    void push_front(const T& element);

    void pop_front();

    void insert_after(size_t pos, const T& element);

    void erase_after(size_t pos);

    void remove(const T& element);

    void merge(const List<T>& other);

    template<class Compare> 
    void merge(const List<T>& other, Compare comp);

    void sort();

    template<class Compare> 
    void sort(Compare comp);

    void clear();

    bool empty() { return _size == 0; }

    size_t size() { return _size; }

    void reserve();

private:
    typedef struct Node
    {
        Node() : data(), next(nullptr) {}
        Node(const T& element) : data(element), next(nullptr) {}
        Node(const T& element, Node* next_ptr) : data(element), next(next_ptr) {}
        T       data;
        Node*   next;
    }*LinkPtr;
    LinkPtr         _head;
    size_t          _size;
};

template<class T>
List<T>::List()
{
    _head = new Node(); 
    _size = 0;
}

template<class T>
List<T>::~List()
{
    LinkPtr ptr = _head; 
    while(_head->next)
    {
        ptr = _head->next;
        _head->next = ptr->next;
        delete ptr;
    }
    delete _head;
}

template<class T>
const T& List<T>::front()
{
    if (empty())  
        throw Exception("");
    return _head->next->data;
}

template<class T>
void List<T>::push_front(const T& element)
{
    _head->next = new Node(element, _head->next);
    _size++;
}

template<class T>
void List<T>::pop_front()
{
    if (empty())  
        throw Exception("");
    LinkPtr node = _head->next;
    _head->next = _head->next->next;
    delete node;
    _size--;
}

template<class T>
void List<T>::insert_after(size_t pos, const T& element)
{
    if (empty())  
        throw Exception("");
    if (pos > _size)
        throw Exception("");
    LinkPtr ptr = _head; 
    while(ptr->next && pos > 0)
    {
        ptr = _head->next;
        pos--;
    }
    ptr->next = new Node(element, ptr->next);
    _size++;
}

template<class T>
void List<T>::erase_after(size_t pos)
{
    if (empty())  
        throw Exception("");
    if (pos > _size)
        throw Exception("");
    LinkPtr ptr = _head; 
    while(ptr->next && pos > 0)
    {
        ptr = _head->next;
        pos--;
    }
    LinkPtr node = ptr->next;
    ptr->next = node->next;
    delete node;
    _size--;
}
    
template<class T>
void List<T>::remove(const T& element)
{
}

template<class T>
void List<T>::merge(const List<T>& other)
{

}

template<class T>
template<class Compare>
void List<T>::merge(const List<T>& other, Compare comp)
{

}

template<class T>
void List<T>::sort()
{
    sort(lt::Less<T>());
}

template<class T>
template<class Compare>
void List<T>::sort(Compare comp)
{
    
}

template<class T>
void List<T>::clear()
{
    
}

template<class T>
void List<T>::reserve()
{
    LinkPtr ptr = _head->next;
    LinkPtr prev = nullptr;
    while(ptr)
    {
        LinkPtr node = ptr->next; 
        ptr->next = prev;
        prev = ptr;
        ptr->node;
    }
    _head->next = prev;
}

}

#endif

