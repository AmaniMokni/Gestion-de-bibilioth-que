#ifndef CATEGORIECLIENT_H_INCLUDED
#define CATEGORIECLIENT_H_INCLUDED
class Categorie_Client
{
    friend class Client;
private:
    string catNom_;
    int nb_emprunt_max_;
    float cotisation_,coeffTarif_,coeffDuree_;
public:
    Categorie_Client(string,int,float,float,float);
    ~Categorie_Client();
    string get_CatNom();
    int get_nb_emprunt_max();
    float get_cotisation();
    float get_coeffTarif();
    float get_coeffDuree();
    void set_nb_emprunt_max(int nb_emprunt_max);
    void set_cotisation(float cotisation);
    void set_coeffTarif(float coeffTarif);
    void set_coeffDuree(float coeffDuree);
};

#endif // CATEGORIECLIENT_H_INCLUDED
