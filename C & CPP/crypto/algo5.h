#ifndef ALGO5_H
#define ALGO5_H
#include "Crypto.h"

#include <iostream>

class Algorithm_5 : public Crypto {
private:
    std::string keyword;

public:
    Algorithm_5(const std::string &keyword) : keyword(keyword) {}

    std::string Encode(std::string text) override {
        std::string output = "";
        int j = 0;

        for (char c : text) {
            if (c >= 'a' && c <= 'z')
                c = c + 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;

            output += ((c + keyword[j] - 2 * 'A') % 26) + 'A';
            j = (j + 1) % keyword.length();
        }
        return output;
    }

    std::string Decode(std::string text) override {
        std::string output = "";
        int j = 0;

        for (char c : text) {
            if (c >= 'a' && c <= 'z')
                c = c + 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;

            output += ((c - keyword[j] + 26) % 26) + 'A';
            j = (j + 1) % keyword.length();
        }
        return output;
    }
};


#endif
