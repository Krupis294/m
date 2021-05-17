#include "hlavicka.h"

skupiny::skupiny()
{
	pocet=0;
}

ostream &operator<<(ostream &vystup, skupiny sk)
{
	int i;
	vystup<<"SEZNAM ZAKU"<<endl;
	vystup<<"-----------------------------"<<endl;
	for(i=0; i<sk.pocet; i++)
	{
		vystup<<sk.pole[i];
	}
}

int skupiny::pridej(studenti sk)
{
	int a=0, b, i;
	for(i=0; i<pocet; i++)
	{
		if(pole[i].DejCislo()==sk.DejCislo())
		{
			a=1; break;
		}
	}
	if(a!=1)
	{
		pole[pocet]=sk;
		pocet++;
		return 1;
	}
	else
	{
		return 0;
	}
}

void skupiny::uloz()
{
	int i;
	ofstream soubor;
	soubor.open("skupiny.txt");
	if (soubor.fail())
	{
		cout<<"Nelze otevrit soubor"<<endl;
	}
	for(i=0; i<pocet; i++)
	{
		soubor<<pole[i].DejCislo()<<"|";
		soubor<<pole[i].DejJmeno()<<"|";
		soubor<<pole[i].DejPrijmeni()<<"|";
		soubor<<pole[i].DejMat()<<"|";
		soubor<<pole[i].DejAj()<<"|";
		soubor<<pole[i].DejCj()<<"|";
		soubor<<pole[i].DejCh()<<"|"<<endl;
	}
	soubor.close();   
}

bool skupiny::nacteni()
{
	int i;
	int cislo, mat, cj, aj, ch;
	string jmeno,prijmeni,radek;
	
	ifstream soubor;
	soubor.open("skupiny.txt");
	if (soubor.fail())
	{
		return false;
	}
	while(getline(soubor,radek,'|'))
	{
		i++;
		switch(i)
		{
			case 1:
			{
				cislo = atoi(radek.c_str()); break;
			}
			case 2: 
			{
				jmeno = radek; break;
			}
			case 3: 
			{
				prijmeni = radek; break;
			}
			case 4:
			{	
			 	mat = atoi(radek.c_str()); break;
			}
			case 5:
			{	
			 	aj = atoi(radek.c_str()); break;
			}
			case 6:
			{	
			 	cj = atoi(radek.c_str()); break;
			}
			case 7:
			{	
			 	ch = atoi(radek.c_str());
			 	studenti nove(cislo,jmeno,prijmeni,mat,aj,cj,ch);
				pridej(nove);
				i=0;	
				break;
			}
			
		}
	}
	soubor.close();
	return true;
}

studenti skupiny::hledani_prijm()
{
	int i,chyba=0;
	string hl_prijm;
	studenti s;
	
	cout<<"Zadej hledane prijmeni: ";
	cin>>hl_prijm;
	for(i=0; i<1; i++)
	{
		hl_prijm[i]=toupper(hl_prijm[i]);
	}
	for(i=1; i<50; i++)
	{
		hl_prijm[i]=tolower(hl_prijm[i]);
	}
	for(i=0; i < pocet; i++)
	{
		if(pole[i].DejPrijmeni()==hl_prijm)
		{
			s=pole[i];
			cout<<endl<<s;
		}
		else
		{
			chyba++;
		}
	
	}
	if(chyba==pocet)
	{
		cout<<"NENALEZENO"<<endl;
	}
	
	return s;
}

studenti skupiny::hledani_id()
{
	int i;
	int hl_id;
	studenti s;
	
	cout<<"Zadej hledane ID: ";
	cin>>hl_id;
	for(i=0; i < pocet; i++)
	{
		if(pole[i].DejCislo()==hl_id)
		{
			s=pole[i];
			cout<<endl<<s;
		}
	
	}
	
	return s;	
}

void skupiny::smazat()
{
	int i,smaz,j;
	cout<<"ID studenta pro smazani: ";
	cin>>smaz;

	for(j=0;j<pocet; j++)
	{
		if(pole[j].DejCislo()==smaz)
		{
			for(i=j;i<pocet-1;i++)
			{
       			pole[i]=pole[i+1];
   			}
   			pocet--;
		}
	}
}

int skupiny::nejlepsi()
{
	int i=0,j=0;
	studenti a;
	int max;
	max=0;
	for(i=0; i<pocet; i++)
	{
		if(max<pole[i].DejCh())
		{
			max=pole[i].DejCh();
			a=pole[i];
		}
	}
	cout<<"NEJLEPSI STUDENT"<<endl;
	cout<<"-----------------------------"<<endl;
	cout<<a;
	return max;
}

void skupiny::razeni_prijmeni()
{
	int i,j;
	studenti pom;
	
	for(i=0; i < pocet; i++)
	{
		for(j=0; j < pocet; j++)
		{
			if((pole[i].DejPrijmeni().compare(pole[j].DejPrijmeni()))<0)
			{
				pom=pole[j];
				pole[j]=pole[i];
				pole[i]=pom;
			}
		}
	}
	cout<<"-----------------------------"<<endl;
	cout<<"SERAZENO PODLE PRIJMENI"<<endl;
	cout<<"-----------------------------"<<endl;
}

void skupiny::razeni_mat()
{
	int i,j;
	studenti pom;
	
	for(i=0; i<pocet; i++)
	{
		for(j=0; j<pocet; j++)
		{
			if(pole[i].DejMat() < pole[j].DejMat())
			{
				pom=pole[j];
				pole[j]=pole[i];
				pole[i]=pom;
			}
		}
	}
	cout<<"-----------------------------"<<endl;
	cout<<"SERAZENO PODLE MATEMATIKY"<<endl;
	cout<<"-----------------------------"<<endl;
}
void skupiny::razeni_aj()
{
	int i,j;
	studenti pom;
	
	for(i=0; i<pocet; i++)
	{
		for(j=0; j<pocet; j++)
		{
			if(pole[i].DejAj() < pole[j].DejAj())
			{
				pom=pole[j];
				pole[j]=pole[i];
				pole[i]=pom;
			}
		}
	}
	cout<<"-----------------------------"<<endl;
	cout<<"SERAZENO PODLE ANGLICTINY"<<endl;
	cout<<"-----------------------------"<<endl;
}

void skupiny::razeni_cj()
{
	int i,j;
	studenti pom;
	
	for(i=0; i<pocet; i++)
	{
		for(j=0; j<pocet; j++)
		{
			if(pole[i].DejCj() < pole[j].DejCj())
			{
				pom=pole[j];
				pole[j]=pole[i];
				pole[i]=pom;
			}
		}
	}
	cout<<"-----------------------------"<<endl;
	cout<<"SERAZENO PODLE CESTINY"<<endl;
	cout<<"-----------------------------"<<endl;
}

int skupiny::DejPocet() const{
	return pocet;
}
