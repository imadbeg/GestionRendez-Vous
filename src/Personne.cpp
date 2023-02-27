#include "Personne.h"
unsigned int Personne::compteur=0;

Personne::Personne(const string& nm,const string sn,const string tel,const string em):name{nm},surName{sn},telephone{tel},email{em}{ID=++compteur;}
ostream& operator<<(ostream& os, const Personne& c) {

    os<<"   ID:"<<c.getID()<<endl;
    os<<"       Name:"<<c.getName()<<endl;
    os<<"       Prenom:"<<c.getPrenom()<<endl;
    os<<"       Telephone:"<<c.getTelephone()<<endl;
    os<<"       Email:"<<c.getEmail()<<endl<<endl<<endl;

    return os ;
}
bool Personne::operator==(const Personne& p)const{
    return (name==p.getName() && surName==p.getPrenom() && telephone==p.getTelephone() && email==p.getEmail());
}
