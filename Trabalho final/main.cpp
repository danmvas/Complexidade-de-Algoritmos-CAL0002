#include <bits/stdc++.h>
#include "lib/rsa.h"
#include <boost/multiprecision/cpp_int.hpp> //biblioteca de numeros grandes
#include <chrono>  


using namespace std;
using namespace chrono;


int main(int argc, char const *argv[])
{
    int n; cin >> n;

    auto start = high_resolution_clock::now();
    key_generator< boost::multiprecision::uint1024_t> kg(n);
    cout << kg.public_key_1 << " " << kg.public_key_2 << " " << kg.private_key << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Tempo para gerar chaves de tamanho "<< n << ": " << duration.count() << "ms" << endl;

    auto start1 = high_resolution_clock::now();
    key_breaker< boost::multiprecision::uint1024_t> kb(kg.public_key_1, kg.public_key_2);
    cout << kb.public_key_1 << " " << kb.public_key_2 << " " << kb.private_key << endl; 
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);
    cout << "Tempo para quebrar chaves de tamanho "<< n << ": " << duration1.count() << "ms" << endl;

    return 0;
}

// k2 expoente
// k1 mod