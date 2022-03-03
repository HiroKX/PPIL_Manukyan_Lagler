//
// Created by Samvel on 20/02/2022.
//

#ifndef CLIENT_GROUPEFORME_H
#define CLIENT_GROUPEFORME_H

#include <vector>
#include "Forme.h"

class GroupeForme: public Forme {
    private:
        vector<Forme*> groupe;

    public:
        GroupeForme(const char* couleur);
        const vector<struct Forme *> & getGroupe() const;
        void addForme(Forme* f);

        void translation(const Vecteur2D& v) override;
        void rotation(double rot, const Vecteur2D& v) override;
        void homotetie(const double k, const Vecteur2D& v) override;
        Vecteur2D getCentre() override;
        double getHighestX() const override;
        double getHighestY() const override;
        double getLowestX() const override;
        double getLowestY() const override;

        Forme* transform(const TransformationAffine& tf) const override;

        string toString() const override ;

        void draw(VisiteurAbstrait *vis)const  override;
        void setGroupe(const vector<Forme*> &groupe);

};

#endif //CLIENT_GROUPEFORME_H