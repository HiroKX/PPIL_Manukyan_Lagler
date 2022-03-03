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
        Polygone(const char *s,vector<Vecteur2D> &vecteurs, const char *couleur);
        Polygone(const Vecteur2D &v,vector<Vecteur2D> &vecteurs, const char *couleur);
        void addVecteur(const Vecteur2D &vecteur);

        string toString() const override;

        void translation(const Vecteur2D& v) override;
        void rotation(const double rot, const Vecteur2D& v) override;
        void homotetie(const double k, const Vecteur2D& v) override;
        void draw(VisiteurAbstrait *vis) const override;
        Forme* transform(const TransformationAffine& tf) const override;
        double getHighestX() const override;
        double getHighestY() const override;
        double getLowestX() const override;
        double getLowestY() const override;

        Vecteur2D getCentre() override;
};

    ostream &operator<<(ostream &os, const Polygone &rectangle);

#endif //PPIL_MANUKYAN_LAGLER_RECTANGLE_H
