#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

float roundToDecimalPlaces(float number, int decimalPlaces) {
    float multiplier = std::pow(10.0f, static_cast<float>(decimalPlaces));
    return std::round(number * multiplier) / multiplier;
}

int main(){
    int size = 10;
    float* ptr = new float[size];
    
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Define the range for the random float
    float min = -100.0f;
    float max = 100.0f;
    int decimalPlaces = 2;

    std::cout << "Initial list:\n";

    for(int i=0; i<size; i++){
        float random_float = min + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX) / (max - min));
        ptr[i] = roundToDecimalPlaces(random_float, decimalPlaces);
        std::cout << ptr[i] << "   ";
    }

    max = min;

    for(int i=0; i<size; i++){
       if (max < ptr[i]){
        max = ptr[i];
       }
    }

    std::cout << "\nMax value is: " << -max;

    delete[] ptr;
    return 0;
}