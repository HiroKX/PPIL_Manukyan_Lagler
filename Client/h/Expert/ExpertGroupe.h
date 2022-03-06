//
// Created by rlagl on 02/03/2022.
//

#ifndef CLIENT_EXPERTGROUPE_H
#define CLIENT_EXPERTGROUPE_H


#include "ExpertForme.h"

class ExpertGroupe: public ExpertForme {
    public:
    ExpertGroupe(ExpertForme *suivant);

    Forme * retrouverForme(string s) override;
};


#endif //CLIENT_EXPERTGROUPE_H
