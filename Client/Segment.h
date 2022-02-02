//
// Created by Samvel on 02/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_SEGMENT_H
#define PPIL_MANUKYAN_LAGLER_SEGMENT_H


#include <ostream>
#include "Forme.h"

class Segment : public Forme{
private:
    Point2D point2;
public:
    Segment(const string &nom, const Point2D &point, const Point2D &point2);

    const Point2D &getPoint2() const;

    void setPoint2(const Point2D &point2);
    string toString() const;

};
    ostream &operator<<(ostream &os, const Segment &segment);

#endif //PPIL_MANUKYAN_LAGLER_SEGMENT_H
