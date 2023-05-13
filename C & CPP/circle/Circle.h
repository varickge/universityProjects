#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"
#include <sstream>

class Circle
{
    friend double circleArea(const Circle&);
    friend std::ostream& operator<<(std::ostream&, const Circle&);


    public:
        Circle(double); 
        Circle(double, double, double); 
        Circle(double, double);
        //copy constructor
        Circle(const Circle&);


       ~Circle(); 

        Circle& setPoint(Point*);

        Point* getPoint() const {
            return _center;
        }

        static int getCounter(){
            return _count;
        }

        Circle& setRadius(double);

        double getRadius() const {
            return _radius;
        }
        std::string info() const; 

        bool containsPoint(Point&) const; 

        const Circle& operator=(const Circle& c1){
            _radius = c1._radius;
            setPoint(c1.getPoint());
            return *this;
        } 
        
    private:
        double _radius;
        static int _count;
        Point* _center;
};

#endif