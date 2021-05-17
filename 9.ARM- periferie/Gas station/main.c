#include "config_kit_ver3.c"
#include "stm32f4xx.h"                  // Device header
#include <stdio.h>
#include <math.h>

  
int main () {		
	uint8_t volb,tmp,z,p=0,btn;
	float lit=0,ben=30,naf=25,cena;
	char line1[10],line2[10];
	SystemCoreClockUpdate(); 							// do SystemCoreClock se nahraje frekvence jadra
	SysTick_Config(SystemCoreClock/ 10000); // konfigurace SysTick timeru na periodu 0.1ms	
	LCD_ini ();
	LCD_config();
	LCD_ini ();
	GPIOD_conf();
	gpio_config();
	klavesnice_config();
	puts_LCD(1,"1.Benzin  ");
	puts_LCD(2,"2.Nafta   ");
    volb=getkey();
	//RCC->AHB1ENR|=(1<<0);
	while(1) {
			btn=GPIOA->IDR;
			if(btn&0x1)
			{
			puts_LCD(1,"Pro tank ");
			puts_LCD(2,"dej 4.   ");
			z=getkey();
			if(z=='4')
			{
				
				do
				{
					z=getkey1();
					if(z==5)
					{
						break;
					}
					lit-=-0.1;
					if(volb=='1')
					{
					cena=lit*ben;
					}
					else
					{
					cena=lit*naf;
					}
					Delay(10);
					sprintf(line1," L:%f ",lit);
					sprintf(line2,"%2.fKc",cena);
					puts_LCD(1,line1);
					puts_LCD(2,line2);
					Delay(10000);
					if(lit==30)
					{
						break;
					}
				}
				while(z!='5');
			}
		}
		};
	};
