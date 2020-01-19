//
// Created by Tina Alaei on 14/01/2020.
//

#ifndef BIBLIOTHEQUE_ADHERENT_H
#define BIBLIOTHEQUE_ADHERENT_H

#include "Livre.h"
#include "Bibliotheque.h"

class Adherent {
private:
    string nom;
    string prenom;
    int numAdherent;
    Bibliotheque* inscritA;
    vector<Livre*> emprunts;
    int limEmprunts;

public:
    Adherent(string, string, int, Bibliotheque*, int);
    void affiche();
    void emprunt(Bibliotheque*, int);
    void rendre(Bibliotheque*, int);
    bool isAdherentBibliotheque(Bibliotheque* bibliotheque);



};


#endif //BIBLIOTHEQUE_ADHERENT_H
