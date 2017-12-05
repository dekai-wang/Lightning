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
#include "base/lt_node.h"

namespace lt
{

template<class K, class T>
class BSTree : public noncopyable
{
public:
    BSTree();
    virtual ~BSTree();

    void insert(const K& key, const T& element);

    TreeNode<K, T>* insert(const K& key, const T& element, TreeNode<K, T>* node);

    void remove(const K& key);

    const T* find(const K& key);
private:
    TreeNode<K, T>*       _root;
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
TreeNode<K, T>* BSTree<K, T>::insert(const K& key, const T& element, TreeNode<K, T>* node)
{
    if (!node) 
    {
        node = new TreeNode<K, T>(key, element);
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

template<class K, class T>
void BSTree<K, T>::remove(const K& key)
{
    
}
    
};

#endif

