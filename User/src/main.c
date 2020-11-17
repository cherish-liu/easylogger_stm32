#include <stdio.h>
#include <string.h>
#include "stm32f10x_usart.h"

#include "rs485.h"

#define LOG_TAG "main"

#include "elog.h"


void elog_init_config(void)
{
    elog_init();    /* initialize EasyLogger */
    
    /* set EasyLogger log format */
    elog_set_fmt(ELOG_LVL_ASSERT, ELOG_FMT_ALL);
    elog_set_fmt(ELOG_LVL_ERROR, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_WARN, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_INFO, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_DEBUG, ELOG_FMT_ALL & ~(ELOG_FMT_FUNC | ELOG_FMT_T_INFO | ELOG_FMT_P_INFO));
    elog_set_fmt(ELOG_LVL_VERBOSE, ELOG_FMT_ALL & ~(ELOG_FMT_FUNC | ELOG_FMT_T_INFO | ELOG_FMT_P_INFO));
    
    elog_start();   /* start EasyLogger */
}
    
//毫秒级的延时
void delay_ms(uint16_t time)
{    
   uint16_t i=0;  
   while(time--)
   {
      i = 12000;  //自己定义
      while(i--) ;    
   }
}

int main()
{  
    Rs485_A_Init();
    Rs485_A_TxEnable();
    
    elog_init_config();
    
    while(1)
    {
        log_a("Hello EasyLogger!");
        log_e("Hello EasyLogger!");
        log_w("Hello EasyLogger!");
        log_i("Hello EasyLogger!");
        log_d("Hello EasyLogger!");
        log_v("Hello EasyLogger!");
        delay_ms(2000);
    }
}
        

int fputc(int ch, FILE *f)
{
	/* Write a character to the USART */
	USART_SendData(USART1, ch);	// 发送数据
	
	/* Loop until the end of transmission */
	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);	// 直到发送完成

	return ch;
}
    


