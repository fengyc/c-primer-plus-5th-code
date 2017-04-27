//
// Created by fengyc on 2017/4/28.
//

#include <stdio.h>

int main(void)
{
    char ch;

    while ((ch = getchar()) != '#')
    {
        putchar(ch);
    }
    return 0;
}