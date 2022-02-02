//
// Created by Samvel on 02/02/2022.
//

#include "Triangle.h"

Triangle::Triangle(const string &nom, const Point2D &point, const Point2D &point2, const Point2D &point3) : Forme(nom, point), point2(point2), point3(point3) {}

const Point2D &Triangle::getPoint2() const {
    return point2;
}

void Triangle::setPoint2(const Point2D &point2) {
    Triangle::point2 = point2;
}

const Point2D &Triangle::getPoint3() const {
    return point3;
}

void Triangle::setPoint3(const Point2D &point3) {
    Triangle::point3 = point3;
}

string Triangle::toString() const {
    return getNom() + " p1:" + getPoint().toString() + " p2" + getPoint2().toString() +" p3" + getPoint3().toString();
}

ostream &operator<<(ostream &os, const Triangle &triangle) {
    return os << triangle.toString();
}
