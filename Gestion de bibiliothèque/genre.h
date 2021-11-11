#ifndef GENRE_H_INCLUDED
#define GENRE_H_INCLUDED
#include "string.h"
using namespace std;
#include <string>
class Genre
{
    friend class Mediatheque;
    friend class Audio;
    friend class Video;
    friend class Livre;
private:
    string nom_;
    int nbre_emprunts_;
public:
    Genre(string);
    ~Genre();
    void set_nom(string ch);
    void set_nbre(int a);
    string get_nom();
    int get_nbre();
};


#endif // GENRE_H_INCLUDED
