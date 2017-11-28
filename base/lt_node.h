/**
 * @file lt_node.cpp
 * @brief 数据结构链路节点
 * @author dekai.wang
 * @version 
 */

#ifndef _LT_NODE_H_
#define _LT_NODE_H_

namespace lt
{

template<class T>
struct LinkNode
{
    LinkNode() 
        : data(), next(nullptr), key(nullptr) {}
    LinkNode(const T& element) 
        : data(element), next(nullptr), key(nullptr) {}
    LinkNode(const T& element, LinkNode<T>* next_ptr) 
        : data(element), next(next_ptr), key(nullptr) {}
    LinkNode(const T& element, LinkNode<T>* next_ptr, const char* key_str) 
        : data(element), next(next_ptr), key(key_str) {}
    ~LinkNode() { next = nullptr; }
    T               data;
    const char*     key;
    LinkNode<T>*    next;
};

template<class T>
struct DoubleLinkNode
{
    DoubleLinkNode()
        : data(), prev(nullptr), next(nullptr) {}
    DoubleLinkNode(const T& element)
        : data(element), prev(nullptr), next(nullptr) {}
    DoubleLinkNode(const T& element, DoubleLinkNode<T>* prev_ptr, DoubleLinkNode<T>* next_ptr)
        : data(element), prev(prev_ptr), next(next_ptr) {}
    T                   data;
    DoubleLinkNode<T>*  prev;
    DoubleLinkNode<T>*  next;
};

template<class T>
struct TreeNode
{
    TreeNode()
        : data(), left(nullptr), right(nullptr) { height = 0; }
    TreeNode(const T& element)
        : data(element), left(nullptr), right(nullptr) { height = 0; }
    TreeNode(const T& element, TreeNode<T>* left_ptr, TreeNode<T>* right_ptr)
        : data(element), left(left_ptr), right(right_ptr) { height = 0; }
    T               data;
    TreeNode<T>*    left;
    TreeNode<T>*    right;
    int             height;
};

};

#endif

