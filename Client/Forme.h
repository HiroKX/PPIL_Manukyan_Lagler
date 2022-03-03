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
using namespace std;

class Forme {
protected:
    Vecteur2D vecteur;
    const char *couleur;
public:

        Forme(const char *couleur);
        Forme(const char * s, const char *couleur);
        Forme(const Vecteur2D  &v1, const char *couleur);
        const Vecteur2D getVecteur() const;
        void setVecteur(const Vecteur2D &vecteur);
        char * getCouleur() const;
        void setCouleur(char *couleur);

        virtual void translation(const Vecteur2D& v) = 0;
        virtual void rotation(const double rot, const Vecteur2D& v) = 0;
        virtual void homotetie(const double k, const Vecteur2D& v) = 0;
        virtual void draw(VisiteurAbstrait *vis) const = 0;
        virtual Forme* transform(const TransformationAffine& tf)const = 0;
        virtual string toString() const =0;

    virtual Vecteur2D getCentre() = 0;

};

#endif //PPIL_MANUKYAN_LAGLER_FORME_H
