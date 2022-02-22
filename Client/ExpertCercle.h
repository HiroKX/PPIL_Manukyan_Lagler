//
// Created by Samvel on 17/02/2022.
//

#ifndef CLIENT_EXPERTCERCLE_H
#define CLIENT_EXPERTCERCLE_H

#include "ExpertForme.h"

class ExpertCercle : public ExpertForme{
    public:
        Forme * retrouverForme(string s) override;
};

#endif //CLIENT_EXPERTCERCLE_H