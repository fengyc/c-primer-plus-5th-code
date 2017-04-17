//
// Created by fengyingcai on 2017/4/17.
//

#include <stdio.h>

int main(void)
{
    float weight;   /* 用户的体重 */
    float value;    /* 相等重量的铑的价值 */
    printf("Are you worth your weight in rhodium?\n");
    printf("Let's check it out.\n");
    printf("Please enter your weight in pounds: ");
    /* 获取用户输入 */
    scanf("%f", &weight);
    /* 假设铑为每盎司 770 美元 */
    /* 14.5833 把镑转换为盎司 */
    value = 770 * weight * 14.5833;
    printf("Your weight in rhodium is worth $%.2f.\n", value);
    printf("Your are easily worth that! If rhodium prices drop.\n");
    printf("eat more to maintain your value.\n");
    return 0;
}
