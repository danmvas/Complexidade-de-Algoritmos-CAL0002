#ifndef __KEY_GENERATOR_H__
#define __KEY_GENERATOR_H__

#include "utils.h"
#include "prime_generator.h"

template <class T>
class key_generator
{
public:
    T public_key_1, public_key_2, private_key;
    key_generator(int size = 32);
    ~key_generator(){};
};

#endif // __KEY_GENERATOR_H__