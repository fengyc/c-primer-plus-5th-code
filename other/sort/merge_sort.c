//
// Created by fengyc on 2017/5/3.
//

#include <stdio.h>

void dump(int a[], int low, int high)
{
    for (int i=low; i<=high;i++)
        printf("%d ", a[i]);
    printf("\n");
}

// 归并， a[m...n] a[n+1...o] 辅助空间 b[m...o]
void merge(int a[], int b[], int m, int n, int o)
{
    int i, j;
    int k = 0;
    // 合并
    for (i=m, j=n+1, k=i; i<=n && j<=o; k++)
    {
        if (a[i] < a[j])
            b[k] = a[i++];
        else
            b[k] = a[j++];
    }
    if (i<=n){
        for (;i<=n;i++)
            b[k++] = a[i];
    }
    if (j<=o){
        for (;j<=0;j++)
            b[k++] = a[j];
    }
    // 更新 a
    for (i=m;i<=o;i++)
        a[i] = b[i];
}

// 归并排序 a[low...high], b[low ... high] 为辅助
void merge_sort(int a[], int b[], int low, int high)
{
    if (low==high)
        b[low] = a[low];
    else {
        int middle = (low + high) / 2;
        merge_sort(a, b, low, middle);
        merge_sort(a, b, middle + 1, high);
        merge(a, b, low, middle, high);
    }
}



int main(void)
{
    int a[] = {9, 7, 3, 4, 6, 2, 0, 11, 5, 10, 1};
    int b[11] = {0};    // 辅助

    merge_sort(a, b, 0, 10);

    for (int i= 0; i<11; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}