//
//  database.h
//  obj_prog
//
//  Created by kuba on 04.05.2021.
//

#ifndef database_h
#define database_h


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

#define MAX 100

using namespace std;

class Auto{
    private:
        string znacka;
        int rok;
        float hp;
    public:
        Auto();
        Auto(string zn);
        Auto(string zn,int r);
        Auto(string zn,int r,float h);
        
        string UkazZnacku(){return znacka;};
        int UkazRok(){return rok;};
        float UkazHp(){return hp;};
    
        friend ostream &operator << (ostream &out, Auto x);
        friend istream &operator >> (istream &in, Auto &x);
    
};

class Garaz{
    private:
        Auto pole[MAX];
        int pocet;
    public:
        Garaz(){pocet=0;};
        int UkazPocet(){return pocet;};
        bool NoveAuto(Auto x);
        bool UlozeniDoSouboru();
        bool NacteniZSouboru();
        bool Hledani();
        bool Serazeni();
        bool Smazani();
        bool Zmena();
        void slabko();
        friend ostream &operator << (ostream &out, Garaz x);
    
};

void menu();

#endif /* database_h */
