
#include "Bibliotheque.h"

int Bibliotheque::codeNext = 1;

Bibliotheque::Bibliotheque(string n, string a){
    nom = n;
    adresse = a;
    code = codeNext;
    codeNext++;
    limEmprunts = 3;
}

Bibliotheque::Bibliotheque(string n, string a, int lim){
    nom = n;
    adresse = a;
    code = codeNext;
    codeNext++;
    limEmprunts = lim;
}

string Bibliotheque::getNom() const{
    return nom;
}

int Bibliotheque::getCode() const {
    return code;
}

int Bibliotheque::getLimEmprunts() const{
    return limEmprunts;
}

void Bibliotheque::ajouterLivre(Livre* livre) {
    listeLivres.push_back(livre);
    livre->setTaken();
}

void Bibliotheque::affiche() {
    cout << "---- Bibliotheque " << this->nom << " - code " << this->code << endl;
    cout << this->adresse << endl;
}

void Bibliotheque::afficheLivres() {
    cout << "---- Bibliotheque " << this->nom << " : ----" << endl;
    for(int i = 0; i < listeLivres.size(); i++){
        listeLivres[i]->affiche();
    }
    for (int i = 0; i < emprunts.size(); i++){
        emprunts[i]->affiche();
    }
}

void Bibliotheque::afficheLivreParCategorie(int categorie) {
    cout << "---- Bibliotheque " << this->nom << " - Livres de la catégorie " << typeName(categorie) << " ----" << endl;
    for(int i = 0; i < listeLivres.size(); i++){
        if(listeLivres[i]->getType() == categorie){
            listeLivres[i]->affiche();
        }
    }
    for(int i = 0; i < emprunts.size(); i++){
        if(emprunts[i]->getType() == categorie){
            emprunts[i]->affiche();
        }
    }
}

bool Bibliotheque::possedeLivreListe(int codeLivre) {
    for (auto i = 0; i < listeLivres.size(); i++) {
        if (listeLivres[i]->getCode() == codeLivre){
            return true;
        }
    }
    return false;
}

bool Bibliotheque::possedeLivreEmprunts(int codeLivre){
    for (auto i = 0; i < emprunts.size(); i++) {
        if (emprunts[i]->getCode() == codeLivre){
            return true;
        }
    }
    return false;
}

bool Bibliotheque::possedeLivre(int codeLivre){
    bool exist = this->possedeLivreListe(codeLivre);
    if (!exist) {
        return this->possedeLivreEmprunts(codeLivre);
    }
    return exist;

}

Livre* Bibliotheque::search(int codeLivre) {
    Livre* livre = this->searchListeLivre(codeLivre);
    if (livre == nullptr) {
        return this->searchEmprunts(codeLivre);
    }
    return livre;
}

Livre* Bibliotheque::searchListeLivre(int codeLivre) {
    int i = 0;
    while (i < listeLivres.size()) {
        if (listeLivres[i]->getCode() == codeLivre) {
            return listeLivres[i];
        }
        i++;
    }

    return nullptr;
}

Livre* Bibliotheque::searchEmprunts(int codeLivre) {
    int i = 0;
    while ( i < emprunts.size() ) {
        if (emprunts[i]->getCode() == codeLivre) {
            return emprunts[i];
        }
        i++;
    }
    return nullptr;
}

vector<Livre*> Bibliotheque::getListeLivres() const {
    return listeLivres;
}

void Bibliotheque::pret(Bibliotheque *bibliotheque, int codeLivre) {
    if (this->possedeLivre(codeLivre)){
        Livre* livre = this->search(codeLivre);
        if (livre->getEtat() == ETATS::LIBRE) {
            bibliotheque->emprunts.push_back(livre);
            livre->setEtat(ETATS::PRETE);
            return;
        }else{
            cout << "Ce livre n'est pas disponible pour le moment" << endl;
        }
    }else{
        cout << "Ce livre n'existe pas dans la bibliotheque en question" << endl;
    }
}

void Bibliotheque::supprimer(int codeLivre){
    for (auto i = 0; i < listeLivres.size(); i++) {
        if (listeLivres[i]->getCode() == codeLivre){
            listeLivres.erase(listeLivres.begin()+i);
            return;
        }
    }
    cout << "Ce livre n'appartient pas a cette Bibliotheque" << endl;
}

void Bibliotheque::demande(Bibliotheque* bibliotheque, string isbn){
    for (auto i = 0; i < bibliotheque->listeLivres.size(); i++){
        if (bibliotheque->listeLivres[i]->getISBN() == isbn && bibliotheque->listeLivres[i]->getEtat() == ETATS::LIBRE){
            bibliotheque->pret(this, bibliotheque->listeLivres[i]->getCode());
            return;
        }
    }
    cout << "Cette demande n'est pas acceptable" << endl;
}

void Bibliotheque::rendre() {
    for (auto i = 0; i < emprunts.size(); i++) {
        if (emprunts[i]->getEtat() != ETATS::EMPRUNTE){
            emprunts[i]->setEtat(ETATS::LIBRE);
            emprunts.erase(emprunts.begin()+i);
            return;
        }
    }
}

Bibliotheque::Bibliotheque(){
    nom = "";
    adresse = "";
    code = 0;
    limEmprunts = 3;
}