/**
 * @file lt_avltree.h
 * @brief AVL树
 * @author dekai.wang
 * @version 
 */

#ifndef _LT_AVLTREE_H_
#define _LT_AVLTREE_H_

#include <algorithm>
#include "base/lt_noncopyable.h"
#include "base/lt_exception.h"
#include "base/lt_node.h"

namespace lt
{

template<class K, class T>
class AVLTree : public noncopyable
{
public:
    AVLTree();
    virtual ~AVLTree();

    void insert(const K& key, const T& element);
    TreeNode<K, T>* insert(const K& key, const T& element, TreeNode<K, T>* node);

    void remove(const T& key);

    TreeNode<K, T>* find(const T& key);

private:
    void destroy(const TreeNode<K, T>* node);
    int height(const TreeNode<K, T>* node);
    TreeNode<K, T>* singleRotateWithLeft(TreeNode<K, T>* node);
    TreeNode<K, T>* singleRotateWithRight(TreeNode<K, T>* node);
    TreeNode<K, T>* doubleRotateWithLeft(TreeNode<K, T>* node);
    TreeNode<K, T>* doubleRotateWithRight(TreeNode<K, T>* node);

    TreeNode<K, T>*       _root;
};

template<class K, class T>
AVLTree<K, T>::AVLTree()
{
    _root = nullptr;    
}

template<class K, class T>
AVLTree<K, T>::~AVLTree()
{
    destroy(_root);
}

template<class K, class T>
void AVLTree<K, T>::insert(const K& key, const T& element)
{
    _root = insert(key, element, _root);
}

template<class K, class T>
TreeNode<K, T>* AVLTree<K, T>::insert(const K& key, const T& element, TreeNode<K, T>* node)
{
    if (!node)
    {
        node = new TreeNode<K, T>(key, element);
    }
    else if (node->key < key)
    {
        node->right = insert(key, element, node->right);
        if (height(node->right) - height(node->left) == 2)
        {
            if (node->right->key < key)
                node = singleRotateWithRight(node);
            else
                node = doubleRotateWithRight(node);
        }
    }
    else
    {
        node->left = insert(key, element, node->left);
        if (height(node->left) - height(node->right) == 2)
        {
            if (node->left->key > key)
                node = singleRotateWithLeft(node);
            else
                node = doubleRotateWithLeft(node);
        }
    }
    node->height = std::max(height(node->right), height(node->left)) + 1;

    return node;
}

template<class K, class T>
void AVLTree<K, T>::remove(const T& element)
{

}

template<class K, class T>
void AVLTree<K, T>::destroy(const TreeNode<K, T>* node)
{
    if (!node)
        return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

template<class K, class T>
int AVLTree<K, T>::height(const TreeNode<K, T>* node)
{
    if (node == nullptr)
        return -1;
    else
        return node->height;
}

template<class K, class T>
TreeNode<K, T>* AVLTree<K, T>::singleRotateWithLeft(TreeNode<K, T>* node)
{
    TreeNode<K, T>* left = node->left;
    node->left = left->right;
    left->right = node;

    node->height = std::max(height(node->left), height(node->right)) + 1;
    left->height = std::max(height(left->left), height(left->right)) + 1;

    return left;
}

template<class K, class T>
TreeNode<K, T>* AVLTree<K, T>::singleRotateWithRight(TreeNode<K, T>* node)
{
    TreeNode<K, T>* right = node->right;  
    node->right = right->left;
    right->left = node;

    node->height = std::max(height(node->left), height(node->right)) + 1;
    right->height = std::max(height(right->left), height(right->right)) + 1;

    return right;
}

template<class K, class T>
TreeNode<K, T>* AVLTree<K, T>::doubleRotateWithLeft(TreeNode<K, T>* node)
{
    node->left = singleRotateWithRight(node->left);

    return singleRotateWithLeft(node);
}

template<class K, class T>
TreeNode<K, T>* AVLTree<K, T>::doubleRotateWithRight(TreeNode<K, T>* node)
{
    node->left = singleRotateWithLeft(node->left);

    return singleRotateWithRight(node);
}

};

#endif

