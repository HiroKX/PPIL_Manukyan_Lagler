//
// Created by Samvel on 17/02/2022.
//

#ifndef CLIENT_EXPERTFORME_H
#define CLIENT_EXPERTFORME_H

#include <vector>
#include "Expert.h"

class ExpertForme : public Expert{
private:
    ExpertForme *suivant;

public:
    ExpertForme(ExpertForme *suivant);
    ExpertForme *getSuivant() const;
    Forme *resoudre(string s) override;

    virtual Forme * retrouverForme(string s) = 0;

    vector<string> split(string s, char delimiteur);
};


#endif //CLIENT_EXPERTFORME_H
