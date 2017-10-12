/* 
 * File:   Pool.cpp
 * Author: aaugustyniak
 * 
 * Created on 15 listopad 2014, 19:49
 */
#include <iostream>
#include <stddef.h>
#include <stdlib.h>
#include "Pool.h"


Pool* Pool::_instance = NULL;

void Pool::init() {
    if (!_instance)
        _instance = new Pool;
}

void Pool::release() {
    if (_instance){
        delete _instance;
        _instance = NULL;
    }
}

Pool::Pool() {
    std::cout << "Pool init" << std::endl;
    mem = 0;
    current = 0;
    mem = (unsigned char*) malloc(size);
}

Pool::~Pool() {
    std::cout << "Pool release" << std::endl;
    free(mem);
}

void* Pool::alloc(std::size_t sz) throw (std::bad_alloc){

    if (size <= (current + sz)) {
        throw std::bad_alloc();
    }
    current += sz;
    return mem + current - sz;
}

