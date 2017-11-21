/**
* @file lt_hashtable.h
* @brief hash表
* @author dekai.wang
* @version 
* @date 2017-11-20
*/

#ifndef _LT_HASH_TABLE_H_
#define _LT_HASH_TABLE_H_

#include "base/lt_node.h"
#include "base/lt_exception.h"
#include "base/noncopyable.h"

namespace lt
{

template<class T>
class HashTable : public noncopyable
{
public:
    HashTable();
    HashTable(unsigned int size);
    virtual ~HashTable();

    LinkNode<T>* find(const char* key);

    void insert(const char* key, const T& element);
    void remove(const char* key);

    unsigned int Hash(const char* key);
private:
    LinkNode<T>*    _table[];
    unsigned int    _size;
};

template<class T>
HashTable<T>::HashTable()
{

}

template<class T>
HashTable<T>::HashTable(unsigned int size)
    : _size(size)
{
    _table = new LinkNode<T>*[_size];
    for (size_t i = 0; i < _size; i++)
        _table[i] = new LinkNode<T>();
}

template<class T>
LinkNode<T>* HashTable<T>::find(const char* key)
{
    LinkNode<T>* ptr = _table[Hash(key)];
    while(ptr->key != key && ptr != nullptr)
    {
        ptr = ptr->next;
    }
    return ptr;
}

template<class T>
void HashTable<T>::insert(const char* key, const T& element)
{
    unsigned int hash_val = Hash(key);
    LinkNode<T>* ptr = _table[hash_val];
    while(ptr->key != key && ptr != nullptr)
        ptr = ptr->next;
    if (ptr)
        return;
    LinkNode<T>* ele = new LinkNode<T>(element, ptr->next, key);
    ptr->next = ele;
}

template<class T>
void HashTable<T>::remove(const char* key)
{
    unsigned int hash_val = Hash(key);
    LinkNode<T>* ptr = _table[hash_val];
    LinkNode<T>* front_ptr = nullptr;
    while(ptr->key != key && ptr != nullptr)
    {
        front_ptr = ptr;
        ptr = ptr->next;
    }
    if (!ptr)
        return;
    front_ptr->next = ptr->next;
    delete ptr;
}

template<class T>
unsigned int HashTable<T>::Hash(const char* key)
{
    unsigned int HashVal = 0;
    while(*key != '\0')
        HashVal = (HashVal << 5) + *key++;

    return HashVal % _size;
}

};

#endif
