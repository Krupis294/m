#include <RTL.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stm32f4xx.h" 
OS_TID t_job1, t_job2;

//      out= 2047 + 2047*sin(i*2*pi/18);  
#define pi 3.14

void ADC_config(void);
void SERIAL_ini();
void putserial(char* ukaz1 );
void gpio_config(void);
void DA_config(void);
void Delay (uint32_t ms);
__task void job1 (void);
__task void job2 (void);

uint16_t k;
uint16_t out10,pole[200];

__task void job1 (void) {
	int i;
		while(1){
			 for (i=0;i<128;i++) {
				 out10=pole[i];
				 Delay (10);
				  DAC->DHR12R1=out10;
			 }
		}
 }

 __task void job2 (void) {
	 int i;
	 FILE *f;
	 char snum[5];
	 //itoa(out, snum, 5);
while (1) {
		int a=GPIOA->IDR;
		if(a & 0x1) for (i=0;i<128;i++) putserial(snum);
}
 }


__task void init(void) {
 t_job1 = os_tsk_create (job1, 1); /* start job1 */
	t_job2 = os_tsk_create (job2, 2);
 os_tsk_delete_self ();
}


int main (void) {
	SystemCoreClockUpdate();
	SysTick_Config(160000);
	ADC_config();
	DA_config();
	gpio_config();
	SERIAL_ini();
	RCC->AHB1ENR |=(1UL<<0);
	for (k=0;k<128;k++)
		pole[k] = (uint16_t)(2047 + 2047*sin(k*2*pi/128));
	os_sys_init(init);
}
