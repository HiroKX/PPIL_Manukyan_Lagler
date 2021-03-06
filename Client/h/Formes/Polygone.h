//
// Created by Samvel on 02/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_RECTANGLE_H
#define PPIL_MANUKYAN_LAGLER_RECTANGLE_H

#include <vector>
#include "Vecteur2D.h"
#include "Forme.h"

class Polygone : public Forme{
    private:
        vector<Vecteur2D> vecteurs;

    public:
        /**
         * Constructor
         * @param vec vector<Vecteur2D> : Liste des Vecteur2D du Polygone
         * @param couleur String: Couleur du Polygone
         */
        Polygone(vector<Vecteur2D> &vec, const string &couleur) : Forme(couleur) {
            setVecteur(vec.at(0));
            vecteurs = vec;
        }

        /**
         * Constructor par copy
         * @param p Polygone
         */
        Polygone(Polygone &p) : Forme(p.getCouleur()), vecteurs(p.vecteurs){
            setVecteur(p.getVecteur());
        }

        void addVecteur(const Vecteur2D &vecteur);

        void translation(const Vecteur2D& v) override;
        void rotation(const double rot, const Vecteur2D& v) override;
        void homotetie(const double k, const Vecteur2D& v) override;
        Vecteur2D getCentre() override;

        Polygone * clone() override;

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

    inline ostream &operator<<(ostream &os, const Polygone &polygone) {
        return os << (string)polygone;
    }

#endif //PPIL_MANUKYAN_LAGLER_RECTANGLE_H
