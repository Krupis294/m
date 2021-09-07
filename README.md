Win server: https://www.uschovna.cz/zasilka/PPE5B2WY3YN6398J-62F/FDG8VU4YMA

## LCD
``` 
LCD_cltrlWR(0x1C) - doleva rotace
LCD_cltrlWR(0x18) - doprava rotace
LCD_cltrlWR(0x80) - první řádek kurzor
LCD_cltrlWR(0xC0) - druhý řádek kurzor
```
  
## RTX
```
t_job1 = os_tsk_create (job1, 1); = Vytvoří task
  
os_evt_set(0x0002,t_job2); = Nastaví vlajky
os_evt_wait_and(0x0004,0xffff); = Čekání na vlajky
os_tsk_delete_self(); = Smaže task
os_sys_init(init); = Spustí init task
```

## RTX Template
```
OS_TID t_job1, t_job2, t_job3;    
__task void job1 (void);
__task void job2 (void);
__task void job3 (void);
```

## ARM
```
RCC->AHB1ENR |= ((1UL << ..));
    0- btn A
    3- led skolni D aktivace: |= (1<<) deaktivace: &=˜(1<<)
    4- led arm E aktivace     &=˜(1<<) deaktivace: |= (1<<)
for(int i=12;i<16;i++) GPIOE->MODER  |= (1UL<< i*2); -aktivace led
 ```
 
 ## Second
https://github.com/Firestone82/m
