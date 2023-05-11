#pragma once
#include <exception>

class copy_unsuccessful_exception_class : public std::exception
{
    virtual const char* what() const throw()
    {
        return "thrown exception: copy_unsuccessful\n";
    }
};