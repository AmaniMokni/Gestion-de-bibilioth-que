#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
#include "CategorieClient.h"
#include "FicheEmprunt.h"
#include <string>
#include <vector>
#include <ctime>

class Client
{
    //friend class Mediatheque;
    //friend class Fiche_emprunt;
public:
    string cin_;
    string nom_,prenom_,adresse_;
    tm date_inscription_,date_renouvellement_;
    Categorie_Client* CategClient_;
    double PrixAP;
    int nbEmpruntsEnCours_,nbEmpruntsDepasses_,nbEmpruntsEffectues_;
    vector <Fiche_emprunt> FicheEmprunt_;
public:
    Client(string,string,string,string,Categorie_Client*);
    ~Client();
    string get_cin();
    string get_nom();
    string get_prenom();
    string get_adresse();
    double get_PrixAP();
    void set_PrixAP(double);
    int get_nbEmpruntsEnCours();
    int get_nbEmpruntsDepasses();
    int get_nbEmpruntsEffectues();
    tm get_date_inscription();
    tm get_date_renouvellement();
    void set_nom(string nom);
    void set_prenom(string prenom);
    void set_adresse(string adresse);
    void set_nbEmpruntsEnCours(int nbEmpruntsEnCours);
    void set_nbEmpruntsDepasses(int nbEmpruntsDepasses);
    void set_nbEmpruntsEffectues(int nbEmpruntsEffectues);
    void set_date_inscription(tm date_inscription);
    void set_date_renouvellement(tm date_renouvellement);
    void set_fiche_emprunt(Fiche_emprunt F);
    void pouvoir_emprunter();
    void changer_adresse(string adresse);
    Categorie_Client get_Categorie_Client();
    void set_Categorie_Client(Categorie_Client* CC);
    friend ostream &operator<<(ostream &out, Client C);

};

#endif // CLIENT_H_INCLUDED
