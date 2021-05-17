 /*----------------------------------------------------------------------------
 *      RL-ARM - RTX
 *----------------------------------------------------------------------------
 *      Name:    RTX_mereni.C			
 *      				 RTX example program 
 *               OPI 28/9/2016 SPSE Havirov
 *---------------------------------------------------------------------------*/

#include <RTL.h>
#include "stm32f4xx.h"                  /* STM32F4xx Definitions             */
#include <stdio.h>
#include <math.h>
#include "config_kit_RTX_2.c"

const uint16_t N=8192,N2=N>>3, N3=N>>7;
uint16_t sample_mic[N];
int16_t sample_zvuk[N2];
int16_t i, out3;
char ser[50],line1[9]="        ",line2[9]="        ";
float rms,rms1=0,db=0;
int16_t vmax,vmin,vpp;

OS_TID t_job1, t_job2, t_job3;    
__task void job1 (void);
__task void job2 (void);
__task void job3 (void);

__task void job1 (void) {
  while (1) {                
		os_evt_wait_and(0x0001,0xffff);
		for(i=0;i<N2;i++){
			out3=2048+ sample_zvuk[i];
			DAC->DHR12R1=out3;
			Delay(1);
		}
		os_evt_set(0x0004,t_job3);
  }
}

__task void job2 (void) {
  while (1) {     
		os_evt_wait_and(0x0002,0xffff);
		read_data_mic(sample_mic,N);
		decode_PDM2PCM(sample_mic,sample_zvuk,N);
		
		//vypocet rms
		
		rms1=0;
		for(i=256;i<512;i++){
			rms1+=sample_zvuk[i]*sample_zvuk[i];
		}
		rms1/=256;
		rms=sqrt(rms1);
		
		//vypocet vmax,vmin,vpp
		
		vmax=sample_zvuk[256];
		vmin=sample_zvuk[256];
		for(i=256;i<512;i++){
			if(vmax<sample_zvuk[i]) vmax=sample_zvuk[i];
			if(vmin>sample_zvuk[i]) vmin=sample_zvuk[i];
		}
		vpp=vmax-vmin;
		
		// vypis serial
		
		for(i=200;i<N2;i++){
			sprintf(ser,"%d  %d  %d  %d  %d  %.1f\r\n",i,sample_zvuk[i],vmax,vmin,vpp,rms);
			putserial(ser);
		}
		
		//vypocet db a vypis lcd
		
		db=20*log10f(rms/32767);
		sprintf(line1,"DECIBEL ");
		sprintf(line2,"db:%3.1f",db);
		puts_LCD(1,line1);
		puts_LCD(2,line2);
    os_evt_set(0x0001,t_job1);
  }
}

__task void job3 (void) {
	uint16_t in1=0;
  while (1) {    
		os_evt_wait_and(0x0004,0xffff);
		in1=GPIOA->IDR & 1;
		if(in1&0x1) os_evt_set(0x0002,t_job2);
		else os_evt_set(0x0001,t_job1);
  }
}

/*----------------------------------------------------------------------------
 *        Task  'init': Initialize
 *---------------------------------------------------------------------------*/
__task void init(void) {
	LCD_config();
		LCD_ini();
	
   t_job1 = os_tsk_create (job1, 1);     /* start job1          */
	t_job2 = os_tsk_create (job2, 1);     /* start job1          */
	t_job3 = os_tsk_create (job3, 1);     /* start job1          */
	 os_evt_set(0x0001,t_job1);
   os_tsk_delete_self ();
}
/*----------------------------------------------------------------------------
 *        Main: Initialize and start RTX Kernel
 *---------------------------------------------------------------------------*/
int main (void) {
		gpio_config();
		DA_config();
		Mic_config();
		SERIAL_ini();
		puts_LCD(1,line1);
		puts_LCD(2,line2);
  os_sys_init(init);                   /* Initialize RTX and start init */
}

