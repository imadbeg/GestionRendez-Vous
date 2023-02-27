#include "PersonneLCH.h"

PersonneLCH::PersonneLCH():head{nullptr}
{}
PersonneLCH::PersonneCH::PersonneCH(const Personne& p,PersonneCH* n):data{p},next{n}{}
PersonneLCH::~PersonneLCH(){
    PersonneCH *c=head;
    while(c){
        PersonneCH*tmp=c->next;
        delete c;
        c=tmp;
    }
}
bool PersonneLCH:: addPersonne(const Personne& pers){
    PersonneCH*n=new PersonneCH(pers);
    if(personneExiste(n->data)){
        cout<<"la personne existe deja";
            return false;
    }
    if(head==nullptr){
       head=n;
       return true;
    }
    /*n->next=head;
    head=n;*/
    PersonneCH *cr=head;
    if(cr){
        while(cr->next){
            cr=cr->next;
        }
        cr->next=n;
    }

    return true;

}
bool PersonneLCH::personneExiste(unsigned int indice)const{
    PersonneCH*cr=head;
    while(cr){
            if(indice==cr->data.getID()){return true;}
        cr=cr->next;
    }
    return false;
}
bool PersonneLCH::personneExiste(const Personne &p)const{
    PersonneCH* cr=head;
    while(cr){
        if(p==cr->data){
            return true;
        }
        cr=cr->next;
    }
    return false;
}
ostream & operator << (ostream &out, const PersonneLCH &c){
    PersonneLCH::PersonneCH * crt = c.head ;

    while(crt != nullptr) {
         out<<crt->data;
        crt = crt->next ;
    }out<<endl<<"SIZE="<<c.getTaille()<<endl<<endl;
    return out;
}
unsigned int PersonneLCH::getTaille()const{
    int x=0;
    PersonneCH* cr=head;
    while(cr){
        x++;
        cr=cr->next;
    }
    return x;
}

bool PersonneLCH:: supprimerPersonne(const Personne& p,const RendezVousLCH&lr){
    if(head!=nullptr){
        if(lr.personneExiste(p)){
            cout<<"la personne ne peut pas etre supprimer car il a un rendezous"<<endl;
            return false;
        }
        else{
            PersonneCH*c=head,*as=nullptr,*precc=nullptr;
            if(p==c->data){
                as=head;
                head=head->next;
                delete as;
                return true;
            }
            while(c!=nullptr&& !(c->data==p)){
                precc=c;
                c=c->next;
            }
            if(c!=nullptr&&c->data==p){
                precc->next=c->next;
                delete c;
                return true;
            }
        }
    }
    return false;
}
Personne& PersonneLCH::getPersonne(unsigned int indice){
    PersonneCH* cr=head;
    while(cr){
            if(cr->data.getID()==indice){return cr->data;}
        cr=cr->next;
    }
}
