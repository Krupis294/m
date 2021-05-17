#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data {
    int id,strany;
    char nazev[20],autor[20];
    struct data *nasl, *pred;
}Tkniha;
Tkniha *prvni=NULL;

//funkce
void nacti(void);
void vypis(void);
void nacteni_z_souboru(void);
void zapis_do_souboru(void);
void razeni(void);
void vyhledavani(void);
void odstraneni(void);
void editace(void);

//main
int main(){
    int volba;
    do{
        printf("-1-Nacteni\n-2-Vypis\n-3-Nacteni z souboru\n-4-Zapis do souboru\n-5-Razeni knih\n-6-Hledani knih\n-7-Odstraneni knihy\n-8-Editace udaju o knize\nVyber:");
        scanf("%d",&volba);
        switch(volba){
            case 1: nacti(); break;
            case 2: vypis(); break;
            case 3: nacteni_z_souboru(); break;
            case 4: zapis_do_souboru(); break;
            case 5: razeni(); break;
            case 6: vyhledavani(); break;
            case 7: odstraneni(); break;
            case 8: editace(); break;
            default: break;
        }
    }while(volba!=0);
    return 0;
}

//Nacteni udaju do seznamu
void nacti(){
    Tkniha *novy;
    novy=(Tkniha*)malloc(sizeof(Tkniha));
    novy->pred=NULL;
    novy->nasl=NULL;
    printf("Zadej id knihy\n");
    scanf("%d",&novy->id);
    printf("Zadej pocet stran knihy\n");
    scanf("%d",&novy->strany);
    fflush(stdin);
    printf("Zadej autora knihy\n");
    gets(novy->autor);
    printf("Zadej nazev knihy\n");
    gets(novy->nazev);
    if(prvni==NULL) prvni=novy;
    else
    {
        novy->nasl=prvni;
        prvni->pred=novy;
        prvni=novy;
    }
}

//Vypis udaju z seznamu
void vypis(){
    Tkniha *p;
    printf("ID\tAutor\tNazev\tPocet stran\n");
    for(p=prvni;p!=NULL;p=p->nasl) printf("%d\t%s\t%s\t%d\n",p->id,p->autor,p->nazev,p->strany);
}

//Nacteni udaju z souboru do seznamu
void nacteni_z_souboru(){
    FILE *f;
    Tkniha *novy, pom;
    prvni=NULL;
    if ((f = fopen("knihy.dat","rb")) == NULL){
        printf("\nSoubor se nepovedlo otevrit\n");
    }
    else {
        while (fread(&pom, sizeof(Tkniha), 1, f) == 1) {
            novy = (Tkniha *) malloc(sizeof(Tkniha));
            *novy = pom;
            novy->pred = NULL;
            novy->nasl = NULL;
            if (prvni == NULL) prvni = novy;
            else {
                prvni->pred = novy;
                novy->nasl = prvni;
                prvni = novy;
            }
        }
        if(fclose(f)==EOF) printf("Soubor se nepodarilo zavrit");
        printf("\nKnihy z souboru byli uspesne pridany do seznamu\n");
    }
}

//Zapsani udaju z seznamu do souboru
void zapis_do_souboru(){
    FILE *f;
    Tkniha *p;
    if((f=fopen("knihy.dat","ab"))==NULL) printf("\nSoubor se nepodarilo otevrit");
    for(p=prvni; p!=NULL; p=p->nasl) fwrite(p,sizeof(Tkniha),1,f);
    if(fclose(f)==EOF) printf("\nSoubor se nepodarilo zavrit!");
    printf("\nKnihy z seznamu byli uspesne pridany do souboru\n");
}

//Razeni seznamu podle vyberu uzivatele
void razeni(){
    int volba;
    Tkniha *p;
    int pom_id,pom_strany,zamena;
    char pom_nazev[20],pom_autor[20];
    printf("Vyberte podle ceho chcete radit:\n1-Podle ID\n2-Podle Nazvu Knihy\n3-Podle Autora\nVase volba:");
    scanf("%d",&volba);
    fflush(stdin);
    switch(volba){
        case 1: do{
                zamena=0;
                for(p=prvni;p->nasl!=NULL;p=p->nasl){
                    if(p->id>p->nasl->id){
                        pom_id=p->id;
                        p->id=p->nasl->id;
                        p->nasl->id=pom_id;
                        strcpy(pom_nazev,p->nazev);
                        strcpy(p->nazev,p->nasl->nazev);
                        strcpy(p->nasl->nazev,pom_nazev);
                        pom_strany=p->strany;
                        p->strany=p->nasl->strany;
                        p->nasl->strany=pom_strany;
                        strcpy(pom_autor,p->autor);
                        strcpy(p->autor,p->nasl->autor);
                        strcpy(p->nasl->autor,pom_autor);
                        zamena=1;
                    }
                }
                }while(zamena==1);
                break;
        case 2: do{
                zamena=0;
                for(p=prvni;p->nasl!=NULL;p=p->nasl){
                    if(strcmp(p->nazev,p->nasl->nazev)>0){
                        pom_id=p->id;
                        p->id=p->nasl->id;
                        p->nasl->id=pom_id;
                        strcpy(pom_nazev,p->nazev);
                        strcpy(p->nazev,p->nasl->nazev);
                        strcpy(p->nasl->nazev,pom_nazev);
                        pom_strany=p->strany;
                        p->strany=p->nasl->strany;
                        p->nasl->strany=pom_strany;
                        strcpy(pom_autor,p->autor);
                        strcpy(p->autor,p->nasl->autor);
                        strcpy(p->nasl->autor,pom_autor);
                        zamena==1;
                    }
                }
            }while(zamena==1);
            break;
        case 3: do{
                zamena=0;
                for(p=prvni;p->nasl!=NULL;p=p->nasl){
                    if(strcmp(p->autor,p->nasl->autor)>0){
                        pom_id=p->id;
                        p->id=p->nasl->id;
                        p->nasl->id=pom_id;
                        strcpy(pom_nazev,p->nazev);
                        strcpy(p->nazev,p->nasl->nazev);
                        strcpy(p->nasl->nazev,pom_nazev);
                        pom_strany=p->strany;
                        p->strany=p->nasl->strany;
                        p->nasl->strany=pom_strany;
                        strcpy(pom_autor,p->autor);
                        strcpy(p->autor,p->nasl->autor);
                        strcpy(p->nasl->autor,pom_autor);
                        zamena==1;
                    }
                }
            }while(zamena==1);
            break;
    }
}

//Vyhledani knihy ze seznamu
void vyhledavani(void){
    int vyber,cis,i=0;
    char ret1[30];
    Tkniha *p;
    printf("Vyberte podle ceho chcete hledat knihu:\n1-Podle ID\n2-Podle Nazvu Knihy\n3-Podle Autora\nVase volba:");
    scanf("%d",&vyber);
    fflush(stdin);
    switch(vyber){
        case 1: printf("\nZadej ID:");
            fflush(stdin);
            scanf("%d",&cis);
            fflush(stdin);
            for(p=prvni;p!=NULL;p=p->nasl) if(p->id==cis) {
                    printf("\nID: %d\nAutor: %s\nNazev: %s\nPocet stran: %d\n\n", p->id, p->autor, p->nazev, p->strany);
                    i++;
                }
            break;
        case 2: printf("\nZadej nazev knihy:");
            fflush(stdin);
            gets(ret1);
            fflush(stdin);
            for(p=prvni;p!=NULL;p=p->nasl) if(!strcmp(p->nazev,ret1)){
                    printf("\nID: %d\nAutor: %s\nNazev: %s\nPocet stran: %d\n\n", p->id, p->autor, p->nazev, p->strany);
                    i++;
                }
            break;
        case 3: printf("\nZadej autora knihy:");
            fflush(stdin);
            gets(ret1);
            fflush(stdin);
            for(p=prvni;p!=NULL;p=p->nasl) if(!strcmp(p->autor,ret1)){
                    printf("\nID: %d\nAutor: %s\nNazev: %s\nPocet stran: %d\n\n", p->id, p->autor, p->nazev, p->strany);
                    i++;
                }
            break;
        default: break;
    }
    if(i==0) printf("V seznamu se nenachazi zadna kniha, kterou hledate");
}

//Ostraneni knihy z seznamu
void odstraneni(){
    Tkniha *p;
    int id,i=0;
    printf("Zadej ID knihy, ktery chcete smazat:");
    scanf("%d",&id);
    fflush(stdin);
    for(p=prvni;p!=NULL;p=p->nasl){
            //kdyz je jen jeden prvek
        if(p->id==id){
            printf("Kniha: ID: %d  Autor: %s  Nazev: %s  Pocet stran: %d", p->id, p->autor, p->nazev, p->strany);
            //kdyz je jen jeden prvek
            if(p->nasl==NULL && p->pred==NULL){
                free(prvni);
                prvni=NULL;
                printf("\nByla odstranena\n");
                i++;
            }
                //odstraneni prvniho
            else if(p->pred==NULL){
                free(prvni);
                prvni=NULL;
                prvni=p->nasl;
                p->nasl->pred=NULL;
                printf("\nByla odstranena\n");
                i++;
            }
                //odstraneni posledniho
            else if(p->nasl==NULL){
                p->pred->nasl=NULL;
                free(p);
                printf("\nByla odstranena\n");
                i++;
            }
                //odstraneni uprostred
            else{
                p->pred->nasl=p->nasl;
                p->nasl->pred=p->pred;
                free(p);
                printf("\nByla odstranena\n");
                i++;
            }
        }
    }
    if(i==0) printf("V seznamu se nenachazi zadna kniha, kterou hledate");
}

void editace(){
    char novy[50];
    int hl_id=0,volba_ed=0,str,vlb=0;
    Tkniha *p;
    do{
        printf("Zadej ID knihy pro editaci: ");
        scanf("%d", &hl_id);
        fflush(stdin);
        for(p=prvni;p!=NULL;p=p->nasl){
            if (hl_id==p->id) {
                printf("Kniha: ID: %d  Autor: %s  Nazev: %s  Pocet stran: %d\n", p->id, p->autor, p->nazev, p->strany);
                printf("Co chcete editovat?");
                printf("\n1 - Autora");
                printf("\n2 - Nazev");
                printf("\n3 - Pocet stran");
                printf("\nVolba: ");
                scanf("%d", &volba_ed);
                fflush(stdin);
                switch (volba_ed) {
                    case 1:
                        printf("\nZadej noveho autora: ");
                        gets(novy);
                        fflush(stdin);
                        strcpy(p->autor,novy);
                        printf("\nEditace probehla uspesne\n");
                        break;
                    case 2:
                        printf("\nZadej novy nazev: ");
                        gets(novy);
                        fflush(stdin);
                        strcpy(p->nazev,novy);
                        printf("\nEditace probehla uspesne\n");
                        break;
                    case 3:
                        printf("\nZadej novy pocet stran: ");
                        scanf("%d",&str);
                        fflush(stdin);
                        p->strany=str;
                        printf("\nEditace probehla uspesne\n");
                        break;
                }
            }
        }
        printf("\nChces jeste neco editovat?\n0-ano\n1-ne\n:");
        scanf("%d",&vlb);
    }while(vlb==0);
}
