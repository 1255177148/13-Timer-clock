#include <Atmel/REGX52.H>
#include "headers/Timer0.h"
#include "headers/LCD1602.h"

char sec, min, hour;

/*
 * 定制器0的中断函数，当定时器0溢出时，执行此函数
 */
void Timer0_Routine() interrupt 1
{
    static unsigned int t0Count;
    TL0 = 0x00; //设置定时初始值，低8位
    TH0 = 0xEE; //设置定时初始值，高8位
    t0Count++;
    if (t0Count >= 200) {
        t0Count = 0;
        sec++;
        if (sec >= 60) {
            sec = 0;
            min++;
            if (min >= 60)
            {
                min = 0;
                hour++;
            }
            
        }
    }
}

void main()
{
    LCD_Init();
    Timer0Init();
    LCD_ShowString(1, 1, "Clock:");
    LCD_ShowString(2, 3, ":");
    LCD_ShowString(2, 6, ":");
    while (1) {
        LCD_ShowNum(2, 1, hour, 2);
        LCD_ShowNum(2, 4, min, 2);
        LCD_ShowNum(2, 7, sec, 2);
    }
}