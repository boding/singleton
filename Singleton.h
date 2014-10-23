/************************************************
 *
 * file  : Singleton.h
 * author: bobding
 * date  : 2014-10-23
 * detail:
 *
************************************************/

#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include "MutexLock.h"

template<typename T> class Singleton
{
public:
    static T* getInstancePtr()
    {
        if (0 == mInstance)
        {
            AutoMutexLock lock;

            if (0 == mInstance)
            {
                mInstance = new T();
            }
        }

        return mInstance;
    }

    virtual ~Singleton()
    {
    }

protected:
    Singleton(void)
    {
    }

    Singleton(const Singleton&)
    {
    }

    Singleton& operator = (const Singleton&)
    {
        return *this;
    }

protected:
    static T* mInstance;
};

template<typename T> T* Singleton<T>::mInstance = 0;

#endif // _SINGLETON_H_