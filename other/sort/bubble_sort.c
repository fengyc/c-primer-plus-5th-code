//
// Created by fengyc on 2017/5/2.
//

#include <stdio.h>

// 冒泡排序
void bubblesort(int a[], int len)
{
    int flag = 0;   // 标记是否有交换

    for (int i=0; i<len; i++)
    {
        flag = 0;
        for (int j=0; j<len-i-1; j++)
        {
            if (a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

int main(void)
{
    int a[] = {9, 7, 3, 4, 6, 2, 0, 11, 5, 10, 1};
    bubblesort(a, 11);
    for (int i= 0; i<11; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

