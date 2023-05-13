#ifndef POINT_H
#define POINT_H
#include <sstream>

class Point {
    // declare global functions as friend functions
    friend Point& operator++(Point&); // preIncrement
    friend Point operator++(Point&, int); // postIncrement
    friend Point& operator--(Point&); // preDecrement
    friend Point operator--(Point&, int); // postDecrement
    friend std::ostream& operator<<(std::ostream&, const Point&);
    friend std::istream& operator>>(std::istream&, Point&);
    friend Point operator-(Point&, Point&);
    friend Point operator+(Point&, Point&);
    friend Point operator+=(Point&, Point&);
    friend Point operator-=(Point&, Point&);
    friend bool operator==(const Point&, const Point&);
    friend bool operator!=(const Point&, const Point&);
    friend bool operator>(const Point&, const Point&);
    friend bool operator<(const Point&, const Point&);
    friend bool operator<=(const Point&, const Point&);
    friend bool operator>=(const Point&, const Point&);

    // friend void setX(double);
    // friend void setY(double);


    public:
        Point(double, double); 

        double getX() const {
            return _x;
        }

        double getY() const {
            return _y;
        }

        void setX(double); 

        void setY(double); 

        // Point& operator++(){
        //     ++_x;
        //     ++_y;
        //     return *this;
        // } 

        // Point operator++(int){
        //     Point& temp(*this); //Question: we can use not only this but also _x, _y ?
        //     ++_x;
        //     ++_y;
        //     return temp;
        // } 

        //  Point& operator--(){
        //     --_x;
        //     --_y;
        //     return *this;
        // } 

        // Point operator--(int){
        //     Point& temp(*this);
        //     --_x;
        //     --_y;
        //     return temp;
        // } 

    private:
        double _x, _y;
};

#endif