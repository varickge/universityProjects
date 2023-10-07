// File: roman.cpp
// Author: Varuzhan Gevorgyan
// Date: September 19, 2023
// Description: This file contains C++ code for converting Roman numerals to integers.
//              It defines functions for converting single Roman numeral characters to integers
//              and for converting complete Roman numeral strings to integers.
// Copyright (c) 2023 Varuzhan Gevorgyan. All rights reserved.

#include <iostream>

/**
 * @brief Converts a single Roman numeral character to an integer.
 *
 * This function takes a Roman numeral character ('I', 'V', etc.) as input and returns
 * the corresponding integer value.
 *
 * @param c The Roman numeral character to convert.
 * @return The integer value of the Roman numeral character.
 */
int getInt(char c)
{
    switch(c)
    {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
        default : return -1;
    }
}

/**
 * @brief Converts a Roman numeral string to an integer.
 *
 * This function takes a Roman numeral string as input and returns the corresponding
 * integer value.
 *
 * @param str The Roman numeral string to convert.
 * @return The integer value of the Roman numeral string.
 */

int romanToInt(std::string str)
{
    int n = str.size() , result = 0 , current , next , i = 0;
    while(i < n)
    {
        if(i == n - 1)
        {
            result += getInt(str[i]);
            return result;
        }
        current = getInt(str[i]) , next = getInt(str[i + 1]);
        if(current >= next)
            result += current , i++;
        else
            result += next - current , i += 2;
    }
    return result;
}

int main()
{
    std::string str = "VXX";
    std::cout << romanToInt(str) << '\n';
    return 0;
}