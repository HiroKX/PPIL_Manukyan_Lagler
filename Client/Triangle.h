//
// Created by Samvel on 02/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_TRIANGLE_H
#define PPIL_MANUKYAN_LAGLER_TRIANGLE_H


#include <ostream>
#include "Point2D.h"
#include "Forme.h"

class Triangle : public Forme {
    private:
        Point2D point2;
        Point2D point3;

    public:
        Triangle(const string &nom, const Point2D &point, const Point2D &point2, const Point2D &point3);
        const Point2D &getPoint2() const;
        void setPoint2(const Point2D &point2);
        const Point2D &getPoint3() const;
        void setPoint3(const Point2D &point3);
        string toString() const;
};

    ostream &operator<<(ostream &os, const Triangle &triangle);

#endif //PPIL_MANUKYAN_LAGLER_TRIANGLE_H
