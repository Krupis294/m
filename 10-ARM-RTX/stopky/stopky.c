//
// Created by kuba on 17.12.2020.
//
#include <RTL.h>
#include "stm32f4xx.h" /* STM32F4xx Definitions */
#include <stdio.h>

void gpio_config(void);
void LCD_config(void);
void LCD_ini(void);
void puts_LCD(int radek, char* ukaz);

OS_TID t_job1, t_job2;
__task void job1 (void);
__task void job2 (void);

char x[8]="        ";

__task void job1 (void)
{
    int s, m = 0;
    while (1)
    {
        sprintf(x,"%dm %ds   ", m, s);
        s++;
        if(s == 60)
        {
            m++;
            s = 0;
        }
        puts_LCD(1, x);
        Delay(9000);
    }
}

__task void job2 (void)
{
    int tlac;
    while (1)
    {
        tlac = GPIOA->IDR;
        if(tlac & 0x1)
        {
            puts_LCD(2,x);
        }
    }
}

__task void init(void)
{
    LCD_config();
    LCD_ini();
    t_job1 = os_tsk_create (job1, 1); /* start job1 */
    t_job2 = os_tsk_create (job2, 1); /* start job2 */
    os_tsk_delete_self ();
}
/* Main: Initialize and start RTX Kernel */

int main (void)
{
    gpio_config();
    RCC->AHB1ENR  |= (1UL <<  0);
    os_sys_init(init); /* Initialize RTX and start init */
}

