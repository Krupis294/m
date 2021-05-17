#include "stm32f4xx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void LCD_ctrlWR(uint16_t cmd);
void LCD_dataWR(uint16_t cmd);
void LCD_ini (void);
void puts_LCD(int radek, char* ukaz);
void LCD_config(void);
void klavesnice_config(void);
uint8_t getkey(void);
void Delay();
int i,k,spatne;
char cislo[5];
char heslo[5]="1234",admin[5]="0000";
int main(){
		SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/10000); //0.1ms
	klavesnice_config();
	LCD_config();
	LCD_ini();
	
	while(1){
	spatne=0;
	do{
		puts_LCD(1,"HESLO : ");
		LCD_ctrlWR(0xC0);
		for(i=0;i<4;i++){
            puts_LCD(1,"HESLO : ");
            LCD_ctrlWR(0xC0);
            k=0;
            while(k<i){
                LCD_dataWR('*');
                k++;
            }
            cislo[i]=getkey();
            LCD_dataWR(cislo[i]);
            Delay(6000);
		}
		puts_LCD(1,"        ");
		puts_LCD(2,"        ");
		if(!strcmp(cislo,admin)){
			puts_LCD(1,"Nove:   ");
            LCD_ctrlWR(0xC0);
            for(i=0;i<4;i++){
                    heslo[i]=getkey();
                    LCD_dataWR(heslo[i]);
            }
		}
		else if(strcmp(cislo,heslo)){
            spatne++;
            puts_LCD(1," SPATNE ");
            puts_LCD(2," SPATNE ");
        }
		else if(!strcmp(cislo,heslo)){
            puts_LCD(1,"OTEVRENO");
            puts_LCD(2,"OTEVRENO");
		}
		Delay(6000);
		puts_LCD(1,"        ");
		puts_LCD(2,"        ");
    }while(spatne!=3);
    puts_LCD(1,"ALARM   ");
    puts_LCD(2,"ALARM   ");
    Delay(6000);
    puts_LCD(1,"        ");
    puts_LCD(2,"        ");
    }
}

