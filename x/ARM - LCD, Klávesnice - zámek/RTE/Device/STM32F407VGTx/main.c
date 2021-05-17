#include "stm32f4xx.h"                  // Device header
#include "RTE_Components.h"             // Component selection
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


void gpio_config(void);
void klavesnice_config(void);
void LCD_config(void);
void Delay (uint32_t ms);
uint8_t getkey();
void LCD_ini (void);
void puts_LCD(int radek, char* ukaz);
void LCD_ctrlWR(uint16_t cmd);
void LCD_dataWR(uint16_t cmd);
void puts_LCD1(int radek, char* ukaz);

int main (void) 
{
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 10000); //konfigurace na 0.1ms
	
	LCD_config();
	gpio_config();
	LCD_ini();
	klavesnice_config();
	
	RCC->AHB1ENR |= (1UL<<0);
	
	char radek1[]="                ";
	char radek2[]="                ";
	char kod_temp[]="                ";
	char kod[]="                ";
	char ser_kod_temp[]="                ";
	char serkod[]="                ";
	
	float s_kod=2660;
	float zad_kod=0;
	float ser_kod=321;
	char noviny[100];
	uint16_t in=0;
	int i,j;
	int spatne=0;
	int spat_pokus=0;
	int case_kod=0;
	int zmena=0;
	
	
	
	do{	
		puts_LCD(2,radek1);
	//LCD_ctrlWR(0x18); //posun doleva; pri posunu doprava 0x1C
	puts_LCD1(1,"Makarenkova 1 Sommer Maxim");
	Delay(5000);
	
		for(i=0;i<4;i++)
		{
			kod[i]=' ';
		}

	for(i=0; i<5; i++)
		{
			kod_temp[i]= getkey();
			
			if(kod_temp[i] == '#') break;
			else
			{
				kod[i]= kod_temp[i];
			}
			puts_LCD(2,kod);
			Delay(8000);
			if(i==4)
			{
				Delay(10000);
			}
		}
		zad_kod=atof(kod);
		case_kod = (int)zad_kod;
		//LCD_ctrlWR(0x1C);
		puts_LCD(2,"****            ");
		zmena=0;
	switch(case_kod){
	case 321: 
				
		if (zad_kod == ser_kod)
		{
			puts_LCD(1,"Zadejte novy kod:");
			for(j=0; j<5; j++)
			{
				ser_kod_temp[j]= getkey();
			
				if(ser_kod_temp[j] == '#') break;
				else
				{
					serkod[j]= ser_kod_temp[j];
				}
				puts_LCD(2,serkod);
				Delay(8000);
				zad_kod=0;
		}
			s_kod=atof(serkod);
		puts_LCD(1,"   KOD ZMENEN   ");
		puts_LCD(2,radek2);
		zmena=1;
		Delay(10000);
		}
		break;
		
	default:
		if(zad_kod==s_kod)
		{
			puts_LCD(1,"     VSTUPTE    ");
			puts_LCD(2,radek2);
			spatne=0;
			spat_pokus=0;
			Delay(10000);
		}
		else
		{
			puts_LCD(1,"     Pristup    ");
			puts_LCD(2,"    ZAMITNUT    ");
			Delay(10000);
			spatne=1;
			spat_pokus++;
			if (spat_pokus==3)
			{
				puts_LCD(1,radek1);
				puts_LCD(2,radek2);
				puts_LCD(1,"     ALARM      ");
				Delay(10000);
			}
		}
		break;
}
	
	}while((spatne==1 && spat_pokus<3) || zmena==1);
}
	