#include "Client.h"
Client::Client(string cin="12345678",string nom="",string prenom="",string adresse="",
        Categorie_Client *CategClient=NULL):
        cin_(cin),nom_(nom),prenom_(prenom),adresse_(adresse),CategClient_(CategClient)
        {
            PrixAP=0;
            time_t ttime = time(0);
            date_inscription_= *localtime(&ttime);
            date_renouvellement_=date_inscription_;
            nbEmpruntsEnCours_=0;
            nbEmpruntsDepasses_=0;
            nbEmpruntsEffectues_=0;
        }
Client::~Client(){}
string Client::get_cin()
    {return cin_;}
string Client::get_nom()
    {return nom_;}
string Client::get_prenom()
    {return prenom_;}
string Client::get_adresse()
    {return adresse_;}
double Client::get_PrixAP()
    {return PrixAP;}
void Client::set_PrixAP(double S)
    {PrixAP=S;}
int Client::get_nbEmpruntsEnCours()
    {return nbEmpruntsEnCours_;}
int Client::get_nbEmpruntsDepasses()
    {return nbEmpruntsDepasses_;}
int Client::get_nbEmpruntsEffectues()
    {return nbEmpruntsEffectues_;}
tm Client::get_date_inscription()
    {return date_inscription_; }
tm Client::get_date_renouvellement()
    {return date_renouvellement_;}
void Client::set_nom(string nom)
    {nom_=nom;}
void Client::set_prenom(string prenom)
    {prenom_=prenom;}
void Client::set_adresse(string adresse)
    {adresse_=adresse;}
void Client::set_nbEmpruntsEnCours(int nbEmpruntsEnCours)
{
  nbEmpruntsEnCours_=nbEmpruntsEnCours;
}
void Client::set_nbEmpruntsDepasses(int nbEmpruntsDepasses)
{
  nbEmpruntsDepasses_=nbEmpruntsDepasses;
}
void Client::set_nbEmpruntsEffectues(int nbEmpruntsEffectues)
{
  nbEmpruntsEffectues_=nbEmpruntsEffectues;
}
void Client::set_date_inscription(tm date_inscription)
    {date_inscription_=date_inscription;}
void Client::set_date_renouvellement(tm date_renouvellement)
    {date_renouvellement_=date_renouvellement;}
void Client::set_fiche_emprunt(Fiche_emprunt F)
{
    FicheEmprunt_.push_back(F);
}
void Client::pouvoir_emprunter()
{
            cout<<"\t\t\t**************************************************************************\n";
            cout<<"\t\t\t|           ****** Verification de possibilite d'emprunt ******          |\n";
            cout<<"\t\t\t**************************************************************************\n";
if (nbEmpruntsEnCours_!=CategClient_->get_nb_emprunt_max())
{
    cout<<"\t\t\t**************************************************************************\n";
    cout<<"\t\t\t|Possible d'emprunter, vous pouvez encore emprunter "<<CategClient_->get_nb_emprunt_max()-nbEmpruntsEnCours_<<" document(s) de plus|\n";
    cout<<"\t\t\t**************************************************************************\n";
}
else
{
    cout<<"\t\t\t**************************************************************************\n";
    cout<<"\t\t\t| Impossible d'emprunter, vous avez depasse le nombre limite d'emprunts. |\n";
    cout<<"\t\t\t**************************************************************************\n";
}
}
void Client::changer_adresse(string adresse)
{
    adresse_=adresse;
}
Categorie_Client Client::get_Categorie_Client()
    {return *CategClient_;}
void Client::set_Categorie_Client(Categorie_Client* CC)
    {CategClient_=CC;}
ostream &operator<<(ostream &out, Client c)
{
    Client* C=&c;
    out<<"\t\t\t   CIN: "<<C->cin_<<" - Nom: "<<C->nom_<<" - Prenom: "<<C->prenom_<<" - Adresse: "<<C->adresse_<<endl;
    out<<"\t\t\t Date Inscription: "<<C->date_inscription_.tm_mday << "/"<<1 +C->date_inscription_.tm_mon
    <<"/"<<1900 +C->date_inscription_.tm_year<<" - Date Renouvellement: ";
    if ((C->date_renouvellement_.tm_year)!=(C->date_inscription_.tm_year))
    {
        out<<C->date_renouvellement_.tm_mday<< "/"<<1 +C->date_renouvellement_.tm_mon<<"/"<<1900 +C->date_renouvellement_.tm_year<<endl;
    }
    else
    {
        out<<"Pas encore renouvele"<<endl;
    }
    out<<"\t\t\t\tCategorie du client: "<<C->CategClient_->get_CatNom()<<" - Nombre d'emprunts max: "<<C->CategClient_->get_nb_emprunt_max()<<endl;
    out<<"\t\t\t\tCotisation: "<<C->CategClient_->get_cotisation()<<" - Coefficient Tarif: "<<C->CategClient_->get_coeffTarif()<<" - Coefficient Duree: "<<C->CategClient_->get_coeffDuree()<<endl;
    out<<"\t\t\t\tNombre Emprunts en cours: "<<C->nbEmpruntsEnCours_<<" - Nombre emprunts depasses: "<<C->nbEmpruntsDepasses_<<endl;
    out<<"\t\t\t\t\t    Nombre emprunts effectuees: "<<C->nbEmpruntsEffectues_<<endl;
    return out;
}


