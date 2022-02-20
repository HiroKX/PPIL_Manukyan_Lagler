//
// Created by Samvel on 02/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_CERCLE_H
#define PPIL_MANUKYAN_LAGLER_CERCLE_H

#include "Vecteur2D.h"
#include "Forme.h"

class Cercle : public Forme{
    private:
        double rayon;

    public:
        Cercle(const char * vecteur, double rayon);
        double getRayon() const;
        void setRayon(double rayon);
        string toString() const;

        void translation(const Vecteur2D& v) override;
        void rotation(double rot, const Vecteur2D& v) override;
};

    ostream &operator<<(ostream &os, const Cercle &cercle);

#endif //PPIL_MANUKYAN_LAGLER_CERCLE_H
