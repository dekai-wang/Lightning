/**
 * @file lt_exception.h
 * @brief 
 * @author dekai.wang
 * @version 
 * @date 2017-10-30
 */

#ifndef _LT_EXCEPTION_H_
#define _LT_EXCEPTION_H_

#include <exception>
#include <string>

namespace lt
{
class Exception : public std::exception
{
public:
    Exception(const char* what)
    {
        _message = what;
    }
    virtual ~Exception() throw()
    {
    }
    virtual const char* what() const throw()
    {
        return _message.c_str();
    }
private:
    std::string _message;
};

};

#endif

