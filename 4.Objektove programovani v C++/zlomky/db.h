//
//  db.h
//  zlomky
//
//  Created by kuba on 02.03.2021.
//

#ifndef db_h
#define db_h

#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>

using namespace std;

class Zlomky{
    private:
        int cit,jmen;
    public:
        Zlomky();
        Zlomky(int c, int j);
        
        friend ostream &operator<<(ostream &out, Zlomky x);
        friend istream &operator>>(istream &in, Zlomky &x);
    
        Zlomky operator+(Zlomky x);
        Zlomky operator-(Zlomky x);
        Zlomky operator*(Zlomky x);
        Zlomky operator/(Zlomky x);
        int hlzlom(int a, int b);
        Zlomky zakl();
        int spol(int x, int y);
        bool por(Zlomky x);
        float rhz(){ return (float)this->cit/this->jmen;};
        Zlomky moc(int n);
};
void menu();

#endif /* db_h */
