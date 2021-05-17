#include "stm32f4xx.h"                  // Device header
#include "RTE_Components.h"             // Component selection
#include <RTL.h>
#include <stdio.h>
#include <math.h>

const uint16_t N=8192, N2= N>>3;
uint16_t sample_mic[N];
int16_t sample_zvuk[N2];
uint16_t ind=0;
uint16_t out=0;


OS_TID t_job1, t_job2, t_job3;
__task void job1 (void);
__task void job2 (void);
__task void job3 (void);

void Mic_config(void);
void read_data_mic(uint16_t* ukaz1, uint16_t delka);
void decode_PDM2PCM(uint16_t* ukaz1, int16_t* ukaz2, uint16_t delka);
void DA_config(void);
void Delay (uint32_t ms);
void LCD_ini (void);
void puts_LCD(int radek, char* ukaz);
void LCD_config(void);
void gpio_config(void);

__task void job1 (void) {
		while(1){
			os_evt_wait_and(0x0001,0xFFFF);
			for(ind=0; ind < N2; ind++)
			{
				out=sample_zvuk[ind]+2048; // 2048 - posun (4096/2)
				DAC -> DHR12R1 = out;
				Delay(1);
			}
			os_evt_set(0x0004,t_job3);
		}
}
__task void job2 (void) {
	
	uint16_t index=0;
	uint32_t suma=0;
	
	float rms1=0, rms2=0;
	float db1=0;
	char db2[]="                ";
		while(1){
			os_evt_wait_and(0x0002,0xFFFF);
			read_data_mic(sample_mic,N);
			decode_PDM2PCM(sample_mic, sample_zvuk, N);
			suma=0;
			for(index=256; index < 512; ++index)
			{
				suma += sample_zvuk[index]*sample_zvuk[index];
			}
			rms1 = (float) (suma >> 8); // Posun o 8 bitu - Deleno 256 (Suma / 256) = jeden vzorek
			rms2 = sqrt(rms1); // efektivni hodnota (jeden vzorek)
			db1=20*log10f(rms2/32768.0);
			sprintf(db2,"%f",db1);
			puts_LCD(1,"      dB        ");
			puts_LCD(2,db2);
			
			os_evt_set(0x0001,t_job1);
		}
}
__task void job3 (void) {
	uint16_t in1=0;
		while(1){
			os_evt_wait_and(0x0004,0xFFFF);
			in1 = GPIOA->IDR&1;
			if(in1==1)
			{
				os_evt_set(0x0002,t_job2);
			}
			else
			{
				os_evt_set(0x0001,t_job1);
			}
		}
}

__task void init(void) {
	char r1[]="     MERENI     ";
	char r2[]="      v dB      ";
	LCD_config();
	LCD_ini(); 
	puts_LCD(1,r1);
	puts_LCD(2,r2);
	 t_job1 = os_tsk_create (job1, 1);     /* start job1          */
	 t_job2 = os_tsk_create (job2, 1); 
	 t_job3 = os_tsk_create (job3, 1); 
	 os_evt_set(0x0001,t_job1);

   os_tsk_delete_self ();
}

int main(void) {
	RCC->AHB1ENR |= (1UL<<0);
	Mic_config();
	DA_config();
	gpio_config();
	
	GPIOE->ODR |= (1UL << 13); //zhasnuti cervenych LED
		GPIOE->ODR |= (1UL << 15);
		GPIOE->ODR |= (1UL << 11);
		GPIOB->ODR |= (1UL << 11);
	
	os_sys_init(init);
};