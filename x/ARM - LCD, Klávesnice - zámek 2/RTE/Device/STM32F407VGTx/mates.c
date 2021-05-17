
#include "stm32f4xx.h"                  // Device header
#include "RTE_Components.h"             // Component selection
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
void klavesnice_config(void);
void LCD_config(void);
void LCD_ini (void);
void puts_LCD(int radek, char* ukaz);
void Delay (uint32_t ms);
uint8_t getkey();



int ser_kod=123;
int uziv_kod=2660;
char kod[4]="    ";
char zadany_ser_kod[4]="    ";
char zadany_ser_kod_temp[4]="    ";
int novy_kod_int=0;
int spatne=0;
int spatne_pokus=0;
int i=0;
int kod_zad=0;
int zmena_kodu=0;
int i2=0;
int zadany_servisni_kod=0;
char novy_kod[5]="     ";
char kod_temp[5]="     ";
char line1[]="         ";
char line2[]="         ";
char novy_kod_temp[5]="     ";
int i3=0;



int main()
{


	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/10000);
	LCD_config();
	LCD_ini();
	klavesnice_config();

do{
	
for(i=0;i<5;i++)
{	

	
	puts_LCD(1,"dej kod");

	
	kod_temp[i]=getkey();
	if(kod_temp[i]=='#')
	{
		break;
	}else {
		kod[i]=kod_temp[i];
	}
	puts_LCD(2,kod);
}	
		
		kod_zad=atoi(kod);
		if(kod_zad==uziv_kod)
		{
			puts_LCD(1,"vstupte");
			puts_LCD(2,line2);
		    spatne=0;
		    spatne_pokus=0;
		    
		    for(i2=0;i2<5;i2++)
		    {
		    	zadany_ser_kod_temp[i2]=getkey();
					if(zadany_ser_kod_temp[i2]=='#')
					{
						break;
					}
					else{
						zadany_ser_kod[i2]=zadany_ser_kod_temp[i2];
					}
					puts_LCD(2,zadany_ser_kod);
				}
		    
		    zadany_servisni_kod=atoi(zadany_ser_kod);
		    	puts_LCD(2,line2);
		    	if(zadany_servisni_kod==ser_kod)
		    	{
		    		puts_LCD(1,"novykod:");
						for(i3=0; i3<5; i3++)
						{
		    		novy_kod_temp[i3]=getkey();
							if(novy_kod_temp[i3]=='#')
							{
								break;
							}else{
								novy_kod[i3]=novy_kod_temp[i3];
							}
							puts_LCD(2,novy_kod);
						}
		    		novy_kod_int=atoi(novy_kod);
		    		
		    		uziv_kod=novy_kod_int;
		    		zmena_kodu=1;
		    		
				}
		    	
		    	
		    	
			
		    	
		 	
			}
		    
			
			
		else{
			
			spatne++;
			puts_LCD(1,"Spatne");
			spatne_pokus=1;
			if(spatne==3)
			{
				puts_LCD(2,"picovina");
			}
		}
		}while((spatne<3 && spatne_pokus==1) ||zmena_kodu==1  );
		
	}
	
	


