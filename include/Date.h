#ifndef DATE_H
#define DATE_H
#include <iostream>

using namespace std;
class Date
{
    unsigned int d_annee,d_mois,d_jour,d_heure,d_minute;

        public:
            Date(unsigned int d_annee=1900,unsigned int d_mois=1,unsigned int d_jour=1,unsigned int d_heure=12,unsigned int d_minute=59);
            bool operator<(const Date&)const;
            bool operator>(const Date&)const;
            bool operator==(const Date&)const;
            bool operator!=(const Date&)const;
            bool operator>=(const Date&)const;
            bool operator<=(const Date&)const;
             unsigned int getDay()const{return d_jour;}
             unsigned int getMonth()const{return d_mois;}
             unsigned int getYear()const{return d_annee;}
             unsigned int getHour()const{return d_heure;}
             unsigned int getMinutes()const{return d_minute;}

             void setjour(unsigned int val){d_jour=val;}
             void setMonth(unsigned int val){d_mois=val;}
             void setYear(unsigned int val){d_annee=val;}
             void setHour(unsigned int val){d_heure=val;}
             void setMinutes(unsigned int val){d_minute=val;}
            friend ostream & operator << (ostream &out, const Date &c);
};
ostream & operator << (ostream &out, const Date &c);
#endif // DATE_H
