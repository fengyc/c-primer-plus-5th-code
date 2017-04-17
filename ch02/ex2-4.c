//
// Created by fengyingcai on 2017/4/17.
//

#include <stdio.h>

void say_good_fellow(void);
void say_nobody_can_deny(void);

int main(void)
{
    say_good_fellow();
    say_good_fellow();
    say_good_fellow();
    say_nobody_can_deny();
    return 0;
}

void say_good_fellow(void)
{
    printf("For he's a jolly good fellow!\n");
}

void say_nobody_can_deny(void)
{
    printf("Which nobody can deny!\n");
}
