//
// Created by Samvel on 20/02/2022.
//

#ifndef CLIENT_GROUPEFORME_H
#define CLIENT_GROUPEFORME_H

#include <vector>
#include "Forme.h"

class GroupeForme : public Forme{
    private:
        vector<Forme> groupe;

    public:
        GroupeForme();
        void addForme(Forme f);
};


#endif //CLIENT_GROUPEFORME_H
