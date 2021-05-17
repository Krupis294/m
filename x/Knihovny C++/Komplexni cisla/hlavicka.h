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
		
		Complex operator+(Complex k);
		Complex operator-(Complex k);
		Complex operator*(Complex k);
		Complex operator/(Complex k);
		
		float absolutni();
		
		Complex sdruzene();
};
#endif
