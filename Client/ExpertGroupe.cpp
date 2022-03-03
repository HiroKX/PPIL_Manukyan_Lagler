//
// Created by rlagl on 02/03/2022.
//

#include "ExpertGroupe.h"
#include "GroupeForme.h"
#include "ExpertCercle.h"
#include "ExpertPolygone.h"
#include "ExpertTriangle.h"
#include "ExpertSegment.h"

ExpertGroupe::ExpertGroupe(ExpertForme *suivant) : ExpertForme(suivant) {}

Forme *ExpertGroupe::retrouverForme(string s) {
    vector<string> c = split(s, '-');
    string ss = join(c, ' ');
    cout << ss << endl;
    cout << "----------------------------" << endl;
    if(c.at(0) == "Groupe" && c.at(1) == "["){
        c.erase( c.begin(), c.begin() + 2);
        string s = join(c, '-');

        //cout << "mdrrrr : " << s <<endl;

        vector<string> c = split(s, '/');
        ExpertForme* expCercle, * expPolygon, * expTriangle, * expSegment, * expGroupe;
        expCercle = new ExpertCercle(nullptr);
        expPolygon = new ExpertPolygone(expCercle);
        expTriangle = new ExpertTriangle(expPolygon);
        expSegment = new ExpertSegment(expTriangle);
        expGroupe = new ExpertGroupe(expSegment);

        GroupeForme* gf = new GroupeForme(c.at(c.size() - 1).c_str());
        for(int i = 0; i <= c.size() - 2; i++){
            cout << c.at(i) << endl;
            Forme * f = expGroupe->resoudre(c.at(i));
            f->setCouleur(gf->getCouleur());
            gf->addForme(f);
        }
        return gf;
    }
    return nullptr;
}
