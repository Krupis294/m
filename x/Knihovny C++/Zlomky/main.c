#include "hlavicka.h"

int main(){
	zlomek z,a,b,vysledek;
	int nabidka=1;
	
	while(nabidka!=0)
	{
		cout<<"-------------------------"<<endl;
		cout<<"1 - Nacteni zlomku"<<endl;
		cout<<"2 - Vypis zlomku"<<endl;
		cout<<"3 - Scitani zlomku"<<endl;
		cout<<"4 - Odcitani zlomku"<<endl;
		cout<<"5 - Nasobeni zlomku"<<endl;
		cout<<"6 - Deleni zlomku"<<endl;
		cout<<"0 - EXIT"<<endl;
		cout<<"Volba: ";
		cin>>nabidka;
		
		switch(nabidka)
		{
			case 0: exit(1);
			case 1: system("CLS");
					cout<<"NACTENI ZLOMKU"<<endl;
					cout<<"-------------------------"<<endl;
					cin>>a;
					cin>>b;
					break;
			case 2: system("CLS");
					cout<<"VYPIS ZLOMKU"<<endl;
					cout<<"-------------------------"<<endl;
					cout<<"1. Zlomek: "<<a<<endl;
					cout<<"2. Zlomek: "<<b<<endl;
					break;
			case 3: system("CLS");
					vysledek=a+b;
					cout<<"SCITANI ZLOMKU"<<endl;
					cout<<"-------------------------"<<endl;
					cout<<"SOUCET: ";
					cout<<vysledek<<endl;
					break;
			case 4: system("CLS");
					vysledek=a-b;
					cout<<"ODCITANI ZLOMKU"<<endl;
					cout<<"-------------------------"<<endl;
					cout<<"ODCITANI: ";
					cout<<vysledek<<endl;
					break;
			case 5: system("CLS");
					vysledek=a*b;
					cout<<"NASOBENI ZLOMKU"<<endl;
					cout<<"-------------------------"<<endl;
					cout<<"NASOBENI: ";
					cout<<vysledek<<endl;
					break;
			case 6: system("CLS");
					vysledek=a/b;
					cout<<"DELENI ZLOMKU"<<endl;
					cout<<"-------------------------"<<endl;
					cout<<"DELENI: ";
					cout<<vysledek<<endl;
					break;
		}
	}
}
