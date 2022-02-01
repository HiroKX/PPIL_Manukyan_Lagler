//
// Created by Samvel on 01/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_POINT2D_H
#define PPIL_MANUKYAN_LAGLER_POINT2D_H

#include <string>
#include <ostream>

using namespace std;

class Point2D {
    private:
        int x;
        int y;

    public:
        Point2D();
        Point2D(const int & x, const int & y);
        int getX() const;
        void setX(int x);
        int getY() const;
        void setY(int y);
        string toString() const;
        friend std::ostream &operator<<(std::ostream &os, const Point2D &d);
};


#endif //PPIL_MANUKYAN_LAGLER_POINT2D_H
