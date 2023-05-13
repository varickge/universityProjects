/*
    Requirments:
                c++ >= 17 (clang++ --std=c++17)
    Compile with : 
                clang++ --std=c++17 file.cpp
*/

#include <iostream>
#include <array>
#include <tuple>
#include <cmath>
const size_t size=5;

class Polynom{

    private:
            std::array<double, size > _coeff;
            std::array<int, size > _degree;
            char _letter; 
            static inline int _counter=0;

    public:
        Polynom()
        : _letter('x')
        {
            _coeff.fill(0);
            _degree.fill(0);
            _counter++;

        }
        Polynom(std::array<double, size >& coeff)
        : _letter('x') 
        {
            _coeff = coeff;
            _degree.fill(0);
            _counter++;
        }
        Polynom(std::array<int, size >& degree)
        : _letter('x') 
        {
            _degree = degree;
            _coeff.fill(0);
            _counter++;
        }
        Polynom(std::array<double, size >& coeff, std::array<int, size >& degree, char letter)
        : _letter('x') 
        {
            _degree = degree;
            _coeff = coeff;
            _letter = letter;
            _counter++;
        }

        void setCoeff(std::array<double, size >& coeff)
        {
            _coeff = coeff;
        }
        void setLetter(char& letter)
        {
            _letter = letter;
        }
        void setDegree(std::array<int, size >& degree)
        {
            _degree = degree;
        }

        static int getCounter()
        {
            return _counter;
        }
        char getLetter()
        {
            return _letter;
        }
        const  std::array<int, size >& getDegree() const
        {
            return  _degree;
        }
        const std::array<double, size >& getCoef() const
        {
            return _coeff;
        }
        void printPolynom() const
        {
            for (int i = 0; i < size; i++)
            {
                 if(i!=size-1)
                {
                    std::cout << _coeff[i] << _letter << "^" << _degree[i] << " + ";   
                }
                else
                {
                    std::cout << _coeff[i] << _letter << "^" << _degree[i];
                }
            }
        }
};

std::tuple<std::array<double, size>,  std::array<int, size>> calcDerivative(const Polynom& pol, int degree) 
{
    std::array<double, size > coeff;
    std::array<int, size > deg;
    for (int j=0; j<degree; j++)
    {
        for (int i=0; i<size; i++)
        {
            coeff[i] = pol.getCoef()[i] *  pol.getDegree()[i];
            deg[i] =  pol.getDegree()[i] - 1;
        }
    }
    return {coeff, deg};
}

int calcPolynomAt(const Polynom& pol, double x) 
{
    std::array<double, size > coeff;
    std::array<int, size > deg;
    double res;
    for (int i=0; i<size; i++)
    {
        res += std::pow(x,  pol.getDegree()[i]) * pol.getDegree()[i];
    }
    return res;
}

int main()
{
    std::array<double, size> coeff={3, 7, 11, 8, 5};
    std::array<int, size> degree={2, 3, 7, 0, 13};
    std::array<double, size> coeff_der;
    std::array<int, size> degree_der;
    char letter = 'x';
    int derDegree = 1;
    int polValAt = 4;

    // creating Polynom
    Polynom pol1(coeff, degree, letter);

    // calculate derDegree -th derivative of polynom
    std::tie(coeff_der, degree_der) = calcDerivative(pol1, derDegree);
    Polynom derPol(coeff_der, degree_der, letter);

    // print polynom and derivative and value at polValAt
    std::cout << "Polynom --> ";
    pol1.printPolynom();
    std::cout << "\n" << derDegree <<" th derivative of Polynom --> ";     
    derPol.printPolynom();
    std::cout << "\nPolynom value at " << polValAt <<  " --> " <<calcPolynomAt(pol1, polValAt) << std::endl;
    std::cout << "Polynom objects count --> " << pol1.getCounter();
    std::cout << "\n";

    return 0;
}
