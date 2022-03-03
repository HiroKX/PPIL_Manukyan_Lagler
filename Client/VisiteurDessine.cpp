//
// Created by rlagl on 01/03/2022.
//
#include "VisiteurDessine.h"
#include "ExpertGroupe.h"
#include "ExpertSegment.h"
#include "ExpertPolygone.h"
#include "ExpertCercle.h"
#include "ExpertTriangle.h"

class Forme;
void VisiteurDessine::visit(const Cercle *ce) {
    c->enregistrerServeur((Forme *) ce);
}

void VisiteurDessine::visit(const Polygone *p) {
    c->enregistrerServeur((Forme *) p);
}

void VisiteurDessine::visit(const Triangle *t){
    c->enregistrerServeur((Forme *) t);
}

void VisiteurDessine::visit(const GroupeForme *g) {
    for(auto &Forme: g->getGroupe()){
        Forme->setCouleur(g->getCouleur());
        Forme->draw(this);
    }
}

void VisiteurDessine::sauvegarder(Forme *f) {
    lFormes.push_back(f);
}

void VisiteurDessine::visit(const Segment *s) {
    c->enregistrerServeur((Forme *) s);
}

VisiteurDessine::VisiteurDessine(ClientWin *c) : c(c) {}

vector<Forme *> VisiteurDessine::charger(string fileName) {
    vector<Forme *> vf;
    cout << fileName << endl;
    ifstream fichier(fileName.c_str(), ios::in);
    ExpertForme* expCercle, * expPolygon, * expTriangle, * expSegment, * expGroupe;
    expCercle = new ExpertCercle(nullptr);
    expPolygon = new ExpertPolygone(expCercle);
    expTriangle = new ExpertTriangle(expPolygon);
    expSegment = new ExpertSegment(expTriangle);
    expGroupe = new ExpertGroupe(expSegment);
    if(fichier){
        string ligne;
        while(getline(fichier, ligne))
        {
            Forme* f = expGroupe->resoudre(ligne);
            lFormes.push_back(f);
        }
        fichier.close();
    }
    else
        cerr << "Erreur a l'ouverture !" << endl;
    return lFormes;
}

void VisiteurDessine::enregistrer(const string& fileName) const {
    ofstream file(fileName);
    for(auto *forme : lFormes){
        file << forme->toString() << endl;
    }
    file.close();
}



