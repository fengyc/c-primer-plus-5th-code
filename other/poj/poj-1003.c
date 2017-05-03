//
// Created by fengyingcai on 2017/5/2.
//

// 使用欧拉公式
// 1+ 1/2 + 1/3 + 1/n = ln(n) + C
// C 为欧拉常数 0.57721566490153286060651209

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C 0.57721

int main(void)
{
    char s[5];
    int flag = 0;
    long i;
    double t = 0;
    double sum;

    while(1) {
        scanf("%s", s);
        if (strcmp(s, "0.00") == 0)
        {
            break;
        }
        t = atof(s);

        sum = 0;
        i=0;
        while(sum <= t)
        {
            sum += (double)1/(double)(1+(++i));
        }
        printf("%ld card(s)\n", i);
    }

    return 0;
}
