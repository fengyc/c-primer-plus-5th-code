//
// Created by fengyc on 2017/5/2.
//

#include <stdio.h>

// 选择排序

void select_sort(int *a, int a_len)
{
    for (int i=0; i<a_len; i++)
    {
        // 找本轮最小
        int min = a[i];
        int min_pos = i;
        for (int j=i+1; j<a_len; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                min_pos = j;
            }
        }
        // 交换
        a[min_pos] = a[i];
        a[i] = min;
    }
}

int main(void)
{
    int a[] = {9, 7, 3, 4, 6, 2, 0, 11, 5, 10, 1};

    select_sort(a, 11);

    for (int i= 0; i<11; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}