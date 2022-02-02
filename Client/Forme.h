//
// Created by Samvel on 01/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_FORME_H
#define PPIL_MANUKYAN_LAGLER_FORME_H

#include <string>
#include <ostream>
#include "Point2D.h"

using namespace std;

class Forme {
    private:
        string nom;
        Point2D point;

    public:
        Forme(const string &nom, const Point2D &point);
        const string &getNom() const;
        void setNom(const string &nom);
        const Point2D &getPoint() const;
        void setPoint(const Point2D &point);
};


#endif //PPIL_MANUKYAN_LAGLER_FORME_H
