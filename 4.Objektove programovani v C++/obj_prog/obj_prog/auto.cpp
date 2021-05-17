//
//  auta.cpp
//  obj_prog
//
//  Created by kuba on 04.05.2021.
//

#include "database.h"

Auto::Auto(){
    znacka="";
    rok=0;
    hp=0.0;
}

Auto::Auto(string zn){
    znacka=zn;
    rok=0;
    hp=0.0;
}

Auto::Auto(string zn,int r){
    znacka=zn;
    rok=r;
    hp=0.0;
}

Auto::Auto(string zn,int r,float h){
    znacka=zn;
    rok=r;
    hp=h;
}

ostream &operator << (ostream &out, Auto x){
    out<< x.znacka<<setw(5)<<x.rok<<setw(5)<<x.hp<<endl;
    return out;
}

istream &operator >> (istream &in, Auto &x){
    cout<<"Zadej znacku auta:";
    in>>x.znacka;
    cin.ignore();
    cout<<"Zadej rok:";
    in>>x.rok;
    cout<<"Zadej vykon:";
    in>>x.hp;
    return in;
}


void menu(){
    cout << endl << "0 -- konec" << endl;
    cout << "1 -- Uloz do souboru" << endl;
    cout << "2 -- Nacti ze souboru" << endl;
    cout << "3 -- Nacti auto" << endl;
    cout << "4 -- Vypis auta" << endl;
    cout << "5 -- Hledac aut" << endl;
    cout << "6 -- Serazeni aut" << endl;
    cout << "7 -- Vymazani auta" << endl;
    cout << "8 -- Zmena auta" << endl;
    cout << "9 -- Nejslabsi auta" << endl;
}
