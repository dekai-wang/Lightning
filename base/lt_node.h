/**
 * @file lt_node.cpp
 * @brief 数据结构链路节点
 * @author dekai.wang
 * @version 
 * @date 2017-09-21
 */

#ifndef _LT_NODE_H_
#define _LT_NODE_H_

namespace lt
{

template<class T>
struct LinkNode
{
    LinkNode() 
        : data(), next(nullptr) {}
    LinkNode(const T &element) 
        : data(element), next(nullptr) {}
    LinkNode(const T &element, LinkNode<T> *next_ptr) 
        : data(element), next(next_ptr) {}
    ~LinkNode() { next = nullptr; }
    T               data;
    LinkNode<T>     *next;
};

template<class T>
struct DoubleLinkNode
{
    DoubleLinkNode()
        : data(), prev(nullptr), next(nullptr) {}
    DoubleLinkNode(const T &element)
        : data(element), prev(nullptr), next(nullptr) {}
    DoubleLinkNode(const T &element, DoubleLinkNode<T> *prev_ptr, DoubleLinkNode<T> *next_ptr)
        : data(element), prev(prev_ptr), next(next_ptr) {}
    T               data;
    DoubleLinkNode<T>   *prev;
    DoubleLinkNode<T>   *next;
};

};

#endif

