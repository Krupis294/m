#include "hlavicka.h"


int main(){
	SetConsoleTitle("Databaze C++ - Sommer Maxim, 4.A");
	studenti s;
	skupiny sk;
	int pom;
	int smaz=0;
	int nabidka=1;
	int volba;
	while(nabidka!=0)
	{
		system("cls");
		cout<<"-----------------------------"<<endl;
		cout<<"NABIDKA"<<endl;
		cout<<"-----------------------------"<<endl;
		cout<<"1 - Pridat studenta"<<endl;
		cout<<"2 - Vypis studentu"<<endl;
		cout<<"3 - Uloz do souboru"<<endl;
		cout<<"4 - Nacteni ze souboru"<<endl;
		cout<<"5 - Hledani podle prijmeni"<<endl;
		cout<<"6 - Hledani podle ID"<<endl;	
		cout<<"7 - Smazat studenta"<<endl;
		cout<<"8 - Nejlepsi student"<<endl;
		cout<<"9 - Razeni"<<endl;
		cout<<"0 - EXIT"<<endl;
		cout<<endl<<"Volba: ";
		cin>>nabidka;
		cout<<endl;
	
		switch(nabidka){
			case 1:
			{
				do{
				system("cls");
				cin>>s;
				pom=sk.pridej(s);
				if(pom == 0)
				{
					cout<<"****TOTO ID JIZ EXISTUJE****"<<endl;
					system("pause");
				}
				}while(pom==0);
				cout<<"****PRIDANO****"<<endl;
				system("pause");
				break;
			}
			case 2:
			{
				system("cls");
				cout<<"****VYPIS****"<<endl;
				cout<<"-----------------------------"<<endl;
				cout<<sk;
				system("pause");
				break;
			}
			case 3:
			{
				system("cls");
				sk.uloz();
				cout<<"****ULOZENO****"<<endl;
				system("pause");
				break;
			}
			case 4:
			{
				system("cls");
				if(sk.nacteni()==true)
				{
					cout<<"****NACTENO****"<<endl;
				}
				else cout<<"Nepodarilo se otevrit"<<endl;
				system("pause");
				break;
			}
			case 5:
			{
				system("cls");
				sk.hledani_prijm();
				system("pause");
				break;
			}
			case 6:
			{
				system("cls");
				sk.hledani_id();
				system("pause");
				break;
			}
			case 7:
			{
				system("cls");
				sk.smazat();
				system("pause");
				break;
			}
			case 8:
			{
				system("cls");
				sk.nejlepsi();
				system("pause");
				break;
			}
			case 9:
			{
				system("cls");
				cout<<"VYBER RAZENI PODLE"<<endl;
				cout<<"-----------------------------"<<endl;
				cout<<"1 - Prijmeni"<<endl<<"2 - Matematiky"<<endl<<"3 - Anglictiny"<<endl<<"4 - Cestiny"<<endl;
				cout<<endl<<"Volba: ";
				cin>>volba;
				switch(volba)
				{
					case 1:
							system("cls");
							sk.razeni_prijmeni();
							system("pause");
							break;
					case 2: 
							system("cls");
							sk.razeni_mat();
							system("pause");
							break;
					case 3: 
							system("cls");
							sk.razeni_aj();
							system("pause");
							break;
					case 4: 
							system("cls");
							sk.razeni_cj();
							system("pause");
							break;
				}
				break;
			}
			case 0:
			{
				exit(1);
				break;
			}
		}
	}
return 0;
}
