//
// Created by fengyc on 2017/5/2.
//

// 希尔排序，缩小增量排序

#include <stdio.h>

// 希尔增量插入
void shell_insert(int *a, int a_len, int d)
{
    int i = 0;
    int j = 0;

    for (i=d; i<a_len; i++){
        int tmp = a[i];
        // 向前比较，以 d 为增量，找到插入位置
        for (j=i-d; j >= 0 && a[j]>tmp; j-=d)
        {
            a[j+d] = a[j];
        }
        // 找到位置
        a[j+d] = tmp;
    }
}

// 希尔排序
void shell_sort(int *a, int a_len, int *d, int t)
{
    int i = 0;
    for (i=0; i<t; i++)
        shell_insert(a, a_len, d[i]);
}

int main(void)
{
    int a[] = {9, 7, 3, 4, 6, 2, 0, 11, 5, 10, 1};
    int d[] = {1, 3, 5};

    shell_sort(a, 11, d, 3);

    for (int i= 0; i<11; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
