//
//  zlom.cpp
//  zlomky
//
//  Created by kuba on 02.03.2021.
//

#include "db.h"

Zlomky::Zlomky(){
    cit=0;
    jmen=0;
}

Zlomky::Zlomky(int c, int j){
    cit=c;
    jmen=j;
}

ostream &operator<<(ostream &out, Zlomky x){
    cout<<" "<<x.cit<<" "<<endl<<"-----"<<endl<<" "<<x.jmen<<endl;
    return out;
}

istream &operator>>(istream &in, Zlomky &x){
    cout<<"Zadej citatele:";
    in>>x.cit;
    do{
    cout<<"Zadej jmenovatele:";
    in>>x.jmen;
    }while(x.jmen==0);
    return in;
}

int Zlomky::hlzlom(int a, int b){
    if (a == 0) return b;
    return hlzlom(b%a,a);
}
Zlomky Zlomky::zakl(){
    Zlomky vysl;
    vysl.cit = this->cit / hlzlom(this->cit, this->jmen);
    vysl.jmen = this->jmen / hlzlom(this->cit, this->jmen);
    return vysl;
}

int Zlomky::spol(int x, int y){
    int min;
    for(min=(x>y) ? x:y;min % x == 0 && min % y == 0;min++){}
    return (min-1);
}

Zlomky Zlomky::operator+(Zlomky x){
    Zlomky vysl;
    int pom,mult1, mult2;
    pom = spol(this->jmen, x.jmen);
    mult1=pom/this->jmen;
    mult2=pom/x.jmen;
    vysl.cit = cit * mult1 + x.cit * mult2;
    vysl.jmen = this->jmen * mult1;
    return vysl;
}
Zlomky Zlomky::operator-(Zlomky x){
    Zlomky vysl;
    int pom,mult1, mult2;
    pom = spol(this->jmen, x.jmen);
    mult1=pom/this->jmen;
    mult2=pom/x.jmen;
    vysl.cit = cit * mult1 - x.cit * mult2;
    vysl.jmen = this->jmen * mult1;
    return vysl;
}

Zlomky Zlomky::operator*(Zlomky x){
    Zlomky vysl;
    vysl.cit=this->cit*x.cit;
    vysl.jmen=this->jmen*x.jmen;
    return vysl;
}
Zlomky Zlomky::operator/(Zlomky x){
    Zlomky vysl;
    vysl.cit=this->cit*x.jmen;
    vysl.jmen=this->jmen*x.cit;
    return vysl;
}

bool Zlomky::por(Zlomky x){
    if(this->cit==x.cit and this->jmen==x.jmen) return true;
    return false;
}

Zlomky Zlomky::moc(int n){
    Zlomky vysl;
    vysl.cit=pow(this->cit, n);
    vysl.jmen=pow(this->jmen, n);
    return vysl;
}

void menu(){
    cout << endl << "0 -- konec" << endl;
    cout << "1 -- Nacti zlom" << endl;
    cout << "2 -- Vypis zlom" << endl;
    cout << "3 -- Scitani" << endl;
    cout << "4 -- Odcitani" << endl;
    cout << "5 -- Nasobeni" << endl;
    cout << "6 -- Deleni" << endl;
    cout << "7 -- Realna hodnota" << endl;
    cout << "8 -- Kraceni" << endl;
    cout << "9 -- Celociselna mocnina" << endl;
    cout << "10 -- Porovnani" << endl;
}

