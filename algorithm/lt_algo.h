/**
 * @file lt_algo.h
 * @brief 
 * @author dekai.wang
 * @version 
 */

#ifndef _LT_ALGO_H_
#define _LT_ALGO_H_

#include "base/lt_noncopyable.h"

namespace lt
{

/**
 * @brief 哈希函数
 */
template<class T>
struct Hash
{
    const int operator()(T key);
};

template<>
const int Hash<const char*>::operator()(const char* key)
{
    int hash_val = 0;
    while(*key != '\0') 
        hash_val = (hash_val << 5) + *key++;
    return hash_val;
}

template<class T>
struct Less
{
    bool operator()(const T& a, const T& b)
    {
        return a < b;
    }
};

class UnionFind : public noncopyable
{
public:
    UnionFind(size_t size)
    {
        _set = new uint32_t[size];
    }
    virtual ~UnionFind()
    {
        delete[] _set;
    }

    uint32_t Find(int x)
    {
        if (_set[x] <= 0)
            return x;
        else
            _set[x] = Find(_set[x]);
            return _set[x];
    }

    void Union(uint32_t root1, uint32_t root2)
    {
        
    }
    
private:
    size_t      _size;
    uint32_t*   _set;    
};

}

#endif
