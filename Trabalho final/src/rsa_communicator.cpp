#include "../lib/rsa_communicator.h"

#include <bits/stdc++.h>

rsa_communicator::rsa_communicator(int size) 
{
    kg = key_generator<big_int>(size);
    block_size = (size-5)/8;
}

big_int rsa_communicator::encrypt(big_int message) 
{
    return mod_exp(message, kg.public_key_2, kg.public_key_1);
}

std::vector<big_int> rsa_communicator::encrypt(std::vector<big_int>& message) 
{
    std::vector<big_int> encrypted;

    for(big_int& m: message)
    {
        encrypted.push_back(encrypt(m));
    }
    return encrypted;
}

big_int rsa_communicator::decrypt(big_int message) 
{
    return mod_exp(message, kg.private_key, kg.public_key_1);
}

std::vector<big_int> rsa_communicator::decrypt(std::vector<big_int>& message) 
{
    std::vector<big_int> decrypted;

    for(big_int& m: message)
    {
        decrypted.push_back(decrypt(m));
    }
    return decrypted;
}

std::vector<big_int> rsa_communicator::trim(std::string& message)
{
    std::vector<big_int> block;

    std::string m = "";
    for (char c: message)
    {
        m += c;
        if (m.size() == block_size)
        {
            block.push_back(hash(m));
            m = "";
        }
    }

    if (m != "")
    {
        block.push_back(hash(m));
        m = "";
    }

    return block;
}

big_int rsa_communicator::hash(std::string& message) 
{
    big_int value(0);
    big_int base(1);
    for(char c: message)
    {
        value += (c-base_start)*base;
        base  *= base_size;
    }
    return value;
}

std::string rsa_communicator::untrim(std::vector<big_int> value) 
{
    std::string message = "";
    for (big_int v: value)
    {
        message += unhash(v);
    }
    return message;
}

std::string rsa_communicator::unhash(big_int value) 
{
    std::string message = "";
    while(value > 0)
    {
        message += char(base_start + value%base_size);
        value /= base_size;
    }
    return message;
}
