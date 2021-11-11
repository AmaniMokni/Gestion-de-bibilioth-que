#ifndef LIVRE_H_INCLUDED
#define LIVRE_H_INCLUDED
#include "Document.h"
#include <fstream>
class Livre:public Document
{
private:
    int nombre_page_;
    int duree_pret_;
    double tarif_;
public:
    Livre(int,string,string,int,bool,bool,Genre *,Localisation *,int);
    ~Livre();
    int get_duree_pret_();
    void set_nbre(int a);
    int get_nbre();
    void set_duree_pret_(int);
    void set_tarif_(double);
    virtual ostream& Afficher(ostream& out);
    double get_tarif_();
    ostream& afficher(ostream&);
    void chargerFichier(ofstream&);

};

#endif // LIVRE_H_INCLUDED
