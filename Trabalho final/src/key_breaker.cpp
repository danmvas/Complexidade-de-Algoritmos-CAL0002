#include "../lib/key_breaker.h"
#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

template<class T>
key_breaker<T>::key_breaker(T key_1, T key_2, int method) 
{
    public_key_1 = key_1;
    public_key_2 = key_2;
    T p;
    if(method != 0)
    {
        p = slow_factorization(key_1);
    }
    else
    {
        p = fast_factorization(key_1);
    }
    T q = key_1/p;
    T totient =  lcm(p-1, q-1);
    private_key = mod_inverse(key_2, totient);
}

template<class T>
T key_breaker<T>::slow_factorization(T value) 
{
    auto start = high_resolution_clock::now();

    for (T i = 2; i <= sqrt(value); i++)
    {
        if (value%i == 0)
        {
            return value/i;
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Tempo de slow factoriation: " << duration.count() << " ms" << endl;
    
    return value;
}


template<class T>
T key_breaker<T>::fast_factorization(T value) // Pollar-Rho: O(N^(1/4) * log(N))
{
    auto start = high_resolution_clock::now();

	auto f = [value](T x) { return x*x % value + 1;};

	T x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	
    while (t++ % 40 || gcd(prd, value) == 1)
    {
		if (x == y)
        {  
            x = ++i, y = f(x);
        } 
		if ((q = prd * (std::max(x,y) - std::min(x,y)) % value))
        {
            prd = q;
        }
        x = f(x), y = f(f(y));
	}

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Tempo de fast factoriation: " << duration.count() << " ms" << endl;


	return gcd(prd, value);
}