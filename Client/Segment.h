//
// Created by Samvel on 02/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_SEGMENT_H
#define PPIL_MANUKYAN_LAGLER_SEGMENT_H

#include "Vecteur2D.h"
#include "Forme.h"

class Segment : public Forme{
private:
    Vecteur2D vecteur2;

public:
    Segment(const string &nom, const char * vecteur, const char * vecteur2);

    const Vecteur2D &getVecteur2() const;

    void setVecteur2(const Vecteur2D &vecteur2);
    string toString() const;

};
    ostream &operator<<(ostream &os, const Segment &segment);

#endif //PPIL_MANUKYAN_LAGLER_SEGMENT_H
