#ifndef ALGO2_H
#define ALGO2_H
#include <iostream>
#include <ctime>  
#include <cstdlib> 
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "Crypto.h"

class Algorithm_2 : public Crypto {
    public:
        Algorithm_2() = default;

        size_t currNumRows;
        size_t currNumCols;

        std::string Encode(std::string inputStr) override {
                
            std::vector<std::string> inpStr = convertTo2D(inputStr);
            std::vector<std::string> transposed = transposeStringVector(inpStr);

            currNumRows = transposed.size();
            currNumCols = transposed[0].size();

            std::string ret = convertTo1D(transposed);
            return ret;
        }



        std::string Decode(std::string inputStr) override {
                
            std::vector<std::string> inpStr = convertTo2D(inputStr);
            std::vector<std::string> transposed = transposeStringVector(inpStr);

            currNumRows = transposed.size();
            currNumCols = transposed[0].size();

            std::string ret = convertTo1D(transposed);
            return ret;
        }

    private:

        std::vector<std::string> convertTo2D(const std::string& input) {
            std::vector<std::string> lines;
            std::string currentLine;

            for (char c : input) {
                if (c == '\n') {
                    lines.push_back(currentLine);
                    currentLine.clear();
                } else {
                    currentLine += c;
                }
            }

            // Add the last line (if not empty)
            if (!currentLine.empty()) {
                lines.push_back(currentLine);
            }

            return lines;
        }



        std::string convertTo1D(const std::vector<std::string>& lines) {
            std::string result;

            for (const std::string& line : lines) {
                result += line + '\n';
            }

            // Remove the trailing '\n' if there are lines in the vector
            if (!lines.empty()) {
                result.pop_back();
            }

            return result;
        }


        std::vector<std::string> transposeStringVector(const std::vector<std::string>& input) {
            std::vector<std::string> transposed;

            // Check if input vector is empty
            if (input.empty()) {
                return transposed; // Return an empty vector
            }

            size_t numRows = input[0].size();
            size_t numCols = input.size();

            transposed.resize(numRows, std::string(numCols, ' '));

            for (size_t i = 0; i < numRows; ++i) {
                for (size_t j = 0; j < numCols; ++j) {
                    transposed[i][j] = input[j][i];
                }
            }

            return transposed;
        }
};


#endif



