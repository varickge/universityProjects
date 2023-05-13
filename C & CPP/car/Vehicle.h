#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>
#include "Engine.h"

class Vehicle{
    private:
        Engine _engine;
        std::string _producer;
        std::string _model;
        int _price;
        int _weight;
        int _maxSpeed;
        int _year;
        int _velocity;
        bool _isRunning;

        virtual void start() = 0;
        virtual void accelerate(double tillVelocity) = 0;
        virtual void stop() = 0;

    public:
        Vehicle() = default;
        Vehicle(const Engine& engine, const std::string& producer, const std::string& model, int price, int weight, int maxSpeed, int year) :
            _engine(engine), _producer(producer), _model(model), _price(price), _weight(weight), _maxSpeed(maxSpeed), _year(year) {}

        virtual ~Vehicle() {}

        friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle) {
            os << " +------------------+" << std::endl;
            os << "Producer: " << vehicle.getProducer() << std::endl;
            os << "Model: " << vehicle.getModel() << std::endl;
            os << "Price: " << vehicle.getPrice() << "$." << std::endl;
            os << "Weight: " << vehicle.getWeight() << "kg." << std::endl;
            os << "Max speed: " << vehicle.getMaxSpeed() << "km/h." << std::endl;
            os << "Year: " << vehicle.getYear() << std::endl;
            os << vehicle.getEngine();

            return os;
        }

        virtual void draw() const {
            std::cout << *this;            
        }

        void run(double tillVelocity) {
            std::cout << "\n---------\n";
            start();
            accelerate(tillVelocity);
            stop();
            std::cout << "---------\n";
            
        }

        const Engine& getEngine() const {
            return _engine;
        }

        const std::string& getProducer() const {
            return _producer;
        }

        const std::string& getModel() const {
            return _model;
        }

        int getPrice() const {
            return _price;
        }

        int getVelocity() const {
            return _velocity;
        }

        bool getRunningInfo() const {
            return _isRunning;
        }

        int getWeight() const {
            return _weight;
        }

        int getMaxSpeed() const {
            return _maxSpeed;
        }

        int getYear() const {
            return _year;
        }

        Vehicle& setEngine(const Engine& engine){
            _engine = engine;
            return *this;
        }

        Vehicle& setProducer(const std::string& producer){
            _producer = producer;
            return *this;
        }

        Vehicle& setModel(const std::string& model){
            _model = model;
            return *this;
        }

        Vehicle& setPrice(int price){
            _price = price;
            return *this;
        }

        Vehicle& setVelocity(int velocity){
            _velocity = velocity;
            return *this;
        }

        Vehicle& setIsRunning(bool isRunning){
            _isRunning = isRunning;
            return *this;
        }

        Vehicle& setWeight(int weight){
            _weight = weight;
            return *this;
        }
        
        Vehicle& setMaxSpeed(int maxSpeed){
            _maxSpeed = maxSpeed;
            return *this;
        }
        Vehicle& setYear(int year){
            _year = year;
            return *this;
        }
};

#endif