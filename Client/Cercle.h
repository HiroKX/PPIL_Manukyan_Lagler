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
        Cercle(const char *s, double rayon, const char *couleur);
        Cercle(const Vecteur2D &s, double rayon, const char *couleur);
        double getRayon() const;
        void setRayon(double rayon);
        string toString() const override;

        void translation(const Vecteur2D& v) override ;
        void rotation(const double rot, const Vecteur2D& v) override;
        void homotetie(const double k, const Vecteur2D& v) override;
        void draw(VisiteurAbstrait *vis) const override;
        Forme* transform(const TransformationAffine& tf) const override;

        Vecteur2D getCentre() override;
};

    ostream &operator<<(ostream &os, const Cercle &cercle);

#endif //PPIL_MANUKYAN_LAGLER_CERCLE_H
