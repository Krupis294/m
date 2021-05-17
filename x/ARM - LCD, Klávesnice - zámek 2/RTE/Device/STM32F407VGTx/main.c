#include "stm32f4xx.h"                  // Device header
#include "RTE_Components.h"             // Component selection
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void klavesnice_config(void);
void LCD_config(void);
void Delay (uint32_t ms);
uint8_t getkey();
void LCD_ctrlWR(uint16_t cmd);
void LCD_dataWR(uint16_t cmd);
void LCD_ini (void);
void puts_LCD(int radek, char* ukaz);

int main()
{
	int nove=0, y=0;
	char zad_kod[]="         ";
	char novy_kod[]="         ";
	char line1[]="         ";
	int kod=2660, ser_kod=321, i=0, koder=0, pocet=0, pom=0;
	
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/10000);
	
	LCD_config();	
	LCD_ini();
	klavesnice_config();
	
	puts_LCD(1," Zamek  ");
	do
	{
		y=0;
	for(i=0;i<5;i++)
	{
		zad_kod[i]=getkey();
		if(zad_kod[i]=='#')
	{	
		zad_kod[i]='\0';
		break;
	}
	puts_LCD(2,zad_kod);
		
	}
	puts_LCD(2,line1);
	koder=atoi(zad_kod);
	switch(koder)
	{
		case 321:
			if(koder==ser_kod)
		{
			puts_LCD(1,"Novy kod");
			for(i=0;i<5;i++)
			{
				novy_kod[i]=getkey();
				if(novy_kod[i]=='#')
			{	
				novy_kod[i]='\0';
				break;
			}
			puts_LCD(2,novy_kod);
			}
			nove=atoi(novy_kod);
			kod=nove;
			y=1;
			puts_LCD(1," zadano ");
			Delay(10000);
			puts_LCD(2,"        ");
			puts_LCD(1," Zamek  ");
			break;
		}
		
		default:
		if(koder==kod)
		{
			puts_LCD(2,"Povoleno ");
		}

		else if(koder!=kod) 
		{
			puts_LCD(2,"  Spatne   ");
			pom=1;
			pocet++;
		}
	
	if(pocet==3)
	{
		puts_LCD(2,"   Alarm   ");
	}
	
}
}while((pocet<3 && pom==1) || y==1);
	}