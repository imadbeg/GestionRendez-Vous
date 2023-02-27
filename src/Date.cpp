#include "Date.h"

Date::Date(unsigned int ye,unsigned int mo,unsigned int da,unsigned int ho,unsigned int mi):d_annee{ye},d_mois{mo},d_jour{da},d_heure{ho},d_minute{mi}{}
bool Date::Date::operator<(const Date& d)const{
    if(
        ((*this).getYear()<d.getYear())||
        ((*this).getYear()==d.getYear() && (*this).getMonth()<d.getMonth())||
        ((*this).getYear()==d.getYear() && (*this).getMonth()==d.getMonth()&& (*this).getDay()<d.getDay())||
        ((*this).getYear()==d.getYear() && (*this).getMonth()==d.getMonth()&& (*this).getDay()==d.getDay() && (*this).getHour()<d.getHour())||
    ((*this).getYear()==d.getYear() && (*this).getMonth()==d.getMonth()&& (*this).getDay()==d.getDay() && (*this).getHour()==d.getHour() && (*this).getMinutes()<d.getMinutes())
       ){
        return true;
    }else {
        return false;
    }
    return true;
}
bool Date::Date::operator>(const Date& d)const{
    return (*this)<d ? false:true;
}
bool Date::operator==(const Date& d)const{
    return ((*this).getYear()==d.getYear() && (*this).getMonth()==d.getMonth()&& (*this).getDay()==d.getDay() && (*this).getHour()==d.getHour() && (*this).getMinutes()==d.getMinutes()) ? true : false;
}
bool Date::operator!=(const Date& d)const{
    return (*this)==d? false:true;
}
ostream & operator << (ostream &out, const Date &c){
    out<<"Annee:"<<c.getYear()<<"       Mois:"<<c.getMonth()<<"      Jour:"<<c.getDay()<<"        Heure:"<<c.getHour()<<"h"<<c.getMinutes()<<endl;
    return out;
}
bool Date::operator>=(const Date& d)const{
    return (*this)==d || (*this)>d;
}
bool Date::operator<=(const Date&d)const{
    return (*this)==d || (*this)<d;
}

