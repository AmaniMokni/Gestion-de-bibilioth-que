#include <typeinfo>
#include "FicheEmprunt.h"
Fiche_emprunt::Fiche_emprunt(Client* client=NULL,Document* document=NULL):
    document_(document),client_(client)
    {
        time_t now = time(0);
        dateEmprunt_ = *localtime(&now);
        dateLimite_ = *localtime(&now);
        dateRappel_= *localtime(&now);
        dateLimite_.tm_mday+=client->CategClient_->get_coeffDuree()*document->get_duree_pret_();
        mktime(&dateLimite_);
    }
Fiche_emprunt::~Fiche_emprunt(){}
tm Fiche_emprunt::get_dateEmprunt()
    {return dateEmprunt_;}
tm Fiche_emprunt::get_dateLimite()
    {return dateLimite_;}
tm Fiche_emprunt::get_dateRappel()
    {return dateRappel_;}

bool Fiche_emprunt::get_depasse()
    {return depasse_;}
void Fiche_emprunt::set_dateEmprunt(tm dateEmprunt)
    {dateEmprunt_=dateEmprunt;}
void Fiche_emprunt::set_dateLimite(tm dateLimite)
    {dateLimite_=dateLimite;}
void Fiche_emprunt::set_dateRappel(tm dateRappel)
    {dateRappel_=dateRappel;}
ostream& Fiche_emprunt::Afficher(ostream& out)
{

    out<<"\t\t\t\t\tCode du document: "<<document_->code_<<" - Type du document: ";cout<<typeid(*document_).name()+1<<endl;
    out<<"\t\t\t\t     Date Emprunt: "<<dateEmprunt_.tm_mday << "/"<<dateEmprunt_.tm_mon+1
    <<"/"<<dateEmprunt_.tm_year+1900<<" - Date Limite: "<<dateLimite_.tm_mday << "/"<<dateLimite_.tm_mon+1
    <<"/"<<dateLimite_.tm_year+1900<<endl;
    time_t now = time(0);
    tm a = *localtime(&now);
    if (a<=dateLimite_)
    {
        out<<"\t\t\t\t      Date Rappel: ";
        out<<"Date Limite n'est pas encore depasse"<<endl;
    }
    else
    {
        out<<"\t\t\t\t\t\tDate Rappel: ";
        out<<dateRappel_.tm_mday << "/"<<dateRappel_.tm_mon+1<<"/"<<dateRappel_.tm_year+1900<<endl;
    }
    return out;
}
ostream& operator <<(ostream& out,Fiche_emprunt& F)
{
      F.Afficher(out);
      return out;
}


