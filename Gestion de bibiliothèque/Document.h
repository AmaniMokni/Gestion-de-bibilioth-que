#ifndef DOCUMENT_H_INCLUDED
#define DOCUMENT_H_INCLUDED
#include "Genre.h"
#include "Localisation.h"
class Document
{
    friend class Fiche_emprunt;
    friend class Mediatheque;
protected:
    int code_;
    string titre_;
    string auteur_;
    int annee_;
    bool empruntable_;
    bool emprunte_;
    Genre *genre_;
    Localisation *loc_;
public:
    Document(int,string,string,int,bool,bool,Genre *,Localisation*);
    virtual ~Document();
    virtual int get_duree_pret_()=0;
    virtual double get_tarif_()=0;
    void set_code(int a);
    void set_titre(string ch);
    void set_auteur(string ch);
    void set_annee(int);
    void set_empruntable(bool a);
    int get_code();
    string get_titre();
    string get_auteur();
    int get_annee();
    bool get_empruntable();
    bool get_emprunte();
    Localisation localiser();
    void etre_empruntable();
    void set_genre(Genre *x);
    void set_localisation(Localisation *x);
    Genre get_genre();
    Localisation get_loc();
    virtual ostream& Afficher(ostream& out){};
    friend ostream& operator <<(ostream& out,Document* D);

};

#endif // DOCUMENT_H_INCLUDED
