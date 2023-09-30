#ifndef ALGO1_H
#define ALGO1_H
#include <iostream>
#include "Crypto.h"

class Algorithm_1 : public Crypto {
    public:
        Algorithm_1() = default;

        std::string Encode(std::string inputStr) override {
            std::string ret = inputStr; 

            for(int i=0; i < inputStr.length(); i++){
                for(int j=0; j < originalCharacters.length(); j++){
                    if(inputStr[i] == originalCharacters[j]){
                        ret[i] = replacementCharacters[j];
                    }
                }
            }

            return ret;

        }

        std::string Decode(std::string inputStr) override {
            std::string ret = inputStr; 

            for(int i=0; i < inputStr.length(); i++){
                for(int j=0; j < replacementCharacters.length(); j++){
                    if(inputStr[i] == replacementCharacters[j]){
                        ret[i] = originalCharacters[j];
                    }
                }
            }

            return ret;
        }

    private:
        std::string originalCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 !#$%&'()*+,-./:;<=>?@[\\]^_`{|}~\"";
        std::string replacementCharacters = "mn67!\"#$qrstu%&'()*+,-./012xyzABCDEFGHI345abcdefMNOPQRSTghijkl89:;<=>?@[\\]^_`opvwJKLUVWXYZ{|}~";


};




#endif



