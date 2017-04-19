//
// Created by fengyc on 2017/4/20.
//

#include <stdio.h>

#define PRAISE "What a super marvelous name!"

int main(void)
{
    char name[40];
    printf("What's your name?\n");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);
    return 0;
}
