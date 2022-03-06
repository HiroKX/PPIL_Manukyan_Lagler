//
// Created by Samvel on 01/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_FORME_H
#define PPIL_MANUKYAN_LAGLER_FORME_H

#include <string>
#include <ostream>
#include <vector>
#include "h/Formes/Vecteur2D.h"
#include "h/Client/TransformationAffine.h"

class VisiteurAbstrait;
#include <string>
using namespace std;

class Forme {
    protected:
        Vecteur2D vecteur;
        string couleur;

    public:
        /**
         * Constructeur de Forme
         * @param couleur Couleur de la Forme
         */
        Forme(const string &couleur) : couleur(couleur) {}

        /**
         * Constructeur de Forme
         * @param s Le 1er Vecteur2D de la Forme en format char*
         * @param couleur Couleur de la Forme
         */
        Forme(const char * s, const string &couleur) : vecteur(s), couleur(couleur) {}

        /**
         * Constructeur de Forme
         * @param v1 Le 1er Vecteur2D de la Forme en format Vecteur2D
         * @param couleur Couleur de la Forme
         */
        Forme(const Vecteur2D &v1, const string &couleur) : vecteur(v1), couleur(couleur) {}

        /**
         * Destructeur par defaut
         */
        virtual ~Forme() = default;

        /**
         *
         * @return Renvoie le 1er Vecteur2D de la Forme
         */
        const Vecteur2D getVecteur() const;

        /**
         * Modifie la valeur du 1er Vecteur2D de la Forme
         * @param vecteur
         */
        void setVecteur(const Vecteur2D &vecteur);

        /**
         *
         * @return Retrourn la Couleur de la Forme
         */
        const string &getCouleur() const;

        /**
         * Modife la valeur de la couleur
         * @param couleur
         */
        void setCouleur(const string &couleur);

        /**
         *
         * @return Renvoie un clone de la Forme
         */
        virtual Forme * clone() = 0;

        /**
         * Permet de faire une translation de la Forme suivant:
         * @param v Vecteur2D qui permet de faire la translation
         */
        virtual void translation(const Vecteur2D& v) = 0;

        /**
         * Permet de faire une rotation de la Forme suivant:
         * @param rot Le degré de la rotation
         * @param v
         */
        virtual void rotation(const double rot, const Vecteur2D& v) = 0;

        /**
         * Permet de faire une homotetie de la Forme suivant:
         * @param k Le rapport de l'homotetie
         * @param v
         */
        virtual void homotetie(const double k, const Vecteur2D& v) = 0;

        /**
         *
         * @return Renvoie le centre de la Forme
         */
        virtual Vecteur2D getCentre() = 0;

        /**
         *
         * @return Retourne l'aire de la Forme
         */
        virtual double aire() = 0;

        virtual void draw(VisiteurAbstrait *vis) const = 0;
        virtual Forme* transform(const TransformationAffine& tf)const = 0;
        /**
         *
         * @return Retroune le plus grand X
         */
        virtual double getHighestX() const = 0;
        /**
         *
         * @return Retourne le plus grand Y
         */
        virtual double getHighestY() const = 0;
        /**
         *
         * @return Retourne le plus petit X
         */
        virtual double getLowestX() const = 0;
        /**
         *
         * @return Retourne le plus petit Y
         */
        virtual double getLowestY() const = 0;

        /**
         *
         * @return Retourne la Forme au fromat String
         */
        virtual string toString() const = 0;
};

#endif //PPIL_MANUKYAN_LAGLER_FORME_H
