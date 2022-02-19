//
// Created by Samvel on 19/02/2022.
//

#ifndef CLIENT_MATRICE_H
#define CLIENT_MATRICE_H


class Matrice {
private:
    int lig;
    int col;
    double *vals;

public:
    Matrice(int lig, int col);
    virtual ~Matrice();
};


#endif //CLIENT_MATRICE_H
