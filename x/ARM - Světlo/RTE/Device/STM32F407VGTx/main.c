#include "stm32f4xx.h"                  // Device header
#include "RTE_Components.h"             // Component selection
#include <stdio.h>
#include <math.h>


uint16_t sample_1( void );
void ADC_config(void);
void LCD_config(void);
void LCD_ini (void);
void puts_LCD(int radek, char* ukaz);
void Delay (uint32_t ms);
void klavesnice_config(void);
void gpio_config(void);
uint8_t getkey();

int main (void)
{
	float sample, mereno, LSB=(float)3000/4096, lux, cd; //3000mv / 4096 -> 2^12
	int i, sum;
	char klavesa1,klavesa2;
	char line1[]="                ";
	char line2[]="                ";
	
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/10000); //0,1 ms
	gpio_config();
	
	RCC->AHB1ENR  |= ((1UL <<  3) ); 
	
	GPIOE->MODER    |=  ((1UL << 2*12) |	// 4x LEDY out
                       (1UL << 2*13) | 
                       (1UL << 2*14) | 
                       (1UL << 2*15)  );
	
	
	GPIOD->MODER    |=  ((1UL << 2*12) |	// 4x LEDY out
                       (1UL << 2*13) | 
                       (1UL << 2*14) | 
                       (1UL << 2*15)  ); 
	
	ADC_config();
	LCD_config();
	LCD_ini();
	klavesnice_config();
	
	do{
		puts_LCD(1,"1 - Denni svetlo");
		puts_LCD(2,"2 - Zarovka     ");
		klavesa1 = getkey();
	}while(klavesa1 != '1' && klavesa1 != '2');
	do{
		puts_LCD(1,"1 - LUX         ");
		puts_LCD(2,"2 - Candela     ");
		klavesa2 = getkey();
	}while(klavesa2 != '1' && klavesa2 != '2');
	
	while(1)
	{
		sum=0;
		for(i=0; i<128; i++) //nacteni 128 vzorku
		{
			sum += sample_1();
			Delay(10);
		}
		sample=(float)sum/128; //jeden vzorek
		mereno=sample*LSB; //vypocet mV
		
		if(klavesa1=='1')
		{
			lux=(8.2314*expf(0.0033*mereno))*0.95; //Pri dennim svetle nasobime 0.95
		}
		else if(klavesa1 == '2')
		{
			lux=(8.2314*expf(0.0033*mereno))*1; //pri zarovce nasobime 1
		}
		if(lux>10000) //ZELENA
		{
			GPIOD->ODR &= ~(1UL << 14);
			GPIOD->ODR &= ~(1UL << 13);
			Delay(2000);
			GPIOD->ODR |= (1UL << 12);
		}
		else if(lux<8000) //CERVENA
		{
			GPIOD->ODR &= ~(1UL << 12);
			GPIOD->ODR &= ~(1UL << 13);
			Delay(2000);
			GPIOD->ODR |= (1UL << 14);
		}
		else if(lux>8000 && lux<10000) //ORANdZOVA
		{
			GPIOD->ODR &= ~(1UL << 14);
			GPIOD->ODR &= ~(1UL << 12);
			Delay(2000);
			GPIOD->ODR |= (1UL << 13);
		}
		if(klavesa2=='1')
		{
			sprintf(line1,"lux %5.2f     ",lux);
			sprintf(line2,"mV  %4.2f     ",mereno);
			puts_LCD(1,line1);
			puts_LCD(2,line2);
			Delay(100);
		}
		else if(klavesa2=='2')
		{
			cd = lux*0.09290304;
			sprintf(line1,"cd  %5.2f     ",cd);
			sprintf(line2,"mV  %4.2f     ",mereno);
			puts_LCD(1,line1);
			puts_LCD(2,line2);
			Delay(100);
		}
	}
}
