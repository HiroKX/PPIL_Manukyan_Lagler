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
        Triangle(const char *v1, const char *v2, const char *v3, const string &couleur);
        Triangle(const Vecteur2D &v1, const Vecteur2D &v2, const Vecteur2D &v3, const string &couleur):Forme(v1,couleur) {
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

        Vecteur2D getCentre() override;
};

    ostream &operator<<(ostream &os, const Triangle &triangle);

#endif //PPIL_MANUKYAN_LAGLER_TRIANGLE_H
