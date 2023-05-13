#include <iostream>
#include "Circle.h"
#include <cmath>
#include <sstream>

int Circle::_count = 0;

Circle::Circle(double radius): _radius(radius){
        _center = new Point(1.0, 1.0);
        _count++;
        }   

Circle::Circle(double radius, double x, double y): _radius(radius){
            _center = new Point(x, y);
            _count++;
        }

Circle::Circle(double x, double y) : Circle(1.0, x, y) {
            _count++;
        }

Circle::Circle(const Circle& c1) : Circle(c1.getRadius(), c1.getPoint()->getX(), c1.getPoint()->getY()) {
            _count++;
        }

std::string Circle::info() const {
            std::ostringstream oss;
            oss << "Circle: (" << _center->getX() << ", " << _center->getY() << "), radius = " << _radius << std::endl;
            return oss.str();
        }

Circle::~Circle(){
            std::cout << "The Circle with the corresponding parameters (" << info() << ") has been deleted." << std::endl;
            delete _center;
        }

Circle& Circle::setPoint(Point* pPtr){
            delete _center;
            _center = new Point(*pPtr);
            return *this;
        }

Circle& Circle::setRadius(double radius) {
            if (radius > 0)
                _radius = radius;
            else
                std::cout << "The radius must be positive." << std::endl;
            return *this;
        }

bool Circle::containsPoint(Point& point) const {
            double distance = std::sqrt(std::pow((point.getX() - _center->getX()), 2) + std::pow((point.getY() - _center->getY()), 2));
            return distance <= _radius;
        }

std::ostream& operator<<(std::ostream& os, const Circle& c1){
    os << "Center: " << *c1._center << ", " << "; Radius: " << c1._radius;
    return os;
}

std::istream& operator>>(std::istream& is, Circle& c1) {
    double x, y, r;
    is >> x >> y >> r;
    Point newPtr = Point(x, y);
    c1.setPoint(&newPtr);
    c1.setRadius(r);
    return is;
}
