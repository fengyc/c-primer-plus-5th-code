//
// Created by fengyingcai on 2017/4/17.
//

#include <stdio.h>

int main(void)
{
    float inches = 0.0f;
    float centimetres = 0.0f;

    printf("How many inches: ");
    scanf("%f", &inches);
    centimetres = inches * 2.54;
    printf("Centimetres: %f\n", centimetres);
    return 0;
}
