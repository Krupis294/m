#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void pridani(); 		//funcke pro pridani slov do slovniku
void osetreni(char slovo[]); 		//osetri prvni velke pismeno zbytek male
void vypis(); 		//vypis vsech slovicek
void vypis_lekce(); 		//vypis slovicek z lekce
void preklad();		 //preklad slovicek AJ->CZ / CZ->AJ
int pocet_slov(); 		//pocet slov ve slovniku
void test_lekce(); 		//test z danne lekce
void nahodny_test(); 		//nahodny test

int main()
{
	int volba=1;
	while(volba!=0)
	{
		system("cls"); 
		printf("NABIDKA\n");
		printf("---------------------------");
		printf("\n1 - Pridani slovicka");
		printf("\n2 - Vypis slovicek");
		printf("\n3 - Vypis lekce");
		printf("\n4 - Preklad");
		printf("\n5 - Pocet slov ve slovniku");
		printf("\n6 - Test lekce");
		printf("\n7 - Nahodny test");
		printf("\n0 - EXIT");
		printf("\n---------------------------");
		printf("\nVolba: ");
		scanf("%d",&volba);
		fflush(stdin);
		
		switch(volba)
		{
			case 1: system("cls");
					pridani();
					system("pause");
					break;
			case 2: system("cls");
					vypis();
					system("pause");
					break;
			case 3: system("cls");
					vypis_lekce();
					system("pause");
					break;
			case 4: system("cls");
					preklad();
					system("pause");
					break;
			case 5: system("cls");
					pocet_slov();
					system("pause");
					break;
			case 6: system("cls");
					test_lekce();
					system("pause");
					break;
			case 7: system("cls");
					nahodny_test();
					system("pause");
					break;
			case 0: exit(1);
					break;
		}
	}
}

void osetreni(char slovo[])
{
	int i;
	for(i=0; i<1; i++)
	{
		slovo[i]=toupper(slovo[i]);
	}
	for(i=1; i<20; i++)
	{
		slovo[i]=tolower(slovo[i]);
	}
}

void pridani()
{
	char prid_cz[20];
	char prid_aj[20];
	char zad_lekce[20];
	
	FILE *f;
	
	printf("PRIDANI SLOVICKA\n");
	printf("---------------------------\n");
	printf("Zadej ceske slovicko: ");
	gets(prid_cz);
	osetreni(prid_cz);
	fflush(stdin);
	
	printf("Zadej anglicke preklad: ");
	gets(prid_aj);
	osetreni(prid_aj);
	fflush(stdin);
	
	printf("Zadej lekci: ");
	fflush(stdin);
	gets(zad_lekce);
	f=fopen("slovnik.txt","a");
	if(f==NULL)
	{
		printf("\nCHYBA\n");
	}
	
	fprintf(f,"%s|",prid_cz); 		// "|" deli slova
	fprintf(f,"%s|",prid_aj);
	fprintf(f,"%s\n",zad_lekce);		 // "\n" pro zalomeni radku 
	fflush(stdin);
	printf("\n***PRIDANO***\n");
	if(fclose(f)==EOF) printf("\nCHYBA\n");
}

void vypis()
{
	FILE *f;
	char radek[80];
	
	printf("VYPIS\n");
	printf("---------------------------\n");
	f=fopen("slovnik.txt","r");
	if(f==NULL)
	{
		printf("\nCHYBA\n");
	}
	while(fgets(radek,80,f)!=NULL)		 //cte z .txt souboru, dokud neni dalsi radek null
	{
		puts(radek); //vypise cely radek
	}
	printf("---------------------------\n");
	if (fclose(f)==EOF) printf("Soubor se nepovedlo zavrit");
}

void vypis_lekce()
{
	char prid_cz[20];
	char prid_aj[20];
	char zad_lekce[20];
	char hl_lekce[20];
	char radek[80];
	
	FILE *f;
	char *p;
	
	printf("Zadej hledanou lekci: ");
	gets(hl_lekce); 		//ulozi hledane cislo uzivatelem
	printf("VYPIS LEKCE\n");
	printf("---------------------------\n");
	f=fopen("slovnik.txt","r");
	while(fgets(radek,80,f)!=NULL)			//prochazi soubor
	{
		p=strtok(radek, "|"); 		//uklada do p hodnoty ze souboru
		strcpy(prid_cz,p); 		//kopirovani ulozenych hodnot do promennych
		p=strtok(NULL, "|");
		strcpy(prid_aj,p);
		p=strtok(NULL, "\n");
		strcpy(zad_lekce,p);
		
		if(strcmp(hl_lekce,zad_lekce)==0) 		//pokud najde lekci odpovidajici hledane, vypise cely radek
		{
			printf("%s | %s | %s\n",prid_cz,prid_aj,zad_lekce);
		}
	}
	printf("---------------------------\n");
	fclose(f);
}

void preklad()
{
	char prid_cz[20];
	char prid_aj[20];
	char zad_lekce[20];
	char hl_slovo[20];
	char radek[80];
	
	FILE *f;
	char *p;
	
	printf("Zadej Ceske nebo Anglicke slovo: ");
	gets(hl_slovo); //zadani slova
	osetreni(hl_slovo);
	printf("PREKLAD\n");
	printf("---------------------------\n");
	f=fopen("slovnik.txt","r");
	while(fgets(radek,80,f)!=NULL)	
	{
		p=strtok(radek, "|");
		strcpy(prid_cz,p);
		p=strtok(NULL, "|");
		strcpy(prid_aj,p);
		p=strtok(NULL, "\n");
		strcpy(zad_lekce,p);
		
		if(strcmp(hl_slovo,prid_cz)==0 ||strcmp(hl_slovo,prid_aj)==0) 	//pokud se zadane slovo shoduje s nejakym aj nebo cj, vypise jej
		{
			printf("%s | %s | %s\n",prid_cz,prid_aj,zad_lekce);
		}
	}
	printf("---------------------------\n");
	fclose(f);
}

int pocet_slov() //celkovy pocet slov ve slovniku
{
	char radek[80];
	int pocet_sl=0;
	FILE *f;
	printf("POCET SLOV VE SLOVNIKU\n");
	printf("---------------------------\n");
	f=fopen("slovnik.txt","r");
	
	while(fgets(radek,80,f)!=NULL) 			//prochazi soubor, kazdy radek zvysi pocet slov o 1
	{
		pocet_sl++;
	}
	printf("Pocet Slovicek: %d\n",pocet_sl);
	printf("---------------------------\n");
	fclose(f);
	return pocet_sl;
}

void test_lekce()
{
	char prid_cz[20];
	char prid_aj[20];
	char zad_lekce[20];
	char hl_slovo[20];
	char radek[80];
	char hl_lekce[10];
	
	float celkove=0;
	
	int spravne=0, spatne=0, pocet=0;
	FILE *f;
	char *p;
	printf("TEST Z LEKCE\n");
	printf("---------------------------\n");
	printf("Test z lekce cislo: ");
	gets(hl_lekce);
	fflush(stdin);
	printf("---------------------------\n");
	f=fopen("slovnik.txt","r");
	while(fgets(radek,80,f)!=NULL)
	{
		p=strtok(radek,"|");
		strcpy(prid_cz,p);
		p=strtok(NULL,"|");
		strcpy(prid_aj,p);
		p=strtok(NULL,"\n");
		strcpy(zad_lekce,p);
		
		if(strcmp(hl_lekce,zad_lekce)==0)		 //hledani zadane lekce
		{
			printf("Zadane slovo: %s\n",prid_cz);
			printf("Anglicke slovo: ");
			gets(hl_slovo); //ulozi odpoved na test
			osetreni(hl_slovo);
			pocet++; //pricita k celkovemu poctu slov z testu
			if(strcmp(hl_slovo,prid_aj)==0) 			//kontrola odpovedi
			{
				spravne++;
			}
			else{
				spatne++;
			}
		}
	}
	fclose(f);
	printf("---------------------------\n");
	celkove=(float)spravne/pocet*100;			 //vypocet celkoveho hodnoceni
	printf("Pocet zadanych slov: %d\n",pocet);
	printf("Spravne odpovedi: %d\n",spravne);
	printf("Spatne odpovedi: %d\n",spatne);
	printf("---------------------------\n");
	printf("Celkove hodnoceni: %.2f %%\n",celkove); 	//nutno pouzit 2x % pro vypsani znaku %
	printf("---------------------------\n");
	
}

void nahodny_test()
{
	char prid_cz[20];
	char prid_aj[20];
	char zad_lekce[20];
	char hl_slovo[20];
	char radek[80];
	char hl_lekce[10];
	int nahodne[50];
	
	float celkove=0;
	
	int spravne=0, spatne=0, pocet=0,zad_slova=0, pocet_slovicek=0,i=0,j=0;	
	int cislo=0, cislo_r=0,pom=0;
	int zmena=0;
	
	FILE *f;
	char *p;
	pocet_slovicek=pocet_slov();
	
	do{
		printf("Zadej pocet slovicek: "); 		//pocet slov na testu, nesmi byt vetsi nez celkovy pocet
		scanf("%d",&zad_slova);
		fflush(stdin);
		if(zad_slova>pocet_slovicek)
		{
			printf("\nNESPRAVN POCET!\n");
		}
	}while(zad_slova>pocet_slovicek);
	time_t t;
	srand(time(NULL)); 		//inicializace srand
	for(i=0; i<zad_slova; i++) 		//osetreni aby gen. cisla nebyla vetsi nez max pocet slov ve slovniku
	{
		cislo=rand()%pocet_slovicek;
		do
		{
			zmena=0;
			for(j=0; j<zad_slova; j++)
			{
				if(nahodne[j]==cislo) 		//pokud je gen. cislo vetsi, prepise se
				{
					cislo=rand()%pocet_slovicek;
					zmena=1;
				}
			}
		}while(zmena==1);
		nahodne[i]=cislo; 		//ulozeni konecnych gen. cisel
	}
	do{
		zmena=0;
		for(i=0; i<zad_slova-1; i++) 		//musime gen. cisla seradit, aby jsme mohli pracovat se souborem
		{
			if(nahodne[i]>nahodne[i+1])
			{
				pom=nahodne[i];
				nahodne[i]=nahodne[i+1];
				nahodne[i+1]=pom;
				zmena=1;
			}
		}
	}while(zmena==1);
	i=0;
	j=0;
	f=fopen("slovnik.txt","r");
	printf("Zadane slova: \n");
	printf("---------------------------\n");
	rewind(f);
	while(fgets(radek,80,f)!=NULL) 		//stejne jako u testu z lekce
	{
		if(nahodne[i]==cislo_r)
		{
		p = strtok(radek,"|");
		strcpy(prid_cz,p);
		p = strtok(NULL, "|");
		strcpy(prid_aj,p);
		p = strtok(NULL,"\n");
		strcpy(zad_lekce,p);
		
		
			printf("\nCeske slovicko: %s\n",prid_cz);
			printf("Anglicky: ");
			gets(hl_slovo);
			osetreni(hl_slovo);
			pocet++;
			if(strcmp(hl_slovo,prid_aj)==0)
			{
				spravne++;
			}
			else
			{
				spatne++;
			}
			i++;
		}
		cislo_r++;		//zvetsujeme cislo radku
		
	}
	fclose(f);
	printf("---------------------------\n");
	celkove=(float)spravne/pocet*100;
	printf("Pocet zadanych slov: %d\n",pocet);
	printf("Spravne odpovedi: %d\n",spravne);
	printf("Spatne odpovedi: %d\n",spatne);
	printf("---------------------------\n");
	printf("Celkove hodnoceni: %.2f %%\n",celkove);
	printf("---------------------------\n");
	
}
