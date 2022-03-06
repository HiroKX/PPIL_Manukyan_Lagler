//
// Created by rlagl on 02/03/2022.
//

#include "h/Expert/ExpertGroupe.h"
#include "h/Formes/GroupeForme.h"
#include "h/Expert/ExpertCercle.h"
#include "h/Expert/ExpertPolygone.h"
#include "h/Expert/ExpertTriangle.h"
#include "h/Expert/ExpertSegment.h"

ExpertGroupe::ExpertGroupe(ExpertForme *suivant) : ExpertForme(suivant) {}

Forme *ExpertGroupe::retrouverForme(string s) {
    vector<string> c;
    int a = 0, b = 0;
    a = s.find_first_of('[');
    b = s.find_last_of(']');

    if(s.substr (0,a) == "Groupe"){
        string grp = s.substr (a + 1,b - a - 1);
        vector<string> c = split(grp, '/');
        bool nouvGrp = false;
        string str;
        vector<string> nc;
        int nbCroch = 0;

        for (int i = 0; i < c.size() - 1; i++) {
            if(nouvGrp){
                str += "/" + c.at(i);
                if(c.at(i).find(']') != string::npos){
                    nbCroch--;
                    if(nbCroch == 0) {
                        nouvGrp = false;
                        nc.push_back(str);
                    }
                }
            }
            else{
                if(c.at(i).find('[') != string::npos){
                    nbCroch++;
                    nouvGrp = true;
                    str = c.at(i);
                }
                else{
                    nc.push_back(c.at(i));
                }
            }
        }

        ExpertForme* expCercle, * expPolygon, * expTriangle, * expSegment, * expGroupe;
        expCercle = new ExpertCercle(nullptr);
        expPolygon = new ExpertPolygone(expCercle);
        expTriangle = new ExpertTriangle(expPolygon);
        expSegment = new ExpertSegment(expTriangle);
        expGroupe = new ExpertGroupe(expSegment);

        GroupeForme* gf = new GroupeForme(c.at(c.size() - 1).c_str());
        for(int i = 0; i <= nc.size() - 1; i++){
            Forme * f = expGroupe->resoudre(nc.at(i));
            f->setCouleur(gf->getCouleur());
            gf->addForme(f);
        }
        return gf;
    }
    return nullptr;
}
