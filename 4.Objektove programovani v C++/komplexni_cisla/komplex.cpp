//
//  komplex.cpp
//  komplexni_cisla
//
//  Created by kuba on 08.02.2021.
//

#include "db.h"

Komplex::Komplex(){
    real=0;
    imag=0;
}

Komplex::Komplex(float re, float im){
    real=re;
    imag=im;
}

ostream &operator<<(ostream &out, Komplex x){
    if(x.imag>0) cout<<x.real<<'+'<<x.imag<<'i';
    else cout<<x.real<<x.imag<<'i';
    return out;
}

istream &operator>>(istream &in, Komplex &x){
    cout<<"Zadej realnou cast:"<<endl;
    in>>x.real;
    cout<<"Zadej imaginarni cast:"<<endl;
    in>>x.imag;
    return in;
}

Komplex Komplex::operator+(Komplex x){
    Komplex y;
    y.real=this->real+x.real;
    y.imag=this->imag+x.imag;
    return y;
}

Komplex Komplex::operator-(Komplex x){
    Komplex y;
    y.real=this->real-x.real;
    y.imag=this->imag-x.imag;
    return y;
}

Komplex Komplex::operator*(Komplex x){
    Komplex y;
    y.real=(this->real*x.real)-(this->imag*x.imag);
    y.imag=(this->imag*x.real)+(this->real*x.imag);
    return y;
}

Komplex Komplex::operator/(Komplex x){
    float del=(x.real*x.real) + (x.imag*x.imag);
    Komplex y;
    y.real=((this->real*x.real)+(this->imag*x.imag)) / del;
    y.imag=((this->imag*x.real)-(this->real*x.imag)) / del;
    return y;
}

float Komplex::abs(){
    float z=sqrt(pow(this->real,2)+pow(this->imag,2));
    return z;
}

bool Komplex::rovnost(Komplex x){
    if(this->real==x.real && this->imag==x.imag) return true;
    else return false;
}

void Komplex::reverse(){
    this->real=-this->real;
    this->imag=-this->imag;
}
void Komplex::sdruzene(){
    this->imag=-this->imag;
}

void menu(){
    cout << endl << "0 -- konec" << endl;
    cout << "1 -- Nacti cislo" << endl;
    cout << "2 -- Vypis cislo" << endl;
    cout << "3 -- Scitani" << endl;
    cout << "4 -- Odcitani" << endl;
    cout << "5 -- Nasobeni" << endl;
    cout << "6 -- Deleni" << endl;
    cout << "7 -- Absolutni hodnota" << endl;
    cout << "8 -- ROVNOST" << endl;
    cout << "9 -- OPACNE" << endl;
    cout << "10 -- SDRUZENE" << endl;
}
