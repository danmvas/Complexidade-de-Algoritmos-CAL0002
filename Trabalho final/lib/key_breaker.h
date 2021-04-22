#ifndef __KEY_BREAKER_H__
#define __KEY_BREAKER_H__

#include "utils.h"
#include "prime_generator.h"

template <class T>
class key_breaker
{
public:
    T public_key_1, public_key_2, private_key;
    key_breaker(){};
    key_breaker(T key_1, T key_2, int method = 0);
    ~key_breaker(){};

    T slow_factorization(T value);
    T fast_factorization(T value);
};


#endif // __KEY_BREAKER_H__