/**
 * @file lt_algo.h
 * @brief 
 * @author dekai.wang
 * @version 
 */

#ifndef _LT_ALGO_H_
#define _LT_ALGO_H_

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

}

#endif
