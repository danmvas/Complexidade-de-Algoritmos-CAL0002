#ifndef __PRIME_GENERATOR_H__
#define __PRIME_GENERATOR_H__

#include <stdlib.h>
#include <time.h>
#include "../lib/utils.h"

template <class T>
class prime_generator
{
public:
    prime_generator(){};
    ~prime_generator(){};
    bool is_prime(T n);
    T prime(int size = 32);
    T random_value(int size = 32);
};


#endif // __PRIME_GENERATOR_H__