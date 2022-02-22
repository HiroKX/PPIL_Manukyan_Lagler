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
        Segment(const char *v1, const char *v2, const string &couleur);
        const Vecteur2D &getVecteur2() const;
        void setVecteur2(const Vecteur2D &vecteur2);
        string toString() const;

        void translation(const Vecteur2D& v) override;
        void rotation(const double rot, const Vecteur2D& v) override;
        void homotetie(const double k, const Vecteur2D& v) override;


        Vecteur2D getCentre() override;
};
        ostream &operator<<(ostream &os, const Segment &segment);

#endif //PPIL_MANUKYAN_LAGLER_SEGMENT_H
