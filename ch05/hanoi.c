//
// Created by fengyingcai on 2017/4/26.
// 汉诺塔

#include <stdio.h>

/**
 * 汉诺塔的移动，以递归方式进行
 *
 * @param n 盘子数
 * @param from 开始柱子
 * @param target 目标柱子
 * @param middle 中间柱子
 */
void move(int n, char from, char target, char middle);


int main(void)
{
    int disks = 0;

    printf("Disks in hanoi tower: ");
    scanf("%d", &disks);
    move(disks, 'A', 'C', 'B');
    return 0;
}


void move(int n, char from, char target, char middle)
{
    /* 结束条件，n=1 */
    if (n == 1) {
        printf("Move %d from %c to %c\n", n, from, target);
    }
    else {
        /* 先将前 n-1 移到 middle */
        move(n-1, from, middle, target);
        /* n 移动到 target */
        printf("Move %d from %c to %c\n", n, from, target);
        /* n-1 个移动到 target */
        move(n-1, middle, target, from);
    }
}
