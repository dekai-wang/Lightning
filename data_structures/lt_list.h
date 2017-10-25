/**
* @file lt_list
* @brief 链表
* @author dekai.wang
* @version 
* @date 2017-09-21
*/

#ifndef _LT_LIST_H_
#define _LT_LIST_H_

#include <iostream>
#include <sstream>
#include "base/lt_node.h"
#include "base/noncopyable.h"

namespace lt
{

template<class T>
class LinkList : public noncopyable
{
    typedef LinkNode<T>* LinkedPtr;
public:
    LinkList();
    virtual ~LinkList();

    /**
     * @brief 在最前位置添加元素
     *
     * @param element
     */
    void push_front(const T &element);

    /**
     * @brief 在最后位置追加元素
     *
     * @param element
     */
    void push_back(const T &element);

    /**
     * @brief 在指定位置之后插入一个元素
     *
     * @param element 元素
     * @param pos 位置
     * @return 成功失败
     */
    bool insert_after(const T &element, int pos);

    /**
     * @brief 删除指定位置的元素
     *
     * @param pos
     * @return 成功失败
     */
    bool erase(int pos);

    /**
     * @brief 删除指定区间的元素
     *
     * @param begin 
     * @param end
     * @return 成功失败
     */
    bool erase(int begin, int end);

    /**
     * @brief 反转
     *
     * @param 
     */
    void reverse();

    /**
     * @brief 清理全部元素 
     */
    void clear();

    /**
     * @brief 获取指定位置的元素 
     *
     * @param pos
     *
     * @return 
     */
    const T& get(int pos);

    /**
     * @brief 
     *
     * @return 大小
     */
    uint32_t size() const { return _size; }

private:
    void valid_index_value(int index);

    uint32_t        _size; 
    LinkedPtr       _head;
};

template<class T>
LinkList<T>::LinkList() 
{
    _head = new LinkNode<T>();
    _size = 0;
}

template<class T>
LinkList<T>::~LinkList()
{
    while (_head->next)
    {
        LinkedPtr ptr = _head->next;
        _head->next = ptr->next;
        delete ptr;
    }
    delete _head;
}

template<class T>
void LinkList<T>::valid_index_value(int index)
{
    if (index < 0 || index > _size) 
    {
        std::ostringstream s;
        s << "out of range : index = " << index << " size = " << _size;
        //throw Exception(s.str().c_str())
    }
}

template<class T>
void LinkList<T>::push_front(const T &element)
{
    insert_after(element, 0);
}

template<class T>
void LinkList<T>::push_back(const T &element)
{
    insert_after(element, _size);
}

template<class T>
bool LinkList<T>::insert_after(const T &element, int pos)
{
    valid_index_value(pos);
    LinkedPtr ptr = _head;    
    while (ptr->next && pos != 0)
    {
        ptr = ptr->next;
        pos--;
    }

    LinkedPtr node = new LinkNode<T>(element);
    node->next = ptr->next;
    ptr->next = node;
    _size++;

    return true;
}

template<class T>
bool LinkList<T>::erase(int pos)
{
    valid_index_value(pos);
    LinkedPtr ptr = _head;    
    while (ptr->next && pos != 0)
    {
        ptr = ptr->next;
        pos--;
    }
    LinkedPtr node = ptr->next;
    ptr->next = node->next;
    delete node;
    _size--;

    return true;
}

template<class T>
bool LinkList<T>::erase(int begin, int end)
{
    if (begin > end)
        return false;
    valid_index_value(begin);
    valid_index_value(end);

    LinkedPtr ptr = _head;
    while(ptr->next && begin != 1)
    {
        ptr = ptr->next;
        begin--;
        end--;
    }

    while(end != 0)
    {
        LinkedPtr node = ptr->next;
        ptr->next = node->next;
        delete node;
        _size--;
        end--;
    }

    return true;
}

template<class T>
void LinkList<T>::clear()
{
    while (_head->next)
    {
        LinkedPtr ptr = _head->next;
        _head->next = ptr->next;
        delete ptr;
    }
    _size = 0;
}

template<class T>
const T& LinkList<T>::get(int pos)
{
    valid_index_value(pos);
    LinkedPtr ptr = _head;
    while (ptr->next && pos != 0)
    {
        ptr = ptr->next;
        pos--;
    }
    return ptr->data;
}

template<class T>
void LinkList<T>::reverse()
{
   LinkedPtr ptr = _head->next; 
   LinkedPtr prev = nullptr;
   while(ptr)
   {
       LinkedPtr node = ptr->next;
       ptr->next = prev;
       prev = ptr;
       ptr = node;
   }
   _head->next = prev;
}

};

#endif
