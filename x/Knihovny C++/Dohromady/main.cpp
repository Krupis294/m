#include "hlavicka.h"


int main(){
	Complex k,a,b,vysledek;
	zlomek z,az,bz,vysledekz;
	
	int nabidka2=1; 
	int nabidka3=1;
	int nabidka1=1;
	float f_vysledek=0;
	
	//nabidka volby pracovani s komplex / zlomky
	cout<<"---------------------------"<<endl;
	cout<<"1 - Komplexni cisla"<<endl;
	cout<<"2 - Zlomky"<<endl;
	cout<<"---------------------------"<<endl;
	cout<<"Volba: ";
	cin>>nabidka1;
		
	if(nabidka1==1)
	{
	while(nabidka2!=0)
	{
		cout<<"---------------------------"<<endl;
		cout<<"1 - Nacteni cisel"<<endl;
		cout<<"2 - Vypis cisel"<<endl;
		cout<<"3 - Scitani cisel"<<endl;
		cout<<"4 - Odcitani cisel"<<endl;
		cout<<"5 - Nasobeni cisel"<<endl;
		cout<<"6 - Deleni cisel"<<endl;
		cout<<"7 - Absolutni hodnota cisel"<<endl;
		cout<<"8 - Komplexne sdruzeni cisel"<<endl;
		cout<<"0 - EXIT"<<endl;
		cout<<"---------------------------"<<endl;
		cout<<"Volba: ";
		cin>>nabidka2;
		
		switch(nabidka2)
		{
			case 0: exit(1); break;
			case 1: system("cls");
					cout<<"NACTENI KOMPLEXNICH CISEL"<<endl;
					cout<<"---------------------------"<<endl;
					cin>>a; //ulozeni prvniho komplexniho cisla
					cin>>b; //ulozeni druheho komplexniho cisla
					break;
			case 2: system("cls");
					cout<<"VYPIS KOMPLEXNICH CISEL"<<endl;
					cout<<"---------------------------"<<endl;
					cout<<a; //vypis prvniho komplexniho cisla
					cout<<b; //vypis prvniho komplexniho cisla
					break;
			case 3: system("cls");
					vysledek=a+b; //vysledek s vyuzitim operatoru +
					cout<<"SOUCET KOMPLEXNICH CISEL"<<endl;
					cout<<"---------------------------"<<endl;
					cout<<"Soucet: ";
					cout<<vysledek;
					break;
			case 4: system("cls");
					vysledek=a-b; //vysledek s vyuzitim operatoru -
					cout<<"ODCITANI KOMPLEXNICH CISEL"<<endl;
					cout<<"---------------------------"<<endl;
					cout<<"ODCITANI: ";
					cout<<vysledek;
					break;
			case 5: system("cls");
					vysledek=a*b; //vysledek s vyuzitim operatoru *
					cout<<"NASOBENI KOMPLEXNICH CISEL"<<endl;
					cout<<"---------------------------"<<endl;
					cout<<"SOUCIN: ";
					cout<<vysledek;
					break;
			case 6: system("cls");
					vysledek=a/b; //vysledek s vyuzitim operatoru / 
					cout<<"DELENI KOMPLEXNICH CISEL"<<endl;
					cout<<"---------------------------"<<endl;
					cout<<"DELENI: ";
					cout<<vysledek;
					break;
			case 7: system("cls");
					f_vysledek=a.absolutni(); //absolutni hodnota pro prvni komplex. cislo (a)
					cout<<"ABSOLUTNI HODNOTA PRVNIHO KOMPLEXNIHO CISLA: "<<endl;
					cout<<"---------------------------"<<endl;
					cout<<"ABS. HODNOTA: ";
					cout<<f_vysledek<<endl;
					cout<<"---------------------------"<<endl;
					f_vysledek=b.absolutni(); //absolutni hodnota pro druhe komplex. cislo (b)
					cout<<"ABSOLUTNI HODNOTA DRUHEHO KOMPLEXNIHO CISLA: "<<endl;
					cout<<"---------------------------"<<endl;
					cout<<"ABS. HODNOTA: ";
					cout<<f_vysledek<<endl;
					break;
			case 8: system("cls");
					vysledek=a.sdruzene(); //sdruzena hodnota pro prvni komplex. cislo (a)
					cout<<"SDRUZENE KOMPLEXNI PRVNIHO CISLA"<<endl;
					cout<<"---------------------------"<<endl;
					cout<<"SDRUZENE PRVNI CISLO: ";
					cout<<vysledek;
					cout<<"---------------------------"<<endl;
					vysledek=b.sdruzene(); //sdruzena hodnota pro druhe komplex. cislo (b)
					cout<<"SDRUZENE KOMPLEXNI DRUHE CISLA"<<endl;
					cout<<"---------------------------"<<endl;
					cout<<"SDRUZENE DRUHE CISLO: ";
					cout<<vysledek;
					break;
		}
	}
}
else if(nabidka1==2)
{
	while(nabidka3!=0)
	{
		cout<<"-------------------------"<<endl;
		cout<<"1 - Nacteni zlomku"<<endl;
		cout<<"2 - Vypis zlomku"<<endl;
		cout<<"3 - Scitani zlomku"<<endl;
		cout<<"4 - Odcitani zlomku"<<endl;
		cout<<"5 - Nasobeni zlomku"<<endl;
		cout<<"6 - Deleni zlomku"<<endl;
		cout<<"0 - EXIT"<<endl;
		cout<<"-------------------------"<<endl;
		cout<<"Volba: ";
		cin>>nabidka3;
		
		switch(nabidka3)
		{
			case 0: exit(1);
			case 1: system("CLS");
					cout<<"NACTENI ZLOMKU"<<endl;
					cout<<"-------------------------"<<endl;
					cin>>az; //ulozeni prvniho zlomku
					cin>>bz; //ulozeni druheho zlomku
					break;
			case 2: system("CLS");
					cout<<"VYPIS ZLOMKU"<<endl;
					cout<<"-------------------------"<<endl;
					cout<<"1. Zlomek: "<<az<<endl; //vypsani prvniho zlomku
					cout<<"2. Zlomek: "<<bz<<endl; //vypsani druheho zlomku
					break;
			case 3: system("CLS");
					vysledekz=az+bz; //stejne jako u komplex
					cout<<"SCITANI ZLOMKU"<<endl;
					cout<<"-------------------------"<<endl;
					cout<<"SOUCET: ";
					cout<<vysledekz<<endl;
					break;
			case 4: system("CLS");
					vysledekz=az-bz;
					cout<<"ODCITANI ZLOMKU"<<endl;
					cout<<"-------------------------"<<endl;
					cout<<"ODCITANI: ";
					cout<<vysledekz<<endl;
					break;
			case 5: system("CLS");
					vysledekz=az*bz;
					cout<<"NASOBENI ZLOMKU"<<endl;
					cout<<"-------------------------"<<endl;
					cout<<"NASOBENI: ";
					cout<<vysledekz<<endl;
					break;
			case 6: system("CLS");
					vysledekz=az/bz;
					cout<<"DELENI ZLOMKU"<<endl;
					cout<<"-------------------------"<<endl;
					cout<<"DELENI: ";
					cout<<vysledekz<<endl;
					break;
		}
	}
}	
}
