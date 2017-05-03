//
// Created by fengyingcai on 2017/5/2.
//

#include <stdio.h>

int main(void)
{
    double sum = 0;
    double b = 0;
    int i;

    for (i=0; i<12; i++) {
        scanf("%lf", &b);
        sum += b;
    }
    printf("$%.2f", sum/12);

    return 0;
}
