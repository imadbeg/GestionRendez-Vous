#include "RendezVous.h"
unsigned int RendezVous::compteur=0;

RendezVous::RendezVous(const Date& db,const Date& fn,string nm):debut{db},fin{fn},nom{nm}{
    ID=++compteur;
}
ostream & operator << (ostream &out, const RendezVous &c){
    out<<"RendezVous ID:"<<c.getID()<<endl;
    out<<"Nom du rendezVous"<<c.getName()<<endl;
    out<<"      Debut   "<<c.getDebut()<<endl;
    out<<"      Fin    "<<c.getFin()<<endl;
    out<<"Nb Participants:"<<c.getTaille()<<endl<<endl<<endl;
    return out;
}
bool RendezVous::personneEstPresent(const Personne& p)const{
    for(int x=0;x<listePersonnes.size();x++){
        if(p==listePersonnes[x]){return true;}
    }
    return false;
}
bool RendezVous::personneExiste(const Personne& c)const{
    for(unsigned int x=0;x<listePersonnes.size();x++){
        if(c==listePersonnes[x]){
            return true;
        }
    }
    return false;
}
unsigned int RendezVous::getIndice(const Personne& p)const{
    for(int x=0;x<listePersonnes.size();x++){
        if(p==listePersonnes[x]){
            cout<<"Indice found"<<endl;
            return x;
        }
    }
}

bool RendezVous::supprimePersonne(const Personne& p){
    if(!personneExiste(p)){
        cout<<"la pers p";
            cout<<p;
        cout<<"la personne n'existe pas dans ce rendezvous"<<endl;
        return false;
    }
    for(int x=0;x<listePersonnes.size();x++){
        if(listePersonnes[x]==p){
            listePersonnes.erase(listePersonnes.begin()+x);
            return true;
        }
    }
    return false;
}
void RendezVous::afficherPersonnes()const{
    if(listePersonnes.size()==0){cout<<"La liste est vide!"<<endl;}
    for(unsigned int x=0;x<listePersonnes.size();x++){
        //cout<<"Indice="<<x<<endl<<listePersonnes[x];cout<<"indice again"<<endl;
    }cout<<"end of the list"<<endl;
}
bool RendezVous::operator==(const RendezVous& rdv){
    return (debut==rdv.getDebut() && fin==rdv.getFin()&& listePersonnes==rdv.getPersonne());
}
bool RendezVous::ajouterPersonne(const Personne& p){
    if(!personneEstPresent(p)){
        listePersonnes.push_back(p);
        cout<<"                     la Personne: "<<endl;
        cout<<"                     "<<p<<endl;
        cout<<"a ete ejoute dans le rendezVous "<<endl;
        cout<<"                     "<<(*this)<<endl;
        return true;
    }
    cout<<endl<<"La personne n'a pas ete ajoutée"<<endl;
    return false;
}
