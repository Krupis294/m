#ifndef HLAVICKA_H
#define HLAVICKA_H

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

class Complex{
	private: 
		double realna;
		double imaginarni;
		
	public:
		Complex();
		Complex(double x, double y);
		
		friend istream &operator>>(istream &cin, Complex &k);
		friend ostream &operator<<(ostream &cout, Complex k);
		
		Complex operator+(Complex k); //scitani
		Complex operator-(Complex k); //odcitani
		Complex operator*(Complex k); //nasobeni
		Complex operator/(Complex k); //deleni
		
		float absolutni(); //abs h. komplex. cisla
		
		Complex sdruzene(); //sdruzeni komplex. cisla
};

class zlomek{
	private:
		int citatel;
		int jmenovatel;
		
	public:
		zlomek();
		zlomek(int x, int y);
		
		friend	istream &operator>>(istream &cin, zlomek &z);
		friend  ostream &operator<<(ostream &cout, zlomek z);
		
		zlomek operator+(zlomek z); //stejne jako u komplex c.
		zlomek operator-(zlomek z);
		zlomek operator*(zlomek z);
		zlomek operator/(zlomek z);
		void kraceni(); //kraceni zlomku
};
#endif
