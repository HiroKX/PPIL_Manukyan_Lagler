//
// Created by Samvel on 01/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_FORME_H
#define PPIL_MANUKYAN_LAGLER_FORME_H

#include <string>
#include <ostream>
#include "Vecteur2D.h"

using namespace std;

class Forme {
    private:
        string nom;
        Vecteur2D vecteur;

    public:
        Forme(const string &nom, const char * s);
        const string &getNom() const;
        void setNom(const string &nom);
        const Vecteur2D &getVecteur() const;
        void setVecteur(const Vecteur2D &vecteur);
};

#endif //PPIL_MANUKYAN_LAGLER_FORME_H
