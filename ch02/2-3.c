//
// Created by fengyingcai on 2017/4/17.
//

#include <stdio.h>

void butler(void);  /* 函数声明 */

int main(void)
{
    printf("I will summon the butler function.\n");
    butler();
    printf("Yes. Bring me some tea and writeable CD-ROMS.\n");
    return 0;
}

void butler(void)   /* 函数定义 */
{
    printf("You rang, sir?\n");
}
