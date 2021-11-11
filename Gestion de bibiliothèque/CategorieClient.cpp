#include "CtegorieClient.h"
Categorie_Client::Categorie_Client(string catNom="Tarif Normal",int nb_emprunt_max=5,float cotisation=1,float coeffTarif=1,float coeffDuree=1):
    catNom_(catNom),nb_emprunt_max_(nb_emprunt_max),cotisation_(cotisation),coeffTarif_(coeffTarif),coeffDuree_(coeffDuree){}
Categorie_Client::~Categorie_Client(){}
    string Categorie_Client::get_CatNom()
    {
        return catNom_;
    }
int Categorie_Client::get_nb_emprunt_max()
    {return nb_emprunt_max_;}
float Categorie_Client::get_cotisation()
    {return cotisation_;}
float Categorie_Client::get_coeffTarif()
    {return coeffTarif_;}
float Categorie_Client::get_coeffDuree()
    {return coeffDuree_;}
void Categorie_Client::set_nb_emprunt_max(int nb_emprunt_max)
    {nb_emprunt_max_=nb_emprunt_max;}
void Categorie_Client::set_cotisation(float cotisation)
    {cotisation_=cotisation;}
void Categorie_Client::set_coeffTarif(float coeffTarif)
    {coeffTarif_=coeffTarif;}
void Categorie_Client::set_coeffDuree(float coeffDuree)
    {coeffDuree_=coeffDuree;}


