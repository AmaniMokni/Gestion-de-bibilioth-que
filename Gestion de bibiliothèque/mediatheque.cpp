#include "Mediatheque.h"
#include <sstream>
using namespace std;

Mediatheque::Mediatheque(string ch=""):nom_(ch){
    ifstream f;
    f.open("documents.txt");
    string line;
    string mot;
    vector<string> v;
    while (getline(f,line)){
        int i=0;
        v.clear();
        while(i<line.length()-2){
            mot="";
            while(i<line.length()-2 && line[i]!=' '){
                mot.push_back(line[i]);
                i++;
            }
            v.push_back(mot);
            i++;
        }
        switch(v[0][1]){
        case 'A':
            {Genre* g=new Genre(v[9]);
            int in;
            istringstream(v[10]) >>in;
            g->set_nbre(in);
            Localisation* l=new Localisation(v[11],v[12]);
            int in1;
            istringstream(v[3]) >>in;
            istringstream(v[6]) >>in;
            Audio* a=new Audio(in1,v[4],v[5],in,(v[7]=="1")?true:false,(v[8]=="1")?true:false,g,l,v[13]);
            istringstream(v[14]) >>in;
            a->set_duree_pret_(in);
            istringstream(v[15]) >>in;
            a->set_tarif_(in);
            liste_document_.push_back(a); break;}
        case 'V':
            {int in;
            istringstream(v[3]) >>in;
            int in1;
            istringstream(v[6]) >>in1;
            Genre* g=new Genre(v[3]);
            g->set_nbre(in);
            Localisation* l=new Localisation(v[11],v[12]);
            int in2;
            istringstream(v[13]) >>in2;
            Video* V=new Video(in,v[4],v[5],in1,(v[7]=="1")?true:false,(v[8]=="1")?true:false,g,l,in2,v[14]);
            istringstream(v[15]) >>in;
            V->set_duree_pret_(in);
            istringstream(v[16]) >>in;
            V->set_tarif_(in);
            liste_document_.push_back(V); break;}
        case 'L':
            {int in;
            istringstream(v[10]) >>in;
            int in1;
            istringstream(v[6]) >>in1;
            Genre* g=new Genre(v[9]);
            g->set_nbre(in);
            istringstream(v[3]) >>in;
            Localisation* l=new Localisation(v[11],v[12]);
            int in2;
            istringstream(v[13]) >>in2;
            Livre* L=new Livre(in,v[4],v[5],in1,(v[7]=="1")?true:false,(v[8]=="1")?true:false,g,l,in2);
            istringstream(v[14]) >>in;
            L->set_duree_pret_(in);
            istringstream(v[15]) >>in;
            L->set_tarif_(in);
            liste_document_.push_back(L); break;}}}
            f.close();}

Mediatheque::~Mediatheque(){}
string Mediatheque::get_nom()
        {return nom_;}
void Mediatheque::set_nom_(string ch)
    {nom_=ch;}



void Mediatheque::ajouterCategorieClient(Categorie_Client* CC)
{
    liste_categ_.push_back(CC);
}
void Mediatheque::supprimerCategorieClient(Categorie_Client* CC)
{
    if ((liste_categ_.size()==1)&&(liste_categ_[0]==CC))
    {
        liste_client_.clear();
    }
    vector<Categorie_Client*>::iterator monit;
    for(monit=liste_categ_.begin();monit!=liste_categ_.end();++monit)
    {if(*monit==CC)
            {liste_categ_.erase(monit);}
             cout<<"\t\t\t**************************************************************************\n";
             cout<<"\t\t\t*             Operation efectuee, categorie supprimee...                 *"<<endl;
             cout<<"\t\t\t**************************************************************************\n";}
}

void Mediatheque::inscrireClient(Client *C)
{
    liste_client_.push_back(C);
}

void Mediatheque::changerClientCategorie(Client *C,Categorie_Client *CC)
{
    C->set_Categorie_Client(CC);
    cout<<"\t\t\t**************************************************************************\n";
    cout<<"\t\t\t*              Operation efectuee, categorie modifiee...                 *"<<endl;
    cout<<"\t\t\t**************************************************************************\n";
}

void Mediatheque::renouvelerInscriptionClient(Client* C)
{
    C->date_renouvellement_.tm_year++;
    cout<<"\t\t\t**************************************************************************\n";
    cout<<"\t\t\t*       Operation efectuee, inscription renouvelle avec succees...       *"<<endl;
    cout<<"\t\t\t**************************************************************************\n";
    system("pause");
}

void Mediatheque::resilierClient(Client *C)
{
    if ((liste_client_.size()==1)&&(liste_client_[0]==C))
    {
        liste_client_.clear();
        cout<<"\t\t\t**************************************************************************\n";
        cout<<"\t\t\t*           Operation effectue, client resilie avec succes...            *"<<endl;
        cout<<"\t\t\t**************************************************************************\n";
    }
    vector<Client*>::iterator monit;
    for(monit=liste_client_.begin();monit!=liste_client_.end();++monit)
    {if(*monit==C)
            {liste_client_.erase(monit);
             cout<<"\t\t\t**************************************************************************\n";
             cout<<"\t\t\t*           Operation efectuee, client resilie avec succes...            *"<<endl;
             cout<<"\t\t\t**************************************************************************\n";
             break;}
             }

}
void Mediatheque::changerAdresseClient(Client *C,string NVadresse)
{
        C->changer_adresse(NVadresse);
        cout<<"\t\t\t**************************************************************************\n";
        cout<<"\t\t\t*           Operation effectue, adresse du client modifiee...            *"<<endl;
        cout<<"\t\t\t**************************************************************************\n";
}
void Mediatheque::consulterEmpruntsClient(Client *C)
{
    cout<<"\t\t\t**************************************************************************\n";
    cout<<"\t\t\t*                       Consultation Emprunts Client                     *\n";
    cout<<"\t\t\t**************************************************************************\n";
    cout<<"\t\t\t                      Client: ["<<C->get_cin()<<"] "<<C->get_nom()<<" "<<C->get_prenom()<<endl;
    cout<<"\t\t\t                   Somme d'argent totale payee: "<<C->get_PrixAP()<<"dt"<<endl;
    for (unsigned int i=0;i<C->FicheEmprunt_.size();i++)
    {
        cout<<C->FicheEmprunt_[i];
    }
    system("pause");
}
void Mediatheque::consulterListeClients()
{
    cout<<"\t\t\t**************************************************************************\n";
    cout<<"\t\t\t*                         Listes des Clients                             *n";
    cout<<"\t\t\t**************************************************************************\n";
    for (unsigned int i=0;i<liste_client_.size();i++)
    {
        cout<<"\t\t\t**************************************************************************\n";
        cout<<"\t\t\t*                             Client N: "<<i+1<<"                         *n";
        cout<<"\t\t\t**************************************************************************\n";
        cout<<liste_client_[i];
    }
}

template <typename D>
void Mediatheque::ajouterDocument(D* doc)
{
    liste_document_.push_back(doc);
    ofstream f;
    f.open("documents.txt",ios::app);
    doc->chargerFichier(f);
    f.close();
    cout<<"\t\t\t**************************************************************************\n";
    cout<<"\t\t\t*           Operation effectue, document ajoute avec succes...           *"<<endl;
    cout<<"\t\t\t**************************************************************************\n";
}

void Mediatheque::rendreConsultableDocument(Document *D)
{
    D->empruntable_=false;
    cout<<"\t\t\t**************************************************************************\n";
    cout<<"\t\t\t    Le Document ayant le code "<<D->get_code()<<" est maintenant consultable... "<<endl;
    cout<<"\t\t\t**************************************************************************\n";
}
void Mediatheque::rendreEmpruntableDocument(Document *D)
{
    D->empruntable_=true;
    cout<<"\t\t\t**************************************************************************\n";
    cout<<"\t\t\t        Le Document ayant le code "<<D->get_code()<<" est maintenant emprunltable...  "<<endl;
    cout<<"\t\t\t**************************************************************************\n";
}
void Mediatheque::retirerDocument(Document* D)
{
    if ((liste_document_.size()==1)&&(liste_document_[0]==D))
    {
        liste_document_.clear();
    }
    vector<Document*>::iterator monit;
    for(monit=liste_document_.begin();monit!=liste_document_.end();++monit)
            {
                if(*monit==D)
                {
                     liste_document_.erase(monit);
                }
            }
    cout<<"\t\t\t**************************************************************************\n";
    cout<<"\t\t\t     Le Document ayant le code "<<D->get_code()<<" a ete retire de la mediatheque... "<<endl;
    cout<<"\t\t\t**************************************************************************\n";
}
bool Mediatheque::emprunterDocument(Document *D,Client *C)
{
    if ((C->nbEmpruntsEnCours_!=C->CategClient_->get_nb_emprunt_max())&&(D->empruntable_==1)&&(D->emprunte_==0))
    {
        D->emprunte_=1;
        C->nbEmpruntsEnCours_++;
        C->nbEmpruntsEffectues_++;
        D->genre_->set_nbre(D->genre_->get_nbre()+1);
        C->set_PrixAP(C->get_PrixAP()+C->CategClient_->get_coeffTarif()*D->get_tarif_());
        cout<<"\t\t\t**************************************************************************\n";
        cout<<"\t\t\t*         Operation effectue, document emprunte avec succes...           *"<<endl;
        cout<<"\t\t\t**************************************************************************\n";
        return true;
    }
    else if (D->empruntable_==0)
    {
        cout<<"\t\t\t**************************************************************************\n";
        cout<<"\t\t\t*     Operation echoue, le document demande n'est pas empruntable...     *"<<endl;
        cout<<"\t\t\t**************************************************************************\n";
        return false;
    }
    else if(C->nbEmpruntsEnCours_==C->CategClient_->get_nb_emprunt_max())
    {
        cout<<"\t\t\t**************************************************************************\n";
        cout<<"\t\t\t* Operation echoue, le client a depasse le nombre maximum d'emprunts...   *"<<endl;
        cout<<"\t\t\t**************************************************************************\n";
        return false;
    }
    else if (D->emprunte_==1)
    {
        cout<<"\t\t\t**************************************************************************\n";
        cout<<"\t\t\t*         Operation echoue, le document est deja emprunte...             *"<<endl;
        cout<<"\t\t\t**************************************************************************\n";
        return false;
    }
    return false;
}

void Mediatheque::restituerDocument(Document *D,Client *C)
{
if (C->FicheEmprunt_.size()==0)
    {
        cout<<"\t\t\t**************************************************************************\n";
        cout<<"\t\t\t*      Operation echoue, le client n'a pas de documents empruntes...     *"<<endl;
        cout<<"\t\t\t**************************************************************************\n";
    }

else if ((C->FicheEmprunt_.size()==1)&&(C->FicheEmprunt_[0].document_==D))
    {   C->FicheEmprunt_.clear();
        D->emprunte_=0;
        C->nbEmpruntsEnCours_--;
        C->set_PrixAP(C->get_PrixAP()-C->CategClient_->get_coeffTarif()*D->get_tarif_());
         cout<<"\t\t\t**************************************************************************\n";
         cout<<"\t\t\t*          Operation efectuee, document restitue avec succes...          *"<<endl;
         cout<<"\t\t\t**************************************************************************\n";
         }
    vector<Fiche_emprunt>::iterator monit;
    for(monit=C->FicheEmprunt_.begin();monit!=C->FicheEmprunt_.end();++monit)
            {  if(monit->document_==D)
                {   D->emprunte_=0;
                    C->nbEmpruntsEnCours_--;
                    cout<<"\t\t\t**************************************************************************\n";
                    cout<<"\t\t\t*          Operation efectuee, document restitue avec succes...          *"<<endl;
                    cout<<"\t\t\t**************************************************************************\n";
                    C->FicheEmprunt_.erase(monit);
                    break;
                }
            }
}

bool operator <=(tm &t1, tm &t2)
{
    if (t1.tm_year < t2.tm_year) return 1;
    if (t1.tm_year > t2.tm_year)  return 0;
    if (t1.tm_year == t2.tm_year)
    {
        if (t1.tm_mon < t2.tm_mon) return 1;
        if (t1.tm_mon > t2.tm_mon) return 0;
        if (t1.tm_mon == t2.tm_mon) return(t1.tm_mday <= t2.tm_mday);
    }
    return 0;
}

void Mediatheque::trouverEmpruntsEnRetard()
{
time_t now = time(0);
tm a = *localtime(&now);


for (unsigned int i=0;i<liste_client_.size();i++)
    {

    for (unsigned int j=0;i<liste_client_[i]->FicheEmprunt_.size();j++)
        {
            if (liste_client_[i]->FicheEmprunt_[j].dateLimite_<=a)
            {
                liste_client_[i]->nbEmpruntsDepasses_++;
                cout<<"\t\t\t       Code Document: "<<liste_client_[i]->FicheEmprunt_[j].document_->code_<<" - CIN du client: "<<liste_client_[i]->cin_;
                cout<<"\t\t\t**************************************************************************\n";
            }
        }
    }
}
void Mediatheque::afficherStatistiques()
{
int st1=0,st2=0,st3=0,st4=0,st5=6;
for (unsigned int i=0; i<liste_document_.size();i++)
{
    if (liste_document_[i]->get_emprunte()==false)
    {st2+=1;}
}
for (unsigned int i=0; i<liste_client_.size();i++)
{

    st1+=liste_client_[i]->get_nbEmpruntsEffectues();
}

cout <<"\t nombre de clients : " <<liste_client_.size()<<endl;
cout <<"\t nombre de documents : " <<liste_document_.size()<<endl;
cout <<"\t nombre de genres : " <<st5<<endl;
cout <<"\t nombre d'emprunts : " <<st1<<endl;
cout <<"\t nombre de documents disponibles : " <<st2<<endl;
cout <<"\t nombre de categories clients disponibles : " <<liste_categ_.size()<<endl;

for (int k=0 ; k<liste_client_.size();k++)
{
    st3=liste_client_[k]->get_nbEmpruntsEnCours();
    st4=liste_client_[k]->get_nbEmpruntsDepasses();
}
cout<<"\t nombre d'emprunts en cours :"<<st3<<endl;
cout<<"\t nombre d'emprunts depasses :"<<st4<<endl;
system("pause");
}

void Mediatheque::consulterCatalogueDocuments()
{
    cout<<"\t\t\t**************************************************************************\n";
    cout<<"\t\t\t*                 ****** Catalogue des Documents ******                  *\n";
    cout<<"\t\t\t**************************************************************************\n";
    for (int i=0;i<liste_document_.size();i++)
    {
        cout<<liste_document_[i];
    }
    system("pause");
}


void Mediatheque::ajouter_liste_emprunt(Fiche_emprunt *F)
    {liste_emprunt_.push_back(F);}

void Mediatheque::ajouter_liste_genre(Genre *G)
{
    liste_genre_.push_back(G);
}
void Mediatheque::ajouter_liste_localisation(Localisation *L)
{
    liste_localisation_.push_back(L);
}

Client* Mediatheque::chercher_client(string CIN)
{
    {
        for (unsigned int i=0;i<liste_client_.size();i++)
        {
            if (liste_client_[i]->get_cin()==CIN)
            {return liste_client_[i];}
        }
    }
    return nullptr;
}
Document& Mediatheque::chercher_document(int Code)
{
    Document *D=NULL;
    {
        for (unsigned int i=0;i<liste_document_.size();i++)
        {
            if (liste_document_[i]->get_code()==Code)
            {return *liste_document_[i];}
        }
    }
    return *D;
}
Categorie_Client* Mediatheque::chercher_CategClient(string catNom)
{
        for (unsigned int i=0;i<liste_categ_.size();i++)
        {
            if (liste_categ_[i]->get_CatNom()==catNom)
            {return liste_categ_[i];}
        }
        return nullptr;
}



