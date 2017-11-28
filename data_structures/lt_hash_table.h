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

    void insert(const K key, const T& element);

    void erase(const K key);

private:
    typedef struct Node
    {

    }*LinkPtr;
    LinkPtr     _table[];
    size_t      _size;
};


}

#endif
