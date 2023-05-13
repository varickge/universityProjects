// g++ --std=c++17 Point.cpp Circle.cpp mainCircle.cpp -o program
// ./program

#include <iostream>
#include "Circle.h"
#include "Point.h"
#include <cmath>

bool isPointInCircle(const Circle& circle, Point& p) {
  return circle.containsPoint(p);
}

double twoCircleDistances(const Circle& c1, const Circle& c2){
    return std::sqrt(std::pow((c1.getPoint()->getX() - c2.getPoint()->getX()), 2) + std::pow((c1.getPoint()->getY() - c2.getPoint()->getY()), 2));
}

int countIntersections(const Circle& c1, const Circle& c2) {
    double distance = twoCircleDistances(c1, c2);

    if (distance > c1.getRadius() + c2.getRadius()) {
        return 0;
    } else if (distance < std::abs(c1.getRadius() - c2.getRadius())) {
        return 0;
    } else if (distance == c1.getRadius() + c2.getRadius()) {
        return 1;
    } else if ( (distance == 0) && (c1.getRadius() == c2.getRadius()) ) {
        return -1;
    } else {
        return 2;
    }
}

double circleLength(const Circle& c1){
    return 2 * M_PI * c1.getRadius();
}

double circleArea(const Circle& c1){
    return 2 * M_PI * std::pow(c1._radius, 2);
}

void shiftAcrossX(Circle& c1, double factor){
    double newX = c1.getPoint()->getX() + factor;
    if (newX > 0){
        Point newPtr = Point(newX, c1.getPoint()->getY());
        c1.setPoint(&newPtr);
    }
    else
        std::cout << "New coordinate out of range (XOY)." << std::endl;
}

void shiftAcrossY(Circle& c1, double factor){
    double newY = c1.getPoint()->getY() + factor;
    if (newY > 0){
        Point newPtr = Point(c1.getPoint()->getX(), newY);
        c1.setPoint(&newPtr);
    }
    else
        std::cout << "New coordinate out of range (XOY)." << std::endl;
}

void scaleCircleArea(Circle& c1, double k){
    if (k > 0){
        double newRadius = c1.getRadius() * std::sqrt(k);
        c1.setRadius(newRadius);
    }
    else
        std::cout << "Can't scale with" << k <<" factor." << std::endl;
}

int main() {

    // create two circles with different radii and centers
    Circle c1(4.0, 3.0, 1.0);
    Circle c2(3.0);
    Circle c3(c1);

    // print the circles' information
    Point nPtr = Point(3.0, 7.0);
    c1.setPoint(&nPtr).setRadius(4.0);
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    std::cout << c3 << std::endl;


    c1 = c2;
    std::cout << "\n" << c1 << std::endl;
    std::cout << c2 << "\n" << std::endl;

    // move the first circle 1 unit to the right and 2 units up
    shiftAcrossX(c1, 1.0);
    shiftAcrossY(c1, 2.0);

    // scale the first circle's area by a factor of 2
    scaleCircleArea(c1, 2.0);
    // print the first circle's new information
    std::cout << c1.info();

    // compute the distance between the two circles
    double distance = twoCircleDistances(c1, c2);
    std::cout << "Distance between circles: " << distance << std::endl;

    // compute the number of intersections between the two circles
    int intersections = countIntersections(c1, c2);
    std::cout << "Number of intersections: " << intersections << std::endl;

    // compute the circumference and area of the first circle
    double circumference = circleLength(c1);
    double area = circleArea(c1);
    std::cout << "Circumference: " << circumference << std::endl;
    std::cout << "Area: " << area << std::endl;

    // create a point and check if it's inside the first circle
    Point p(3.0, 4.0);
    bool inside = isPointInCircle(c1, p);
    std::cout << "Point is inside circle: " << inside << std::endl;
    std::cout << "Count of Circle class objects is " << c1.getCounter() << std::endl;

    return 0;
}

