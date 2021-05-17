//
//  db.h
//  komplexni_cisla
//
//  Created by kuba on 08.02.2021.
//

#ifndef db_h
#define db_h

#include<iostream>
#include<iomanip>
#include<complex>
#include<cmath>
#include<cstdlib>
#include<ccomplex>

using namespace std;
using namespace std::complex_literals;

class Komplex{
    private:
        float real,imag;
    public:
        Komplex();
        Komplex(float re, float im);
        
        friend ostream &operator<<(ostream &out, Komplex x);
        friend istream &operator>>(istream &in, Komplex &x);
    
        Komplex operator+(Komplex x);
        Komplex operator-(Komplex x);
        Komplex operator*(Komplex x);
        Komplex operator/(Komplex x);
        float abs();
        bool rovnost(Komplex x);
        void reverse();
        void sdruzene();
};
void menu();
#endif /* db_h */
