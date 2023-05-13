#ifndef ENGINE_H
#define ENGINE_H

#include <string>

class Engine{
    private:
        int _year;
        double _horsePower;
        std::string _engineModel;

    public:
        enum Type {GAS, PETROL, DIESEL, ELECTRIC};
        Type _type;
        Engine() = default;
    
        Engine(double horsePower, std::string engineModel, Type type, int year) : _horsePower(horsePower), _engineModel(engineModel), _type(type), _year(year) {}

        std::string getEngineType() const {
            switch(_type){
                case(GAS):
                    return "GAS";
                case(PETROL):
                    return "PETROL";
                case(DIESEL):
                    return "DIESEL";
                case(ELECTRIC):
                    return "ELECTRIC";
            }
            return "UNKNOWN";
        }

        friend std::ostream& operator<<(std::ostream& os, const Engine& engine) {
            os << "Engine horsepower: " << engine._horsePower << std::endl;
            os << "Engine model: " << engine._engineModel << std::endl;
            os << "Engine type: " << engine._type << std::endl;
            os << "Engine year: " << engine._year << std::endl;
            return os;
        }

        double getHorsePower() const {
            return _horsePower;
        }

        int getYear() const {
            return _year;
        }

        std::string getEngineModel() const {
            return _engineModel;
        }

        Engine& setEngineModel(std::string engineModel) {
            _engineModel = engineModel;
            return *this;
        }

        Engine& setEngineType(Type type) {
            _type = type;
            return *this;
        }

        Engine& setHorsePower(double horsePower) {
            _horsePower = horsePower;
            return *this;            
        }

        Engine& setYear(int year) {
            _year = year;
            return *this;
        }
};
#endif

