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
	cin>>k.realna; //nacteni realneho cisla
	
	cout<<"Napis imaginarni cislo: ";
	cin>>k.imaginarni; //nacteni imaginarniho cisla
}

ostream &operator<<(ostream &cout, Complex k)
{
	if(k.imaginarni<0)
	{
	cout<<k.realna<<k.imaginarni<<"i"<<endl;	//vypis komplex cisla, osetreno aby se nezobrazovalo "+-"
	}
	else{
	cout<<k.realna<<"+"<<k.imaginarni<<"i"<<endl;
	}
}

Complex Complex::operator+(Complex k) //scitani komplex cisel
{
				
	k.realna=realna+k.realna;
	k.imaginarni=imaginarni+k.imaginarni;
	
	return k;
}

Complex Complex::operator-(Complex k) //odcitani komplex cisel
{
				
	k.realna=realna-k.realna;
	k.imaginarni=imaginarni-k.imaginarni;
	
	return k;
}

Complex Complex::operator*(Complex k) //nasobeni komplex cisel
{
	Complex cislo;
	
	cislo.realna=(realna * k.realna) - (imaginarni * k.imaginarni);
	cislo.imaginarni=(realna * k.imaginarni ) + (k.realna * imaginarni);
	
	return cislo;
}

Complex Complex::operator/(Complex k) //deleni komplex cisel
{
	Complex cislo;
	
	cislo.realna=((realna * k.realna) + (imaginarni * k.imaginarni)) / ((k.realna * k.realna) + (k.imaginarni * k.imaginarni));
	cislo.imaginarni=((imaginarni * k.realna) - (realna*k.imaginarni)) / ((k.realna * k.realna) + (k.imaginarni * k.imaginarni));
	
	return cislo;
}

float Complex::absolutni() //absolutni hodnota komplex cisla (funguje jako pythagorova veta)
{
	float cislo;
	
	cislo = sqrt((realna * realna) + (imaginarni * imaginarni));
	
	return cislo;
}

Complex Complex::sdruzene() //sdruzeni komplex cisel
{
	Complex cislo;
	
	cislo.realna=realna;
	cislo.imaginarni=imaginarni * (-1);
	
	return cislo;
}

//----------------------------------------------------------------------------

zlomek::zlomek(){
	citatel=0;
	jmenovatel=0;
}

zlomek::zlomek(int x, int y)
{
	citatel=x;
	jmenovatel=y;
}

istream &operator>>(istream &cin, zlomek &z)
{
	cout<<"Zadej citatel: ";
	cin>>z.citatel; //nacteni citatele
	
	cout<<"Zadej jmenovatel: ";
	cin>>z.jmenovatel; //nacteni jmenovatele
}

ostream &operator<<(ostream &cout, zlomek z)
{
	cout<<z.citatel<<"/"<<z.jmenovatel; //vypis zlomku
}

void zlomek::kraceni() //funkce pro kraceni zlomku
{
	int a;
	int b;
	
	a=abs(citatel);
	b=abs(jmenovatel);
	
	while(a!=b)
	{
		if(a>b)
		{
			a=a-b;
		}
		else
		{
			b=b-a;
		}
	}
	citatel=citatel/a;
	jmenovatel=jmenovatel/b;
}

zlomek zlomek::operator+(zlomek z) //scitani zlomku
{
	z.citatel = (citatel * z.jmenovatel) + (jmenovatel * z.citatel);
	z.jmenovatel = (jmenovatel * z.jmenovatel);
	z.kraceni();
	
	return z;
}

zlomek zlomek::operator-(zlomek z) //odcitani zlomku
{
	z.citatel = (citatel * z.jmenovatel) - (jmenovatel * z.citatel);
	z.jmenovatel = (jmenovatel * z.jmenovatel);
	z.kraceni();
	
	return z;
}
zlomek zlomek::operator*(zlomek z) //nasobeni zlomku
{
	z.citatel = (citatel * z.citatel);
	z.jmenovatel = (jmenovatel * z.jmenovatel);
	z.kraceni();
	
	return z;
}
zlomek zlomek::operator/(zlomek z) //deleni zlomku
{
	zlomek cislo;
	cislo.citatel=(citatel * z.jmenovatel);
	cislo.jmenovatel=(jmenovatel * z.citatel);
	cislo.kraceni();
	
	return cislo;
}
