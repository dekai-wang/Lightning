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

template<class K, class T>
class TreeNode
{
public:
    TreeNode()
        : key(), data(), left(nullptr), right(nullptr) { height = 0; }
    TreeNode(const K& k, const T& element)
        : key(k), data(element), left(nullptr), right(nullptr) { height = 0; }
    TreeNode(const K& k, const T& element, TreeNode<K, T>* left_ptr, TreeNode<K, T>* right_ptr)
        : key(k), data(element), left(left_ptr), right(right_ptr) { height = 0; }
    K                   key;
    T                   data;
    TreeNode<K, T>*     left;
    TreeNode<K, T>*     right;
    int                 height;
};

};

#endif

