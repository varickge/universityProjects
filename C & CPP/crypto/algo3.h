#ifndef ALGO3_H
#define ALGO3_H

#include <iostream>
#include "Crypto.h"

class Algorithm_3 : public Crypto {
public:
    Algorithm_3() = default;

    std::string Encode(std::string inputStr) override {
        std::string encodedStr = "";
        int count = 1;

        for (int i = 0; i < inputStr.length(); i++) {
            // Check if the current character is the same as the next one
            if (i + 1 < inputStr.length() && inputStr[i] == inputStr[i + 1]) {
                count++;
            } else {
                // Append the character and its count to the encoded string
                encodedStr += inputStr[i] + std::to_string(count);
                count = 1; // Reset the count for the next character
            }
        }

        return encodedStr;
    }

    std::string Decode(std::string inputStr) override {
        std::string decodedStr = "";

        for (int i = 0; i < inputStr.length(); i++) {
            // Read the character
            char currentChar = inputStr[i];

            // Find the count by parsing the following digits
            int count = 0;
            while (i + 1 < inputStr.length() && isdigit(inputStr[i + 1])) {
                count = count * 10 + (inputStr[i + 1] - '0');
                i++;
            }

            // Append the character to the decoded string 'count' times
            for (int j = 0; j < count; j++) {
                decodedStr += currentChar;
            }
        }

        return decodedStr;
    }
};

#endif
