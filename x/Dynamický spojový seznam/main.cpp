#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct prijimacky{
	int id_prijm;
	char jmeno[50];
	char prijmeni[50];
	int mat;
	int fyz;
	int vsp;
	
	struct prijimacky *pred, *nasl;
	
}Tprijimacky;

Tprijimacky *prvni=NULL;
void pridani();		//pridani studenta
void vypis();		//vypis studenta
void uloz_do_s ();
void nacti_ze_s();
void hledani_prijm();
void pismena_osetreni(char slovo[]);
void razeni();
void editace();
void nejlepsi();

int main()
{
	int volba=0, zamek=0;
	do{
	system("cls");
	printf("\nVyber si volbu: \n");
	printf("------------------------\n");
	printf("1 - Pridani\n");
	printf("2 - Vypis\n");
	printf("3 - Uloz do souboru\n");
	printf("4 - Nacti ze souboru\n");
	printf("5 - Hledani podle prijmeni\n");
	printf("6 - Razeni\n");
	printf("7 - Editace\n");
	printf("8 - Nejlepsi student\n");
	printf("0 - EXIT\n");
	printf("------------------------\n");
	printf("\nVolba: ");
	scanf("%d",&volba);
	

	switch(volba)
	{
	case 1: system("cls");
			pridani();zamek=0;
			system ("pause");
			break;
	case 2: system("cls");
			vypis();
			zamek=0;
			system ("pause");
			break;
	case 3: system("cls");
			uloz_do_s();
			zamek=0;
			system ("pause");
			break;
	case 4: system("cls");
			nacti_ze_s();
			zamek=0;
			system ("pause");
			break;
	case 5: system("cls");
			hledani_prijm();
			zamek=0;
			system ("pause");
			break;
	case 6: system("cls");
			razeni();
			zamek=0;
			system ("pause");
			break;
	case 7: system("cls");
			editace();
			zamek=0;
			system ("pause");
			break;
	case 8: system("cls");
			nejlepsi();
			zamek=0;
			system ("pause");
			break;
	case 0: exit(1);
			zamek=0;
			break;
	}
}while(zamek==0);
}

void pridani(){
	nacti_ze_s();
	int i=0;
	int chyba=0;
	Tprijimacky *novy;
	Tprijimacky *p;
	novy=(Tprijimacky*)malloc(sizeof(Tprijimacky));
	
	novy->pred=NULL;
	novy->nasl=NULL;
	
	do{
		chyba=0;
		printf("Zadej ID: ");
		scanf("%d", &novy->id_prijm);
		fflush(stdin);
		for(p=prvni; p!=NULL; p=p->nasl)
		if(novy->id_prijm == p->id_prijm)
		{
			printf("\n*****ZADANE ID JIZ EXISTUJE!*****\n");
			chyba=1;
		}
	}while(chyba==1);
	
	printf("\nZadej jmeno: ");
	gets(novy->jmeno);
	pismena_osetreni(novy->jmeno);
	
	printf("\nZadej prijmeni: ");
	gets(novy->prijmeni);
	pismena_osetreni(novy->prijmeni);
	
	do{
	printf("\nZadej hodnoceni matiky: ");
	scanf("%d",&novy->mat);
	fflush(stdin);
	if(novy->mat>20)
	{
		printf("\nHodnoceni musi byt od 0 do 20!\n");
	}
	if(novy->mat<0)
	{
		printf("\nHodnoceni musi byt od 0 do 20!\n");
	}
	}while(novy->mat>20 || novy->mat < 0);
	
	do{
	printf("\nZadej hodnoceni fyziky: ");
	scanf("%d",&novy->fyz);
	fflush(stdin);
	if(novy->fyz>20)
	{
		printf("\nHodnoceni musi byt od 0 do 20!\n");
	}
	if(novy->fyz<0)
	{
		printf("\nHodnoceni musi byt od 0 do 20!\n");
	}
	}while(novy->fyz>20 || novy->fyz < 0);
	
	do{
	printf("\nZadej hodnoceni VSP: ");
	scanf("%d",&novy->vsp);
	fflush(stdin);
	if(novy->vsp>20)
	{
		printf("\nHodnoceni musi byt od 0 do 20!\n");
	}
	if(novy->vsp<0)
	{
		printf("\nHodnoceni musi byt od 0 do 20!\n");
	}
	}while(novy->vsp>20 || novy->vsp < 0);
	
	if(prvni==NULL) prvni=novy;
	else{
		novy->nasl=prvni;
		prvni->pred=novy;
		prvni=novy;
	}
	printf("******************\n");
	printf("PRIDANO\n");
	printf("******************\n");
}

void vypis(){
	Tprijimacky *p;
	printf("\nVYPIS\n");
	printf("******************\n");
	for(p=prvni; p!=NULL; p=p->nasl)
	{
		printf("\nID: %d\nJmeno: %s\nPrijmeni: %s\nHodnoceni MATIKA: %d\nHodnoceni FYZIKA: %d\nHodnoceni VSP: %d\n\n",p->id_prijm,p->jmeno,p->prijmeni,p->mat,p->fyz,p->vsp);
	}
}

void uloz_do_s (){
	FILE *f;
	Tprijimacky *p;
	
	if((f=fopen("prijimacky.dat","wb"))==NULL)
	{
		printf("\nSoubor se nepodarilo otevrit");
	}
	for(p=prvni; p!=NULL; p=p->nasl)
	{
		fwrite(p,sizeof(Tprijimacky),1,f);
	}
	if(fclose(f)==EOF)
	{
		printf("\nSoubor se nepodarilo zavrit!");
	}
	printf("\n******ULOZENO******\n");
}

void nacti_ze_s()
{
	FILE *f;
	Tprijimacky *novy, pom;
	prvni=NULL;
	
	if ((f = fopen("prijimacky.dat","rb")) == NULL) 
	{
	  printf("\nSoubor se nepovedlo otevrit\n");
	}
	
	while(fread(&pom, sizeof(Tprijimacky),1,f)==1)
	{
		novy = (Tprijimacky*) malloc(sizeof(Tprijimacky));
		*novy = pom;
		novy->pred=NULL;
		novy->nasl=NULL;
		
		if(prvni==NULL) prvni=novy;
		else{
			prvni->pred=novy;
			novy->nasl=prvni;
			prvni=novy;
		}
	}
	if (fclose(f)==EOF) 
 	 { 
        printf("Soubor se nepodarilo zavrit"); 
 	 }
	printf("\n****NACTENO****\n");
}

void hledani_prijm()
{
	Tprijimacky *p;
	
	char hl_prijm[50];
	int pocet=0;
	
	nacti_ze_s();
	
	printf("Zadej cast prijmeni: ");
	fflush(stdin);
	gets(hl_prijm);
	pismena_osetreni(hl_prijm);
	for(p=prvni; p!=NULL; p=p->nasl)
	{
		if(strstr(p->prijmeni,hl_prijm)>0)
		{
			printf("\nID: %d\nJmeno: %s\nPrijmeni: %s\nHodnoceni MATIKA: %d\nHodnoceni FYZIKA: %d\nHodnoceni VSP: %d\n\n",p->id_prijm,p->jmeno,p->prijmeni,p->mat,p->fyz,p->vsp);
			pocet=1;
		}
		
	}
	if(pocet==0)
		{
			printf("\nNENALEZENO\n");
		}
}

void pismena_osetreni(char slovo[])
{
	int i;
	for(i=0;i<1;i++)
	{
		slovo[i]=toupper(slovo[i]);
	}
	for(i=1;i<50;i++)
	{
		slovo[i]=tolower(slovo[i]);
	}
}

void razeni(){
	nacti_ze_s();
	
	Tprijimacky *p,pom;
	int zamena, pom_mat, pom_fyz, pom_vsp, pom_id;
	char pom_jmeno[50],pom_prijmeni[50];
	int volb_r=0;
	
	printf("Zvol si razeni podle: ");
	printf("\n1 - Prijmeni");
	printf("\n2 - Podle matiky");
	printf("\n3 - Podle celkoveho hodnoceni");
	printf("\nVolba: ");
	scanf("%d",&volb_r);
	fflush(stdin);
	switch(volb_r)
	{
	case 1:
	//prijmeni
	do{
		zamena=0;
		for(p=prvni; p->nasl!=NULL; p=p->nasl)
		{
			if(strcmp(p->prijmeni,p->nasl->prijmeni)>0)
			{
				pom_id=p->id_prijm;
				p->id_prijm = p->nasl->id_prijm;
				p->nasl->id_prijm = pom_id;
				
				strcpy(pom_jmeno,p->jmeno);
				strcpy(p->jmeno,p->nasl->jmeno);
				strcpy(p->nasl->jmeno,pom_jmeno);
				
				strcpy(pom_prijmeni,p->prijmeni);
				strcpy(p->prijmeni,p->nasl->prijmeni);
				strcpy(p->nasl->prijmeni,pom_prijmeni);
				
				pom_mat=p->mat;
				p->mat = p->nasl->mat;
				p->nasl->mat = pom_mat;
				
				pom_fyz=p->fyz;
				p->fyz = p->nasl->fyz;
				p->nasl->fyz = pom_fyz;
				
				pom_vsp=p->vsp;
				p->vsp = p->nasl->vsp;
				p->nasl->vsp = pom_vsp;
				
				zamena = 1;
			}
		}
	}while(zamena == 1);
	printf("\n*****SERAZENO PODLE PRIJMENI*****\n");
	break;
	
	case 2:
		//Podle matiky
	do{
		zamena=0;
		for(p=prvni; p->nasl!=NULL; p=p->nasl)
		{
			if(p->mat > p->nasl->mat)
			{
				pom_id=p->id_prijm;
				p->id_prijm = p->nasl->id_prijm;
				p->nasl->id_prijm = pom_id;
				
				strcpy(pom_jmeno,p->jmeno);
				strcpy(p->jmeno,p->nasl->jmeno);
				strcpy(p->nasl->jmeno,pom_jmeno);
				
				strcpy(pom_prijmeni,p->prijmeni);
				strcpy(p->prijmeni,p->nasl->prijmeni);
				strcpy(p->nasl->prijmeni,pom_prijmeni);
				
				pom_mat=p->mat;
				p->mat = p->nasl->mat;
				p->nasl->mat = pom_mat;
				
				pom_fyz=p->fyz;
				p->fyz = p->nasl->fyz;
				p->nasl->fyz = pom_fyz;
				
				pom_vsp=p->vsp;
				p->vsp = p->nasl->vsp;
				p->nasl->vsp = pom_vsp;
				
				zamena = 1;
			}
		}
	}while(zamena == 1);
	printf("\n*****SERAZENO PODLE MATIKY*****\n");
	break;
	
	case 3:
		//podle nejlepsiho
		do{
			zamena=0;
		for(p=prvni;p->nasl!=NULL;p=p->nasl)
		{
        	if((p->mat + p->fyz + p->vsp) > (p->nasl->mat + p->nasl->fyz + p->nasl->vsp))
			{
            	pom_id=p->id_prijm;
				p->id_prijm = p->nasl->id_prijm;
				p->nasl->id_prijm = pom_id;
				
				strcpy(pom_jmeno,p->jmeno);
				strcpy(p->jmeno,p->nasl->jmeno);
				strcpy(p->nasl->jmeno,pom_jmeno);
				
				strcpy(pom_prijmeni,p->prijmeni);
				strcpy(p->prijmeni,p->nasl->prijmeni);
				strcpy(p->nasl->prijmeni,pom_prijmeni);
				
				pom_mat=p->mat;
				p->mat = p->nasl->mat;
				p->nasl->mat = pom_mat;
				
				pom_fyz=p->fyz;
				p->fyz = p->nasl->fyz;
				p->nasl->fyz = pom_fyz;
				
				pom_vsp=p->vsp;
				p->vsp = p->nasl->vsp;
				p->nasl->vsp = pom_vsp;
				
				zamena = 1;
        }
	}
	}while(zamena==1);
	printf("\n*****SERAZENO PODLE NEJLEPSICH*****\n");
	break;
	
}
}

void editace(){
	nacti_ze_s();
	int hl_id=0,volba_ed=0;
	char nove_jm[50];
	int ed_mat=0;
	int uloz=0;
	
	Tprijimacky *p;
	
	printf("Zadej ID studenta pro editaci: ");
	scanf("%d",&hl_id);
	fflush(stdin);
	
	for(p=prvni; p != NULL; p=p->nasl)
	{
		if(hl_id == p->id_prijm)
		{
			printf("Co chcete editovat?");
			printf("\n1 - Jmeno");
			printf("\n2 - Matika");
			printf("\nVolba: ");
			scanf("%d",&volba_ed);
			fflush(stdin);
			switch(volba_ed)
			{
				case 1: printf("\nZadej nove jmeno: ");
						gets(nove_jm);
						fflush(stdin);
						strcpy(p->jmeno,nove_jm);
						printf("\n****EDITOVANO****\n");
						break;
				case 2: printf("\nZadej nove hodnoceni z MATIKY: ");
						scanf("%d",&ed_mat);
						fflush(stdin);
						p->mat=ed_mat;
						printf("\n****EDITOVANO****\n");
						break;
			}
		}
	}
	printf("\nChcete ulozit zmeny do souboru?\n1 - Ano\n2 - Ne\nVolba: ");
	scanf("%d",&uloz);
	if(uloz == 1)
	{
		uloz_do_s();
	}
}

void nejlepsi(){
	Tprijimacky pom;
	Tprijimacky *p;
	nacti_ze_s();
	int soucet1=0, soucet2=0;
	for(p=prvni;p!=NULL;p=p->nasl)
	{
        if((p->mat + p->fyz + p->vsp) > (pom.mat + pom.fyz + pom.vsp))
		{
            pom.id_prijm = p->id_prijm;
            strcpy(pom.jmeno, p->jmeno);
            strcpy(pom.prijmeni, p->prijmeni);
            pom.mat = p->mat;
            pom.fyz = p->fyz;
            pom.vsp = p->vsp;
        }
	}
	printf("-------------------\nNelepsi student:\n-------------------");
	printf("\nID: %d\nJmeno: %s\nPrijmeni: %s\nHodnoceni MATIKA: %d\nHodnoceni FYZIKA: %d\nHodnoceni VSP: %d\n\n",pom.id_prijm,pom.jmeno,pom.prijmeni,pom.mat,pom.fyz,pom.vsp);
	
 
}

