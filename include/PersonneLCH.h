#ifndef PERSONNELCH_H
#define PERSONNELCH_H
#include"Personne.h"
#include"RendezVousLCH.h"
class RendezVousLCH;
class PersonneLCH
{

    private:


    class PersonneCH{
    public:
        PersonneCH(const Personne& p,PersonneCH* n=nullptr);
        friend ostream& operator<<(ostream& ost,const PersonneLCH& c);
        void afficherPersonneCH()const;
        friend class PersonneLCH;
    private:
        Personne data;
        PersonneCH*next;
    };
    PersonneCH* head;
public:
    PersonneLCH();
    ~PersonneLCH();

    bool operator==(const PersonneLCH &lc) const;
    unsigned int getTaille()const;
    friend ostream& operator<<(ostream& ost,const PersonneLCH& c);
    inline bool estVide()const{return head==nullptr;}
    bool  ajouterPersonne(const Personne& pers);
    bool personneExiste(const Personne& p)const;
    bool personneExiste(unsigned int indice)const;
    bool supprimerPersonne(const Personne& p,const RendezVousLCH& lr);
    bool addPersonne(const Personne& pr);
    Personne& getPersonne(unsigned int indice);

    friend ostream & operator << (ostream &out, const PersonneLCH &c);
    friend void afficheChoisPersonne(const PersonneLCH& c);

};
ostream & operator << (ostream &out, const PersonneLCH &c);
#endif // PERSONNELCH_H
