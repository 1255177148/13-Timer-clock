#include<Atmel/REGX52.H>
#include "../headers/Deplay.h"

/*
 * 获取按下的是哪个独立按键
*/
char getKeyNum()
{
    char keyNum = 0;
    if (P3_1 == 0)
    {
        Delayms(20);
        while (P3_1 == 0);
        Delayms(20);
        keyNum = 1;
    } else if (P3_0 == 0)
    {
        Delayms(20);
        while (P3_0 == 0);
        Delayms(20);
        keyNum = 2;
    } else if (P3_2 == 0)
    {
        Delayms(20);
        while (P3_2 == 0);
        Delayms(20);
        keyNum = 3;
    } else if (P3_3 == 0)
    {
        Delayms(20);
        while (P3_3 == 0);
        Delayms(20);
        keyNum = 4;
    }
    return keyNum;
}