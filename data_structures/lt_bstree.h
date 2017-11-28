/**
 * @file lt_bstree.h
 * @brief 二叉搜索树
 * @author dekai.wang
 * @version 
 */

#ifndef _LT_BTREE_H_
#define _LT_BTREE_H_

#include <iostream>
#include <sstream>
#include "base/lt_node.h"
#include "base/lt_exception.h"
#include "base/lt_noncopyable.h"

namespace lt
{

template<class T>
class BSTree : public noncopyable
{
    typedef TreeNode<T>*    LinkedPtr;
public:
    BSTree();
    virtual ~BSTree();

    void insert(const T& element);

    void remove(const T& element);

    LinkedPtr find(const T& element);

private:
    void _destroy(LinkedPtr node);
    LinkedPtr       _root;
};

template<class T>
BSTree<T>::BSTree()
{
    _root = nullptr;
}

template<class T>
BSTree<T>::~BSTree()
{
    _destroy(_root);
}

template<class T>
TreeNode<T>* BSTree<T>::find(const T& element)
{
    if (!_root)
        return nullptr;
    LinkedPtr ptr = _root; 
    while(ptr && ptr->data != element)
    {
        if (element < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return ptr;
}

template<class T>
void BSTree<T>::insert(const T& element)
{
    LinkedPtr ptr = _root; 
    LinkedPtr target = nullptr;
    while(ptr)
    {
        target = ptr; 
        if (element < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    if (!target)
        _root = new TreeNode<T>(element);
    else if (element < target->data)
        target->left = new TreeNode<T>(element);
    else
        target->right = new TreeNode<T>(element);
}

template<class T>
void BSTree<T>::remove(const T& element)
{
    LinkedPtr node = _root; 
    LinkedPtr parent = nullptr;
    while(node && element != node->data)
    {
        if (element < node->data)
        {
            parent = node; 
            node = node->left;
        }
        else
        {
            parent = node; 
            node = node->right;
        }
    }
    if (!parent && _root)
    {
        delete _root;
        _root = nullptr;
    }
    else
    {
        if (node->left == nullptr)
        {
            if (node->data < parent->data)
                parent->left = node->right;
            else
                parent->right = node->right;
        }
        else if (node->right == nullptr)
        {
            if (node->data < parent->data)
                parent->left = node->left;
            else
                parent->right = node->left;
        }
        else
        {
            LinkedPtr left = node->right;
            LinkedPtr leftParent = left;
            while(left->left)
            {
                leftParent = left;
                left = left->left;
            }
            if (leftParent->left != left)
            {
                leftParent->left = left->right;
                left->left = node->left;
                left->right = node->right;
            }
            else
            {
                left->left = node->left;
            }
            if (element < parent->data)
                parent->left = left;
            else
                parent->right = left;
        }
        delete node;
    }
}

template<class T>
void BSTree<T>::_destroy(LinkedPtr node)
{
    if (!node) 
        return;
    _destroy(node->left);
    _destroy(node->right);
    delete node;
}
    
};

#endif

