#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"

class Truck : public Vehicle{
    public:
        Truck(const Engine& engine, const std::string& producer, const std::string& model, int price, int weight, int maxSpeed, int year, int capcity) : 
            Vehicle(engine, producer, model, price, weight, maxSpeed, year), _capcity(capcity) {}

        ~Truck() {
            Vehicle* vPtr = dynamic_cast<Vehicle*>(this);
            std::cout << "The " << vPtr->getProducer() << " " << vPtr->getModel() << " has been deleted.\n" << std::endl;
        }

        friend std::ostream& operator<<(std::ostream& os, const Truck& truck) {
            os << static_cast<const Vehicle&>(truck); 
            os << "Capcity: " << truck.getCapcity() << "l." << std::endl;
            os << " +------------------+" << std::endl;
            return os;
        }

        void draw() const override{
           std::cout << *this;
        }

        void start() override {
            Vehicle* vPtr = dynamic_cast<Vehicle*>(this);
            vPtr->setIsRunning(true);
            std::cout << "The" << vPtr->getProducer() << " " << vPtr->getModel() << "(truck) started going." << std::endl;
        }
        
        void accelerate(double tillVelocity) override {
            Vehicle* vPtr = dynamic_cast<Vehicle*>(this);
            int currVel = vPtr->getVelocity();
            int maxSpeed = vPtr->getMaxSpeed();
            while (currVel != tillVelocity && currVel <= maxSpeed) {
                currVel++;
            }
            vPtr->setVelocity(currVel);
            std::cout << "The " << vPtr->getProducer() << " " << vPtr->getModel() << "'s (truck) current velocity is " << vPtr->getVelocity() << " km/h." << std::endl;
        }

        void stop() override {
            Vehicle* vPtr = dynamic_cast<Vehicle*>(this);
            vPtr->setIsRunning(false);
            std::cout <<  "The " << vPtr->getProducer() << " " << vPtr->getModel() <<" (truck) stops. " << std::endl;
        }

        int getCapcity() const {
            return _capcity;
        }

        int getCurrentLoad() const {
            return _currentLoad;
        }

        Truck& setCapcity(int capcity) {
            _capcity = capcity;
            return *this;
        }

        Truck& setCurrentLoad(int currentLoad) {
            _currentLoad = currentLoad;
            return *this;
        }

    private:
        int _capcity;
        int _currentLoad;
};

#endif