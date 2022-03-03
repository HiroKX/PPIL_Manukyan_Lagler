//
// Created by Samvel on 01/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_FORME_H
#define PPIL_MANUKYAN_LAGLER_FORME_H

#include <string>
#include <ostream>
#include <vector>
#include "Vecteur2D.h"

class VisiteurAbstrait;
using namespace std;

class Forme {
    private:
        Vecteur2D vecteur;
        string couleur;
    public:

        Forme(const string &couleur);
        Forme(const char * s, const string & couleur);
        Forme(const Vecteur2D  &v1, const string & couleur);
        const Vecteur2D &getVecteur() const;
        void setVecteur(const Vecteur2D &vecteur);
        const string &getCouleur() const;
        void setCouleur(const string &couleur);

        virtual void translation(const Vecteur2D& v) = 0;
        virtual void rotation(const double rot, const Vecteur2D& v) = 0;
        virtual void homotetie(const double k, const Vecteur2D& v) = 0;
        virtual void draw(VisiteurAbstrait *vis) const = 0;
        virtual string toString() const =0;

    virtual Vecteur2D getCentre() = 0;

};

#endif //PPIL_MANUKYAN_LAGLER_FORME_H
