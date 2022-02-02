/*
//
// Created by Robin Lagler on 25/01/2022.
//

#include <iostream>
#include <sstream>
#include <string>
#include <pcap/socket.h>
#include <netinet/in.h>
#import <sys/socket.h>
#include <unistd.h>
#include "Erreur.h"

#define L 200


#ifndef PPIL_MANUKYAN_LAGLER_CLIENT_H
#define PPIL_MANUKYAN_LAGLER_CLIENT_H

struct SOCKADDR_IN {
    short sin_family;   // e.g. AF_INET
    unsigned short sin_port;     // e.g. htons(3490)
    struct in_addr sin_addr;     // see struct in_addr, below
    char sin_zero[8];  // zero this if you want to
};

class Client {

    SOCKET sock;

public:
    void lancerClient(){
        int r;

        sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        if (sock == INVALID_SOCKET) {
            ostringstream oss;
            oss << "la création du socket a échoué : code";
        }
        cout << "socket créé" << endl;
        char adresseServeur[L];
        short portServeur;

        cout << "tapez l'adresse IP du serveur de majuscule : " << endl;
        cin >> adresseServeur;
        cin.clear();
        cout << "tapez le port du serveur du serveur de majuscule : " << endl;
        cin >> portServeur;
        cin.clear();

        SOCKADDR_IN sockaddr{}; // informations concernant le serveur avec lequel on va communiquer

        sockaddr.sin_family = AF_INET;
        sockaddr.sin_addr.s_addr = inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
        sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)

        r = connect(sock, reinterpret_cast<const struct sockaddr *>(&sockaddr),
                    sizeof(sockaddr));

        // TODO : Rajouter erreur quand connect pas ok

        cout << "connexion au serveur réussie " << r << endl;

    }


   void shutClient() const {
        int r;
        r = shutdown(sock, SHUT_RDWR);                            // on coupe la connexion pour l'envoi et la réception
        // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()


       // TODO : Rajouter erreur quand deconnect pas ok


       cout << "Déconnexion au serveur réussie" << endl;

    }

    void receiveServeur(){
        char reponse[L];
        int r;
        r = recv(sock, reponse, 200,
                 0);

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
        receiveServeur();
    }
};


#endif //PPIL_MANUKYAN_LAGLER_CLIENT_H*/
