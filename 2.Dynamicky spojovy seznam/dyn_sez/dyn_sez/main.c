//
//  main.c
//  dyn_sez
//
//  Created by kuba on 23.04.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct data{
    int id;
    char znacka[20];
    float hp;
    struct data *nasl, *pred;
}Tauto;

Tauto *prvni=NULL;

int nacteni(void);
void vypis(void);
void uloz(void);
void zsoub(void);
void sort(void);
void delete(void);
void edit(void);
void max(void);
void menu(void){
    printf("\n1-Nove auto\n");
    printf("2-Vypis\n");
    printf("3-Ulozeni do souboru\n");
    printf("4-Nacteni z souboru\n");
    printf("5-Serazeni\n");
    printf("6-Odstraneni\n");
    printf("7-editace\n");
    printf("8-nejvice hp\n");
    printf("Vyber->");
}

int main(int argc, const char * argv[]) {
    int vyber,k=1;
    do{
        menu();
        scanf("%d",&vyber);
        switch (vyber) {
            case 1: k=nacteni();
                break;
            case 2: vypis();
                break;
            case 3: uloz();
                break;
            case 4: zsoub();
                break;
            case 5: sort();
                break;
            case 6: delete();
                break;
            case 7:edit();
                break;
            case 8:max();
                break;
            default: break;
        }
    }while(vyber!=0);
    return 0;
}

int nacteni(void){
    Tauto *novy;
    novy=(Tauto*)malloc(sizeof(Tauto));
    if(novy==NULL) return 0;
    novy->pred=NULL;
    novy->nasl=NULL;
    printf("id-");
    scanf("%d",&novy->id);
    printf("hp-");
    scanf("%f",&novy->hp);
    printf("znacka-");
    fflush(stdin);
    gets(novy->znacka);
    if(prvni==NULL) prvni=novy;
    else{
        novy->nasl=prvni;
        prvni->pred=novy;
        prvni=novy;
    }
    return 1;
}

void vypis(void){
    Tauto *p;
    for(p=prvni;p!=NULL;p=p->nasl) printf("ID:%d\tZnacka:%s\tHP:%.0f\n",p->id,p->znacka,p->hp);
}

void uloz(void){
    FILE *f;
    Tauto *p;
    f=fopen("auta.dat", "wb");
    for(p=prvni;p!=NULL;p=p->nasl) fwrite(p, sizeof(Tauto), 1, f);
    fclose(f);
}

void zsoub(void){
    FILE *f;
    prvni=NULL;
    Tauto *p,pom;
    p=(Tauto*)malloc(sizeof(Tauto));
    f=fopen("auta.dat", "rb");
    while(fread(&pom, sizeof(Tauto), 1, f)){
        p=(Tauto*)malloc(sizeof(Tauto));
        *p=pom;
        p->pred=NULL;
        p->nasl=NULL;
        if(prvni==NULL) prvni=p;
        else{
            p->nasl=prvni;
            prvni->pred=p;
            prvni=p;
        }
    }
    fclose(f);
}

void sort(void){
    Tauto *p;
    int zamena,id;
    char znacka[20];
    float hp;
    do{
        zamena=0;
        for(p=prvni;p->nasl!=NULL;p=p->nasl){
            if(p->hp>p->nasl->hp){
                id=p->id;
                p->id=p->nasl->id;
                p->nasl->id=id;
                hp=p->hp;
                p->hp=p->nasl->hp;
                p->nasl->hp=hp;
                strcpy(znacka, p->znacka);
                strcpy(p->znacka, p->nasl->znacka);
                strcpy(p->nasl->znacka,znacka);
                zamena=1;
            }
        }
    }while(zamena!=0);
}

void delete(void){
    Tauto *p;
    int id,k=0;
    printf("Zadej id ktere se ma smazat:");
    scanf("%d",&id);
    for(p=prvni;p!=NULL;p=p->nasl){
        if(p->id==id){
            //sam
            if(p->pred==NULL && p->nasl==NULL){
                free(prvni);
                prvni=NULL;
            }
            //posledni
            else if(p->nasl==NULL){
                p->pred->nasl=NULL;
                free(p);
            }
            //prvni
            else if(p->pred==NULL){
                free(prvni);
                prvni=NULL;
                prvni=p->nasl;
                p->nasl->pred=NULL;
            }
            //prostred
            else{
                p->pred->nasl=p->nasl;
                p->nasl->pred=p->pred;
                free(p);
            }
            k++;
        }
    }
    
    if(k==0) printf("Nebyl nalezen");
    else printf("Odstranen");
}

void edit(void){
    Tauto *p;
    int hled,k=0,id;
    float hp;
    char znacka[20];
    printf("Zadej id ktere se ma editovat:");
    scanf("%d",&hled);
    for(p=prvni;p!=NULL;p=p->nasl){
        if(p->id==hled){
            printf("Zadej nove id:");
            scanf("%d",&id);
            printf("Zadej novou znacku:");
            fflush(stdin);
            gets(znacka);
            printf("Zadej nove hp:");
            scanf("%f",&hp);
            p->hp=hp;
            p->id=id;
            strcpy(p->znacka,znacka);
            k++;
        }
    }
    if(k==0) printf("no neni tam");
}

void max(void){
    Tauto *p=prvni;
    float max=p->hp;
    for(p=p->nasl;p!=NULL;p=p->nasl){
        if(p->hp>max) max=p->hp;
    }
    for(p=prvni;p!=NULL;p=p->nasl){
        if(p->hp==max) printf("ID:%d\tZnacka:%s\tHP:%.0f\n",p->id,p->znacka,p->hp);
    }
}
