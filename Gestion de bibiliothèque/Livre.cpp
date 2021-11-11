#include "Livre.h"
Livre::Livre(int a=0,string b="",string c="",int d=2000,bool e=true,bool i=false,Genre *f=NULL,Localisation *g=NULL,int h=0):Document(a,b,c,d,e,i,f,g),nombre_page_(h)
    {
        emprunte_=0;
        duree_pret_=6*7;
        tarif_=0.5;
    }
Livre::~Livre(){}
void Livre::set_nbre(int a)
        {nombre_page_=a;}
int Livre::get_nbre()
    {return nombre_page_;}
int Livre::get_duree_pret_()
    {return duree_pret_;}
double Livre::get_tarif_()
    {return tarif_;}

void Livre::set_duree_pret_(int i){
    this->duree_pret_=i;
}

void Livre::set_tarif_(double d){
    this->tarif_=d;
}

ostream &Livre::Afficher(ostream &out)
{
    out<<"\t\t\t**************************************************************************\n";
        out<<"\t\t\t|                               Livre                                    |\n";
        out<<"\t\t\t**************************************************************************\n";
        out<<"\t\t\t    Code: "<<this->code_<<" - Titre: "<<titre_<<" - Auteur: "<<auteur_<<" - Annee: "<<annee_<<endl;
        out<<"\t\t\t    Empruntable: "<<empruntable_<<" - Genre: "<<genre_->nom_<<" - Nombre d'emprunts: "<<genre_->nbre_emprunts_<<endl;
        out<<"\t\t\t    Nombre de pages: "<<nombre_page_<<" - Salle: "<<loc_->salle_<<" - Rayon: "<<loc_->rayon_<<endl;
        return out;
}

void Livre::chargerFichier(ofstream& f){
    f<<"(L) : [ "<< this->get_code()<<' '<<this->get_titre()<<' '<<this->get_auteur()<<' '<<this->get_annee()<<' '<<this->get_empruntable()<<' '<<this->get_emprunte()<<' '<<this->get_genre().get_nom()<<' '<<this->get_genre().get_nbre()<<' '<<this->get_loc().get_rayon()<<' '<<this->get_loc().get_salle()<<' '<<this->get_nbre()<<' '<<this->get_duree_pret_()<<' '<<this->get_tarif_()<<" ]"<<endl;
}

