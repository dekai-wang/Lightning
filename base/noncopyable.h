/**
 * @file noncopyable.h
 * @brief 不可复制对象基类
 * @author dekai.wang
 * @version 
 * @date 2017-09-21
 */

#ifndef _NONCOPYABLE_H_
#define _NONCOPYABLE_H_

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

typedef base::_noncopyable noncopyable;

#endif //noncopyable.h
