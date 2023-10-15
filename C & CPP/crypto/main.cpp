#include <iostream>
#include "algo1.h"
#include "algo2.h"
#include "algo3.h"
#include "algo4.h"



int main(){
    std::cout << "\nՊարզ փոխարինման\n" << std::endl;
    std::string myStr_1 = "NPUA";

    Algorithm_1 algo1;
    std::string strEncoded_1 = algo1.Encode(myStr_1);
    std::string strDecoded_1 = algo1.Decode(strEncoded_1);

    std::cout << "Inputed text: " << myStr_1 << "\n" << "Encoded text: " << strEncoded_1 << "\n" << "Decoded text: " << strDecoded_1 << std::endl;

    std::cout << "\n---------------------";
    std::cout << "\nՏողեր և Սյուներ\n" << std::endl;
    std::cout <<  "Inputed text: " << std::endl;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    size_t numRows = 4;
    size_t numCols = 3;
    // std::vector<std::vector<std::string>> myStr(numRows, std::vector<std::string>(numCols));
    std::string myStr;
    for(int i=0; i<numRows; i++){
        for(int j=0; j<numCols; j++){
            myStr += 'a' + (std::rand() % 26);
            std::cout << myStr.back() << " ";
        }
        myStr += "\n";
        std::cout << std::endl;
    }

    Algorithm_2 algo2;
    std::string strEncoded = algo2.Encode(myStr);
    numRows = algo2.currNumRows;
    numCols = algo2.currNumCols;
    std::cout <<  "\nEncoded text: " << std::endl;
    for (char c : strEncoded) {
        if (c == '\n') {
            std::cout << std::endl; // Print a newline when '\n' is encountered
        } else {
            std::cout << c << ' '; // Print the character followed by a space
        }
    }



    std::string strDecoded = algo2.Decode(strEncoded);
    numRows = algo2.currNumRows;
    numCols = algo2.currNumCols;
    std::cout <<  "\n\nDecoded text: " << std::endl;
    for (char c : strDecoded) {
        if (c == '\n') {
            std::cout << std::endl; // Print a newline when '\n' is encountered
        } else {
            std::cout << c << ' '; // Print the character followed by a space
        }
    }

    std::cout << "\n\n---------------------";
    std::cout << "\nRLE\n" << std::endl;

    Algorithm_3 algorithm;
    std::string inputStr1 = "00022347799";
    std::cout <<  "Inputed text:\n" << inputStr1 <<std::endl;

    std::string encodedStr1 = algorithm.Encode(inputStr1);
    std::cout << "\nEncoded text:\n" << encodedStr1 << std::endl;
    std::string decodedStr1 = algorithm.Decode(encodedStr1);
    std::cout << "\nDecoded text:\n" << decodedStr1 << std::endl;



    std::cout << "\n\n---------------------";
    std::cout << "\nCesar\n" << std::endl;

    Algorithm_4 caesar(3); // Create a CaesarCipher instance with a shift of 3
    std::string inputStr = "HELLO";
    std::cout <<  "Inputed text:\n" << inputStr <<std::endl;

    std::string encodedStr = caesar.Encode(inputStr);
    std::cout << "\nEncoded text:\n" << encodedStr << std::endl;
    std::string decodedStr = caesar.Decode(encodedStr);
    std::cout << "\nDecoded text:\n" << decodedStr << std::endl;

    return 0;

}