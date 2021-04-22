#include <bits/stdc++.h>
#include <chrono>
#include "lib/rsa.h"


using namespace std;
using namespace chrono;


int main(int argc, char const *argv[])
{
    ofstream encrypted, decrypted;
    encrypted.open("test_files/encrypted.txt");
    decrypted.open("test_files/decrypted.txt");

    ifstream input("test_files/input.txt");
    stringstream buffer;
    buffer << input.rdbuf();
    std::string m(buffer.str());

    auto start = high_resolution_clock::now();

    rsa_communicator rsa(200);
    cout << rsa.kg.public_key_1 << " " << rsa.kg.public_key_2 << " " << rsa.kg.private_key << endl << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Tempo do RSA: " << duration.count() << " ms" << endl;
    
    auto v = rsa.trim(m);
    for (auto i: v)
    {
        cout << i << " ";
    }
    cout << endl << endl;
    // cout << rsa.untrim(v) << endl;

    auto v2 = rsa.encrypt(v);
    for (auto i: v2)
    {
        cout << i << " ";
    }
    cout << endl << endl;
    encrypted << rsa.untrim(v2) << endl;

    auto v3 = rsa.decrypt(v2);
    for (auto i: v3)
    {
        cout << i << " ";
    }
    cout << endl << endl;
    decrypted << rsa.untrim(v3) << endl;

    return 0;
}

// 418262377057 ^ 242999406436442011 % 1208235855064990133  = 8056123497285046
// 8056123497285046 ^ 136324210389921683 % 1208235855064990133 = 418262377057