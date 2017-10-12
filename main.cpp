/* 
 * File:   main.cpp
 * Author: aaugustyniak
 *
 * Created on 15 listopad 2014, 19:33
 */

#include <cstdlib>

#include "Pool.h"
#include "Object.h"

using namespace std;

/*
 * No memory leaks
 * valgrind --leak-check=yes -v ./arenaallocator
 */
int main(int argc, char** argv) {
    Pool::init();

    Object* a = new Object;
    Object* b = new Object;

    delete a;
    Pool::release();

    Object* c = new Object;
    delete c;

    return 0;
}

