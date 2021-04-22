#include "../lib/key_generator.h"

template<class T>
key_generator<T>::key_generator(int size) 
{
    T p, q, n, e, totient, d;
    do
    {
        prime_generator<T> pg;
        p = pg.prime(size/2);

        q = pg.prime(size/2);

        n = p*q;
        totient = lcm(p-1, q-1);

        e = pg.prime(size);
        while(e > totient || gcd(e, totient) != 1)
        {
            e = pg.prime(size);
        }

        d = mod_inverse(e, totient);

        this->public_key_1 = n;
        this->public_key_2 = e;
        this->private_key  = d;
    }
    while (e * d % totient != T(1));
    
}