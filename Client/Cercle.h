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
        Cercle(const char *s, double rayon, const string &couleur);
        double getRayon() const;
        void setRayon(double rayon);
        string toString() const;

        void translation(const Vecteur2D& v) override;
        void rotation(const double rot, const Vecteur2D& v) override;
        void homotetie(const double k, const Vecteur2D& v) override;


    Vecteur2D getCentre() override;
};

    ostream &operator<<(ostream &os, const Cercle &cercle);

#endif //PPIL_MANUKYAN_LAGLER_CERCLE_H
