//
// Created by fengyc on 2017/4/19.
//

#include <stdio.h>

int main(void)
{
    float f;
    printf("Float number: ");
    scanf("%f", &f);
    printf("The input is %.6f or %.6e.\n", f, f);
    return 0;
}
