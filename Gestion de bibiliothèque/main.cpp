#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "mediatheque.cpp"
#include "Document.cpp"
#include "Client.cpp"
#include "Audio.cpp"
#include "Video.cpp"
#include "Livre.cpp"
#include "CategorieClient.cpp"
#include "FicheEmprunt.cpp"
#include "Genre.cpp"
#include "Localisation.cpp"
#include <string>
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std;


void gotoxy(int x, int y)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD point; // COORD est predefinie dans la biblio windwos.h
    point.X = (SHORT)x;
    point.Y = (SHORT)y;
    SetConsoleCursorPosition(H, point);
}

/****************************************************/
void Color(int flags)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, (WORD)flags);
}
void image()
{
    FILE* fichier;
    int i;
    int key=-1;
    gotoxy(10,4);
    fichier=fopen("livre_image.txt","r+");
    if (fichier==NULL)
        exit(1);
        Color(14);
    while (1)
    {
        i = fgetc(fichier);
        if (feof(fichier))
            break;
        printf("%c",i);
    }
    fclose(fichier);
}

/****************************************************/
void loading()
{
    int i;
    long double c;
    int f = 25;
    gotoxy(30, 15);
    Color(4);
    printf("Loading...");
    for (i = 0; i < 18; i++)
    {
        for (c = 0; c < 40000000; c++)
        {
        }
        gotoxy(f, 16);
        Color(1);
        printf("%c", 180);
        f++;
    }
    system("cls");
}
/****************************************************/
void init_stade()
{
    int j;
    int i;
    char ch[71][31];
    for (i = 20; i <= 70; i++)
    {
        for (j = 3; j <= 30; j++)
        {
            if ((i == 20) || (j == 3) || (j == 30) || (i == 70))
            {
                ch[i][j] = 177;
                gotoxy(i, j);
                Color(FOREGROUND_RED);
                printf("%c", ch[i][j]);
            }
        }
    }
}

int main()
{
image();
loading();
Mediatheque M("Médiathéque");
Categorie_Client CC1;
M.ajouterCategorieClient(&CC1);
Categorie_Client CC2("Tarif Reduit",2,0.5,0.5,1);
M.ajouterCategorieClient(&CC2);
Categorie_Client CC3("Abonne",10,0,0,2);
M.ajouterCategorieClient(&CC3);
Client C1("14356378","Yahyaoui","Tayssir","Manouba, Tunisie",&CC1);
M.inscrireClient(&C1);

    while (true)
    {
        char c = '1';
        char c1 = '1';
        char c2 = '1';
        int c3 = 1;
        init_stade();
        gotoxy(30, 8);
        Color(1);
        cout << "****************************** \n"<< endl;
        gotoxy(29, 9);
        Color(4);
        cout << "Bienvenue dans notre mediatheque \n"<< endl;
        gotoxy(30, 10);
        Color(1);
        cout << "****************************** \n"<< endl;
        gotoxy(27, 14);
        Color(3);
        cout << "choisir l'une des propositions suivantes :\n"<< endl;
        gotoxy(30, 15);
        cout << "1:Espace client" << endl;
        gotoxy(30, 16);
        cout << "2:Espace employe \n"<< endl;
        gotoxy(30, 17);
        fflush(stdin);
        cout << "Choix:  ";
        c = getchar();
        system("cls");
        switch (c)
        {
        case '1':
            while (c1 != '4')
            {
                init_stade();
                gotoxy(30, 8);
                Color(14);
                cout << "****************************** \n"<< endl;
                gotoxy(29,9);
                Color(4);
                cout << "          ESPACE CLIENT \n"<< endl;
                gotoxy(30, 10);
                Color(14);
                cout << "****************************** \n"<< endl;
                gotoxy(27, 14);
                Color(3);
                cout << "choisir l'une des propositions suivantes :\n"<< endl;
                gotoxy(30, 15);
                Color(14);
                cout << "1:Consulter catalogue document" << endl;
                gotoxy(30, 16);
                cout << "2:Changer l'adresse" << endl;
                gotoxy(30, 17);
                cout << "3:Consulter les emprunts" << endl;
                gotoxy(30, 18);
                cout << "4:Revenir au menu principale" << endl;
                gotoxy(30, 19);
                fflush(stdin);
                cout << "Choix:  ";
                c1 = getchar();
                system("cls");
                switch (c1)
                { case '1' :
                    {
                         system("cls");
                         fflush(stdin);
                         M.consulterCatalogueDocuments();
                         system("cls");
                         break ;
                    }
                  case '2':
                        {
                         system ("cls");
                         fflush (stdin);
                         string a,e;
                         cout<<"\t\t\t**************************************************************************\n";
                         cout<<"\t\t\t*                       Changement d'adresse Client                      *\n";
                         cout<<"\t\t\t**************************************************************************\n";
                         cout<<"\t\t\t           Veuillez remplir les informations suivantes:"<<endl;
                         cout<<"\t\t\t     Numero CIN (8 chiffres) du client: ";
                         cin>>a;
                         while (M.chercher_client(a)==nullptr)
                             {
                               cout<<"\t\t\t     Le CIN donne n'existe pas !"<<endl;
                               cout<<"\t\t\t     Veuillez tapez le CIN de nouveau: ";
                               cin>>a;
                              }
                               cout<<"\t\t\t     Nouvelle adresse: ";
                               cin>>e;
                               M.changerAdresseClient(M.chercher_client(a),e);
                               system("cls") ;
                               break ;
                        }
                  case '3':
                        {
                        system ("cls");
                        fflush (stdin);
                        string Ci;
                        cout<<"\t\t\t**************************************************************************\n";
                        cout<<"\t\t\t*                       Consultation des emprunts                        *\n";
                        cout<<"\t\t\t**************************************************************************\n";
                        cout << "\t\t\t veuillez entrer le cin du client !\n "<<endl ;
                        cin >> Ci;
                        M.consulterEmpruntsClient (M.chercher_client(Ci));
                        system("cls") ;
                        break ;
                        }
//                  default :
//                        c1='1';
//                        break ;

                }
            }
            break;

        case '2':
            while (c2 != '3')
            {
                c3 = 1;
                init_stade();
                gotoxy(30, 8);
                Color(14);
                cout << "****************************** \n"
                     << endl;
                gotoxy(29, 9);
                Color(4);
                cout << "          ESPACE EMPLOYEE \n"<< endl;
                gotoxy(30, 10);
                Color(14);
                cout << "****************************** \n"<< endl;
                gotoxy(27, 14);
                Color(1);
                cout << "choisir l'une des propositions suivantes :\n"<< endl;
                gotoxy(30, 15);
                Color(14);
                cout << "1:Gestion clients" <<endl;
                gotoxy(30, 16);
                cout << "2:Gestion documents" <<endl;
                gotoxy(30, 17);
                cout << "3: Retour" <<endl;
                gotoxy(30, 18);
                fflush(stdin);
                cout << "Choix:  ";
                c2 = getchar();
                system("cls");
                switch (c2)
                {
                case '1':
                    while (c3 != 0)
                    {
                        init_stade();
                        gotoxy(30, 8);
                        Color(14);
                        cout << "choisir l'une des options suivantes" << endl;
                        gotoxy(30, 9);
                        cout << "1: Ajouter categorie client" << endl;
                        gotoxy(30, 10);
                        cout << "2: Changer categorie client" << endl;
                        gotoxy(30, 11);
                        cout << "3: Supprimer categorie client" << endl;
                        gotoxy(30, 12);
                        cout << "4: Inscrire client ";
                        gotoxy(30, 13);
                        cout << "5: Afficher caracteristique client" << endl;
                        gotoxy(30, 14);
                        cout << "6: Modifier carateristiques client" << endl;
                        gotoxy(30, 15);
                        cout << "7: Renouveler inscription client " << endl;
                        gotoxy(30, 16);
                        cout << "8: Resiliser client " << endl;
                        gotoxy(30, 17);
                        cout << "0: Retour" << endl;
                        gotoxy(30, 18);
                        cout << "Choix:  ";
                        fflush(stdin);
                        cin >> c3;
                        system("cls");
                        switch(c3)
                               { case 1:
                                   {

                                       system("cls");
                                       fflush(stdin);

                                      string b ;
                                      int c ;
                                      float d,e,f;

                                      cout<<"\t\t\t**************************************************************************\n";
                                      cout<<"\t\t\t*                       Ajout de categorie client                        *\n";
                                      cout<<"\t\t\t**************************************************************************\n";
                                      cout<<"\t\t\t           Veuillez remplir les informations suivantes du client:"<<endl;

                                         cout<<"\t\t\t     Nom de la categorie : ";
                                         cin>>b;
                                         cout<<"\t\t\t     nombre d'emprunt max: ";
                                         cin>>c;
                                         cout<<"\t\t\t     cotisation ";
                                         cin>>d;
                                         cout<<"\t\t\t     coeffTarif ";
                                         cin>>e;
                                         cout<<"\t\t\t     coeffDuree ";
                                         cin>>f;
                                         Categorie_Client* C1=new Categorie_Client(b,c,d,e,f);
                                         M.ajouterCategorieClient(C1);
                                         system("cls") ;
                                       break ;
                                   }

                                case 2:
                                       {
                                       system("cls");
                                       fflush(stdin);
                                       string f;string a;
        cout<<"\t\t\t**************************************************************************\n";
        cout<<"\t\t\t*               ****** Changement Categorie Client ******                *\n";
        cout<<"\t\t\t**************************************************************************\n";
        cout<<"\t\t\t           Veuillez remplir les informations suivantes:"<<endl;
        cout<<"\t\t\t     Numero CIN (8 chiffres) du client: ";
        cin>>a;
        cout<<"\t\t\t     Nouvelle categorie: ";
        cin>>f;

        if ((M.chercher_client(a)==nullptr))
        {
            cout<<"\t\t\t**************************************************************************\n";
            cout<<"\t\t\t*         Client introuvable, veuillez verifier le CIN donnee...         *"<<endl;
            cout<<"\t\t\t**************************************************************************\n";
        }
        else
        {
                M.changerClientCategorie(M.chercher_client(a),M.chercher_CategClient(f));
        }
             system("pause");
                                       system ("cls") ;
                                       break ;
                                       }
                                case 3 :
                                    {

                                    system("cls");
                                     fflush(stdin);
                                     string a;
        cout<<"\t\t\t**************************************************************************\n";
        cout<<"\t\t\t*                     Suppression Categorie Client                       *\n";
        cout<<"\t\t\t**************************************************************************\n";
        cout<<"\t\t\t           Veuillez remplir les informations suivantes:"<<endl;
        cout<<"\t\t\t     Nom de la categorie à supprimer: ";
        cin>>a;
                                     M.supprimerCategorieClient(M.chercher_CategClient(a));
                                     system ("cls") ;
                                     break ;
                                    }
                                case 4 :
                                    {

                                      system("cls");
                                      fflush(stdin);
                                      int e;
                                      string a,b,c,d;

                                      cout<<"\t\t\t**************************************************************************\n";
                                      cout<<"\t\t\t*                        Inscription Client                              *\n";
                                      cout<<"\t\t\t**************************************************************************\n";
                                      cout<<"\t\t\t           Veuillez remplir les informations suivantes du client:"<<endl;
                                      cout<<"\t\t\t     Numero CIN (8 chiffres): ";
                                      cin>>a;
                                      while ((M.chercher_client(a)!=nullptr)||(a.size()!=8))
                                     {
                                        if (a.size()!=8)
                                        {cout<<"\t\t\t     Le CIN doit contenir 8 chiffres !"<<endl;}
                                        else
                                        {
                                         cout<<"\t\t\t     Le CIN donne existe deja !"<<endl;
                                        }
                                         cout<<"\t\t\t     Veuillez tapez le CIN de nouveau: ";
                                         cin>>a;
                                        }
                                         cout<<"\t\t\t     Nom: ";
                                         cin>>b;
                                         cout<<"\t\t\t     Prenom: ";
                                         cin>>c;
                                         cout<<"\t\t\t     Adresse: ";
                                         cin>>d;
                                         cout<<"\t\t\t     Categorie(1- Tarif Normal, 2- Tarif Reduit, 3- Abonnee): ";
                                         cin>>e;
                                        while ((e!=1)&&(e!=2)&&(e!=3))
                                              {
                                                cout<<"\t\t\t     Choix non valide !"<<endl;
                                                cout<<"\t\t\t     Veuillez tapez le numero de categorie de nouveau: ";
                                                cin>>e;
                                            }
                                         string f;
                                         switch(e)
                                            {
                                                case 1:{f="Tarif Normal";break;}
                                                case 2:{f="Tarif Reduit";break;}
                                                case 3:{f="Abonne";break;}
                                             }
                                        Client* C1=new Client(a,b,c,d,M.chercher_CategClient(f));
                                        M.inscrireClient(C1);
                                        cout<<"\t\t\t**************************************************************************\n";
                                        cout<<"\t\t\t*           Operation effectue, client inscrit avec succes...            *"<<endl;
                                        cout<<"\t\t\t**************************************************************************\n";


                                      system ("cls") ;
                                      break ;
                                    }

                                case 5 :
                                     {

                                      system("cls") ;
                                      fflush(stdin) ;
                                string a;
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t|                 ****** Caracteristiques Client ******                  |\n";
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t           Veuillez donner le CIN du client: ";
        cin>>a;
        system("cls");
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t|                 ****** Caracteristiques Client ******                  |\n";
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
            while (M.chercher_client(a)==nullptr && a!="quitter")
        {
            system("cls");
            cout<<"\t\t\t--------------------------------------------------------------------------\n";
            cout<<"\t\t\t|                 ****** Caracteristiques Client ******                  |\n";
            cout<<"\t\t\t--------------------------------------------------------------------------\n";
            cout<<"\t\t\t--------------------------------------------------------------------------\n";
            cout<<"\t\t\t|         Client introuvable, veuillez verifier le CIN donnee...         |"<<endl;
            cout<<"\t\t\t--------------------------------------------------------------------------\n";
            system("pause");
            system("cls");
            cout<<"\t\t\t--------------------------------------------------------------------------\n";
            cout<<"\t\t\t|                 ****** Caracteristiques Client ******                  |\n";
            cout<<"\t\t\t--------------------------------------------------------------------------\n";
            cout<<"\t\t\t           Veuillez donner le CIN du client: ";
            cin>>a;
        }
        if(a!="quitter")
        {
                cout<<*M.chercher_client(a);
                system("pause");


        }
        system ("cls") ;
                                      break ;
                                     }
                                case 6:
                                      {
                                      system("cls") ;
                                      fflush(stdin) ;
                                      string a,nom,prenom,adresse; int choix,choixUnique;
                                      cout<<"\t\t\t--------------------------------------------------------------------------\n";
                                      cout<<"\t\t\t|        ****** Modification des caracteristiques du Client ******       |\n";
                                      cout<<"\t\t\t--------------------------------------------------------------------------\n";
                                      cout<<"\t\t\t           Veuillez donner le CIN du client: ";
                                      cin>>a;
                                      if ((M.chercher_client(a)!= nullptr))
                                      {
                                            cout<<"\n Si vous voulez modifier plusieurs champs tapez 0 \n"<<endl;
                                            cout<<"\n Si vous voulez modifier un seul champ tapez 1 \n" ;
                                            cin>>choix;

                                if(choix == 1) {


                                            cout<<"\n 1: modifier le nom \n"<<endl;
                                            cout<<"\n 2: modifier le prenom \n";
                                            cout<<"\n 3: modifier l'adresse \n";
                                            cout<<"\n 4: modifier la date de renouvellement \n";
                                            cin>>choixUnique;
                                            if(choixUnique==1)
                                                {
                                                  cout<<"Quelle est le nouveau nom du client ?"<<endl;
                                                  cin>>nom;
                                                  M.chercher_client(a)->set_nom(nom);
                                                  cout<<" Operation effectuee avec succés, le nouveau nom est: "<<nom<<endl;

                                                }
                                            if(choixUnique==2)
                                                {
                                                  cout<<"Quelle est le nouveau prenom du client ?"<<endl;
                                                  cin>>prenom;
                                                  M.chercher_client(a)->set_prenom(prenom);
                                                  cout<<" Operation effectuee avec succés, le nouveau prenom est: "<<prenom<<endl;
                                                }
                                             if(choixUnique==3)
                                             {
                                                  cout<<"Quelle est la nouvelle adresse du client ?"<<endl;
                                                  cin>>adresse;
                                                  M.chercher_client(a)->set_adresse(adresse);
                                                  cout<<" Operation effectuee avec succés, le nouvelle adresse est: "<<adresse<<endl;

                                             }


                                        }


                    else{
                                   int userChoise ;

                        do{
                            system("cls");
                            cout<<"\n 1: modifier le nom \n"<<endl;
                            cout<<"\n 2: modifier le prenom \n";
                            cout<<"\n 3: modifier l'adresse \n";
                            cout<<"\n 4: modifier la date de renouvellement \n";
                            cin>>userChoise;

                            } while(userChoise!=1&&userChoise!=2&&userChoise!=3&&userChoise!=4) ;


                              if(userChoise==1)
                                {
                                  cout<<"Quelle est le nouveau nom du client ?"<<endl;
                                  cin>>nom;
                                  M.chercher_client(a)->set_nom(nom);
                                  cout<<" Operation effectuee avec succés, le nouveau nom est: "<<nom<<endl;
                                }
                              if(userChoise==2)
                               {
                                  cout<<"Quelle est le nouveau prenom du client ?"<<endl;
                                  cin>>prenom;
                                  M.chercher_client(a)->set_prenom(prenom);
                                  cout<<" Operation effectuee avec succés, le nouveau prenom est: "<<prenom<<endl;
                                }
                              if(userChoise==3)
                               {
                                      cout<<"Quelle est la nouvelle adresse du client ?"<<endl;
                                      cin>>adresse;
                                      M.chercher_client(a)->set_adresse(adresse);
                                      cout<<" Operation effectuee avec succés, le nouvelle adresse est: "<<adresse<<endl;

                               }

                           } }
 system("cls") ;
                                      break;
                }
                                case 7:
                                    {


                                      system("cls");
                                      fflush(stdin);
                                    string a;
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t|            ****** Renouvellement Inscription Client ******             |\n";
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t     Veuillez donner le numero CIN (8 chiffres) du client: ";
        cin>>a;
        if (M.chercher_client(a)==nullptr)
        {
            cout<<"\t\t\t--------------------------------------------------------------------------\n";
            cout<<"\t\t\t|         Client introuvable, veuillez verifier le CIN donnee...         |"<<endl;
            cout<<"\t\t\t--------------------------------------------------------------------------\n";

        }
        else
        {
                M.renouvelerInscriptionClient(M.chercher_client(a));
        }

                                      system("cls");
                                      break ;
                                    }
                                case 8:
                                    {


                                      system ("cls") ;
                                      fflush(stdin);
                                     string a;
                                     cout<<"\t\t\t--------------------------------------------------------------------------\n";
                                     cout<<"\t\t\t|               ****** Suppression de Client ******                |\n";
                                     cout<<"\t\t\t--------------------------------------------------------------------------\n";
                                     cout<<"\t\t\t           Veuillez remplir les informations suivantes:"<<endl;
                                     cout<<"\t\t\t     Numero CIN (8 chiffres) du client: ";
                                     cin>>a;
                                     M.resilierClient(M.chercher_client(a));
                                      system("cls");
                                      break ;
                                    }
//                                default :
//                                     c3='1';
//                                     break ;

                                                }
                    }

                case '2':

                    while (c3 != 0)
                    {
                        init_stade();
                        gotoxy(30, 8);
                        Color(14);
                        cout << "choisir l'une des options suivantes" << endl;
                        gotoxy(30, 9);
                        cout << "1: Ajouter une audio" << endl;
                        gotoxy(30, 10);
                        cout << "2: Ajouter un livre" << endl;
                        gotoxy(30, 11);
                        cout << "3: Ajouter une video" << endl;
                        gotoxy(30, 12);
                        cout << "4: Rendre consultable document" << endl;
                        gotoxy(30, 13);
                        cout << "5: Rendre empruntable document" << endl;
                        gotoxy(30, 14);
                        cout << "6: Retirer document" << endl;
                        gotoxy(30, 15);
                        cout << "7: Emprunter document" << endl;
                        gotoxy(30, 16);
                        cout << "8: Restituer document" << endl;
                        gotoxy(30, 17);
                        cout << "9: Trouver les emprunts en retard " << endl;
                        gotoxy(30, 18);
                        cout << "10: Afficher les statistiques" << endl;
                        gotoxy(30, 19);
                        cout << "0: Retour" << endl;
                        gotoxy(30, 20);
                        cout << "Choix:  ";
                        fflush(stdin);
                        cin>>c3;
                        system("cls");
                        switch(c3)
                        {
                        case 1:
                            {
                                 system("cls");
                                       fflush(stdin);
                                       bool e;
        int a,d,f,x,ss,rr;
        string b,c,z,g,h,i;
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t|                     ****** Ajout d'un Audio ******                     |\n";
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t   Veuillez remplir les informations suivantes du document a ajouter:"<<endl;
        cout<<"\t\t\t     Code: ";
        cin>>a;
        while ((&M.chercher_document(a)!=NULL))
        {
            cout<<"\t\t\t     Le code donne existe deja !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le code de nouveau: ";
            cin>>a;
        }
        cout<<"\t\t\t     Titre: ";
        cin>>b;
        cout<<"\t\t\t     Auteur: ";
        cin>>c;
        cout<<"\t\t\t     Annee de sortie: ";
        cin>>d;
        while ((d<1600)||(d>2020))
        {
            cout<<"\t\t\t     L'annee de sortie doit etre entre 1600 et 2020 !"<<endl;
            cout<<"\t\t\t     Veuillez tapez l'annee de sortie de nouveau: ";
            cin>>d;
        }
        cout<<"\t\t\t     Empruntable (1=true/0=false): ";
        cin>>e;
        cout<<"\t\t\t     Genre: 1-Classique / 2-Varietes internationales / 3- Musiques afro-americaines"<<endl;
        cout<<"\t\t\t     Votre choix: ";
        cin>>f;
        while ((f!=1)&&(f!=2)&&(f!=3))
        {
            cout<<"\t\t\t     Choix non valide !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le numero de genre de nouveau: ";
            cin>>f;
        }
        switch(f)
        {
        case 1:{z="Classique";
        cout<<"\t\t\t     Classification (1-Opera / 2-Symphonie / 3-Valse)"<<endl;
        cout<<"\t\t\t     Votre choix: ";
        cin>>x;
        while ((x!=1)&&(x!=2)&&(x!=3))
        {
            cout<<"\t\t\t     Choix non valide !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le numero de classification de nouveau: ";
            cin>>x;
        }
        switch(x)
        {
        case 1:{i="Opera";break;}
        case 2:{i="Symphonie";break;}
        case 3:{i="Valse";break;}
        }
        break;}
        case 2:{z="Varietes internationales";
        cout<<"\t\t\t     Classification (1-Rock / 2-Pop / 3-Folk / 4-Metal / 5-Punk / 6-New wave)"<<endl;
        cout<<"\t\t\t     Votre choix: ";
        cin>>x;
        while ((x!=1)&&(x!=2)&&(x!=3)&&(x!=4)&&(x!=5)&&(x!=6))
        {
            cout<<"\t\t\t     Choix non valide !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le numero de classification de nouveau: ";
            cin>>x;
        }
        switch(x)
        {
        case 1:{i="Rock";break;}
        case 2:{i="Pop";break;}
        case 3:{i="Folk";break;}
        case 4:{i="Metal";break;}
        case 5:{i="Punk";break;}
        case 6:{i="New wave";break;}
        }
        break;}
        case 3:{z="Musiques afro-americaines";
        cout<<"\t\t\t     Classification (1-Blues / 2-Gospel / 3-Jazz / 4-r'n'b / 5-Rap / 6-Hip-hop / 7-Reggae)"<<endl;
        cout<<"\t\t\t     Votre choix: ";
        cin>>x;
        while ((x!=1)&&(x!=2)&&(x!=3)&&(x!=4)&&(x!=5)&&(x!=6)&&(x!=7))
        {
            cout<<"\t\t\t     Choix non valide !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le numero de classification de nouveau: ";
            cin>>x;
        }
        switch(x)
        {
        case 1:{i="Blues";break;}
        case 2:{i="Gospel";break;}
        case 3:{i="Jazz";break;}
        case 4:{i="r'n'b";break;}
        case 5:{i="Rap";break;}
        case 6:{i="Hip-Hop";break;}
        case 7:{i="Reggae";break;}
        }
        break;}
        }
        cout<<"\t\t\t     Salle (1-Salle A / 2-Salle B / 3-Salle C): ";
        cin>>ss;
        while ((ss!=1)&&(ss!=2)&&(ss!=3))
        {
            cout<<"\t\t\t     Choix non valide !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le numero de salle de nouveau: ";
            cin>>ss;
        }
        switch(ss)
        {
        case 1:{g="A";break;}
        case 2:{g="B";break;}
        case 3:{g="C";break;}
        }
        cout<<"\t\t\t     Rayon (1-R1 / 2-R2 / 3-R3 / 4-R4 / 5-R5): ";
        cin>>rr;
                while ((ss!=1)&&(ss!=2)&&(ss!=3)&&(rr!=4)&&(rr!=5))
        {
            cout<<"\t\t\t     Choix non valide !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le numero de salle de nouveau: ";
            cin>>rr;
        }
        switch(rr)
        {
        case 1:{h="R1";break;}
        case 2:{h="R2";break;}
        case 3:{h="R3";break;}
        case 4:{h="R4";break;}
        case 5:{h="R5";break;}
        }
        M.ajouterDocument<Audio>(new Audio(a,b,c,d,e,false,new Genre(z),new Localisation(g,h),i));
        Sleep(3000);
                                       system("cls") ;
                                       break ;
                            }
                        case 2:
                            { system("cls");
                                       fflush(stdin);
                                       bool e;
        int a,d,nb,rr,ss,x;
        string b,c,f,g,h,i;
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t|                     ****** Ajout d'un Livre ******                     |\n";
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t   Veuillez remplir les informations suivantes du document a ajouter:"<<endl;
        cout<<"\t\t\t     Code: ";
        cin>>a;
        while ((&M.chercher_document(a)!=NULL))
        {
            cout<<"\t\t\t     Le code donne existe deja !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le code de nouveau: ";
            cin>>a;
        }
        cout<<"\t\t\t     Titre: ";
        cin>>b;
        cout<<"\t\t\t     Auteur: ";
        cin>>c;
        cout<<"\t\t\t     Annee de sortie: ";
        cin>>d;
        while ((d<1600)||(d>2020))
        {
            cout<<"\t\t\t     L'annee de sortie doit etre entre 1600 et 2020 !"<<endl;
            cout<<"\t\t\t     Veuillez tapez l'annee de sortie de nouveau: ";
            cin>>d;
        }
        cout<<"\t\t\t     Empruntable (1=true/0=false): ";
        cin>>e;
        cout<<"\t\t\t     Genre (1-Bibliographie / 2-Fantasy / 3-Aventures / 4-Horreur / 5-Science-fiction)"<<endl;
        cout<<"\t\t\t     Votre choix: ";
        cin>>x;
        while ((x!=1)&&(x!=2)&&(x!=3)&&(x!=4)&&(x!=5))
        {
            cout<<"\t\t\t     Choix non valide !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le numero de genre de nouveau: ";
            cin>>x;
        }
        switch(x)
        {
        case 1:{f="Bibliographie";break;}
        case 2:{f="Fantasy";break;}
        case 3:{f="Aventures";break;}
        case 4:{f="Horreur";break;}
        case 5:{f="Science-fiction";break;}
        }
        cout<<"\t\t\t     Nombre de pages: ";
        cin>>nb;
        cout<<"\t\t\t     Salle (1-Salle A / 2-Salle B / 3-Salle C): ";
        cin>>ss;
        while ((ss!=1)&&(ss!=2)&&(ss!=3))
        {
            cout<<"\t\t\t     Choix non valide !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le numero de salle de nouveau: ";
            cin>>ss;
        }
        switch(ss)
        {
        case 1:{g="A";break;}
        case 2:{g="B";break;}
        case 3:{g="C";break;}
        }
        cout<<"\t\t\t     Rayon (1-R1 / 2-R2 / 3-R3 / 4-R4 / 5-R5): ";
        cin>>rr;
                while ((ss!=1)&&(ss!=2)&&(ss!=3)&&(rr!=4)&&(rr!=5))
        {
            cout<<"\t\t\t     Choix non valide !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le numero de salle de nouveau: ";
            cin>>rr;
        }
        switch(rr)
        {
        case 1:{h="R1";break;}
        case 2:{h="R2";break;}
        case 3:{h="R3";break;}
        case 4:{h="R4";break;}
        case 5:{h="R5";break;}
        }
        M.ajouterDocument<Livre>(new Livre(a,b,c,d,e,false,new Genre(f),new Localisation(g,h),25));
        Sleep(3000);


                                system("cls") ;
                                break ;
                            }
                        case 3:
                            { system("cls");
                                       fflush(stdin);
                                       bool e;
        int a,d,dd,rr,ss,x;
        string b,c,f,g,h,i,ml;
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t|                     ****** Ajout d'une Video ******                    |\n";
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t   Veuillez remplir les informations suivantes du document a ajouter:"<<endl;
        cout<<"\t\t\t     Code: ";
        cin>>a;
        while ((&M.chercher_document(a)!=NULL))
        {
            cout<<"\t\t\t     Le code donne existe deja !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le code de nouveau: ";
            cin>>a;
        }
        cout<<"\t\t\t     Titre: ";
        cin>>b;
        cout<<"\t\t\t     Auteur: ";
        cin>>c;
        cout<<"\t\t\t     Annee de sortie: ";
        cin>>d;
        while ((d<1600)||(d>2020))
        {
            cout<<"\t\t\t     L'annee de sortie doit etre entre 1600 et 2020 !"<<endl;
            cout<<"\t\t\t     Veuillez tapez l'annee de sortie de nouveau: ";
            cin>>d;
        }
        cout<<"\t\t\t     Empruntable (1=true/0=false): ";
        cin>>e;
        cout<<"\t\t\t     Genre (1-Documentaire / 2-Comedie / 3-Action / 4-Horreur / 5-Romance)"<<endl;
        cout<<"\t\t\t     Votre choix: ";
        cin>>x;
        while ((x!=1)&&(x!=2)&&(x!=3)&&(x!=4)&&(x!=5))
        {
            cout<<"\t\t\t     Choix non valide !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le numero de genre de nouveau: ";
            cin>>x;
        }
        switch(x)
        {
        case 1:{f="Documentaire";break;}
        case 2:{f="Comedie";break;}
        case 3:{f="Action";break;}
        case 4:{f="Horreur";break;}
        case 5:{f="Romance";break;}
        }
        cout<<"\t\t\t     Salle (1-Salle A / 2-Salle B / 3-Salle C): ";
        cin>>ss;
        while ((ss!=1)&&(ss!=2)&&(ss!=3))
        {
            cout<<"\t\t\t     Choix non valide !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le numero de salle de nouveau: ";
            cin>>ss;
        }
        switch(ss)
        {
        case 1:{g="A";break;}
        case 2:{g="B";break;}
        case 3:{g="C";break;}
        }
        cout<<"\t\t\t     Rayon (1-R1 / 2-R2 / 3-R3 / 4-R4 / 5-R5): ";
        cin>>rr;
                while ((ss!=1)&&(ss!=2)&&(ss!=3)&&(rr!=4)&&(rr!=5))
        {
            cout<<"\t\t\t     Choix non valide !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le numero de salle de nouveau: ";
            cin>>rr;
        }
        switch(rr)
        {
        case 1:{h="R1";break;}
        case 2:{h="R2";break;}
        case 3:{h="R3";break;}
        case 4:{h="R4";break;}
        case 5:{h="R5";break;}
        }
        cout<<"\t\t\t     Duree: ";
        cin>>dd;
        cout<<"\t\t\t     Mention Legale: ";
        cin>>ml;
        M.ajouterDocument<Video>(new Video(a,b,c,d,e,false,new Genre(f),new Localisation(g,h),dd,ml));
        Sleep(3000);

                                system("cls") ;
                                break ;
                            }
                        case 4:
                             { system("cls");
                                       fflush(stdin);
                                       int a;
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t|               ****** Rendre Document Consultable ******                |\n";
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t     Veuillez donner le code du document: ";

        cin>>a;
        while (&M.chercher_document(a)==NULL)
        {
            cout<<"\t\t\t     Le code donne n'existe pas !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le code de nouveau: ";
            cin>>a;
        }

  M.rendreConsultableDocument(&M.chercher_document(a));


                                system("cls") ;
                                break ;
                            }
                        case 5:
                             { system("cls");
                                       fflush(stdin);
                                       int a;
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t|               ****** Rendre Document Emprunltable ******               |\n";
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t     Veuillez donner le code du document: ";

        cin>>a;
        while (&M.chercher_document(a)==NULL)
        {
            cout<<"\t\t\t     Le code donne n'existe pas !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le code de nouveau: ";
            cin>>a;
        }
        M.rendreEmpruntableDocument(&M.chercher_document(a));


                                system("cls") ;
                                break ;
                            }
                        case 6:
                             { system("cls");
                                       fflush(stdin);
                                       int a;
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t|         ****** Suppression de Document de la mediatheque ******        |\n";
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t     Veuillez donner le code du document: ";

        cin>>a;
        if (&M.chercher_document(a)==NULL)
        {
            cout<<"\t\t\t--------------------------------------------------------------------------\n";
            cout<<"\t\t\t|       Document introuvable, veuillez verifier le Code donnee...        |"<<endl;
            cout<<"\t\t\t--------------------------------------------------------------------------\n";

        }
        else
        {
                M.retirerDocument(&M.chercher_document(a));
        }



                                system("cls") ;
                                break ;
                            }
                        case 7:
                             { system("cls");
                                       fflush(stdin);
                                       string c;
        int b;
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t|                  ****** Emprunt d'un document ******                   |\n";
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t           Veuillez remplir les informations suivantes:"<<endl;
        cout<<"\t\t\t     Numero CIN (8 chiffres) du client: ";
        cin>>c;
        while (M.chercher_client(c)==nullptr)
        {
            cout<<"\t\t\t     Le CIN donne n'existe pas !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le CIN de nouveau: ";
            cin>>c;
        }
        cout<<"\t\t\t     Code du document a emprunter: ";
        cin>>b;
         while (&M.chercher_document(b)==NULL)
        {
            cout<<"\t\t\t     Le code donne n'existe pas !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le code de nouveau: ";
            cin>>b;
        }
        bool a=false;
        a=M.emprunterDocument(&M.chercher_document(b),M.chercher_client(c));
        if (a==true)
        {
            Fiche_emprunt F(M.chercher_client(c),&M.chercher_document(b));
            M.chercher_client(c)->set_fiche_emprunt(F);
            M.ajouter_liste_emprunt(&F);
        }



                                system("cls") ;
                                break ;
                            }
                        case 8:
                             { system("cls");
                                       fflush(stdin);
                                       string c;
        int b;
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t|                ****** Restitution d'un document ******                 |\n";
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t           Veuillez remplir les informations suivantes:"<<endl;
        cout<<"\t\t\t     Numero CIN (8 chiffres) du client: ";
        cin>>c;
        while (M.chercher_client(c)==nullptr)
        {
            cout<<"\t\t\t     Le CIN donne n'existe pas !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le CIN de nouveau: ";
            cin>>c;
        }
        cout<<"\t\t\t     Code du document a rendre: ";
        cin>>b;
         while (&M.chercher_document(b)==NULL)
        {
            cout<<"\t\t\t     Le code donne n'existe pas !"<<endl;
            cout<<"\t\t\t     Veuillez tapez le code de nouveau: ";
            cin>>b;
        }
        M.restituerDocument(&M.chercher_document(b),M.chercher_client(c));



                                system("cls") ;
                                break ;
                            }
                        case 9:
                             { system("cls");
                               fflush(stdin);
                               cout<<"\t\t\t--------------------------------------------------------------------------\n";
                               cout<<"\t\t\t|                    ****** Emprunts en retard ******                    |\n";
                               cout<<"\t\t\t--------------------------------------------------------------------------\n";
                                Sleep(3000);
                               M.trouverEmpruntsEnRetard();

                               system("cls") ;
                               break ;
                            }
                        case 10:
                             { system("cls");
                               fflush(stdin);
                               cout<<"\t\t\t--------------------------------------------------------------------------\n";
                               cout<<"\t\t\t|                    ****** Affichage des statistiques ******             |\n";
                               cout<<"\t\t\t--------------------------------------------------------------------------\n";
                               Sleep(3000);
                               M.afficherStatistiques();
                               system("cls") ;
                                break ;
                            }
//                        default :
//                                     c3='1';
//                                     break ;

                        }

                    }

                    }
                    break;
                }
            }
        }

    return 0;
}


