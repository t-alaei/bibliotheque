
#include "Livre.h"

int Livre::codeNext = 1;

Livre::Livre() {
    code = 0;
    auteur = "";
    titre = "";
    editeur = "";
    ISBN = "";
    publicDestine = PUBLIC::TOUTPUBLIC;
    etat = ETATS::LIBRE;
    type = TYPE::LIVRE;

}

Livre::Livre(string a, string t, string edit, string num_isbn, int publ) {
    code = codeNext;
    codeNext++;
    auteur = a;
    titre = t;
    editeur = edit;
    ISBN = num_isbn;
    publicDestine = publ;
    etat = ETATS::LIBRE;
    type = TYPE::LIVRE;
    taken = false;
}

void Livre::setEtat(int newEtat){
    if (newEtat == 0 || newEtat == 1 || newEtat == 2){
        etat = newEtat;
    }
    else{
        cout << "Cet état n'existe pas !" << endl;
    }
}

int Livre::getCode() const{
    return code;
}

int Livre::getType() const{
    return type;
}

int Livre::getEtat() const{
    return etat;
}

void Livre::affiche() {
    cout << "Livre " << this->code << " : " << endl << this->titre << ", " << this->auteur << ", " << this->editeur << endl;
    cout << "ISBN : " << this->ISBN << "- public : " << publicName(this->publicDestine) << "- type : " << typeName(this->type) << endl;
}

string Livre::getISBN() const{
    return ISBN;
}

bool Livre::isTaken() const {
    return taken;
}

void Livre::setTaken() {
    taken = true;
}

