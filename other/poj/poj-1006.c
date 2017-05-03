//
// Created by fengyingcai on 2017/5/3.
//

// 中国剩余定理，同余
// k % 23 = p % 23 , k % 28 = e % 28, k % 33 = i % 33
// k = p (mod 23),  k = e (mod 28), k = i (mod 33)
// x = ai (mod mi)
// 若 m(i) 互质，则在 mod M = m1 * m2 ... * mn 上有整数解，为
// x = (a1 * M1 * N1 + ... + an * Mn * Nn)
// Mi = M / mi ，Ni 为 Mi 逆元 (即 Ni * Mi = 1 (mod mi))
// Ni 通过扩展欧几里德公式求解

#include <stdio.h>

// 扩展欧几里德求 a 逆元 x
int egcd(int a, int b, int *x, int *y)
{
    int r;
    int tmp;

    if (b==0) {
        *x = 1;
        *y = 0;
        return a;
    }
    r = egcd(b, a%b, x, y);
    tmp = *x;
    *x = *y;
    *y = tmp - a/b * (*y);
    return *x;
}

// 中国剩余定理
int crl(int p, int e, int i, int d)
{
    int next, x, y;
    int m[] = {23, 28, 33};
    int M = 23 * 28 * 33;
    int M1 = M / 23;
    int M2 = M / 28;
    int M3 = M / 33;

    next += (M1*egcd(M1, 23, &x, &y) % M + M) * p;
    next += (M2*egcd(M2, 28, &x, &y) % M + M) * e;
    next += (M3*egcd(M3, 33, &x, &y) % M + M) * i;
    next = (next - d + M) % M;
    if (next == 0)
        next = M;
    return next;
}

// 简单枚举，以 1 为步长
int force(int p, int e, int i, int d)
{
    int next;
    int step = 1;

    next = d+1;
    while (1)
    {
        if ((next-p)%23==0 && (next-e)%28==0 && (next-i)%33==0)
            break;
        next += step;
    }
    return next;
}

// 暴力枚举，以 33 为步长
int force2(int p, int e, int i, int d)
{
    int next;
    int step = 33;

    // 求 33 的下个峰点
    next = i;
    while (next < d)
        next += step;

    // 以 33 为步长
    while (1)
    {
        if ((next-p)%23==0 && (next-e)%28==0)
            break;
        next += step;
    }

    next -= d;
    return next;
}

// 暴力枚举，并加速
// 先求 23 与 28 的共同高点 x
// x = 23i + p，  x = 28j + e ， 则 i = (28j + e - p) / 23 为整数
// 枚举先求最小j
int force3(int p, int e, int i, int d)
{
    int next;
    int j = 0;
    int step = 23 * 28 / 1;     // 最大公约数为 1

    // 求 j 和 next 初值
    while ((28*j + e - p)%23 != 0)
        j++;
    next = 28*j + e;
    while (next < d)
        next += step;

    while(1)
    {
        if ((next-i)%33 == 0)
            break;
        next += step;
    }

    next = (next - d) % 21252;
    if (next==0)
        next = 21252;
    return next;
}


int main(void)
{
    int p, e, i, d;
    int next;
    int count = 0;

    while (1) {
        scanf("%d %d %d %d", &p, &e, &i, &d);
        if (p==-1 && e==-1 && i==-1 && d==-1)
            break;
        // 计算 next
        next = force3(p, e, i, d);
        printf("Case %d: the next triple peak occurs in %d days.\n", ++count, next);
    }
}
