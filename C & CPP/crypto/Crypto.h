#ifndef CRYPTO_H
#define CRYPTO_H
#include <iostream>

class Crypto {

    public:
        Crypto() = default;
        virtual std::string Encode(std::string) = 0;
        virtual std::string Decode(std::string) = 0;

};


#endif