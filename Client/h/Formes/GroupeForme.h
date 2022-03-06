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
        GroupeForme(const char *couleur) : Forme(couleur) {}
        GroupeForme(GroupeForme &g) : Forme(g.getCouleur()), groupe(g.groupe) {}
        virtual ~GroupeForme(){
            for(Forme * f: groupe){
                delete f;
            }
        }

        const vector<struct Forme *> & getGroupe() const;
        void setGroupe(const vector<Forme*> &groupe);

        void addForme(Forme* f);

        void translation(const Vecteur2D& v) override;
        void rotation(double rot, const Vecteur2D& v) override;
        void homotetie(const double k, const Vecteur2D& v) override;
        Vecteur2D getCentre() override;

        GroupeForme * clone() override;

        double aire() override;

        void draw(VisiteurAbstrait *vis)const  override;
        Forme* transform(const TransformationAffine& tf) const override;
        double getHighestX() const override;
        double getHighestY() const override;
        double getLowestX() const override;
        double getLowestY() const override;

        string toString() const override ;

        operator string() const{
            return toString();
        }
};

    inline ostream &operator<<(ostream &os, const GroupeForme &groupeForme) {
        return os << (string)groupeForme;
    }

#endif //CLIENT_GROUPEFORME_H