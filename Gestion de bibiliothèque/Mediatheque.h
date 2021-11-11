#ifndef MEDIATHEQUE_H_INCLUDED
#define MEDIATHEQUE_H_INCLUDED
#include "Document.h"
#include "Client.h"
#include "Audio.h"
#include "Video.h"
#include "Livre.h"
#include <string>
#include <vector>
#include <fstream>
#include <typeinfo>
#include <iostream>

using namespace std;

class Mediatheque
{
private:
    string nom_;
    vector <Client*> liste_client_;
    vector <Document*> liste_document_;
    vector <Fiche_emprunt*> liste_emprunt_;
    vector <Categorie_Client*> liste_categ_;
    vector <Genre*> liste_genre_;
    vector <Localisation*> liste_localisation_;
public:
    Mediatheque(string);
    ~Mediatheque();
    string get_nom();

//    methode consulter les listes
//    vector consulter_liste_categorie () ;
//    vector consulter_genre () ;
//    vector consulter_localisation () ;
    void set_nom_(string ch);
    void ajouterCategorieClient(Categorie_Client*);
    void supprimerCategorieClient(Categorie_Client*);
    void inscrireClient(Client*);
    void changerClientCategorie(Client*,Categorie_Client *);
    void renouvelerInscriptionClient(Client*);
    void resilierClient(Client*);
    void changerAdresseClient(Client*,string);
    void consulterEmpruntsClient(Client*);
    void consulterListeClients();
    template <typename D>
    void ajouterDocument(D*);
    void rendreConsultableDocument(Document *);
    void rendreEmpruntableDocument(Document *);
    void retirerDocument(Document* );
    bool emprunterDocument(Document *D,Client *C);
    void restituerDocument(Document*,Client *);
    void trouverEmpruntsEnRetard();
    void afficherStatistiques();
    void consulterCatalogueDocuments();
    void ajouter_liste_emprunt(Fiche_emprunt *F);
    void ajouter_liste_genre(Genre *G);
    void ajouter_liste_localisation(Localisation *L);
    Client* chercher_client(string);
    Document& chercher_document(int);
    Categorie_Client* chercher_CategClient(string);


};



#endif // MEDIATHEQUE_H_INCLUDED
