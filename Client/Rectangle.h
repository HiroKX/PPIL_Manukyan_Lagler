//
// Created by Samvel on 02/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_RECTANGLE_H
#define PPIL_MANUKYAN_LAGLER_RECTANGLE_H

#include "Vecteur2D.h"
#include "Forme.h"


class Rectangle : public Forme{
    private:
        double hauteur;
        double largeur;

    public:

        Rectangle(const char *s, double hauteur, double largeur);
        double getHauteur() const;
        void setHauteur(double hauteur);
        double getLargeur() const;
        void setLargeur(double largeur);
        string toString() const;

        void translation(const Vecteur2D& v) override;
        void rotation(double rot, const Vecteur2D& v) override;
};

    ostream &operator<<(ostream &os, const Rectangle &rectangle);

#endif //PPIL_MANUKYAN_LAGLER_RECTANGLE_H
