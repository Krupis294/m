#include "hlavicka.h"


int main(){
	Complex k,a,b,vysledek;
	int nabidka=1;
	float f_vysledek=0;
	
	while(nabidka!=0)
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
		cout<<"Volba: ";
		cin>>nabidka;
		
		switch(nabidka)
		{
			case 0: exit(1); break;
			case 1: system("cls");
					cout<<"NACTENI KOMPLEXNICH CISEL"<<endl;
					cout<<"---------------------------"<<endl;
					cin>>a;
					cin>>b;
					break;
			case 2: system("cls");
					cout<<"VYPIS KOMPLEXNICH CISEL"<<endl;
					cout<<"---------------------------"<<endl;
					cout<<a;
					cout<<b;
					break;
			case 3: system("cls");
					vysledek=a+b;
					cout<<"SOUCET KOMPLEXNICH CISEL"<<endl;
					cout<<"---------------------------"<<endl;
					cout<<"Soucet: ";
					cout<<vysledek;
					break;
			case 4: system("cls");
					vysledek=a-b;
					cout<<"ODCITANI KOMPLEXNICH CISEL"<<endl;
					cout<<"---------------------------"<<endl;
					cout<<"ODCITANI: ";
					cout<<vysledek;
					break;
			case 5: system("cls");
					vysledek=a*b;
					cout<<"NASOBENI KOMPLEXNICH CISEL"<<endl;
					cout<<"---------------------------"<<endl;
					cout<<"SOUCIN: ";
					cout<<vysledek;
					break;
			case 6: system("cls");
					vysledek=a/b;
					cout<<"DELENI KOMPLEXNICH CISEL"<<endl;
					cout<<"---------------------------"<<endl;
					cout<<"DELENI: ";
					cout<<vysledek;
					break;
			case 7: system("cls");
					f_vysledek=a.absolutni();
					cout<<"ABSOLUTNI HODNOTA KOMPLEXNICH CISEL"<<endl;
					cout<<"---------------------------"<<endl;
					cout<<"ABS. HODNOTA: ";
					cout<<f_vysledek;
					break;
			case 8: system("cls");
					vysledek=a.sdruzene();
					cout<<"KOMPLEXNE SDRUZENE KOMPLEXNI CISLA"<<endl;
					cout<<"---------------------------"<<endl;
					cout<<"KOMPLEXNE SDRUZENE: ";
					cout<<vysledek;
					break;
		}
	}
	
	
	
	cin>>a;
	cin>>b;
	
	cout<<a;
	cout<<b;	
}
