#ifndef __UTILS_H__
#define __UTILS_H__

template <class T>
T gcd(T x, T y);

template <class T>
T gcd(T a, T b, T& x, T& y);

template <class T>
T mod_exp(T base, T exp, T mod);

template <class T>
T mod_inverse(T x, T mod);

template <class T>
T lcm(T x, T y);

template <class T>
bool is_composite(T n, T a, T d, T s);

#endif // __UTILS_H__