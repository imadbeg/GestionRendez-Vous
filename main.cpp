#include<iostream>
using namespace std;
#include"RendezVousLCH.h"
#include"PersonneLCH.h"


void alerte(){
    cout<<endl<<endl<<"         ##############__________ERREUR_DE_SAISI__________________###############"<<endl<<endl;
}
void erreurDateDansRendezVous(){
    cout<<endl<<endl;
    cout<<"     ###########################____ERREUR___#############################"<<endl;
    cout<<"     ##   La date debut doit etre strictement inferieur a la date fin   ##"<<endl;
    cout<<"     ##   Le mois doit etre strictement entre 1 et 12                   ##"<<endl;
    cout<<"     ##   le jour doit etre strictement entre 1 et 31                   ##"<<endl;
    cout<<"     ##   Heure doit etre strictement entre 0 et 24                     ##"<<endl;
    cout<<"     ##   Minute doit etre inclu entre 0 et 60                          ##"<<endl;
    cout<<"     #####################################################################"<<endl;
    cout<<endl<<endl;
}
void infoEtAideTexte(){
    cout<<"###########################################################################################################"<<endl;
    cout<<"###  Choisissez le nombre que vous voulez qui correnspond a l'etiquete                                 ####"<<endl;
    cout<<"###  Sache que si on a pas de rendevous, quelque fonctionzlite sur rendevous sont cachés,             ####"<<endl;
    cout<<"###  egalement au personnes                                                                            ####"<<endl;
    cout<<"###  Lors de la creation d'une RendezVous, c'est onligatoire d'ajouter directement les personnes       ####"<<endl;
    cout<<"###  Lajout des personnes dans ce rendezvous est faite immediatement, en saisissant le chiffre indice  ####"<<endl;
    cout<<"###  du listes des personnes donnée ou en creant une nouvelle personnes                                ####"<<endl;
    cout<<"###########################################################################################################"<<endl<<endl<<endl;

}
void messageQuitter(){
    cout<<endl<<endl<<endl<<"             !!Merci d'avoir utiliser Notre systeme!!"<<endl<<endl<<endl;
    cout<<"__________Developpeurs____________"<<endl;
    cout<<"         "<<endl;
    cout<<"         "<<endl;
    cout<<"         "<<endl;
}
void mainNav(){
    cout<<"         CARNET DE RENDEZVOUS"<<endl;
    cout<<"________________________________________"<<endl;
    cout<<"         1.RendezVous"<<endl;
    cout<<"         2.Personnes"<<endl;
    cout<<"         3.Quitter"<<endl;
    cout<<"         4.Info et Aide"<<endl<<endl<<endl<<endl;
}
void afficheChoisRendezVous(const RendezVousLCH& c){
            cout<<"         1.Creeer un rendezVous"<<endl;
            if(c.head!=nullptr){
                cout<<"         2.supprimer un rendezvous"<<endl;
                cout<<"         3.ajouter une personne dans un rendezVous"<<endl;
                cout<<"         4.voir la taille des rendevous"<<endl;
                cout<<"         5.voir les membre du rendezvous en details"<<endl;
                cout<<"         6.afficher tous les rendezVous"<<endl;
                cout<<"         7.supprimer une personne dans un rendezvous"<<endl;
            }
}
bool supprimerPersonneDansListePersonne(PersonneLCH&personnes,RendezVousLCH& carnet){
    cout<<personnes;
    cout<<"saississez l'indice:";unsigned int indice;cin>>indice;
    if(personnes.personneExiste(indice)){
        Personne pers=personnes.getPersonne(indice);
        //personnes.supprimerPersonne(pers,carnet);
        return personnes.supprimerPersonne(pers,carnet);
    }
    alerte();
    return false;
}
void afficheChoisPersonne(const PersonneLCH& c){
            cout<<"         1.Creeer une personnes"<<endl;
            if(c.head!=nullptr){
                cout<<"         2.supprimer une personnes"<<endl;
                cout<<"         3.ajouter une personne dans un rendezVous"<<endl;
                cout<<"         4.voir la taille des personnes"<<endl;
                cout<<"         5.afficher les rendezVous d'une personne"<<endl;
                cout<<"         6.afficher tous les personnes"<<endl;
            }
}
Personne creerPersonne(PersonneLCH& personnes){
    string nom,prenom,tel,email;
    cout<<"Nom:";cin>>nom;
    cout<<"Prenom:";cin>>prenom;
    cout<<"Telephone:";cin>>tel;
    cout<<"Email:";cin>>email;
    Personne p(nom,prenom,tel,email);
    while(!personnes.addPersonne(p)){
        string nomm,prenomm,telm,emailm;
        cout<<"Erreur!! le personne existe deja !! saisissez a nouveau"<<endl;
        cout<<"     Nom:";cin>>nomm;
        cout<<"     Prenom:";cin>>prenom;
        cout<<"     Telephone:";cin>>telm;
        cout<<"     Email:";cin>>emailm;
        p.setEmail(emailm);
        p.setNom(nomm);
        p.setTelephone(telm);
        p.setPrenom(prenomm);
    }
    return p;
}
vector<Date> creerDateRendezVous(){
    cout<<"Saississez la date DEBUT et date FINdu rendezVous(jour mois année heure minutes)"<<endl<<endl;//<<"     i.e:Le  25 11 1995 14 50"<<endl;
                unsigned int jourD,moisD,anneeD,heureD,minuteD,jourF,moisF,anneeF,heureF,minuteF;
                //cin>>jourD>>moisD>>anneeD>>heureD>>minuteD;
                cout<<"DEBUT"<<endl;
                cout<<"     jour:";cin>>jourD;
                cout<<endl<<"     mois:";cin>>moisD;
                cout<<endl<<"     annee:";cin>>anneeD;
                cout<<endl<<"     heure:";cin>>heureD;
                cout<<endl<<"     minute:";cin>>minuteD;
                cout<<"FIN"<<endl;
                cout<<endl<<"     jour:";cin>>jourF;
                cout<<endl<<"     mois:";cin>>moisF;
                cout<<endl<<"     annee:";cin>>anneeF;
                cout<<endl<<"     heure:";cin>>heureF;
                cout<<endl<<"     minute:";cin>>minuteF;

                Date deb(anneeD,moisD,jourD,heureD,minuteD),fin(anneeF,moisF,jourF,heureF,minuteF);
                while(// le while a verifier encore la consdition!!
                      deb>=fin || moisD>12 || moisD <1 || jourD>31 || jourD<1 || heureD>60 || heureD<0 || minuteD>60 || minuteD<0 ||
                      moisF>12 || moisF <1 || jourF>31 || jourF<1 || heureF>60 || heureF<0 || minuteF>60 || minuteF<0
                      ){
                        erreurDateDansRendezVous();
                        creerDateRendezVous();
                      }
                    vector<Date>d;
                    d.push_back(deb);
                    d.push_back(fin);
                    return d;

}
void creerRendezVous(RendezVousLCH& carnet,PersonneLCH& personnes){
                vector<Date>d=creerDateRendezVous();
                cout<<"Nom du rendezVous:"<<endl;
                string nomRDV;cin>>nomRDV;

                RendezVous rdv(d[0],d[1],nomRDV);
                carnet.addRendezVous(rdv);
                cout<<endl<<endl<<"     ###Le RendezVous a ete creer avec success###      "<<endl<<endl;
                cout<<"####################"""""<<endl;
                //cout<<carnet;
                cout<<""<<endl<<endl<<endl<<endl;
                cout<<"il faut ajouter une personne!"<<endl;

                cout<<"voulez vous ajuter parmi les personnes existants ou vous voulez en creer une autre"<<endl;
                cout<<"     1.Creer une nouvelle personne"<<endl;
                cout<<"     2.Ajouter parmi les personnes existants"<<endl;
                unsigned int ch;cin>>ch;
                if(ch==1){
                    Personne p=creerPersonne(personnes);
                    bool b=rdv.ajouterPersonne(p);
                    if(b==true){
                        cout<<"La personne a ete ajoute"<<endl;
                    }else{alerte();}
                }else if(ch==2){
                    cout<<personnes;
                    unsigned int cdd;cin>>cdd;
                    if(personnes.personneExiste(cdd)){
                        rdv.ajouterPersonne(personnes.getPersonne(cdd));
                        //cout<<carnet.getRendezVous(cd);
                    }
                }else{alerte();}





}
bool ajouterUnePersonneDansUnRendezVous(RendezVousLCH& carnet,PersonneLCH&personnes,RendezVous& rdv){
    if(!(personnes.estVide())){
        cout<<"Voici les Personnes deja existant!"<<endl;
        cout<<personnes;
        cout<<endl<<"       voulez vous ajouter parmi les personnes existant ou creer un nouveau personne?"<<endl;
        cout<<"     1.Ajouter une personne existant!"<<endl;
        cout<<"     2.creer un nouveau personne!"<<endl;
        unsigned int crr;
        cout<<"Votre choix:";cin>>crr;
        while(crr!=1 && crr!=2){
            cout<<"Choix invalide! resssaississez"<<endl;
            cout<<"Votre choix:";cin>>crr;
        }
        if(crr==2){
            cout<<"Creation d'une personne"<<endl;
            Personne p=creerPersonne(personnes);
            cout<<"#################################################################################################################"<<endl;
            bool b=carnet.ajouterPersonne(p,rdv);
            if(b){
                    cout<<"la personne a ete ajpouté"<<endl;
            }else{
                cout<<"ERREUR!! la personne n'a pas ete ajoute";
            }

        }else{
            cout<<personnes;
            cout<<"choississez dans la liste ci dessus avec leure indices!"<<endl;
            //cout<<personnes;
            unsigned int chh;
            cout<<"Indice:";cin>>chh;
            Personne p;
            int ct=0;

            while(!(personnes.personneExiste(chh)) && ct<4){
                cout<<"Valeurs invalide! ressaisissez l'indice"<<endl;
                cout<<"Indice:";cin>>chh;
                ct++;
                if(ct==3){
                        cout<<"ALERTE:ceci est la dernier chance de saisi!!!!"<<endl;
                }
            }


            if(!(personnes.personneExiste(chh))){
               cout<<"Procedure echouee!!"<<endl;
               //afficherMenu(c,personnes);
               return false;
            }

            /*********
            *  recuperrer le personne a tel indice, et ajouter une vecteur des rendezVous rendezVous dedans
            *
            ***********/
        }//else{alerte();}
    }else{
        creerPersonne(personnes);
        ajouterUnePersonneDansUnRendezVous(carnet,personnes,rdv);
    }
    return true;
}

void afficherMenu(RendezVousLCH& carnet,PersonneLCH& personnes){
    bool run=true;
    while(run==true){
        unsigned int choixMenuPrincipal;
        mainNav();
        cout<<"saisissez votre choix:";cin>>choixMenuPrincipal;
        if(choixMenuPrincipal==1){//RENDEZVOUS
            int choixRendezVous;

            afficheChoisRendezVous(carnet);
            cout<<"saisissez votre choix:";cin>>choixRendezVous;
            if(choixRendezVous==1){

                creerRendezVous(carnet,personnes);

            }else{/**__debut__*/
                //if(carnet.head!=nullptr){
                        while(choixRendezVous>7 || choixRendezVous<0){
                            cout<<"Valeur invalide: retaper la valeur";cin>>choixRendezVous;
                        }
                        if(choixRendezVous==2){
                            cout<<"Vous voulez supprimer un rendezVous!";
                            cout<<endl<<"   choisissez l'indice du rendervous shouhaitez parmi la liste ci dessus"<<endl;
                            cout<<carnet;
                            unsigned int vhh;
                            cin>>vhh;
                            if(carnet.rendezVousExiste(vhh)){
                                //cout<<"...............la peronne pour supprimer est trouve!"<<endl;
                                /*Rendez p=personnes.getPersonne(vhh);
                                carnet.supprimerPersonneDansTousLesRendezVous(p);
                                personnes.supprimerPersonne(p,carnet);*/
                                //cout<<".................suppression ressie"<<endl;
                                RendezVous rd=carnet.getRendezVous(vhh);
                                rd.viderRendezVous();
                                carnet.supprimer(rd);// ou carnet.supprimer(carnet.getRendezVous(vhh);)
                            }else{
                                cout<<"Personne n'existe pas"<<endl;
                            }

                        }else if(choixRendezVous==3){
                            cout<<carnet<<endl;
                            cout<<"Dans quel rendezVous voulez vous ajouter ne personne?"<<endl;
                            cout<<"Indice:";unsigned int cd;cin>>cd;
                            if(carnet.rendezVousExiste(cd)){
                                cout<<"RendezVous existe bien!"<<endl;
                                cout<<"selection la personne souhaité!"<<endl;
                                cout<<personnes;
                                unsigned int cdd;cin>>cdd;
                                if(personnes.personneExiste(cdd)){
                                    carnet.getRendezVous(cd).ajouterPersonne(personnes.getPersonne(cdd));

                                }
                            }
                        }
                        else if(choixRendezVous==4){
                            cout<<"On a "<<carnet.getTaille()<<"RendezVous"<<endl;

                        }else if(choixRendezVous==5){
                            //cout<<carnet;
                            cout<<"Choississez l'inice du rendezVous que vous voulez afficher"<<endl;
                            unsigned int chhc;cout<<"  Indice";
                            cin>>chhc;
                            if(carnet.rendezVousExiste(chhc)){
                                vector<Personne>v=carnet.getRendezVous(chhc).getPersonne();
                                for(unsigned int x=0;x<v.size();x++){
                                    cout<<v[x];
                                }
                            }else{
                                alerte();
                                //afficherMenu(carnet,personnes);
                            }

                        }else if(choixRendezVous==6){
                            cout<<carnet;
                        }else if(choixRendezVous==7){
                            cout<<carnet;
                            if(carnet.getTaille()!=0){
                                cout<<carnet;
                                cout<<"Dans quel rendezVous voulez vous supprimzr une personne?"<<endl;
                                unsigned int xs;cout<<"Choix:";cin>>xs;
                                if(carnet.rendezVousExiste(xs)){
                                    ///cout<<personnes;
                                    cout<<"             ############________________LISTE DES MEMBRES_________________________############                "<<endl;
                                    carnet.getRendezVous(xs).afficherPersonnes();
                                    cout<<"quel est la personne que vous voulez supprimer parmi la listes des membres!"<<endl;
                                    cout<<"Choix personne:";unsigned int ok;cin>>ok;
                                    if(personnes.personneExiste(ok)){
                                        if(carnet.getRendezVous(xs).personneExiste(personnes.getPersonne(ok))){
                                            Personne *pe=&(personnes.getPersonne(xs));
                                            cout<<"______La personne ci dessous va etre supprimer dans le rendevous"<<endl;
                                            cout<<*pe;
                                            bool x=carnet.getRendezVous(xs).supprimePersonne(*pe);
                                            cout<<"suppression........................."<<endl;
                                            if(x==true){
                                                cout<<"!!La personne a ete supprime!!"<<endl;
                                            }else{cout<<"_______ERREUR LORS DE LA SUPPRESSION D'UNE PERSONNE DANS LE RENDEZVOUS inconnue________"<<endl;}
                                        }else{
                                            cout<<"######  ________  ERREUR____________LA PERSONNE CHOISIT N'EST PAS DANS LE RENDEZVOUS CHOITI!! #########"<<endl;
                                            afficherMenu(carnet,personnes);
                                        }
                                    }else{
                                        cout<<"_____________ERROR LA PERSONNE N'EXISTE PAS ______________"<<endl;
                                    }

                                }else{alerte();}
                            }else{
                                cout<<"Votre carnet est vide!! il faut d'abord creer un rendezvous pour pouvoir l'utiliser"<<endl;
                                afficherMenu(carnet,personnes);
                            }

                        }else{
                            cout<<"choix invalde";
                        }
               // }/**_____end____**/
            }
        }else if(choixMenuPrincipal==2){//PERSONNES
            afficheChoisPersonne(personnes);int ch;
            cin>>ch;
            if(ch==1){
                creerPersonne(personnes);
            }else if(ch==2){
                supprimerPersonneDansListePersonne(personnes,carnet);
            }else if(ch==3){
                cout<<carnet<<endl;
                cout<<"Dans quel rendezVous voulez vous ajouter ne personne?"<<endl;
                cout<<"Indice:";unsigned int cd;cin>>cd;
                if(carnet.rendezVousExiste(cd)){
                    cout<<"RendezVous existe bien!"<<endl;
                    cout<<"selection la personne souhaité!"<<endl;
                    cout<<personnes;
                    unsigned int cdd;cin>>cdd;
                    if(personnes.personneExiste(cdd)){
                        carnet.getRendezVous(cd).ajouterPersonne(personnes.getPersonne(cdd));
                        //cout<<carnet.getRendezVous(cd);
                    }
                }

            }else if(ch==4){
            cout<<"     Taille:"<<personnes.getTaille()<<endl;
            }else if(ch==5){
                cout<<personnes;

                cout<<"     choix:";unsigned int chj;cin>>chj;
                if(personnes.personneExiste(chj)){
                    Personne p=personnes.getPersonne(chj);
                    carnet.afficherRendezVousDunePersonne(p);
                }else{
                    cout<<"______________ERROR__PERSONNE N'EXISTE PAS_______________"<<endl;
                }
            }else if(ch==6){cout<<personnes;}else{
            }

        }else if(choixMenuPrincipal==3){//QUITTER
            run=false;
        }else if(choixMenuPrincipal==4){
            infoEtAideTexte();
        }else{
            cout<<endl<<endl<<"     ####____ERROR_WRONG_CHOICE______#####"<<endl;
            afficherMenu(carnet,personnes);
        }
    }
    messageQuitter();
}
void printV(const vector<int>&v){
    for(int x=0;x<v.size();x++){
        cout<<"     "<<v[x]<<endl;
    }
    cout<<"SIZE="<<v.size()<<endl;
}
void runV(vector<int>v){
    bool tru=true;
    while (tru){
        cout<<"1.add value in a vector"<<endl;
        cout<<"2.delete value in a vector"<<endl;
        int choice;
        cin>>choice;
        if(choice==1){
            cout<<"number to add"<<endl;int num;
            cin>>num;
            v.push_back(num);
            printV(v);
        }else if(choice==2){
            cout<<"number to delete"<<endl;int num;
            cin>>num;
            for(int x=0;x<v.size();x++){
                if(v[x]==num){
                    v.erase(v.begin()+x);
                    break;
                }
            }
            printV(v);
        }else{
            tru=false;
        }
    }
}
int main(){
    RendezVousLCH lch;
    PersonneLCH p;

    afficherMenu(lch,p);

    cout<<"Hello world"<<endl;
    return 0;
}

