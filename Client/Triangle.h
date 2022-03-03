//
// Created by Samvel on 02/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_TRIANGLE_H
#define PPIL_MANUKYAN_LAGLER_TRIANGLE_H

#include "Vecteur2D.h"
#include "Forme.h"

class Triangle : public Forme {
    private:
        Vecteur2D vecteur2;
        Vecteur2D vecteur3;

    public:
    //TODO : rajouter un constructeur avec vecteur
        Triangle(const char *v1, const char *v2, const char *v3, const char *couleur);
        Triangle(const Vecteur2D &v1, const Vecteur2D &v2, const Vecteur2D &v3, const char *couleur): Forme(v1, couleur) {
            vecteur2 = v2;
            vecteur3 = v3;
        }

    const Vecteur2D &getVecteur2() const;
        void setVecteur2(const Vecteur2D &vecteur2);
        const Vecteur2D &getVecteur3() const;
        void setVecteur3(const Vecteur2D &vecteur3);
        string toString() const;

        void translation(const Vecteur2D& v) override;
        void rotation(const double rot, const Vecteur2D& v) override;
        void homotetie(const double k, const Vecteur2D& v) override;
        Forme* transform(const TransformationAffine& tf) const override;
        double getHighestX() const override;
        double getHighestY() const override;
        double getLowestX() const override;
        double getLowestY() const override;
        void draw(VisiteurAbstrait *vis) const override;
        Vecteur2D getCentre() override;
};

    ostream &operator<<(ostream &os, const Triangle &triangle);

#endif //PPIL_MANUKYAN_LAGLER_TRIANGLE_H
