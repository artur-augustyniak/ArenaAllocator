/* 
 * File:   Pool.h
 * Author: aaugustyniak
 *
 * Created on 15 listopad 2014, 19:49
 */

#ifndef POOL_H
#define	POOL_H
#include <iostream>
#include <cstddef>

class Pool {
    friend class Object;
public:
    static void init();
    static void release();
    enum {size = 10000000};
private:
    unsigned char* mem;
    unsigned int current;
    Pool();
    virtual ~Pool();
    Pool(const Pool& orig);
    static Pool* Instance();
    void* alloc(std::size_t sz) throw (std::bad_alloc);
    Pool& operator=(Pool const&);
    static Pool* _instance;
};

#endif	/* POOL_H */

