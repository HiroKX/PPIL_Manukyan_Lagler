//
// Created by Samvel on 02/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_CERCLE_H
#define PPIL_MANUKYAN_LAGLER_CERCLE_H

#include "Forme.h"

class Cercle : public Forme{
    private:
        Point2D point;
        double rayon;

    public:
        Cercle(const string &nom, const Point2D &point, double rayon);
        double getRayon() const;
        void setRayon(double rayon);
        string toString() const;
};

    ostream &operator<<(ostream &os, const Cercle &cercle);

#endif //PPIL_MANUKYAN_LAGLER_CERCLE_H
