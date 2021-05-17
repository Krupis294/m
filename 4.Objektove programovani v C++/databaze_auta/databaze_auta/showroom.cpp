//
//  showroom.cpp
//  databaze_auta
//
//  Created by kuba on 07.02.2021.
//

#include "database.h"

bool Showroom:: SaveToFile(){
    ofstream file;
    file.open("data.txt");
    if(file.fail()) return false;
    for(int i=0;i<count;i++){
        file<<array[i].ShowBrand()<<'|';
        file<<array[i].ShowYear()<<'|';
        file<<array[i].ShowHp()<<'|';
    }
    file.close();
    return true;
}

bool Showroom::ImportFromFile(){
    ifstream file;
    string row,brand;
    float hp;
    int i=0,year=0;
    file.open("data.txt");
    if(file.fail()) return false;
    while(getline(file,row,'|')){
        i++;
        switch(i){
            case 1: brand=row;
                break;
            case 2: year=atoi(row.c_str());
                break;
            case 3: hp=atof(row.c_str());
                    Car nove(brand,year,hp);
                    NewCar(nove);
                    i=0;
                break;
        }
    }
    file.close();
    return true;
}

bool Showroom::NewCar(Car x){
    if(count<MAX){
        array[count]=x;
        count++;
        return true;
    }
    return false;
}

ostream &operator << (ostream &out, Showroom x){
    cout << "Databaze aut:" << endl;
    if(x.ShowCount()==0) cout<<"Prazna databaze"<<endl;
    else for(int i=0;i<x.ShowCount();i++) out << x.array[i];
    return out;
}

bool Showroom::Finder(){
    int choice,y,k=0;
    string b;
    float h;
    do{
        cout<<"0-nic"<<endl<<"1-Znacka"<<endl<<"2-Rok vyroby"<<endl<<"3-HP"<<endl;
        cout<<"Podle ceho chces hledat:";
        cin>>choice;
        switch (choice) {
            case 1: cout<<"Zadej model vozidla, ktere chces hledat:";
                    cin.ignore();
                    getline(cin,b);
                    for(int i=0;i<count;i++){
                        if(b==array[i].ShowBrand()){
                            cout<<array[i]<<endl;
                            k++;
                        }
                    }
                break;
            case 2: cout<<"Zadej rok vyroby vozidla, ktere chces hledat:";
                    cin>>y;
                    for(int i=0;i<count;i++){
                        if(y==array[i].ShowYear()){
                            cout<<array[i]<<endl;
                            k++;
                        }
                    }
                break;
            case 3: cout<<"Zadej HP vozidla, ktere chces hledat:";
                    cin>>h;
                    for(int i=0;i<count;i++){
                        if(h==array[i].ShowHp()){
                            cout<<array[i]<<endl;
                            k++;
                        }
                    }
                break;
            case 0: break;
            default: cout<<"Dalsi moznosti nevedeme"<<endl;
                break;
        }
        if(k==0) return false;
    }while(choice!=0);
    return true;
}

bool Showroom::Sort(){
    Car pom;
    int change;
    do{
        change=0;
        for(int i=0;i<count-1;i++){
            if(array[i].ShowHp()<array[i+1].ShowHp()){
                pom = array[i];
                array[i] = array[i+1];
                array[i+1] = pom;
                change=1;
            }
        }
    }while(change==1);
    return true;
}

bool Showroom::Delete(){
    int pom = 0;
    Car k;
    string hl;
    int l=0;
    cout<< "Zadej model auta ktere chces smazat:";
    cin.ignore();
    getline(cin,hl);
    for (int i=0; i<count; i++) if(hl==array[i].ShowBrand()){
            pom=i;
            l++;
        }
    if(l==0) return false;
    if(count==1) count=0;
    else{
        for(int i=0;i<count;i++){
            if(i==pom){
                k=array[count-1];
                array[count-1]=array[i];
                array[i]=k;
            }
        }
        count--;
    }
    return true;
}

bool Showroom::Change(){
    int k=0,choice,year;
    float hp;
    string find,brand;
    cout<< "Zadej model auta pro editaci:";
    cin.ignore();
    getline(cin,find);
    cout<< "1-Model auta"<<endl << "2-Rok vyroby"<<endl<<"3-HP"<<endl <<"Editace:";
    cin>>choice;
    for(int i=0; i<count; i++) {
        if(find==array[i].ShowBrand()){
            switch (choice){
                case 1:{
                        cout<< array[i];
                        cout<<"Zadej novy model auta:";
                        cin.ignore();
                        getline(cin, brand);
                        Car x(brand,array[i].ShowYear(),array[i].ShowHp());
                        array[i]=x;
                    break;
                    }
                case 2:{
                        cout<< array[i];
                        cout<<"Zadej novy rok vyroby:";
                        cin>>year;
                        Car y(array[i].ShowBrand(),year,array[i].ShowHp());
                        array[i]=y;
                    break;
                    }
                case 3:{
                        cout<< array[i];
                        cout<<"Zadej nove HP:";
                        cin>>hp;
                        Car z(array[i].ShowBrand(),array[i].ShowYear(),hp);
                        array[i]=z;
                    break;
                    }
                default: cout<<"Tato moznost zde neni"<<endl;
                    break;
            }
            k++;
        }
    }
    if(k==0) return false;
    return true;
}

float Showroom::ShittyCar(){
    float min = array[0].ShowHp();
    for(int i=1;i<count; i++) if(min > array[i].ShowHp()) min = array[i].ShowHp();
    for(int i=0;i<count;i++) if(min==array[i].ShowHp()) cout<< "Nejpomalejsi auto:"<<array[i]<<endl;
    return min;
}
