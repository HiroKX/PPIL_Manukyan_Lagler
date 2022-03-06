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
        Triangle(const char *v1, const char *v2, const char *v3, const string &couleur = "") : Forme(v1, couleur), vecteur2(v2), vecteur3(v3) {}
        Triangle(const Vecteur2D &v1, const Vecteur2D &v2, const Vecteur2D &v3, const string &couleur = ""): Forme(v1, couleur), vecteur2(v2), vecteur3(v3) {}
        Triangle(Triangle &t) : Forme(t.getVecteur(), t.getCouleur()), vecteur2(t.getVecteur2()), vecteur3(t.getVecteur3()) {}

        const Vecteur2D &getVecteur2() const;//Pourquoi le & sur le resultat?
        void setVecteur2(const Vecteur2D &vecteur2);
        const Vecteur2D &getVecteur3() const;
        void setVecteur3(const Vecteur2D &vecteur3);

        void translation(const Vecteur2D& v) override;
        void rotation(const double rot, const Vecteur2D& v) override;
        void homotetie(const double k, const Vecteur2D& v) override;
        Vecteur2D getCentre() override;

        Triangle * clone() override;

        double air() override;

        void draw(VisiteurAbstrait *vis) const override;
        Forme* transform(const TransformationAffine& tf) const override;
        double getHighestX() const override;
        double getHighestY() const override;
        double getLowestX() const override;
        double getLowestY() const override;

        string toString() const;

        operator string() const{//Munir toute classe de cet operateur
            return toString();
        }
};

    inline ostream &operator<<(ostream &os, const Triangle &triangle) {//Munir toute classe de cet operateur
        return os << (string)triangle;
    }

#endif //PPIL_MANUKYAN_LAGLER_TRIANGLE_H