#include "../lib/utils.h"

template<class T>
T gcd(T x, T y) 
{
    if(x < y)
    {
        T aux = x;
        x = y;
        y = aux;
    }
    return (y == 0)? x : gcd(y, x%y);
}

template<class T> //O(b) ou O(log(n))
T gcd(T a, T b, T& x, T& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    T x1, y1;
    T d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

template<class T>
T lcm(T x, T y) 
{
    return x * y / gcd(x, y);
}

template<class T>
bool is_composite(T n, T a, T d, T s) 
{
    // Miller-Rabin Test
    T x = mod_exp(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (T r = 1; r < s; r++) {
        x = x * x % n;
        if (x == n - 1) return false;
    }
    return true;
}

template<class T>
T mod_exp(T base, T exp, T mod) 
{
    T res(1);
    while(exp){
        if(exp & 1)
        {
            res = (res * base) % mod;
        }
        exp /= 2;
        base = (base * base) % mod;
    }
    return res;
}

template<class T>
T mod_inverse(T a, T mod) 
{
    T x, y;
    T g = gcd(a, mod, x, y);
    x = (x % mod + mod) % mod;
    return x;
}