#include "RendezVousLCH.h"

RendezVousLCH::RendezVousLCH():head{nullptr}{}
RendezVousLCH::RendezVousCH::RendezVousCH(const RendezVous& data,RendezVousCH* n):data{data},next{n}{}
RendezVousLCH::~RendezVousLCH(){
	RendezVousCH *c=head;
	while(c)
	{
		RendezVousCH *tmp=c->next;
		delete c;
		c=tmp;
	}
}
bool RendezVousLCH::estDisponible(const Personne& p, const RendezVous&rv)const{
    RendezVousCH*cr=head;
    while(cr){
        unsigned int taille=(cr->data.getPersonne()).size();
        for(unsigned int  i=0;i<taille;i++){
            if(p==cr->data.getPersonne()[i]){
                 if((cr->data.getDebut()<rv.getDebut()&& cr->data.getFin()>rv.getDebut())||
                       (cr->data.getFin()<rv.getFin() && cr->data.getFin()>rv.getFin()))
                {return false;}
            }
        }
    }
    return true;
}
bool RendezVousLCH::ajouterPersonne(const Personne& p,RendezVous&rv)const{
    RendezVousCH* cr=head;
    while(cr){
        if(( !cr->data.personneExiste(p))&&(estDisponible(p,(rv))) ){
             cr->data.getPersonne().push_back(p);
            return true;
        }
        cr=cr->next;
    }
    cout<<"personne indisponible pour ce RendezVous"<<endl;
    return false;
}
bool RendezVousLCH::supprimer(const RendezVous& rv){

	if(head==nullptr){
        return false;
	}
	if(head->data==rv){
        RendezVousCH*assup=head;
        head=head->next;
        delete assup;
        cout<<"rendezvous supprimes!!"<<endl;
        return true;
	}
    RendezVousCH *c=head,*precc=nullptr;
    while(c&& !(c->data==rv)){
        precc=c;
        c=c->next;
	}
    if(c!=nullptr&&c->data==rv){

        precc->next=c->next;
        delete c;
        cout<<"rendezvous supprimes!!"<<endl;
        return true;
	}
	cout<<"rendezvous n'a pas ete supprimes!!"<<endl;
    return false;
}
bool RendezVousLCH::addRendezVous(const RendezVous& rdv) {
    RendezVousCH*n= new RendezVousCH(rdv);
	if(head==nullptr){
		head=n;return true;
	}
    if(head->data.getDebut()>rdv.getDebut()){
        n->next=head;
        head=n;
        return true;
    }
	RendezVousCH*c=head,*precc=nullptr;
	while(c!=nullptr&&c->data.getDebut()<rdv.getDebut()){
		precc=c;
		c=c->next;
	}
	precc->next=n;
	n->next=c;
	return true;
}
bool RendezVousLCH::personneExiste(const Personne& p)const{
    RendezVousCH*c=head;
    while(c!=nullptr){
        if(c->data.personneExiste(p)) {
            return true;
        }
        else
        c=c->next;
    }
    return false;
}
unsigned int RendezVousLCH::getTaille()const{
    RendezVousCH* crt = head ;
    unsigned int taille=0;
    while(crt) {
        taille++;
        crt = crt->next ;
    }
    return taille ;
}
void RendezVousLCH::afficher() const{
    RendezVousCH* crt = head ;
    if(head==nullptr){
        cout<<"it is empty"<<endl;
    }
    while(crt != nullptr) {
        cout<<crt->data;
        crt = crt->next ;
    }
    cout<<"SIZE="<<this->getTaille()<<endl<<endl;
}
bool RendezVousLCH::operator==(const RendezVousLCH &lc) const{
    if (this==&lc)
        return true;

    RendezVousCH *c1=head,*c2=lc.head;
    while (c1!=nullptr && c2!=nullptr &&
           c1->data.getDebut().getYear()==c2->data.getDebut().getYear()&&
           c1->data.getDebut().getMonth()==c2->data.getDebut().getMonth()&&
           c1->data.getDebut().getHour()==c2->data.getDebut().getHour() &&
           c1->data.getDebut().getMinutes()==c2->data.getDebut().getMinutes()
           )
    {
        c1=c1->next;
        c2=c2->next;
    }
    return (c1==nullptr && c2==nullptr);
}
bool RendezVousLCH::rendezVousExiste(const RendezVous& rdv)const{
    RendezVousCH*cr=head;
    while(cr){
            if(cr->data==rdv){return true;}
        cr=cr->next;
    }
    return false;
}
bool RendezVousLCH::rendezVousExiste(unsigned int rdv)const{
    RendezVousCH*cr=head;
    while(cr){
        if(cr->data.getID()==rdv){
            cout<<"RendezVous trouve avec son indice (ID)"<<endl;
                return true;}
        cr=cr->next;
    }
    cout<<"RendezVous n'existe avec scet indice (ID)"<<endl;
    return false;
}
void RendezVousLCH::supprimerPersonneDansTousLesRendezVous(const Personne& p){
    if(personneExiste(p)){
        RendezVousCH*cr=head;
        while(cr){
            if(cr->data.personneEstPresent(p)){
                cr->data.supprimePersonne(p);
            }
        }
        cr=cr->next;
    }
}
ostream& operator<<(ostream& ost,const RendezVousLCH& c){
    RendezVousLCH::RendezVousCH* cr=c.head;
    while(cr){
        ost<<cr->data;
        cr=cr->next;
    }ost<<endl<<"SIZE="<<c.getTaille()<<endl;
    return ost;
}
RendezVous& RendezVousLCH::getRendezVous(unsigned int indice)const{
    RendezVousCH*cr=head;
    while(cr){
        if(cr->data.getID()==indice){return cr->data;}
        cr=cr->next;
    }
}

void RendezVousLCH::afficherRendezVousDunePersonne(const Personne& p){
    if(personneExiste(p)){
        cout<<"la personne a des rendezVous"<<endl;
        RendezVousCH*cr=head;
        while(cr){
            if(cr->data.personneExiste(p)){
                cout<<p;
            }
            cr=cr->next;
        }
    }else{cout<<"la personne n'est dans aucune rendezVous"<<endl;}
}
