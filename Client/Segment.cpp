//
// Created by Samvel on 02/02/2022.
//

#include "Segment.h"

Segment::Segment(const string &nom, const Point2D &point, const Point2D &point2) : Forme(nom, point), point2(point2) {}

const Point2D &Segment::getPoint2() const {
    return point2;
}

void Segment::setPoint2(const Point2D &point2) {
    Segment::point2 = point2;
}

string Segment::toString() const {
    return getNom() + " " + getPoint().toString() + " : " + getPoint2().toString();
}

ostream &operator<<(ostream &os, const Segment &segment) {
    return os << segment.toString();
}
