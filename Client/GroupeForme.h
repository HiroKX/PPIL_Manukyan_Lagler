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

    const vector<struct Forme *> & getGroupe() const;
    void translation(const Vecteur2D& v) override;
    void rotation(double rot, const Vecteur2D& v) override;
    void homotetie(const double k, const Vecteur2D& v) override;
    Vecteur2D getCentre() override;
    double getHighestX() const override;
    double getHighestY() const override;
    double getLowestX() const override;
    double getLowestY() const override;

    Forme* transform(const TransformationAffine& tf) const override {
        return nullptr;
    }

    void addForme(Forme* f){
        groupe.push_back(f);
    }


    string toString() const override {
        string s = "Groupe;"+string(getCouleur())+";";
        s+= std::to_string(groupe.size());
        for(auto* a : groupe){
            s+=";"+a->toString();
        }
        return s;
    }

    void draw(VisiteurAbstrait *vis)const  override;
    void setGroupe(const vector<Forme*> &gro);

    GroupeForme(const char *couleur);
};

#endif //CLIENT_GROUPEFORME_H