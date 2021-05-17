//
//  main.c
//  sracka_dynamicky_seznam
//
//  Created by kuba on 16.05.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data{
    int vek;
    char jmeno[8];
    float vyska;
    struct data *nasl,*pred;
}TStud;

TStud *prvni=NULL;

void menu(){
    printf("1-Novy\n");
    printf("2-Vypis\n");
    printf("3-Do soub\n");
    printf("4-Z soub\n");
    printf("5-Sort\n");
    printf("6-Delete\n");
    printf("7-Editace\n");
    printf("8-Nejvyssi\n");
    printf("0-exit\n");
    printf("Volba:");
}
void novy(void);
void vypis(void);
void do_s(void);
void z_s(void);
void sort(void);
void del(void);
void edit(void);
void nej(void);

int main(int argc, const char * argv[]) {
    int volba;
    do{
        menu();
        scanf("%d",&volba);
        switch (volba) {
            case 1: novy();
                break;
            case 2: vypis();
                break;
            case 3: do_s();
                break;
            case 4: z_s();
                break;
            case 5: sort();
                break;
            case 6: del();
                break;
            case 7: edit();
                break;
            case 8: nej();
                break;
            default: break;
        }
    }while(volba!=0);
    return 0;
}

void novy(){
    TStud *novy;
    novy=(TStud*)malloc(sizeof(TStud));
    novy->pred=NULL;
    novy->nasl=NULL;
    printf("Zadej jmeno studenta:");
    fflush(stdin);
    scanf("%s",&novy->jmeno);
    fflush(stdin);
    printf("Zadej vek studenta:");
    scanf("%d",&novy->vek);
    printf("Zadej vysku studenta:");
    scanf("%f",&novy->vyska);
    if(prvni==NULL) prvni=novy;
    else{
        prvni->pred=novy;
        novy->nasl=prvni;
        prvni=novy;
    }
}

void vypis(){
    TStud *p;
    for(p=prvni;p!=NULL;p=p->nasl) printf("Jmeno:%7s Vek:%2d Vyska%4.1f\n",p->jmeno,p->vek,p->vyska);
}

void do_s(){
    TStud *p;
    FILE *f;
    f=fopen("data.lmao","wb");
    for(p=prvni;p!=NULL;p=p->nasl) fwrite(p,sizeof(TStud),1,f);
    fclose(f);
}
void z_s(){
    TStud *novy,pom;
    FILE *f;
    f=fopen("data.lmao","rb");
    prvni=NULL;
   // novy=(TStud*)malloc(sizeof(TStud));
    while(fread(&pom,sizeof(TStud),1, f)){
        novy=(TStud*)malloc(sizeof(TStud));
        *novy=pom;
        novy->pred=NULL;
        novy->nasl=NULL;
        if(prvni==NULL) prvni=novy;
        else{
            prvni->pred=novy;
            novy->nasl=prvni;
            prvni=novy;
        }
    }
    fclose(f);
}

void sort(){
    TStud *p;
    int vek;
    char jmeno[8];
    float vyska;
    
    int zamena=0;
    for(p=prvni;p->nasl!=NULL;p=p->nasl){
        do{
            zamena=0;
            if(p->vyska<p->nasl->vyska){
                vek=p->vek;
                p->vek=p->nasl->vek;
                p->nasl->vek=vek;
                vyska=p->vyska;
                p->vyska=p->nasl->vyska;
                p->nasl->vyska=vyska;
                strcpy(jmeno, p->jmeno);
                strcpy(p->jmeno,p->nasl->jmeno );
                strcpy(p->nasl->jmeno, jmeno);
                zamena=1;
            }
        }while(zamena==1);
    }
}

void del(){
    TStud *p;
    int k=0;
    char jmeno[8];
    printf("Zadej jmeno pro mazani:");
    fflush(stdin);
    scanf("%s",&jmeno);
    fflush(stdin);
    for(p=prvni;p!=NULL;p=p->nasl){
        if(!strcmp(jmeno,p->jmeno)){
            if(p->pred==NULL && p->nasl==NULL){ //jeden samotny
                free(prvni);
                prvni=NULL;
            }
            else if(p->pred==NULL){ //prvni
                free(prvni);
                prvni=NULL;
                prvni=p->nasl;
                p->nasl->pred=NULL;
            }
            else if(p->nasl==NULL){ //posledni
                p->pred->nasl=NULL;
                free(p);
            }
            else{
                p->pred->nasl=p->nasl;
                p->nasl->pred=p->pred;
                free(p);
            }
            k++;
        }
    }
    if(k==0) printf("Nenalezen Student");
}

void edit(void){
    TStud *p;
    int k=0;
    char jmeno[8];
    printf("Zadej jmeno pro mazani:");
    fflush(stdin);
    scanf("%s",&jmeno);
    fflush(stdin);
    for(p=prvni;p!=NULL;p=p->nasl){
        if(!strcmp(jmeno,p->jmeno)){
            printf("Zadej nove jmeno studenta:");
            fflush(stdin);
            scanf("%s",&p->jmeno);
            fflush(stdin);
            printf("Zadej novy vek studenta:");
            scanf("%d",&p->vek);
            printf("Zadej novou vysku studenta:");
            scanf("%f",&p->vyska);
            k++;
        }
    }
    if(k==0) printf("Nenalezen Student");
}

void nej(){
    TStud *p;
    float vyska=prvni->vyska;
    for(p=prvni;p!=NULL;p=p->nasl){
        if(p->vyska>vyska) vyska=p->vyska;
    }
    for(p=prvni;p!=NULL;p=p->nasl) if(p->vyska==vyska) printf("Jmeno:%7s Vek:%2d Vyska%4.1f\n",p->jmeno,p->vek,p->vyska);
}
