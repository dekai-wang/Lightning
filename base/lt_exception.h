/**
 * @file lt_exception.h
 * @brief 
 * @author dekai.wang
 * @version 
 */

#ifndef _LT_EXCEPTION_H_
#define _LT_EXCEPTION_H_

#include <string>
#include <exception>

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

