//
// Created by Samvel on 01/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_CLIENTWIN_H
#define PPIL_MANUKYAN_LAGLER_CLIENTWIN_H

#include <winsock2.h>
#include <iostream>
#include <sstream>
#include <string>
//#include <string.h>
#include "Erreur.h"

using namespace std;

#define L 200 // longueur max d'une chaîne de caractères

class ClientWin {
    private:
        SOCKET sock;
        int r;

    public:
        void lancerClient(){
            WSADATA wsaData;
            r = WSAStartup( MAKEWORD(2,0), &wsaData);       // MAKEWORD(2,0) sert à indiquer la version de la librairie à utiliser : 1 pour winsock et 2 pour winsock2

            if (r) throw Erreur("L'initialisation a échoué");

            int familleAdresses = AF_INET;         // IPv4
            int typeSocket = SOCK_STREAM;           // mode connecté TCP
            int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres
            // pour les valeurs des paramètres : cf. fct socket dans la doc sur winsock

            sock =  socket( familleAdresses, typeSocket, protocole);

            if (sock == INVALID_SOCKET)
            {
                ostringstream oss;
                oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoyées par WSAGetLastError() : cf. doc réf winsock
                throw Erreur(oss.str().c_str());
            }

            cout << "socket créé" << endl;

            char adresseServeur[L];
            short portServeur;

            cout <<"tapez l'adresse IP du serveur de majuscule : " << endl;
            cin >> adresseServeur;
            cout <<"tapez le port du serveur du serveur de majuscule : " << endl;
            cin >> portServeur;

            SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

            sockaddr.sin_family = AF_INET;
            sockaddr.sin_addr.s_addr = inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
            sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)
        }

        void shutClient() {
            r = shutdown(sock,SD_BOTH);							// on coupe la connexion pour l'envoi et la réception
            // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

            if (r == SOCKET_ERROR)
                throw Erreur("la coupure de connexion a échoué");

            r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
            if (r) throw Erreur("La fermeture du socket a échoué");

            WSACleanup();
            cout << "arrêt normal du client" << endl;
        }

        void receiveServeur(){
            char reponse[L];
            r = recv(sock, reponse, 200,
                     0);

            if (r == SOCKET_ERROR)
                throw Erreur("La réception de la réponse a échoué");

            // reçoit au plus l octets
            // en cas de succès, r contient le nombre d'octets reçus
            cout << reponse << endl;
            sendServeur();

        }

        void sendServeur(){
            string requete;
            cout << "Texte à envoyer : ";
            cin >> requete;
            requete += "\r\n";
            int l = requete.length();
            send(sock, requete.c_str(), l, 0);

            if (r == SOCKET_ERROR)
                throw Erreur("échec de l'envoi de la requête");

            receiveServeur();
        }

};


#endif //PPIL_MANUKYAN_LAGLER_CLIENTWIN_H
