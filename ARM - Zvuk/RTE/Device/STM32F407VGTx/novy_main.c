#include "stm32f4xx.h"                  // Device header
#include "RTE_Components.h"             // Component selection
#include <RTL.h>
#include <stdio.h>
#include <math.h>

const uint16_t N=8192, N2= N >> 3;
uint16_t i,out;
uint16_t sample_mic[N];
int16_t sample_zvuk[N2];


OS_TID t_job1, t_job2, t_job3;
__task void job1 (void);
__task void job2 (void);
__task void job3 (void);

void Mic_config(void);
void read_data_mic(uint16_t* ukaz1, uint16_t delka);
void decode_PDM2PCM(uint16_t* ukaz1, int16_t* ukaz2, uint16_t delka);
void DA_config(void);
void LCD_config(void);
void LCD_ini (void);
void puts_LCD(int radek, char* ukaz);
void Delay (uint32_t ms);

__task void job1 (void) {
		while(1){
			os_evt_wait_and(0x0001,0xFFFF);
			for(i=0; i<N2; i++)
			{
				out=sample_zvuk[i]+2048;
				DAC->DHR12R1=out;
				Delay(1);
			}
			os_evt_set(0x0004,t_job3);
		}
}
__task void job2 (void) {
		uint32_t suma=0;
		uint16_t index=0;
	
		char db2[]="                ";
		float rms1=0;
		float rms2=0;
		float db1=0;
		float pom;
		while(1){
			os_evt_wait_and(0x0002,0xFFFF);
			read_data_mic(sample_mic,N);
			decode_PDM2PCM(sample_mic,sample_zvuk,N);
			suma=0;
			for(index=256; index<512; ++index)
			{
				suma += sample_zvuk[index]*sample_zvuk[index];
			}
			rms1 = (float)(suma>>8);
			rms2=sqrt(rms1);
			db1=20*log10f(rms2/32768.0);
			sprintf(db2," %.4f dB    ",db1);
			puts_LCD(1,"     MERENI     ");
			puts_LCD(2,db2);
			os_evt_set(0x0001,t_job1);
		}
}
__task void job3 (void) {
		uint16_t in1=0;
		while(1){
			os_evt_wait_and(0x0004,0xFFFF);
			in1=GPIOA->IDR&1;
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
	 LCD_config();
	 LCD_ini();
	 char radek1[]="                ";
   char radek2[]="                ";
	 t_job1 = os_tsk_create (job1, 1);     /* start job1          */
	 t_job2 = os_tsk_create (job2, 1); 
	 t_job3 = os_tsk_create (job3, 1); 
	 os_evt_set(0x0001,t_job1);
   os_tsk_delete_self ();
}

int main(void) {
	RCC -> AHB1ENR |= (1UL << 0);
	Mic_config();
	DA_config();
	
	os_sys_init(init);
};