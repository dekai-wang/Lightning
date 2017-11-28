/**
 * @file lt_hash_table.h
 * @brief 哈希表
 * @author dekai.wang
 * @version 
 */

#ifndef _LT_HASH_TABLE_H_
#define _LT_HASH_TABLE_H_

#include "base/lt_exception.h"
#include "base/lt_noncopyable.h"
#include "algorithm/lt_algo.h"

namespace lt
{

template<class K, class T, class H = lt::Hash<K> >
class HashTable : public noncopyable
{
public:
    HashTable();
    HashTable(size_t size);
    virtual ~HashTable();

    void insert(const K& key, const T& element);

    void erase(const K& key);

    const T& find(const K& key);

private:
    typedef struct Node
    {
        Node() : key(), data(), link(nullptr) {}
        Node(const K& k, const T& element) 
            : key(k), data(element), link(nullptr) {}
        Node(const K& k, const T& element, Node* link_ptr) 
            : key(k), data(element), link(link_ptr) {}
        K       key;
        T       data;
        Node*   link; 
    }*LinkPtr;
    LinkPtr*    _table;
    size_t      _size;
    H           _hash;
};

template<class K, class T, class H>
HashTable<K, T, H>::HashTable()
{
    HashTable(128);
}

template<class K, class T, class H>
HashTable<K, T, H>::HashTable(size_t size)
{
    _table = new LinkPtr[size];
    for (size_t i = 0; i < size; i++)
        _table[i] = new Node();
}

template<class K, class T, class H>
HashTable<K, T, H>::~HashTable()
{
    delete[]  _table;
}

template<class K, class T, class H>
void HashTable<K, T, H>::insert(const K& key, const T& element)
{
    const char* key_str = key;
    unsigned int hash_val = _hash(key_str) % _size;
    LinkPtr node = _table[hash_val];
    while(node->link && node->link->key != key)
    {
        node = node->link; 
    }
    if (node->link)
    {
        node->link->data = element;
    }
    else
    {
        node->link = new Node(key, element, node->link);
    }
}

template<class K, class T, class H>
void HashTable<K, T, H>::erase(const K& key)
{
    unsigned int hash_val = _hash(key) % _size;
    LinkPtr node = _table[hash_val];
    while(node->link && node->link->key != key)
    {
        node = node->link; 
    }
    if (node->link)
    {
        LinkPtr ptr = node->link;        
        node->link = node->link->link;
        delete ptr;
    }
}

template<class K, class T, class H>
const T& HashTable<K, T, H>::find(const K& key)
{
    unsigned int hash_val = _hash(key) % _size;
    LinkPtr node = _table[hash_val];
    while(node->link && node->link->key != key)
    {
        node = node->link; 
    }
    if (node->link)
    {
        return node->link->data;
    }
    else
    {
        return _table[hash_val]->data;
    }
}

}

#endif
