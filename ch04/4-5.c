//
// Created by fengyc on 2017/4/25.
//

#include <stdio.h>
#include <limits.h> // 整数限制
#include <float.h>  // 浮点数限制

int main(void)
{
    printf("Some number limits for this system: \n");
    printf("Biggest int: %d\n", INT_MAX);
    printf("Smallest unsigned long: %lld\n", LLONG_MIN);
    printf("One byte = %d bits on this syste.\n", CHAR_BIT);
    printf("Largest double: %e\n", DBL_MAX);
    printf("Smallest normal float: %e\n", FLT_MIN);
    printf("float precision = %d digits\n", FLT_DIG);
    printf("float epsilon = %e\n", FLT_EPSILON);
    return 0;
}
