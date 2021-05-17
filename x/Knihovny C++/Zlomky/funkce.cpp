#include "hlavicka.h"


zlomek::zlomek()
{
	citatel=0;
	jmenovatel=0;
}

zlomek::zlomek(int x, int y){
	citatel = x;
	jmenovatel = y;
}

istream &operator>>(istream &cin, zlomek &z)
{
	cout<<"Zadej citatel: ";
	cin>>z.citatel;
	
	cout<<"Zadej jmenovatel: ";
	cin>>z.jmenovatel;		
}

ostream &operator<<(ostream &cout, zlomek z)
{
	cout<<z.citatel<<"/"<<z.jmenovatel;
}

zlomek zlomek::operator+(zlomek z)
{
	z.citatel=(citatel * z.jmenovatel) + (z.citatel * jmenovatel);
	z.jmenovatel=(jmenovatel * z.jmenovatel);
	z.kraceni();
	
	return z;
}

void zlomek::kraceni()
{
	int a,b;
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

zlomek zlomek::operator-(zlomek z)
{
	z.citatel = (citatel * z.jmenovatel) - (z.citatel * jmenovatel);
	z.jmenovatel = (jmenovatel * z.jmenovatel);
	z.kraceni();
	
	return z;
}

zlomek zlomek::operator*(zlomek z)
{
	z.citatel = (citatel * z.citatel);
	z.jmenovatel = (jmenovatel * z.jmenovatel );
	z.kraceni();
	
	return z;
}

zlomek zlomek::operator/(zlomek z)
{
	zlomek cislo;
	cislo.citatel = (citatel * z.jmenovatel);
	cislo.jmenovatel = (jmenovatel * z.citatel);
	cislo.kraceni();
	
	return cislo;
	
}
