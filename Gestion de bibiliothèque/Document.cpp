#include "Document.h"
Document::Document(int a=0,string b="",string c="",int d=2000,bool e=true,bool h=false,Genre *f=NULL,Localisation *g=NULL):
    code_(a),titre_(b),auteur_(c),annee_(d),empruntable_(e),emprunte_(h),genre_(f),loc_(g){}
Document::~Document(){}
void Document::set_code(int a)
    {code_=a;}
void Document::set_titre(string ch)
    {titre_=ch;}
void Document::set_auteur(string ch)
    {auteur_=ch;}
void Document::set_annee(int ch)
    {annee_=ch;}
void Document::set_empruntable(bool a)
    {empruntable_=a;}
int Document::get_code()
    {return code_;}
string Document::get_titre()
    {return titre_;}
string Document::get_auteur()
    {return auteur_;}
int Document::get_annee()
    {return annee_;}
bool Document::get_empruntable()
    {return empruntable_;}
bool Document::get_emprunte()
    {return emprunte_;}
Localisation Document::localiser()
{
    return *loc_;
}
void Document::etre_empruntable()
{
    empruntable_=true;
}
void Document::set_genre(Genre *x)
    {genre_=x;}
void Document::set_localisation(Localisation *x)
    {loc_=x;}
Genre Document::get_genre()
    {return *genre_;}
Localisation Document::get_loc()
    {return *loc_;}

ostream& operator <<(ostream& out,Document* D){
    D->Afficher(out);
}
