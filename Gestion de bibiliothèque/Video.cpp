#include "Video.h"
 Video::Video(int a=0,string b="",string c="",int d=2000,bool e=true,bool j=false,Genre *f=NULL,Localisation *g=NULL,int h=0,string i=""):Document(a,b,c,d,e,j,f,g),duree_(h),mention_legale_(i)
    {
        emprunte_=0;
        duree_pret_=2*7;
        tarif_=1.5;
    }
Video::~Video(){}
void Video::set_mention_legale(string ch)
    {mention_legale_=ch;}
void Video::set_duree(int a)
    {duree_=a;}
int Video::get_duree_pret_()
    {return duree_pret_;}
string Video::get_mention_legale()
    {return mention_legale_;}
int Video::get_duree()
    {return duree_;}
double Video::get_tarif_()
    {return tarif_;}

void Video::set_duree_pret_(int i){
    this->duree_pret_=i;
}

void Video::set_tarif_(double d){
    this->tarif_=d;
}

void Video::afficherMentionLegale()
{
    cout<<"Mention Legale: "<<mention_legale_<<endl;
}

ostream &Video::Afficher(ostream &out)
{
    out<<"\t\t\t**************************************************************************\n";
    out<<"\t\t\t*                               Video                                    *\n";
    out<<"\t\t\t**************************************************************************\n";
    out<<"\t\t\t    Code: "<<this->code_<<" - Titre: "<<titre_<<" - Auteur: "<<auteur_<<" - Annee: "<<annee_<<endl;
    out<<"\t\t\t    Empruntable: "<<empruntable_<<" - Genre: "<<genre_->nom_<<" - Nombre d'emprunts: "<<genre_->nbre_emprunts_<<endl;
    out<<"\t\t\t    Duree: "<<duree_<<"mn - Mention Legale: "<<mention_legale_<<" - Salle: "<<loc_->salle_<<" - Rayon: "<<loc_->rayon_<<endl;
    return out;
}

void Video::chargerFichier(ofstream& f){
    f<<"(V) : [ "<< this->get_code()<<' '<<this->get_titre()<<' '<<this->get_auteur()<<' '<<this->get_annee()<<' '<<this->get_empruntable()<<' '<<this->get_emprunte()<<' '<<this->get_genre().get_nom()<<' '<<this->get_genre().get_nbre()<<' '<<this->get_loc().get_rayon()<<' '<<this->get_loc().get_salle()<<' '<<this->get_duree()<<' '<<this->get_mention_legale()<<' '<<this->get_duree_pret_()<<' '<<this->get_tarif_()<<" ]"<<endl;
}
