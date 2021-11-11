#ifndef FICHEEMPRUNT_H_INCLUDED
#define FICHEEMPRUNT_H_INCLUDED
#include <ctime>
#include "Client.h"
#include "Document.h"
class Client;
class Fiche_emprunt
{
    friend class Mediatheque;
private:
    tm dateEmprunt_,dateLimite_,dateRappel_;
    bool depasse_;
    Document* document_;
    Client* client_;
public:
    Fiche_emprunt(Client*,Document*);
    ~Fiche_emprunt();
    tm get_dateEmprunt();
    tm get_dateLimite();
    tm get_dateRappel();
    bool get_depasse();
    void set_dateEmprunt(tm dateEmprunt);
    void set_dateLimite(tm dateLimite);
    void set_dateRappel(tm dateRappel);
    double calculer_tarif();
    friend ostream& operator <<(ostream& out,Fiche_emprunt& F);

    ostream& Afficher(ostream& out);
};
std::ostream& operator<<(ostream& out,const Fiche_emprunt &F);

#endif // FICHEEMPRUNT_H_INCLUDED
