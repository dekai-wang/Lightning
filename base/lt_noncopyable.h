/**
 * @file noncopyable.h
 * @brief 不可复制对象基类
 * @author dekai.wang
 * @version 
 */

#ifndef _NONCOPYABLE_H_
#define _NONCOPYABLE_H_

namespace lt
{

namespace base
{

class _noncopyable
{
public:
    _noncopyable(){};
    ~_noncopyable(){};

private:
    _noncopyable(const _noncopyable &);
    const _noncopyable & operator= (const _noncopyable &);
};

}

}

typedef lt::base::_noncopyable noncopyable;

#endif //noncopyable.h
