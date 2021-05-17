#include "hlavicka.h"


studenti::studenti()
{
	cislo=0;
	jmeno="";
	prijmeni="";
	mat=0;
	aj=0;
	cj=0;
	ch=0;
}

studenti::studenti(int id, string jm, string prij, int matika, int ajina, int cestina, int celkoveh)
{
	cislo=id;
	jmeno=jm;
	prijmeni=prij;
	mat=matika;
	aj=ajina;
	cj=cestina;
	ch=celkoveh;
}

istream &operator>>(istream &vstup, studenti &s)
{
	int i;
	skupiny sk;
	cout<<"PRIDANI STUDENTA"<<endl;
	cout<<"-----------------------------"<<endl;
	
	cout<<"Zadej ID: ";
	vstup.clear();
	fflush(stdin);
	vstup>>s.cislo;
	
	cout<<"Zadej jmeno: ";
	vstup.clear();
	fflush(stdin);
	getline(vstup,s.jmeno);
	
	cout<<"Zadej prijmeni: ";
	vstup.clear();
	fflush(stdin);
	getline(vstup,s.prijmeni);
	
	do{
	cout<<"Body z matiky: ";
	vstup.clear();
	fflush(stdin);
	vstup>>s.mat;
	if(s.mat>100 || s.mat<0)
	{
		cout<<"*****HODNOCENI MUSI BYT 0-100*****"<<endl;
	}
	}while(s.mat>100 || s.mat<0);
	
	do{
	cout<<"Body z Anglictiny: ";
	vstup.clear();
	fflush(stdin);
	vstup>>s.aj;
	if(s.aj>100 || s.aj<0)
	{
		cout<<"*****HODNOCENI MUSI BYT 0-100*****"<<endl;
	}
	}while(s.aj>100 || s.aj<0);
	
	do{
	cout<<"Body z Cestiny: ";
	vstup.clear();
	fflush(stdin);
	vstup>>s.cj;
	if(s.cj>100 || s.cj<0)
	{
		cout<<"*****HODNOCENI MUSI BYT 0-100*****"<<endl;
	}
	}while(s.cj>100 || s.cj<0);
	
	s.ch = s.mat + s.aj + s.cj;
	
}

ostream &operator<<(ostream &vystup, studenti s)
{
	vystup<<"ID             : "<<s.cislo<<endl;
	vystup<<"Jmeno          : "<<s.jmeno<<endl;
	vystup<<"Prijmeni       : "<<s.prijmeni<<endl;
	vystup<<"Body z Matiky  : "<<s.mat<<endl;
	vystup<<"Body z Ajiny   : "<<s.aj<<endl;
	vystup<<"Body z Cestiny : "<<s.cj<<endl;
	vystup<<"Pocet bodu     : "<<s.ch<<endl;
	if(s.aj < 35 || s.cj < 35 || s.mat < 35)
	{
		vystup<<"****NEPROSPEL****"<<endl;
	}
	else{
		vystup<<"****PROSPEL****"<<endl;
	}
	vystup<<"-----------------------------"<<endl;
}

int studenti::DejCislo() const {
	return cislo;
}

string studenti::DejJmeno() const {
	return jmeno;
}

string studenti::DejPrijmeni() const {
	return prijmeni;
}

int studenti::DejMat() const {
	return mat;
}

int studenti::DejAj() const {
	return aj;
}

int studenti::DejCj() const {
	return cj;
}
int studenti::DejCh() const {
	return ch;
}


