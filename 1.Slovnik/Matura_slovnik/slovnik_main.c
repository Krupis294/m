//
//  main.c
//  slovnik
//
//  Created by Jakub Lengsfeld on 16/01/2020.
//  Copyright © 2020 Jakub Lengsfeld. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include<ctype.h>

void nacteni(void);
int vypis(void);
void vypis_lekce(int pocet);
void preklad(int pocet);
float test_lekce(int pocet);
float nah_test(int pocet);
int pocet_slov(void);
char pismena(char slovo[]);
void edit(int pocet);
int main(int argc, char *argv[]){
    int volba,pocet = 0;
    float prumer,nah_prumer;
    do{
        printf("\n\t0-exit\n\t1-pridani slova\n\t2-vypis slovicek\n\t3-vypis z lekce\n\t4-preklad\n\t5-testovani z dane lekce\n\t6-nahodne testovani\n\t7-editace/mazani\n\tVyber:");
        scanf("%d",&volba);
        switch(volba){
            case 1: nacteni();
                    break;
            case 2: vypis();
                    break;
            case 3: vypis_lekce(pocet);
                    break;
            case 4: preklad(pocet);
                    break;
            case 5: prumer=test_lekce(pocet);
                    printf("%.1f %c Uspesnost",prumer,37);
                    break;
            case 6: nah_prumer=nah_test(pocet);
                    printf("%.1f %c Uspesnost",nah_prumer,37);
                    break;
            case 7: edit(pocet);
                    break;
            default: return 0;
        }
    }while(volba!=0);
    return 0;
}
void edit(int pocet){
    FILE *f,*g;
    char x[80],cz[20],en[20],*tok,zmena[20],slovo[20];
    int select,p=0,lekce,vyber,i=0;
    printf("1-edit\n2-delete\nVolba:");
    scanf("%d",&select);
    switch (select) {
        case 1: printf("Zadej slovicko ktere chces zmenit:");
                scanf("%s",slovo);
                pismena(slovo);
                printf("1-cz\n2-en\nVyber co u nej chces zmenit:");
                scanf("%d",&vyber);
                printf("Napis slovicko za ktere ho zmenis:");
                scanf("%s",zmena);
                f= fopen("slovnik.txt","r");
                g= fopen("prepis.txt","w");
                while(fgets(x,80,f)!=NULL){
                    tok=strtok(x,"/");
                    lekce=atoi(tok);
                    tok=strtok(NULL,"/");
                    strcpy(cz,tok);
                    tok=strtok(NULL,"/");
                    strcpy(en,tok);
                    if(strcmp(slovo, cz)==0){
                        if(vyber==1){
                            if(i==0){
                                fprintf(g,"%d/%s/%s/",lekce,zmena,en);
                            }
                            else{
                                fprintf(g,"\n%d/%s/%s/",lekce,zmena,en);
                            }
                        }
                        else if (vyber==2){
                            if(i==0){
                                fprintf(g,"%d/%s/%s/",lekce,cz,zmena);
                            }
                            else{
                                fprintf(g,"\n%d/%s/%s/",lekce,cz,zmena);
                            }
                        }
                        p++;
                    }
                    else if (strcmp(slovo, en)==0){
                        if(vyber==1){
                           if(i==0){
                               fprintf(g,"%d/%s/%s/",lekce,zmena,en);
                           }
                           else{
                               fprintf(g,"\n%d/%s/%s/",lekce,zmena,en);
                           }
                        }
                        else if (vyber==2){
                            if(i==0){
                                fprintf(g,"%d/%s/%s/",lekce,cz,zmena);
                            }
                            else{
                                fprintf(g,"\n%d/%s/%s/",lekce,cz,zmena);
                            }
                        }
                        p++;
                    }
                    else{
                         if(i==0){
                             fprintf(g,"%d/%s/%s/",lekce,cz,en);
                         }
                         else{
                             fprintf(g,"\n%d/%s/%s/",lekce,cz,en);
                         }
                    }
                    i++;
                }
                if(p==0){
                    printf("Toto slovicko zde nevedeme");
                }
                fclose(f);
                fclose(g);
                rename("prepis.txt", "slovnik.txt");
                break;
        case 2: printf("Zadej slovicko ktere chces smazat:");
                scanf("%s",slovo);
                pismena(slovo);
                f= fopen("slovnik.txt","r");
                g= fopen("prepis.txt","w");
                while(fgets(x,80,f)!=NULL){
                    tok=strtok(x,"/");
                    lekce=atoi(tok);
                    tok=strtok(NULL,"/");
                    strcpy(cz,tok);
                    tok=strtok(NULL,"/");
                    strcpy(en,tok);
                    if(strcmp(slovo, cz)==0){
                        p++;
                    }
                    else if (strcmp(slovo, en)==0){
                        p++;
                    }
                    else{
                        if(i==0){
                            fprintf(g,"%d/%s/%s/",lekce,cz,en);
                        }
                        else{
                            fprintf(g,"\n%d/%s/%s/",lekce,cz,en);
                        }
                    }
                    i++;
                }
                if(p==0){
                    printf("Toto slovicko zde nevedeme");
                }
                fclose(f);
                fclose(g);
                rename("prepis.txt", "slovnik.txt");
                break;
            
        default: printf("Spatna moznost");
                 system("cls");
                 break;
    }
}
float nah_test(int pocet){
    FILE *f;
    float prumer = 0.0,spravne=0;
    int volba,i,j,pole[30];
    char x[80],*tok,cz[20],test[20],en[20];
    do{
    printf("\nZadej pocet slovicek, z kterech chces byt testovany:");
    scanf("%d",&volba);
    }while(volba<1 || volba>pocet);
    srand( (unsigned) time(NULL));
            for(i=0;i<volba;i++){
                pole[i]=rand()%pocet;
                if(pole[i]==0) pole[i]=rand()%pocet;
            for(j=0;j<i;j++){
                while(pole[j]==pole[i]){
                    pole[j]=rand()%pocet;
            }
        }
    }
    for(i=0;i<volba;i++){
        f= fopen("slovnik.txt","r");
        for(j=0;j<pole[i];j++){
            fgets(x,80,f);
        }
        tok=strtok(x,"/");
        tok=strtok(NULL,"/");
        strcpy(cz,tok);
        tok=strtok(NULL,"/");
        strcpy(en,tok);
            printf("Slovicko: %s\nPreklad:",cz);
            fflush(stdin);
            scanf("%s",test);
            pismena(test);
            if(strcmp(test,en)==0){
                spravne++;
                printf("\nSpravne\n\n");
            }
            else printf("\nSpatne\n\n");
        fclose(f);
    }
    prumer=(spravne/volba)*100;
    return prumer;
}
float test_lekce(int pocet){
    FILE *f;
    float prumer = 0.0,spravne=0,count = 0;
    int volba,lekce;
    char x[80],*tok,cz[20],test[20],en[20];
    f= fopen("slovnik.txt","r");
    printf("Zadej cislo lekce:");
    scanf("%d",&volba);
    while(fgets(x,40,f)!=NULL){
        tok=strtok(x,"/");
        lekce=atoi(tok);
        tok=strtok(NULL,"/");
        strcpy(cz,tok);
        tok=strtok(NULL,"/");
        strcpy(en,tok);
        if(volba==lekce){
            printf("Slovicko: %s\nPreklad:",cz);
            fflush(stdin);
            scanf("%s",test);
            pismena(test);
            if(strcmp(test,en)==0){
                spravne++;
                printf("\nSpravne\n\n");
            }
            else printf("\nSpatne\n\n");
            count++;
        }
    }
    prumer=(spravne/count)*100;
    fclose(f);
    return prumer;
}
void preklad(int pocet){
    FILE *f;
    char volba[20],x[80],*tok,cz[20],en[20];
    int lekce,p=0;
    f= fopen("slovnik.txt","r");
    printf("Zadej slovicko:");
    scanf("%s",volba);
    pismena(volba);
    while(fgets(x,40,f)!=NULL){
        tok=strtok(x,"/");
        lekce=atoi(tok);
        tok=strtok(NULL,"/");
        strcpy(cz,tok);
        tok=strtok(NULL,"/");
        strcpy(en,tok);
        if(strcmp(volba, cz)==0){
            printf("Ceske slovicko: %s Anglicky preklad: %s",cz,en);
            p++;
        }
        else if (strcmp(volba, en)==0){
             printf("Cesky preklad: %s Anglicke slovicko: %s",cz,en);
            p++;
        }
    }
    if(p==0){
        printf("Toto slovicko zde nevedeme");
    }
    fclose(f);
}
void vypis_lekce(int pocet){
    FILE *f;
    int volba,i,lekce;
    char x[80],cz[20],en[20],*tok;
    printf("Zadej lekci, kterou chces vypsat:");
    scanf("%d",&volba);
    f= fopen("slovnik.txt","r");
    i=0;
    while(fgets(x,40,f)!=NULL){
        tok=strtok(x,"/");
        lekce=atoi(tok);
        if(lekce==volba){
            tok=strtok(NULL,"/");
            strcpy(cz,tok);
            tok=strtok(NULL,"/");
            strcpy(en,tok);
            printf("%d %s %s\n",lekce,cz,en);
        }
        i++;
    }
    fclose(f);
}
int vypis(){
    FILE *f;
    char x[200],*tok;
    int i;
    f= fopen("slovnik.txt","r");
    fflush(stdin);
    if(f==NULL){
      printf("\nSoubor se nepovedlo otevrit\n");
        return 0;
    }
    i=0;
    while(fgets(x,40,f)!=NULL){
        tok=strtok(x,"/");
        while(tok!=NULL){
        printf(" %s",tok);
        tok=strtok(NULL,"/");
    }
        i++;
    }
    fclose(f);
    return i;
}
void nacteni(){
    int zad_lekce,lekce,k=0;
    char zad_cz[20],zad_en[20],x[200],*tok,cz[20],en[20];
    FILE *f;
    printf("\nZadej cislo lekce:");
    scanf("%d",&zad_lekce);
    printf("Zadej ceske slovicko:");
    fflush(stdin);
    scanf("%s",zad_cz);
    pismena(zad_cz);
    printf("Zadej anglicke slovicko:");
    scanf("%s",zad_en);
    pismena(zad_en);
    fflush(stdin);
    f=fopen("slovnik.txt","r");
    while(fgets(x,40,f)!=NULL){
        tok=strtok(x,"/");
        lekce=atoi(tok);
        tok=strtok(NULL,"/");
        strcpy(cz,tok);
        tok=strtok(NULL,"/");
        strcpy(en,tok);
        if(strcmp(zad_cz,cz)==0){
            printf("Toto slovicko zde uz mame");
            k++;
        }
        else if(strcmp(zad_en,en)==0){
            printf("Toto slovicko zde uz mame");
            k++;
        }
    }
    fclose(f);
    if(k==0){
    f=fopen("slovnik.txt","a");
    fprintf(f,"\n%d/%s/%s/",zad_lekce,zad_cz,zad_en);
    fclose(f);
    }
}
int pocet_slov(){
    FILE *f;
    char x[200],*tok;
    int i;
    f= fopen("slovnik.txt","r");
    i=0;
    while(fgets(x,40,f)!=NULL){
        tok=strtok(x,"/");
        while(tok!=NULL){
        tok=strtok(NULL,"/");
    }
        i++;
    }
    fclose(f);
    return i;
}
char pismena(char slovo[]){
    int i=0;
    while(slovo[i]){
        if(slovo[i]>='A' && slovo[i]<='Z'){
            slovo[i]+=32;
        }
        i++;
    }
    return *slovo;
}
