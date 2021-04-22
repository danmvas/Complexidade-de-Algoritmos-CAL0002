#ifndef __RSA_COMMUNICATOR_H__
#define __RSA_COMMUNICATOR_H__

#include <vector>
#include <string>
#include "key_generator.h"
#include <boost/multiprecision/cpp_int.hpp>

typedef boost::multiprecision::uint1024_t big_int;

class rsa_communicator
{
private:
    int block_size;
    int base_start = 0, base_size = 256;
public:
    key_generator<big_int> kg;
    rsa_communicator(int size = 32);
    ~rsa_communicator() {}

    big_int encrypt(big_int message);
    std::vector<big_int> encrypt(std::vector<big_int>& message);

    big_int decrypt(big_int message);
    std::vector<big_int> decrypt(std::vector<big_int>& message);

    std::vector<big_int> trim(std::string& message);
    big_int hash(std::string& message);

    std::string untrim(std::vector<big_int> value);
    std::string unhash(big_int value);

};

#endif // __RSA_COMMUNICATOR_H__

// texto -> int -> cryp_int

// cryp_int -> int -> texto 
