/**
 * @file lt_bstree.h
 * @brief 二叉搜索树
 * @author dekai.wang
 * @version 
 */

#ifndef _LT_BTREE_H_
#define _LT_BTREE_H_

#include "base/lt_exception.h"
#include "base/lt_noncopyable.h"

namespace lt
{

template<class K, class T>
class BSTree : public noncopyable
{
public:
    BSTree();
    virtual ~BSTree();

    void insert(const K& key, const T& element);

    void remove(const K& key);

    const T* find(const K& key);

private:
    typedef struct Node
    {
        Node() 
            : key(), data(), left(nullptr), right(nullptr) {}
        Node(const K& k, const T& element) 
            : key(k), data(element), left(nullptr), right(nullptr) {}
        Node(const K& k, const T& element, Node* left_ptr, Node* right_ptr) 
            : key(k), data(element), left(left_ptr), right(right_ptr) {}
        K       key;
        T       data;
        Node*   left;
        Node*   right;
    }*LinkPtr;

    LinkPtr insert(const K& key, const T& element, LinkPtr node)
    {
        if (!node) 
        {
            node = new Node(key, element);
            return node;
        }
        if (key > _root->key)
        {
            node->right = insert(key, element, node->right);
        }
        else if (key < _root->key)
        {
            node->left = insert(key, element, node->left);
        }
        else
        {

        }
        return node;
    }

    LinkPtr     _root;
};

template<class K, class T>
BSTree<K, T>::BSTree()
{
     
}

template<class K, class T>
BSTree<K, T>::~BSTree()
{
     
}

template<class K, class T>
void BSTree<K, T>::insert(const K& key, const T& element)
{
    _root = insert(key, element, _root);
}

template<class K, class T>
void BSTree<K, T>::remove(const K& key)
{
    
}
    
};

#endif

