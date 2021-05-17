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
	float p_cena;
	float haha;
	char radek1[]="        ";
	char radek2[]="        ";
	char cena[]="        ";
	char cena_temp[]="        ";
	char kl_palivo, klavesa1,kl3;
	float litry;
	char tankovani;
	char stop;
	char tank[]="        ";
	int tecka=0;

	
	
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 10000);
	
	gpio_config();
	klavesnice_config();
	LCD_config();
	LCD_ini();
	
	do{
	puts_LCD(1,"1 - BENZ");
	puts_LCD(2,"2 - NAFT");
	kl_palivo=getkey();
	Delay(1000);
	}while(kl_palivo != '1' && kl_palivo != '2');
	puts_LCD(2,radek1);
	
	puts_LCD(1,"CENA/l  ");
	for(i=0; i < 5; i++)
	{
		cena_temp[i]=getkey();
		Delay(1000);
		if(cena_temp[i]=='.' && tecka==1)
		{
			do{
				cena_temp[i]=getkey();
			}while(cena_temp[i]=='.');
		}
		else if(cena_temp[i] == '.'){
			tecka=1;
		}
		else{
		tecka=0;
		}
		
		if(cena_temp[i]=='#') break;
		else{
				cena[i]=cena_temp[i];
		}
		puts_LCD(2,cena);
		Delay(1000);
	}
	
	p_cena=atof(cena);
	puts_LCD(1,radek1);
	puts_LCD(2,radek2);
	

		litry=0;
		puts_LCD(1,"1-T  2-S");
		tankovani=getkey();
		Delay(1000);
		if(tankovani=='1')
		{
				do{
				litry = litry+0.01;
				sprintf(radek1,"%.2f l   ",litry);
				puts_LCD(2,radek1);
					stop=getkey1();
					if(litry>=20) break;
				}while(stop != '2');
				Delay(1000);
				if(getkey()=='2')
				{
					puts_LCD(1,"        ");
					puts_LCD(2,"        ");
					sprintf(radek2,"%.2f Kc ",litry*p_cena);
					puts_LCD(1,"CEL CENA");
					puts_LCD(2,radek2);
					Delay(100);
				}
			
		}

		}
