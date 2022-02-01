//
// Created by Samvel on 01/02/2022.
//

#include "Point2D.h"

Point2D::Point2D(){
    this->x = 0;
    this->y = 0;
}

Point2D::Point2D(const int & x, const int & y){
    this->x = x;
    this->y = y;
}

int Point2D::getX() const {
    return x;
}

void Point2D::setX(int x) {
    this->x = x;
}

int Point2D::getY() const {
    return y;
}

void Point2D::setY(int y) {
    this->y = y;
}

string Point2D::toString() const{
    return "[" +to_string(x) + "," + to_string(y) + "]";
}

std::ostream &operator<<(ostream &os, const Point2D &d) {
    return os << d.toString();
}