//
// Created by fengyingcai on 2017/5/3.
//

#include <stdio.h>
#include <math.h>

#define PI 3.1415927

int main(void)
{
    int n;
    double x, y;    // 坐标 x,y
    double area;    // 半圆面积
    int year;       // 第 year 年被冲坏
    int i;

    scanf("%d", &n);
    for (i=0; i<n; i++){
        scanf("%lf %lf", &x, &y);
        area = PI * (x*x + y*y) / 2;
        year = ceil(area / 50);
        printf("Property %d: This property will begin eroding in year %d.\n", i+1, year);
    }
    printf("END OF OUTPUT.\n");

    return 0;
}
