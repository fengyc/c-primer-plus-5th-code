//
// Created by fengyc on 2017/4/20.
//

#include <stdio.h>
#include <string.h>

#define PRAISE "What a super marvelous name!"

int main(void)
{
    char name[40];

    printf("What's your name?\n");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);
    printf("Your name of %d letters occupies %d memory cells.\n", strlen(name), sizeof name);
    printf("The phrase of praise has %d letters, ", strlen(PRAISE));
    printf("and occupies %d memory cells.\n", sizeof PRAISE);   // sizeof 比 strlen 多了一个字节
    return 0;
}
