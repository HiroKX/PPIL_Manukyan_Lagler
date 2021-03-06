//
// Created by Samvel on 02/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_CERCLE_H
#define PPIL_MANUKYAN_LAGLER_CERCLE_H

#include "Vecteur2D.h"
#include "Forme.h"

class Cercle : public Forme{
    private:
        double rayon;

    public:
    /**
     * Constructor
     * @param s String: Centre du Cercle
     * @param rayon double: Rayon du Cercle
     * @param couleur String: Couleur du Cercle
     */
        Cercle(const char *s, double rayon, const string &couleur) : Forme(s, couleur) {
            setRayon(rayon);
        }

        /**
         * Constructor
         * @param s Vecteur2D: Centre du Cercle
         * @param rayon double: Rayon du Cercle
         * @param couleur String: Couleur du Cercle
         */
        Cercle(const Vecteur2D &s, double rayon, const string &couleur) : Forme(s, couleur) {
            setRayon(rayon);
        }

        /**
         * Constructor par Copy
         * @param c Cercle
         */
        Cercle(Cercle &c) : Forme(c.getVecteur(), c.getCouleur()), rayon(c.rayon){}

        double getRayon() const;
        void setRayon(double rayon);

        void translation(const Vecteur2D& v) override ;
        void rotation(const double rot, const Vecteur2D& v) override;
        void homotetie(const double k, const Vecteur2D& v) override;
        Vecteur2D getCentre() override;

        Cercle * clone() override;

        double aire() override;

        void draw(VisiteurAbstrait *vis) const override;
        Forme* transform(const TransformationAffine& tf) const override;
        double getHighestX() const override;
        double getHighestY() const override;
        double getLowestX() const override;
        double getLowestY() const override;

        string toString() const override;

        operator string() const{
            return toString();
        }
};

    inline ostream &operator<<(ostream &os, const Cercle &cercle) {
        return os << (string)cercle;
    }

#endif //PPIL_MANUKYAN_LAGLER_CERCLE_H