#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H
#include"Date.h"
#include"Personne.h"

class RendezVous{
public:
    RendezVous(const Date& db,const Date& fn,string nom="NoName");
    bool operator==(const RendezVous&);
    inline unsigned int getTaille()const{return listePersonnes.size();}
    inline Date getDebut()const{return debut;}
    inline Date getFin()const{return fin;}
    inline unsigned int getID()const{return ID;}
    inline string getName()const{return nom;}
    void afficherPersonnes()const;
    unsigned int getIndice(const Personne& p)const;
    bool ajouterPersonne(const Personne& p);
    bool supprimePersonne(const Personne& p);
    inline void viderRendezVous(){listePersonnes.resize(0);}
    bool personneExiste(const Personne& p)const;
    inline std::vector<Personne> getPersonne()const{return listePersonnes;}
    friend ostream & operator << (ostream &out, const RendezVous &c);
    bool personneEstPresent(const Personne& p)const;
    static unsigned int compteur;
private:
    Date debut;
    Date fin;
    unsigned int ID;
    string nom;
    std::vector<Personne>listePersonnes;
};
ostream & operator << (ostream &out, const RendezVous &c);
#endif // RENDEZVOUS_H
