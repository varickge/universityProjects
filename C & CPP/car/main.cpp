#include <iostream>
#include "Car.h"
#include "Truck.h"
#include "Vehicle.h"
#include "Engine.h"


int main() {

    Car* car1 = new Car(Engine(120, "w111", Engine::PETROL, 2010), "Toyota", "Corolla", 12000, 2100, 190, 2022, 5);
    Car* car2 = new Car(Engine(300, "w10", Engine::PETROL, 2015), "Mercedes-Benz", "CLS 600", 27000, 2350, 268, 2017, 4);
    Truck* truck1 = new Truck(Engine(120, "g-67", Engine::PETROL, 2016), "Ford", "F-150", 68000, 3250, 210, 2019, 5000);
    truck1->setCurrentLoad(12000);

    Vehicle* arr[3];
    arr[0] = car1;
    arr[1] = car2;
    arr[2] = truck1;

    for (int i = 0; i < 3; i++){
        if (typeid(*arr[i]) == typeid(Truck) ){
            int currLoad = dynamic_cast<Truck*>(arr[i])->getCurrentLoad();
            if(currLoad > 10000){
                std::cout << "\n---> " << arr[i]->getProducer() << " " << arr[i]->getModel() << " can't be runed, because it's current load is " << currLoad << " kg.\n" << std::endl;
                continue;
            }
        }
        arr[i]->run(60);
    }

    for (int i = 0; i < 3; i++){
        std::cout << typeid(*arr[i]).name() << " *Note: ";
        delete arr[i];
    }





    return 0;
}
