//
//  database.h
//  databaze_auta
//
//  Created by kuba on 07.02.2021.
//

#ifndef database_h
#define database_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

#define MAX 100

using namespace std;

class Car{
    private:
        string brand;
        int year;
        float hp;
    public:
        Car();
        Car(string br);
        Car(string br,int ye);
        Car(string br,int ye,float h);
        
        string ShowBrand(){return brand;};
        int ShowYear(){return year;};
        float ShowHp(){return hp;};
    
        friend ostream &operator << (ostream &out, Car x);
        friend istream &operator >> (istream &in, Car &x);
};

class Showroom{
    private:
        Car array[MAX];
        int count;
    public:
        Showroom(){count=0;};
    
        int ShowCount(){return count;};
        friend ostream &operator << (ostream &out, Showroom x);
        
        bool SaveToFile();
        bool ImportFromFile();
        bool NewCar(Car x);
        bool Finder();
        bool Sort();
        bool Delete();
        bool Change();
        float ShittyCar();
};
void menu();
#endif /* database_h */
