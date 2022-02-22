//
// Created by Samvel on 02/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_RECTANGLE_H
#define PPIL_MANUKYAN_LAGLER_RECTANGLE_H

#include <vector>
#include "Vecteur2D.h"
#include "Forme.h"


class Polygone : public Forme{
    private:
        vector<Vecteur2D> vecteurs;

    public:
        Polygone(const char *s, const vector<Vecteur2D> &vecteurs, const string &couleur);

        void addVecteur(const Vecteur2D &vecteur);

        string toString() const;

        void translation(const Vecteur2D& v) override;
        void rotation(const double rot, const Vecteur2D& v) override;
        void homotetie(const double k, const Vecteur2D& v) override;

        Vecteur2D getCentre() override;
};

    ostream &operator<<(ostream &os, const Polygone &rectangle);

#endif //PPIL_MANUKYAN_LAGLER_RECTANGLE_H
