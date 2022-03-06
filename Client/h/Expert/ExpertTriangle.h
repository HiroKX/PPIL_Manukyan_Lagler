//
// Created by Samvel on 18/02/2022.
//

#ifndef CLIENT_EXPERTTRIANGLE_H
#define CLIENT_EXPERTTRIANGLE_H

#include "ExpertForme.h"

class ExpertTriangle : public ExpertForme{
    public:
    ExpertTriangle(ExpertForme *suivant);

    Forme * retrouverForme(string s) override;
};

#endif //CLIENT_EXPERTTRIANGLE_H