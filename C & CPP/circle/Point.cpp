#include <iostream>
#include "Point.h"

Point::Point(double x, double y): _x(x), _y(y) {}

void Point::setX(double x){
    if (x > 0)
        _x = x;
    else
        std::cout << "The coordinate out of range (XOY)." <<  std::endl;
}

void Point::setY(double y){
    if (y > 0) {
        _y = y;
    }
    else {
        std::cout << "The coordinate out of range (XOY)." <<  std::endl;
    }
}


Point& operator++(Point& point){
    ++point._x;
    ++point._y;
    return point;
} 

Point operator++(Point& point, int){
    Point temp{point}; 
    ++point._x;
    ++point._y;
    return temp;
} 

Point& operator--(Point& point){
    --point._x;
    --point._y;
    return point;
} 

Point operator--(Point& point, int){
    Point temp(point);
    --point._x;
    --point._y;
    return temp;
} 

std::ostream& operator<<(std::ostream& os, const Point& p1){
    os << "X: " << p1._x << " Y: " << p1._y;
    return os;
}   

std::istream& operator>>(std::istream& is, Point& p1) {
    double x, y;
    is >> x >> y;
    p1._x = x;
    p1._y = y;
    return is;
}

Point operator+(Point& p1, Point& p2){
    return Point(p1._x + p2._x, p1._y + p2._y);
} 

Point operator-(Point& p1, Point& p2){
    return Point(p1._x - p2._x, p1._y - p2._y);
} 

const Point& operator+=(Point& p1, const Point& p2){
    p1._x += p2._x;
    p1._y += p2._y;
    return p1;
} 

const Point& operator-=(Point& p1, const Point& p2){
    p1._x -= p2._x;
    p1._y -= p2._y;
    return p1;
} 

bool operator==(const Point& p1, const Point& p2){
    return (p1._x == p2._x) && (p1._y == p2._y);
}

bool operator!=(const Point& p1, const Point& p2){
    return (p1._x != p2._x) && (p1._y != p2._y);
}

bool operator>(const Point& p1, const Point& p2){
    return (p1._x > p2._x) && (p1._y > p2._y);
}

bool operator>=(const Point& p1, const Point& p2){
    return (p1._x >= p2._x) && (p1._y >= p2._y);
}

bool operator<(const Point& p1, const Point& p2){
    return (p1._x < p2._x) && (p1._y < p2._y);
}

bool operator<=(const Point& p1, const Point& p2){
    return (p1._x <= p2._x) && (p1._y <= p2._y);
}