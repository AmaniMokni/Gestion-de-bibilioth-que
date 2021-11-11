#include "localisation.h"
Localisation::Localisation(string a="",string b=""):salle_(a),rayon_(b){}
    Localisation::~Localisation(){}
void Localisation::set_salle(string ch)
    {salle_=ch;}
void Localisation::set_rayon(string ch)
    {rayon_=ch;}
string Localisation::get_salle()
    {return salle_;}
string Localisation::get_rayon()
    {return rayon_;}


