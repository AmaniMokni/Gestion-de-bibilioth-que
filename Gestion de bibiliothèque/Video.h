#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED
#include "Document.h"
#include <fstream>

class Video:public Document
{
private:
    int duree_;
    string mention_legale_;
    int duree_pret_;
    double tarif_;
public:
    Video(int,string,string,int,bool,bool,Genre *,Localisation *,int,string);
    ~Video();
    void set_mention_legale(string ch);
    void set_duree(int a);
    string get_mention_legale();
    int get_duree();
    int get_duree_pret_();
    double get_tarif_();
    void afficherMentionLegale();
    ostream& Afficher(ostream& out);
    void chargerFichier(ofstream&);
    void set_duree_pret_(int);
    void set_tarif_(double);
};

#endif // VIDEO_H_INCLUDED
