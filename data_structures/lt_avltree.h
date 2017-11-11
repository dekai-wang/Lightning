/**
 * @file lt_avltree.h
 * @brief 
 * @author dekai.wang
 * @version 
 * @date 2017-11-10
 */

#ifndef _LT_AVLTREE_H_
#define _LT_AVLTREE_H_

#include <algorithm>
#include "base/lt_node.h"
#include "base/noncopyable.h"
#include "base/lt_exception.h"

namespace lt
{

template<class T>
class AVLTree : public noncopyable
{
public:
    AVLTree();
    virtual ~AVLTree();

    void insert(const T& element);
    TreeNode<T>* insert(const T& element, TreeNode<T>* node);

    void remove(const T& element);

    TreeNode<T>* find(const T& element);

private:
    void _destroy();
    int _height(const TreeNode<T>* node);
    TreeNode<T>* _singleRotateWithLeft(TreeNode<T>* node);
    TreeNode<T>* _singleRotateWithRight(TreeNode<T>* node);
    TreeNode<T>* _doubleRotateWithLeft(TreeNode<T>* node);
    TreeNode<T>* _doubleRotateWithRight(TreeNode<T>* node);


    TreeNode<T>*       _root;
};

template<class T>
AVLTree<T>::AVLTree()
{
    _root = nullptr;    
}

template<class T>
AVLTree<T>::~AVLTree()
{
    
}

template<class T>
void AVLTree<T>::insert(const T& element)
{
    _root = insert(element, _root);
}

template<class T>
TreeNode<T>* AVLTree<T>::insert(const T& element, TreeNode<T>* node)
{
    if (!node)
    {
        node = new TreeNode<T>(element);
    }
    else if (node->data < element)
    {
        node->right = insert(element, node->right);
        if (height(node->right) - height(node->left) == 2)
        {
            if (node->right->data < element)
                node = _singleRotateWithRight(node);
            else
                node = _doubleRotateWithRight(node);
        }
    }
    else
    {
        node->left = insert(element, node->left);
        if (height(node->left) - height(node->right) == 2)
        {
            if (node->left->data > element)
                node = _singleRotateWithLeft(node);
            else
                node = _doubleRotateWithLeft(node);
        }
    }
    node->height = std::max(height(node->right), height(node->left)) + 1;

    return node;
}

template<class T>
int AVLTree<T>::_height(const TreeNode<T>* node)
{
    if (node == nullptr)
        return -1;
    else
        return node->height;
}

template<class T>
TreeNode<T>* AVLTree<T>::_singleRotateWithLeft(TreeNode<T>* node)
{
    TreeNode<T>* left = node->left;
    node->left = left->right;
    left->right = node;

    node->height = std::max(height(node->left), height(node->right)) + 1;
    left->height = std::max(height(left->left), height(left->right)) + 1;

    return left;
}

template<class T>
TreeNode<T>* AVLTree<T>::_singleRotateWithRight(TreeNode<T>* node)
{
    TreeNode<T>* right = node->right;  
    node->right = right->left;
    right->left = node;

    node->height = std::max(height(node->left), height(node->right)) + 1;
    right->height = std::max(height(right->left), height(right->right)) + 1;

    return right;
}

template<class T>
TreeNode<T>* AVLTree<T>::_doubleRotateWithLeft(TreeNode<T>* node)
{
    node->left = _singleRotateWithRight(node->left);

    return _singleRotateWithLeft(node);
}

template<class T>
TreeNode<T>* AVLTree<T>::_doubleRotateWithRight(TreeNode<T>* node)
{
    node->left = _singleRotateWithLeft(node->left);

    return _singleRotateWithRight(node);
}

};

#endif

