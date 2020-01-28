
#ifndef BIBLIOTHEQUE_BANDEDESSINEE_H
#define BIBLIOTHEQUE_BANDEDESSINEE_H

#include "Livre.h"

class BandeDessinee : public Livre{
protected:
    string dessinateur;
public :
    BandeDessinee(string, string, string, string, int, string);
    void affiche();
    BandeDessinee();
};


#endif //BIBLIOTHEQUE_BANDEDESSINEE_H
