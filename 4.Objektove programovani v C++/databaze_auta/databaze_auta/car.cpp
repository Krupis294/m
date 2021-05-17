//
//  car.cpp
//  databaze_auta
//
//  Created by kuba on 07.02.2021.
//

#include "database.h"

Car::Car(){
    brand="";
    year=0;
    hp=0.0;
}

Car::Car(string br){
    brand=br;
    year=0;
    hp=0.0;
}

Car::Car(string br,int ye){
    brand=br;
    year=ye;
    hp=0.0;
}

Car::Car(string br,int ye,float h){
    brand=br;
    year=ye;
    hp=h;
}

ostream &operator << (ostream &out, Car x){
    out << x.brand<<setw(5)<<x.year<<setw(5)<<x.hp<<endl;
    return out;
}

istream &operator >> (istream &in, Car &x){
    cout<<"Zadej znacku vozidla:"<<endl;
    in>>x.brand;
    cin.ignore();
    cout<<"Zadej rok vyroby vozidla:"<<endl;
    in>>x.year;
    cout<<"Zadej hp vozidla:"<<endl;
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
