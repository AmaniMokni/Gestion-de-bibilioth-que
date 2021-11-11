#ifndef AUDIO_H_INCLUDED
#define AUDIO_H_INCLUDED
#include "Document.h"
#include <fstream>

class Audio:public Document
{
private:
    string classification_;
    int duree_pret_;
    double tarif_;
public:
    Audio(int,string,string,int,bool,bool,Genre*,Localisation*,string);
    ~Audio();
    int get_duree_pret_();
    double get_tarif_();
    void set_classification(string ch);
    string get_classification();
    void set_duree_pret_(int);
    void set_tarif_(double);
    ostream& Afficher(ostream& out);
    void chargerFichier(ofstream&);
};

#endif // AUDIO_H_INCLUDED
