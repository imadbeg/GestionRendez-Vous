#ifndef PERSONNE_H
#define PERSONNE_H

#include <iostream>
#include<vector>
using namespace std;
class Personne{
    string name;
    string surName;
    string telephone;
    string email;
    unsigned int ID;
    static unsigned int compteur;
public:
    Personne(const string& nm="NoName",const string sn="NoSurname",const string tl="NoTel",const string em="NoEmail");
    inline void setNom(const std::string& nm){name=nm;}
    inline void setPrenom(const std::string& pn){surName=pn;}
    inline void setTelephone(const std::string& tl){telephone=tl;}
    inline void setEmail(const std::string& em){email=em;}

    std::string getName()const{return name;}
     unsigned int getID()const{return ID;}
     std::string getPrenom()const{return surName;}
     std::string getTelephone()const{return telephone;}
     std::string getEmail()const{return email;}
    friend ostream & operator << (ostream &out, const Personne &c);
    bool operator==(const Personne& p)const;

};

ostream & operator << (ostream &out, const Personne &c);


#endif // PERSONNE_H








