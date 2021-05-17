Win server: https://www.uschovna.cz/zasilka/LK389H278UVXAH66-DD7/4K2VLP2IZ5

LCD:
  
  LCD_cltrlWR(0x1C) -doleva rotace
  
  LCD_cltrlWR(0x18) -doprava rotace
  
  LCD_cltrlWR(0x80) -první řádek kurzor
  
  LCD_cltrlWR(0xC0) -druhý řádek kurzor
RTX:
  os_tsk_create(); = Vytvoří task
  
  os_evt_set(0x0002,t_job2); = Nastaví vlajky
 
  os_evt_wait_and(0x0004,0xffff); = Čekání na vlajky
 
  os_tsk_delete_self(); = Smaže task
  
  OS_TID t_job1, t_job2, t_job3;    
__task void job1 (void);
__task void job2 (void);
__task void job3 (void);
  
  os_sys_init(init);
  
  https://github.com/Firestone82/m
