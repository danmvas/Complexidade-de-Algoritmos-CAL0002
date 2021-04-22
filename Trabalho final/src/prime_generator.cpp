#include "../lib/prime_generator.h"

template<class T>
T prime_generator<T>::prime(int size) 
{
    T p = random_value(size);
    while(not is_prime(p))
    {
        p = random_value(size);
    }
    return p;
}

template<class T>
bool prime_generator<T>::is_prime(T n) 
{
    // Miller-Rabin: O(log(N))
    if (n < 2) return false;
    T r = 0;
    T d = n - 1;
    while ((d & 1) == 0) d >>= 1, ++r;
    for (T a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return true;
        if (is_composite(n, a, d, r)) return false;
    }
    return true;
}

template<class T>
T prime_generator<T>::random_value(int size) 
{
    T value(0);
    T base(1);
    for(int bit = 0; bit < size; ++bit)
    {
        int r = rand();
        if(r & 1)
        {
            value += base;
        }
        base <<= 1;
    }
    return value;
}