#include "Audio.h"
Audio::Audio(int a=0,string b="",string c="",int d=0,bool e=true,bool h=false,Genre *f=NULL,Localisation *g=NULL,string ch=""):
    Document(a,b,c,d,e,h,f,g),classification_(ch)
    {
        emprunte_=0;
        duree_pret_=4*7;
        tarif_=1;
    }
Audio::~Audio(){}
void Audio::set_classification(string ch)
        {classification_=ch;}
int Audio::get_duree_pret_()
    {return duree_pret_;}
double Audio::get_tarif_()
    {return tarif_;}
string Audio::get_classification()
        {return classification_;}

void Audio::set_duree_pret_(int i){
    this->duree_pret_=i;
}

void Audio::set_tarif_(double d){
    this->tarif_=d;
}

ostream& Audio::Afficher(ostream &out)
{
    out<<"\t\t\t**************************************************************************\n";
    out<<"\t\t\t*                               Audio                                    *\n";
    out<<"\t\t\t**************************************************************************\n";
    out<<"\t\t\t    Code: "<<this->code_<<" - Titre: "<<titre_<<" - Auteur: "<<auteur_<<" - Annee: "<<annee_<<endl;
    out<<"\t\t\t    Empruntable: "<<empruntable_<<" - Genre: "<<genre_->nom_<<" - Classification: "<<classification_<<endl;
    out<<"\t\t\t    Nombre d'emprunts: "<<genre_->nbre_emprunts_<<" - Salle: "<<loc_->salle_<<" - Rayon: "<<loc_->rayon_<<endl;
    return out;
}

void Audio::chargerFichier(ofstream& f){
    f<<"(A) : [ "<< this->get_code()<<' '<<this->get_titre()<<' '<<this->get_auteur()<<' '<<this->get_annee()<<' '<<this->get_empruntable()<<' '<<this->get_emprunte()<<' '<<this->get_genre().get_nom()<<' '<<this->get_genre().get_nbre()<<' '<<this->get_loc().get_rayon()<<' '<<this->get_loc().get_salle()<<' '<<this->get_classification()<<' '<<this->get_duree_pret_()<<' '<<this->get_tarif_()<<" ]"<<endl;
}
