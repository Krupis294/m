#include "hlavicka.h"



Complex::Complex(){
	realna=0;
	imaginarni=0;
}

Complex::Complex(double x, double y)
{
	realna=x;
	imaginarni=y;
}

istream &operator>>(istream &cin, Complex &k)
{
	cout<<"Napis realne cislo: ";
	cin>>k.realna;
	
	cout<<"Napis imaginarni cislo: ";
	cin>>k.imaginarni;
}

ostream &operator<<(ostream &cout, Complex k)
{
	if(k.imaginarni<0)
	{
	cout<<k.realna<<k.imaginarni<<"i"<<endl;	
	}
	else{
	cout<<k.realna<<"+"<<k.imaginarni<<"i"<<endl;
	}
}

Complex Complex::operator+(Complex k)
{
				
	k.realna=realna+k.realna;
	k.imaginarni=imaginarni+k.imaginarni;
	
	return k;
}

Complex Complex::operator-(Complex k)
{
				
	k.realna=realna-k.realna;
	k.imaginarni=imaginarni-k.imaginarni;
	
	return k;
}

Complex Complex::operator*(Complex k)
{
	Complex cislo;
	
	cislo.realna=(realna * k.realna) - (imaginarni * k.imaginarni);
	cislo.imaginarni=(realna * k.imaginarni ) + (k.realna * imaginarni);
	
	return cislo;
}

Complex Complex::operator/(Complex k)
{
	Complex cislo;
	
	cislo.realna=((realna * k.realna) + (imaginarni * k.imaginarni)) / ((k.realna * k.realna) + (k.imaginarni * k.imaginarni));
	cislo.imaginarni=((imaginarni * k.realna) - (realna*k.imaginarni)) / ((k.realna * k.realna) + (k.imaginarni * k.imaginarni));
	
	return cislo;
}

float Complex::absolutni()
{
	float cislo;
	
	cislo = sqrt((realna * realna) + (imaginarni * imaginarni));
	
	return cislo;
}

Complex Complex::sdruzene()
{
	Complex cislo;
	
	cislo.realna=realna;
	cislo.imaginarni=imaginarni * (-1);
	
	return cislo;
}
