#include "stm32f4xx.h"                  // Device header
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
	
void teplo_config(void);
int teplo_aktiv(uint8_t adr);
uint8_t teplo_cti2(uint8_t adr);
uint16_t sample_1( void );
void LCD_config(void);
void LCD_ini (void);
void puts_LCD(int radek, char* ukaz);
void Delay (uint32_t ms);
uint8_t getkey();
void GPIOD_conf();

int main (void) {		
    uint8_t teplota_M,teplota_L ;
	int i=0;
	float teplo,LSB,MSB;
	char dm[8],hm[8],pm;
	char line1[20]="TEPLOTA ";
	char line2[20]="              ";
	teplo_config();
	teplo_aktiv(0x80);	
	GPIOD_conf();
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/10000); //0,1 ms
	LCD_config();
	LCD_ini();
	puts_LCD(1, "Zadej DM");
	LCD_ctrlWR(0xC0);
	for(i=0;i<8;i++){
	    pm = getkey();
	    if(pm=='#') break;
	        dm[i]=pm;
            puts_LCD(2,dm);
            Delay(1000);
        }
        dm[i]='\0';
        LSB=atof(dm);
        puts_LCD(1, "Zadej HM");
        LCD_ctrlWR(0xC0);
        for(i=0;i<8;i++){
            pm = getkey();
            if(pm=='#') break;
                hm[i]=pm;
                puts_LCD(2,hm);
                Delay(1000);
        }
        hm[i]='\0';
        MSB=atof(hm);
	while(1) {
			teplota_M = teplo_cti2(0x02);
			teplota_L = teplo_cti2(0x01);
			teplo=teplota_M+((float)teplota_L/16)/16;
			sprintf(line2,"%.3f�C    ",teplo);
			puts_LCD(1,line1);
			puts_LCD(2,line2);
			if(teplo>=LSB && teplo<=MSB){
				GPIOD->ODR &= ~(1UL << 12);
				GPIOD->ODR |= (1UL << 13);
				GPIOD->ODR &= ~(1UL << 14);
				GPIOD->ODR &= ~(1UL << 15);
			}
			if(teplo<LSB){
				GPIOD->ODR |= (1UL << 12);
				GPIOD->ODR &= ~(1UL << 13);
				GPIOD->ODR &= ~(1UL << 14);
				GPIOD->ODR &= ~(1UL << 15);
			}
			if(teplo>MSB){
				GPIOD->ODR &= ~(1UL << 12);
				GPIOD->ODR &= ~(1UL << 13);
				GPIOD->ODR |= (1UL << 14);
				GPIOD->ODR &= ~(1UL << 15);
			}
        Delay (12000);
		};
	}