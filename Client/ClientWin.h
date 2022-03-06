//
// Created by Samvel on 01/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_CLIENTWIN_H
#define PPIL_MANUKYAN_LAGLER_CLIENTWIN_H

#pragma comment(lib, "ws2_32.lib")

#include <winsock2.h>
#include <iostream>
#include <sstream>
#include <string>
#include "Erreur.h"
#include "Forme.h"
#include "Fenetre.h"
#include "Triangle.h"

using namespace std;

#define L 200 // longueur max d'une chaîne de caractères

class ClientWin {
private:
    SOCKET sock;
    int r;
    Fenetre f;
    vector<Forme*> formes;

public:

    void lancerClient() {
        try {
//-------------- initialisation ressources librairie winsock -------------------------------

            int r;
            WSADATA wsaData;        // structure contenant les données de la librairie winsock à initialiser

            this->r = WSAStartup(MAKEWORD(2, 0),
                                 &wsaData);       // MAKEWORD(2,0) sert à indiquer la version de la librairie à utiliser : 1 pour winsock et 2 pour winsock2

/* en cas de succès, wsaData a été initialisée et l'appel a renvoyé la valeur 0 */


            cout << "client vers le serveur de majuscule" << endl;
            cout << "initialisation effectuée" << endl;

//---------------------- création socket -------------------------------------------------

            // informations concernant le socket à créer : famille d'adresses acceptées, mode connecté ou non, protocole

            int familleAdresses = AF_INET;         // IPv4
            int typeSocket = SOCK_STREAM;           // mode connecté TCP
            int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres
            // pour les valeurs des paramètres : cf. fct socket dans la doc sur winsock

            this->sock = socket(familleAdresses, typeSocket, protocole);

            if (this->sock == INVALID_SOCKET) {
                ostringstream oss;
                oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError()
                    << endl;    // pour les valeurs renvoyées par WSAGetLastError() : cf. doc réf winsock
            }

            cout << "socket créé" << endl;

//------------------------------ création du représentant du serveur ----------------------------------------

            char adresseServeur[L];
            short portServeur = 9112;

            strcpy(adresseServeur,"192.168.56.1");

            SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

            sockaddr.sin_family = AF_INET;
            sockaddr.sin_addr.s_addr = inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
            sockaddr.sin_port = htons(
                    portServeur);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)

//-------------- connexion du client au serveur ---------------------------------------

            r = connect(sock, (SOCKADDR *) &sockaddr,
                        sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'échec.
            // Le code d'erreur peut être obtenu par un appel à WSAGetLastError()


            cout << "connexion au serveur réussie" << endl;
        } catch (Erreur e) {
            cout << e << endl;
        }
    }

    void shutClient() {
        try {
            r = shutdown(sock,
                         SD_BOTH);                            // on coupe la connexion pour l'envoi et la réception
            // Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

            if (r == SOCKET_ERROR)
                throw Erreur("la coupure de connexion a échoué");

            r = closesocket(
                    sock);                          // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
            if (r) throw Erreur("La fermeture du socket a échoué");
            cout << "connexion au serveur réussie" << endl;

        } catch (Erreur e) {

            WSACleanup();
            cout << "arrêt normal du client" << endl;
        }
    }

    void receiveServeur() {
        char reponse[L];
        r = recv(sock, reponse, 200,
                 0);

        if (r == SOCKET_ERROR)
            throw Erreur("La réception de la réponse a échoué");

        // reçoit au plus l octets
        // en cas de succès, r contient le nombre d'octets reçus
        cout << reponse << endl;
    }

    void sendServeur(string requete) {
        requete += "\r\n";
        int l = requete.length();
        send(this->sock, requete.c_str(), l, 0);

        if (r == SOCKET_ERROR)
            throw Erreur("échec de l'envoi de la requête");
    }

    void enregistrerServeur(Forme* f){
        formes.push_back(f);
    }

    void dessine(){
        double p1x = 0, p1y = 0, p2x = 0, p2y = 0;
        cout << "axvfyjyj grgrgrg: " << formes.size() << endl;
        for(Forme* forme : formes){
            p1x = min(p1x, forme->getLowestX());
            p2x = max(p2x, forme->getHighestX());
            p1y = min(p1y, forme->getLowestY());
            p2y = max(p1x, forme->getHighestY());
        }
        Vecteur2D P1(p1x, p1y) , P2(p2x, p2y), P1e(0, f.getHeight()), P2e(f.getWidth(), 0);

        TransformationAffine tf(P1, P2, P1e, P2e);
        cout << "bb : " << formes.size() << endl;
        for(Forme* forme : formes){
            cout << "1 : " << forme->toString() << endl;
            sendServeur(forme->transform(tf)->toString());
        }
        sendServeur("dessine");
    }

    void ouvreFenetre(Fenetre &fen){
        f=fen;
        sendServeur(f.toString());
    }

};


#endif //PPIL_MANUKYAN_LAGLER_CLIENTWIN_H
