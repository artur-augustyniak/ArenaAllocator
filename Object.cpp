/* 
 * File:   Object.cpp
 * Author: aaugustyniak
 * 
 * Created on 15 listopad 2014, 19:43
 */

#include <stdlib.h>
#include <iostream>
#include "Object.h"
#include "Pool.h"

Object::Object() {
}

Object::Object(const Object& orig) {
}

Object::~Object() {
}

void* Object::operator new(std::size_t size) {
    Pool* p = Pool::_instance;
    if (NULL != p) {
        std::cout << "Pool new" << std::endl;
        return Pool::_instance->alloc(size);
    }
    std::cout << "Regular new" << std::endl;
    return malloc(size);
}

void Object::operator delete(void* o) {
    Pool* p = Pool::_instance;
    if (NULL == p) {
        std::cout << "Regular delete" << std::endl;
        free(o);
        return;
    }
    std::cout << "Pool active, delete noop" << std::endl;
}
