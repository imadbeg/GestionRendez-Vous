#ifndef RENDEZVOUSLCH_H
#define RENDEZVOUSLCH_H
#include"RendezVous.h"
#include<iostream>
#include"PersonneLCH.h"
class PersonneLCH;
using namespace std;

class RendezVousLCH
{
    private:
        class RendezVousCH{
        public:
            RendezVousCH(const RendezVous& data,RendezVousCH* n=nullptr);
            friend class RendezVousLCH;

        friend ostream& operator<<(ostream& ost,const RendezVousLCH& c);
        friend void afficherMenu(RendezVousLCH& carnet,PersonneLCH& personnes);
        private:
            RendezVous data;
            RendezVousCH* next;
        };
        RendezVousCH* head;
    public:
        RendezVousLCH();
        ~RendezVousLCH();
        bool supprimer(unsigned int i);
        bool supprimer(const RendezVous&);
        void afficher()const;
        bool operator==(const RendezVousLCH &lc) const;
        bool addRendezVous(const RendezVous& rdv);
        bool personneExiste(const Personne& p)const;
        bool rendezVousExiste(const RendezVous& )const;
        bool rendezVousExiste(unsigned int  )const;
        unsigned int getTaille()const;

        bool estDisponible(const Personne& p, const RendezVous&rv)const;
        RendezVous& getRendezVous(unsigned int indice)const;
        void afficherRendezVousDunePersonne(const Personne&);
        bool ajouterPersonne(const Personne& p,RendezVous&rv)const;
        void supprimerPersonneDansTousLesRendezVous(const Personne& p);

        friend ostream& operator<<(ostream& ost,const RendezVousLCH& c);
        /***fonctions ddans le main**/
        friend void afficheChoisRendezVous(const RendezVousLCH& c);


};


ostream& operator<<(ostream& os, const RendezVousLCH& c);
#endif // RENDEZVOUSLCH_H
