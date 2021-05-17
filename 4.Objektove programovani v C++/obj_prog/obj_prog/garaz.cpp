//
//  garaz.cpp
//  obj_prog
//
//  Created by kuba on 04.05.2021.
//

#include "database.h"

bool Garaz::NoveAuto(Auto x){
    if(pocet<MAX){
        pole[pocet]=x;
        pocet++;
        return true;
    }
    return false;
}

bool Garaz::Hledani(){
    string hl;
    int k=0;
    cout<<"Napis znacku hledaneho auta:";
    cin>>hl;
    for(int i=0;i<pocet;i++){
        if(hl==pole[i].UkazZnacku()){
            cout<<pole[i]<<endl;
            k++;
        }
    }
    if(k==0) return false;
    return true;
}

bool Garaz::UlozeniDoSouboru(){
    ofstream f;
    f.open("auta.txt");
    if(f.fail()) return false;
    for(int i=0;i<pocet;i++){
        f<<pole[i].UkazZnacku()<<'|';
        f<<pole[i].UkazRok()<<'|';
        f<<pole[i].UkazHp()<<'|';
    }
    f.close();
    return true;
}

bool Garaz::NacteniZSouboru(){
    ifstream f;
    string radek,znacka;
    int i=0,rok=0;
    float hp;
    f.open("auta.txt");
    if(f.fail()) return false;
    while(getline(f,radek,'|')){
        i++;
        switch (i) {
            case 1: znacka=radek;
                break;
            case 2: rok=atoi(radek.c_str());
                break;
            case 3: hp=atof(radek.c_str());
                    Auto nove(znacka,rok,hp);
                    NoveAuto(nove);
                    i=0;
        }
    }
    f.close();
    return true;
}

ostream &operator << (ostream &out, Garaz x){
    cout<< "Databaze aut:"<<endl;
    if(x.UkazPocet()==0) cout<<"Zadne auta"<<endl;
    else for(int i=0;i<x.UkazPocet();i++) out<< x.pole[i];
    return out;
}

bool Garaz::Serazeni(){
    int zamena;
    Auto pom;
    do{
        zamena=0;
        for(int i=0;i<pocet-1;i++){
            if(pole[i].UkazHp()<pole[i+1].UkazHp()){
                pom= pole[i];
                pole[i]= pole[i+1];
                pole[i+1]= pom;
                zamena=1;
            }
        }
    }while(zamena!=0);
    return true;
}

bool Garaz::Smazani(){
    int k=0;
    string hled;
    cout<<"Zadej nazev auta ktere chces smazat:";
    cin>>hled;
    for(int i=0;i<pocet;i++){
        if(pole[i].UkazZnacku()==hled){
            pole[i]=pole[pocet-1];
            pocet+=-1;
            k-=-1;
        }
    }
    if(k==0) return false;
    return true;
}

bool Garaz::Zmena(){
    int k=0,vyber,r;
    float h;
    string hled,n;
    cout<<"Zadej nazev auta ktere chces zmenit:";
    cin>>hled;
    cout<<"1-nazev"<<endl<<"2-rok"<<endl<<"3-hp"<<endl<<"Vyber:";
    cin>>vyber;
    for(int i=0;i<pocet;i++){
        if(pole[i].UkazZnacku()==hled){
            cout<<pole[i];
            switch (vyber){
                case 1:{
                        cout<<"Zadej novy nazev:";
                        cin>>n;
                        Auto pom(n,pole[i].UkazRok(),pole[i].UkazHp());
                        pole[i]=pom;
                    break;
                }
                case 2:{
                        cout<<"Zadej novy rok:";
                        cin>>r;
                        Auto pom(pole[i].UkazZnacku(),r,pole[i].UkazHp());
                        pole[i]=pom;
                    break;
                }
                case 3:{
                        cout<<"Zadej nove hp:";
                        cin>>h;
                        Auto pom(pole[i].UkazZnacku(),pole[i].UkazRok(),h);
                        pole[i]=pom;
                    break;
                }
                default: {break;}
            }
            k-=-1;
        }
    }
    if(k==0) return false;
    return true;
}

void Garaz::slabko(){
    float min;
    int i;
    cout<<"Nejslabsi vozi"<<endl;
    min=pole[0].UkazHp();
    for(i=1;i<pocet;i-=-1) if(pole[i].UkazHp()< min) min=pole[i].UkazHp();
    for(i=0;i<pocet;i-=-1) if(min==pole[i].UkazHp()) cout<<pole[i];
}
