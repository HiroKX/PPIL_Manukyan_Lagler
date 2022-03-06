//
// Created by Samvel on 01/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_FORME_H
#define PPIL_MANUKYAN_LAGLER_FORME_H

#include <string>
#include <ostream>
#include <vector>
#include "Vecteur2D.h"
#include "TransformationAffine.h"

class VisiteurAbstrait;
#include <string>
using namespace std;

class Forme {
    protected:
        Vecteur2D vecteur;
        string couleur;

    public:
        Forme(const string &couleur) : couleur(couleur) {}
        Forme(const char * s, const string &couleur) : vecteur(s), couleur(couleur) {}
        Forme(const Vecteur2D &v1, const string &couleur) : vecteur(v1), couleur(couleur) {}

        const Vecteur2D getVecteur() const;
        void setVecteur(const Vecteur2D &vecteur);
        const string &getCouleur() const;
        void setCouleur(const string &couleur);

        virtual void translation(const Vecteur2D& v) = 0;
        virtual void rotation(const double rot, const Vecteur2D& v) = 0;
        virtual void homotetie(const double k, const Vecteur2D& v) = 0;
        virtual Vecteur2D getCentre() = 0;

        virtual double air() = 0;

        virtual void draw(VisiteurAbstrait *vis) const = 0;
        virtual Forme* transform(const TransformationAffine& tf)const = 0;
        virtual double getHighestX() const = 0;
        virtual double getHighestY() const = 0;
        virtual double getLowestX() const = 0;
        virtual double getLowestY() const = 0;

        virtual string toString() const = 0;
};

#endif //PPIL_MANUKYAN_LAGLER_FORME_H
