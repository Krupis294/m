//Marek Pukowiec 2020 4.B SPŠE HAVÍROV
#include "stm32f4xx.h"                  // Device header
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void gpio_config(void);
void klavesnice_config(void);
void LCD_config(void);
uint8_t getkey();
void LCD_ini (void);
void puts_LCD(int radek, char* ukaz);
void Delay (uint32_t ms);
uint8_t getkey1();
uint8_t getkey2();

	

int main(void){
	int i;
	float b_cena;
	char radek1[]="        ";
	char radek2[]="        ";
	char cena[]="        ";
	char cena_temp[]="        ";
	char kl_palivo, klavesa1,kl3,pom;
	float litry;
	char tankovani;
	char stop;
	char tank[]="        ";

	
	
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 10000);
	
	gpio_config();
	klavesnice_config();
	LCD_config();
	LCD_ini();
	
	do{
	puts_LCD(1,"1 - BENZ");
	puts_LCD(2,"2 - NAFT");
	kl_palivo=getkey(); //Výber mezi Benzínem a Naftou
	Delay(1000);
	}while(kl_palivo != '1' && kl_palivo != '2');
	
	puts_LCD(2,radek1);
	if(kl_palivo=='1'){
		b_cena=28.20;
	}else if(kl_palivo=='2'){
		b_cena=27.10;
	}
		puts_LCD(1,"CENA/l  "); 
		sprintf(cena,"%.2f",b_cena); //Výpis ceny za litr
		puts_LCD(2,radek2);
		puts_LCD(2,cena);
		//b_cena=atof(cena);
		//puts_LCD(1,radek1);
	do{
		pom='1';
		pom=getkey();
		Delay(1000);
	}while(pom!='#');
		litry=0;
		puts_LCD(1,"4-T  5-S"); //4 tece 5 stop
		puts_LCD(2,"        ");
		tankovani=getkey1();
		Delay(1000);
		if(tankovani=='4')
		{
				do{
				litry = litry+0.01;
				sprintf(radek1,"%.2f l   ",litry);
				puts_LCD(2,radek1);
				stop=getkey1();
				if(litry>=30) break;
				}while(stop != '5');
				Delay(1000);
				if(getkey()=='5')
				{
					puts_LCD(1,"        ");
					puts_LCD(2,"        ");
					sprintf(radek1,"%.2fL   ",litry);
					sprintf(radek2,"%.2f Kc ",litry*b_cena);
					puts_LCD(1,radek1);
					puts_LCD(2,radek2);
					Delay(100);
				}
		}
	}
