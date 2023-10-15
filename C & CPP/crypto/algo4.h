#ifndef ALGO4_H
#define ALGO4_H
#include "Crypto.h"

class Algorithm_4 : public Crypto {
    private:
        int shift;

    public:
        Algorithm_4(int shift) : shift(shift) {}
        
        std::string Encode(std::string text) override {
            std::string result = "";
            for (char c : text) {
                if (isalpha(c)) {
                    char base = islower(c) ? 'a' : 'A';
                    result += static_cast<char>((c - base + shift) % 26 + base);
                } else {
                    result += c;
                }
            }
            return result;
        }

        std::string Decode(std::string text) override {
            std::string result = "";
            for (char c : text) {
                if (isalpha(c)) {
                    char base = islower(c) ? 'a' : 'A';
                    result += static_cast<char>((c - base - shift + 26) % 26 + base);
                } else {
                    result += c;
                }
            }
            return result;
        }
};

#endif
