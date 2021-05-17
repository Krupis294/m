//   HAL for RTX ver.3 SPSE  31.10.2018  mic + filter, LCD, ser. channel 115200 Bd
//   SYSCLK(Hz) | 168 000000 Hz  ====  libPDMFilter_Keil.lib

#include "STM32F4xx.h"         
#include <rtl.h>
#include <string.h>
#include "pdm_filter.h"


volatile uint32_t Ticks;
uint16_t out1 ;
PDMFilter_InitStruct Filter;

/* Exported macros -----------------------------------------------------------*/
#define HTONS(A)  ((((uint16_t)(A) & 0xff00) >> 8) | \
                   (((uint16_t)(A) & 0x00ff) << 8))
									 
									 

void gpio_config(void){
RCC->AHB1ENR  |= ((1UL <<  4) );         

 
GPIOE->MODER    |=  ((1UL << 2*12) |	// 4x LEDY out
                       (1UL << 2*13) | 
                       (1UL << 2*14) | 
                       (1UL << 2*15)  ); 
	
GPIOE->OTYPER   &= ~((1UL <<   12) |
                       (1UL <<   13) |
                       (1UL <<   14) |
                       (1UL <<   15)  );   // Push - Pull
GPIOE->OSPEEDR  &= ~((3UL << 2*12) |
                       (3UL << 2*13) |
                       (3UL << 2*14) |
                       (3UL << 2*15)  );   
GPIOE->OSPEEDR  |=  ((2UL << 2*12) |	// 50 Mhz out
                       (2UL << 2*13) | 
                       (2UL << 2*14) | 
                       (2UL << 2*15)  ); 
GPIOE->PUPDR    &= ~((3UL << 2*12) |
                       (3UL << 2*13) |
                       (3UL << 2*14) |
                       (3UL << 2*15)  );   
GPIOE->PUPDR    |=  ((1UL << 2*12) |	// Pull up
                       (1UL << 2*13) | 
                       (1UL << 2*14) | 
                       (1UL << 2*15)  ); 
}

void klavesnice_config(void){
RCC->AHB1ENR  |= ((1UL <<  3) );         

 
GPIOD->MODER    |=  ((1UL << 2*6) |	// vystup PD6..9
                       (1UL << 2*7) | 
                       (1UL << 2*8) | 
                       (1UL << 2*9)  );
GPIOD->OTYPER   &= ~((1UL <<   6) |
                       (1UL <<   7) |
                       (1UL <<   8) |
                       (1UL <<   9)  );   // Push - Pull
GPIOD->OSPEEDR    &= ~((3UL << 2*6) |
                       (3UL <<2*7) |
                       (3UL << 2*8) |
                       (3UL << 2*9)  );   
GPIOD->OSPEEDR  |=  ((2UL << 2*6) |	// 50 Mhz out
                       (2UL << 2*7) | 
                       (2UL << 2*8) | 
                       (2UL << 2*9)  ); 	
GPIOD->PUPDR    &= ~((3UL << 2*6) |
                       (3UL << 2*7) |
                       (3UL << 2*8) |
                       (3UL << 2*9)  );   

GPIOD->MODER    &=  ~((3UL << 2*0) |	// vstup PD0..2
                       (3UL << 2*1) | 
                       (3UL << 2*2))  ;
											 
GPIOD->PUPDR    &= ~((3UL << 2*0) |
                       (3UL << 2*1) |
                       (3UL << 2*2) );
GPIOD->PUPDR    |= ((1UL << 2*0) |
                       (1UL << 2*1) |
                       (1UL << 2*2) );                            
}
void LCD_config(void){
RCC->AHB1ENR  |= ((1UL <<  4) );  // PE povolit clock 
GPIOE->MODER    |=  (	(1UL << 2*3) |	//  RS
												(1UL << 2*4) |	//	R/W
												(1UL << 2*5) |	//	E
											 (1UL << 2*6) |	// vystup DB4..DB7 data
                       (1UL << 2*7) | 
                       (1UL << 2*8) | 
                       (1UL << 2*9) |
												(1UL << 2*10))	;
GPIOE->OTYPER   &= ~( (1UL << 3) |	
												(1UL << 4) |	
												(1UL << 5) |	
											 (1UL <<   6) |
                       (1UL <<   7) |
                       (1UL <<   8) |
                       (1UL <<   9) |
												(1UL <<  10)	);   // Push - Pull
GPIOE->OSPEEDR    &= ~( (3UL << 2*3) |
                        (3UL << 2*4) |
                        (3UL << 2*5 )|
									    	(3UL << 2*6) |
                       (3UL << 2*7) |
                       (3UL << 2*8) |
                       (3UL << 2*9) |
											 (3UL << 2*10) ) ;  
GPIOE->OSPEEDR  |=  (	(2UL << 2*3) |	// 50 Mhz out
                       (2UL << 2*4) | 
                       (2UL << 2*5) | 
												(2UL << 2*6) |	
                       (2UL << 2*7) | 
                       (2UL << 2*8) | 
                       (2UL << 2*9) |
											(2UL << 2*10) ); 	 
GPIOE->PUPDR    &= ~((3UL << 2*3) |
                       (3UL << 2*4) |
                       (3UL << 2*5) |	
												(3UL << 2*6) |
                       (3UL << 2*7) |
                       (3UL << 2*8) |
                       (3UL << 2*9) |
											(3UL << 2*10) )   	
;}

void ADC_config(void){
			RCC->AHB1ENR  |= ((1UL ) );  // PA povolit clock 
			RCC->APB2ENR |= 0x00000100;		 // povolení hodinového signálu k AD pøevodníku	
			GPIOA->MODER    |=  	(3UL << 2*1) 	;	// PA1    *** Vstup ch1 A/D prevod ***	

			ADC1->SMPR2 |= (7UL << 3*1); // nastaveni casu samplovani pro kanal 1: 480 cycles = 111
			ADC1->CR1 = 0x00000800; // nastaveni DISCEN do 1	Discontinuous mode
			ADC1->SQR1 = 0x00000000; // nastaveni poctu konvertovanych kanalu na 1	
			ADC1->SQR3 = 0x00000001; // konvertovat se bude kanal cislo 1
			ADC1->CR2  |= 1UL  ;  // PA povolit ADC1 => zapnuti AD prevodniku	

// ADC1->CR2 |= 0x08; // resetovani kalibracnich registru
// while ((ADC1->CR2 & 0x08) != 0) {} ;// cekani na nacteni hodnot po resetu
// ADC1->CR2 |= 0x04; // zapnuti autokalibrace
// while ((ADC1->CR2 & 0x04) != 0) {} ;// cekani na konec autokalibrace	
}
void Buzz_config(void){
			RCC->AHB1ENR  |= ((1UL ) );  // PA povolit clock 
				GPIOA->MODER    |=  	(1UL << 2*8) ;  // PA8  out
				GPIOA->OTYPER   &= ~ (1UL << 8) ;      // Output push-pull
				GPIOA->OSPEEDR    &= ~ (3UL << 2*8)  ;
				GPIOA->OSPEEDR  |=  	(2UL << 2*8) ;	// 50 Mhz out
		  	GPIOA->PUPDR    &= ~(3UL << 2*8) ; // No pull-up, pull-down
}
void Mic_config(void){
					RCC->AHB1ENR  |= ((1UL << 1 ) );  // PB povolit clock 		
				GPIOB->MODER    |=  	(2UL << 2*10) ;  // PB pin 10
				GPIOB->AFR[1] |=  (5UL << 4*2) ;   // AF 5 .... SPI2_SCK alter.f.
				GPIOB->OTYPER   &= ~ (1UL << 10) ;      // Output push-pull	
				GPIOB->OSPEEDR    &= ~ (3UL << 2*10)  ;
				GPIOB->OSPEEDR  |=  	(2UL << 2*10) ;	// 50 Mhz out
		  	GPIOB->PUPDR    &= ~(3UL << 2*10) ; // No pull-up, pull-down
					RCC->AHB1ENR  |= ((1UL << 2 ) );  // PC povolit clock 	
				GPIOC->MODER    |=  	(2UL << 2*3) ;  // PC pin 3	
				GPIOC->AFR[0] |=  (5UL << 4*3) ;   // AF 5 .... SPI2_MOSI alter.f.		
				GPIOC->OTYPER   |=  (1UL << 3) ;      // Output OPEN drain	
				GPIOC->OSPEEDR    &= ~ (3UL << 2*3)  ;
				GPIOC->OSPEEDR  |=  	(2UL << 2*3) ;	// 50 Mhz out
		  	GPIOC->PUPDR    &= ~(3UL << 2*3) ; // No pull-up, pull-down
	
				RCC->APB1ENR |= (1UL << 14 );	//  SPI2 clock enabled
//				SPI2->CR1 |= ((1L << 1*1)| 		//  CK to 1 when idle
// 											(1L << 1*0 )| 	//  PHA = 1
// 											(1L << 1*10)|		//	Bit 10 RXONLY: Receive only
//											(1L << 1*6)|		//	Bit 6 SPE: SPI enable
//											(5L << 3)|		//	BR[2:0]: Baud rate control 101: fPCLK/64
//											(1L << 1*2));		//	Bit 2 MSTR: Master selection 
											
		SPI2->I2SCFGR	 |= (     (1L << 1*3)| 		// CKPOL: Steady state clock polarity 
									(2L << 1*4 )| 		//  10: LSB justified standard 
									(3L << 1*8)|		//	11: Master - receive
							//		(1L << 1*10)|		//	Bit 10 I2SE: I2S Enable
									(1L << 11*1))	;	//	Bit 11 I2SMOD: I2S mode selection
			SPI2->I2SPR	 |= (16L )	;	//	Bit 7:0 I2SDIV: I2S Linear prescaler		
			SPI2->I2SCFGR	 |=(1L << 1*10)	;	//	Bit 10 I2SE: I2S Enable	
// ****************   FILTER  ***************************
Filter.LP_HZ = 8000;
   			 Filter.HP_HZ = 40;
   			 Filter.Fs = 16000;
   			 Filter.Out_MicChannels = 1;
   			 Filter.In_MicChannels = 1;
	
		RCC->AHB1ENR |= RCC_AHB1ENR_CRCEN;							
		PDM_Filter_Init((PDMFilter_InitStruct *)&Filter);	  
}
void DA_config(void){    // DA ... PA4
	RCC->AHB1ENR  |= ((1UL ) );  // PA povolit clock 
			RCC->APB1ENR |= (1UL << 1*29 );     //DACEN: DAC interface clock enable
			GPIOA->MODER    |=  	(3UL << 2*4) 	;	// PA4    *** Vystup  D/A prevod ***	
			DAC->CR |= (1UL << 1*0) ;  		// EN1: DAC channel 1 enable
								//	(7UL << 1*3 ));     // TSEL1[2:0]: DAC channel 1 sw trigger			
}


void Delay (uint32_t ms){
os_itv_set (ms);
	 {
    os_itv_wait ();  
  }
}

uint8_t getkey(){
		uint8_t	key= 0;
		uint16_t	temp;
		while (!key){
				Delay(1000);			// delay for key
				GPIOD->ODR &= ~((15UL << 6));	
				GPIOD->ODR |= ((7UL << 6));
					temp = GPIOD->IDR ;
					temp &= 7 ;
					switch (temp){
						case 6 : key ='.'; break ;  // exchange '.'
						case 5 : key ='0'; break ;
						case 3 : key ='#'; break ;}
						
				GPIOD->ODR &= ~((15UL << 6));	
				GPIOD->ODR |= ((11UL << 6));
					temp = GPIOD->IDR ;
					temp &= 7 ;
					switch (temp){
						case 6 : key ='7'; break ;
						case 5 : key ='8'; break ;
						case 3 : key ='9'; break ;}
					
				GPIOD->ODR &= ~((15UL << 6));	
				GPIOD->ODR |= ((13UL << 6));
					temp = GPIOD->IDR ;
					temp &= 7 ;
					switch (temp){
						case 6 : key ='4'; break ;
						case 5 : key ='5'; break ;
						case 3 : key ='6'; break ;}
						
				GPIOD->ODR &= ~((15UL << 6));	
				GPIOD->ODR |= ((14UL << 6));
					temp = GPIOD->IDR ;
					temp &= 7 ;
					switch (temp){
						case 6 : key ='1'; break ;
						case 5 : key ='2'; break ;
						case 3 : key ='3'; break ;}
					}	
	return key ;	
}

void write_nibble_res(uint16_t nibble){
	uint16_t x;
			GPIOE->BSRR  = (   (1UL <<  (3+16)) |     //	  RS=0    
													(1UL << ( 4+16) ) |   	//	R/W=0
													(1UL << (5+16)) ); 	  //	E=0 
			Delay(1);	// 100 us	
			GPIOE->BSRR = (1UL << 5) ; 	  //	E=1  (clk)
			nibble &= 0x0F;
			nibble = nibble << 6 ;
			x = GPIOE->ODR & 0xFC3F ; // nuluj data
			GPIOE->ODR = nibble | x ; // pridej data		
			Delay(1);	// 100 us	
			GPIOE->BSRR = (1UL << (5+16)) ; 	  //	E=0 
			Delay(1);	// 100 us		
}

void write_nibble(uint16_t nibble){
	uint16_t x;
			GPIOE->BSRR  = (  (1UL << ( 4+16) ) |   	//	R/W=0
													(1UL << (5+16)) ); 	  //	E=0 
			GPIOE->BSRR = (1UL << 5) ; 	  //	E=1  (clk)
			nibble &= 0x0F;
			nibble = nibble << 6 ;
			x = GPIOE->ODR & 0xFC3F ; // nuluj data
			GPIOE->ODR = nibble | x ; // pridej data		
			Delay(1);	// 100 us	
			GPIOE->BSRR = (1UL << (5+16)) ; 	  //	E=0 
			Delay(1);	// 100 us		
}
void LCD_ctrlWR(uint16_t cmd){
			GPIOE->BSRR  = 	(1UL <<  (3+16)); //	  RS=0
			write_nibble ( cmd >> 4);
			write_nibble (cmd);
				Delay(1);	// 100 us	
}
void LCD_dataWR(uint16_t cmd){
			GPIOE->BSRR  = 	(1UL <<  3); //	  RS=1
			write_nibble ( cmd >> 4);
			write_nibble (cmd);
				Delay(1);	// 100 us	
}
void LCD_ini (void){
GPIOE->BSRR  =  (1UL << (10+16) ) ; 	  //	DIR=0 						
			Delay(800); // 80 ms
			write_nibble_res(0x3);	// 3
			Delay(50);	// 5 ms	
			write_nibble_res(0x3);
			Delay(10);	// 1 ms			
			write_nibble_res(0x3);	// 
			Delay(10);	// 1 ms		
			write_nibble_res(0x2);
			LCD_ctrlWR(0x28);				
			LCD_ctrlWR(0x28);	
			LCD_ctrlWR(0x0C);
			LCD_ctrlWR(0x06);
			LCD_ctrlWR(0x01);
			Delay(20);	// 2 ms	
}
void puts_LCD(int radek, char* ukaz){
	uint32_t i, adresa, n = 17;
	if (radek==1)  adresa = 0x80 ; else adresa = 0xC0 ;
	LCD_ctrlWR(adresa);
	for (i=0 ; i < n ; ++i ){
				LCD_dataWR(*ukaz);
				++ukaz ;
				};
}
unsigned char hextoascii(unsigned char cislo ){
	unsigned char asci ;
	asci = cislo&0x0F ;
	if (asci > 9)  asci += 7 ;
	return (asci +='0') ;
}
void putasci(uint16_t cislo1 ){
		LCD_dataWR(hextoascii(cislo1 >> 8));
		LCD_dataWR(hextoascii(cislo1 >> 4));	  
		LCD_dataWR(hextoascii(cislo1));	
  }
uint16_t sample_1( void ){
				ADC1->CR2 |= (0x40000000); // start mereni AD => SWSTART
				while ((ADC1->SR & 0x02) == 0){} ; // cekani na konec mereni AD
				return (uint16_t) ADC1->DR;	
	}
void bzz(uint16_t ms){
uint16_t i; ms *= 10;
	 for (i=0;i< ms; ++i ){
		 	 GPIOA->ODR &= ~(1UL << 8) ;  // bzz off
		Delay(5);
		 	GPIOA->ODR |= (1UL << 8) ;    // bzz on
		Delay(5); 
		}};
void SERIAL_ini(){
	RCC->APB1ENR |= (1UL << 17);	// USART2 CLK ENABLE
	RCC->AHB1ENR |= (1UL << 0);		// PORT A CLK ENABLE
	GPIOA->AFR[0] |= (7U << 4*2) | (7U << 4*3);
	/* Tx Configuration */
	GPIOA->MODER &= ~(3UL << 2*2);
	GPIOA->MODER |= (2UL << 2*2);		// PA2 Alternate Function
	GPIOA->OTYPER &= ~(1UL << 2);	// Pull
	GPIOA->OSPEEDR &= ~(3UL << 2*2);
	GPIOA->OSPEEDR |= (2UL << 2*2);		// 50Mhz
	GPIOA->PUPDR &= ~(3UL << 2*2);
	GPIOA->PUPDR |= (1UL << 2*2);		// PullUp
	/* Rx Configuration */
	GPIOA->MODER &= ~(3UL << 2*3);
	GPIOA->MODER |= (2UL << 2*3);		// PA2 Alternate Function	
	USART2->BRR = 0x16D; // 115200 Bd
	USART2->CR1 |= (1U << 3) | (1U << 2); //Rxen Txen
	USART2->CR1 |= (1U << 13); // usart enable
}
void putchar1(char znak ){
	{ USART2->DR = (znak);
		while((!(USART2->SR & 0x40))); // Transmision Complete
	} }
	
void putserial(char* ukaz1 ){
  	unsigned char n=strlen(ukaz1)  ;
	unsigned char i ;
  	for(i=0; i<n ;++i)
	{ USART2->DR = (*ukaz1);
		while((!(USART2->SR & 0x40))); // Transmision Complete
		++ukaz1 ;
	} }
uint16_t  sample1( ){
		uint16_t znak;
	 while(!(SPI2->SR & 0x1)){}; // Bit 0 RXNE: Receive buffer not empty	
		znak = SPI2->DR ;		 
		return znak ;			
 }   
void read_data_mic(uint16_t* ukaz1, uint16_t delka){
		uint16_t ind2 ;
		for (  ind2=0;ind2< delka; ++ind2 ){					
				while(!(SPI2->SR & 0x1)){}; // Bit 0 RXNE: Receive buffer not empty	
					(*ukaz1) = HTONS(SPI2->DR);	// microphone
						++ukaz1 ;	
					}	
}
 void write_da (uint16_t* ukaz1,uint16_t delka, uint16_t cas_us){
		uint16_t ind2, k ;
			DAC->DHR12R1= 1500 ;	
		
		for (ind2=0; ind2< delka; ++ind2 ){
			out1 = (*ukaz1)+1500;
			if (out1 > 3000) {out1 = 1500;}
			DAC->DHR12R1 = out1 ;
			
				++ukaz1 ;
			for(k=0 ; k < cas_us; ++k ){};
//				Delay(1);
				}	}
 
void decode_PDM2PCM(uint16_t* ukaz1, int16_t* ukaz2, uint16_t delka)
	{	uint16_t k, l,  pocet ;	
		uint16_t ind2 ;
			 k=0; l=0;  pocet = delka >>7 ; 
		for (  ind2=0;ind2 < pocet ; ++ind2 ){					
				PDM_Filter_64_LSB((uint8_t*)ukaz1+l,(uint16_t*)ukaz2+k, 1,(PDMFilter_InitStruct*)&Filter);
			 l+=128 ; k+=16;					
					}	
}
			
 
