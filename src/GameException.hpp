

#pragma once
#ifndef __SPACEG_EXCEPTION__
#define __SPACEG_EXCEPTION__

namespace spaceg {
 
/**
* Engine Exception
*/
class GameException : public std::exception
{
private:
    /// exception msg
    const char* msg;

public:
    /**
    * Constructor
    */
    GameException(const char* msg)
        : msg(msg)
    {
    }
    
    /**
    * Description
    */
    virtual const char* what() const throw()
    {
        return msg;
    }
};
    
}





#endif // __SPACEG_EXCEPTION__
