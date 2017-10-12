/* 
 * File:   Object.h
 * Author: aaugustyniak
 *
 * Created on 15 listopad 2014, 19:43
 */

#ifndef OBJECT_H
#define	OBJECT_H
#include <cstddef>

class Object {
public:
    Object();
    Object(const Object& orig);
    virtual ~Object();

    void* operator new(std::size_t);
    void operator delete(void*);
private:
    int member;
};

#endif	/* OBJECT_H */

