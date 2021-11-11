#include "genre.h"
Genre::Genre(string a=""):nom_(a){nbre_emprunts_=0;}
Genre::~Genre(){}
void Genre::set_nom(string ch)
    {nom_=ch;}
void Genre::set_nbre(int a)
    {nbre_emprunts_=a;}
string Genre::get_nom()
    {return nom_;}
int Genre::get_nbre()
    {return nbre_emprunts_;}


