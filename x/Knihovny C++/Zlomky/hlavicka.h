#ifndef HLAVICKA_H
#define HLAVICKA_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

class zlomek{
	private:
		int citatel;
		int jmenovatel;
		
	public:
		zlomek();
		zlomek(int x, int y);
		
	friend	istream &operator>>(istream &cin, zlomek &z);
	friend	ostream &operator<<(ostream &cout, zlomek z);
	
	zlomek operator+(zlomek z);
	zlomek operator-(zlomek z);
	zlomek operator*(zlomek z);
	zlomek operator/(zlomek z);
	void kraceni();
};





#endif
