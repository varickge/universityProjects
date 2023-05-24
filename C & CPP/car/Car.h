#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"

class Car : public Vehicle{
    public:
        Car(const Engine& engine, const std::string& producer, const std::string& model, int price, int weight, int maxSpeed, int year, int sitCount) : 
            Vehicle(engine, producer, model, price, weight, maxSpeed, year), _sitCount(sitCount) {}

        ~Car() {
            // Vehicle* vPtr = dynamic_cast<Vehicle*>(this);
            std::cout << "The " << getProducer() << " " << getModel() << " has been deleted.\n" << std::endl;
        }

        friend std::ostream& operator<<(std::ostream& os, const Car& car) {
            os << static_cast<const Vehicle&>(car); 
            os << "Sit Count: " << car.getSitCount() << std::endl;
            os << " #------------------#" << std::endl;

            return os;
        }

        void draw() const override{
           std::cout << *this;
        }

       void start() override {
            Vehicle* vPtr = dynamic_cast<Vehicle*>(this);
            vPtr->setIsRunning(true);
            std::cout << "The " << vPtr->getProducer() << " " << vPtr->getModel() <<  " (car) started going." << std::endl;
        }
        
        void accelerate(double tillVelocity) override {
            Vehicle* vPtr = dynamic_cast<Vehicle*>(this);
            int currVel = vPtr->getVelocity();
            int maxSpeed = vPtr->getMaxSpeed();
            while (currVel != tillVelocity && currVel <= maxSpeed) {
                currVel++;
            }
            vPtr->setVelocity(currVel);
            std::cout << "The " << vPtr->getProducer() << vPtr->getModel() << "'s (car) current velocity is " << vPtr->getVelocity() << " km/h." << std::endl;
        }

        void stop() override {
            Vehicle* vPtr = dynamic_cast<Vehicle*>(this);
            vPtr->setIsRunning(false);
            std::cout << "The " << vPtr->getProducer() << " " << vPtr->getModel() << " (car) stops." << std::endl;
        }


        int getSitCount() const {
            return _sitCount;
        }

        Car& setSitCount(int sitCount) {
            _sitCount = sitCount;
            return *this;
        }

    private:
        int _sitCount;
};

#endif
