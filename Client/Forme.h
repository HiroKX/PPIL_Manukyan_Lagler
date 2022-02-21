//
// Created by Samvel on 01/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_FORME_H
#define PPIL_MANUKYAN_LAGLER_FORME_H

#include <string>
#include <ostream>
#include "Vecteur2D.h"

using namespace std;

class Forme {
    private:
        Vecteur2D vecteur;

    public:
        Forme();
        Forme(const char * s);
        const Vecteur2D &getVecteur() const;
        void setVecteur(const Vecteur2D &vecteur);

        virtual void translation(const Vecteur2D& v) = 0;
        virtual void rotation(const double rot, const Vecteur2D& v) = 0;
        virtual void homotetie(const double k, const Vecteur2D& v) = 0;

        virtual Vecteur2D getCentre() = 0;
};

#endif //PPIL_MANUKYAN_LAGLER_FORME_H
