//
// Created by fengyc on 2017/5/2.
//

#include <stdio.h>

// 一个划分
int partition(int a[], int low, int high)
{
    int pivot = a[low];

    while (low < high) {
        while (low < high && a[high] >= pivot)
            high --;
        a[low] = a[high];   // 一个比 pivot 小的记录，或 high = low
        while (low < high && a[low] <= pivot)
            low ++;
        a[high] = a[low];   // 一个比 pivot 大的记录，或 high = low
    }
    a[low] = pivot;
    return low;
}

// 快速排序
void qsort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivoc_loc = partition(a, low, high);
        qsort(a, low, pivoc_loc - 1);
        qsort(a, pivoc_loc + 1, high);
    }
}

int main(void)
{
    int a[] = {9, 7, 3, 4, 6, 2, 0, 11, 5, 10, 1};

    qsort(a, 0, 10);

    for (int i= 0; i<11; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}