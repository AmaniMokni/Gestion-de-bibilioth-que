#ifndef LOCALISATION_H_INCLUDED
#define LOCALISATION_H_INCLUDED
class Localisation
{
    friend class Audio;
    friend class Video;
    friend class Livre;
private:
    string salle_;
    string rayon_;
public:
    Localisation(string,string);
    ~Localisation();
    void set_salle(string ch);
    void set_rayon(string ch);
    string get_salle();
    string get_rayon();
};
#endif // LOCALISATION_H_INCLUDED
