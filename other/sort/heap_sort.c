//
// Created by fengyc on 2017/5/3.
//

// 堆排序
// 只需要一个辅助存储空间用于交换
// k(i) <= k(2i), k(i) <= k(2i+1) ，小根堆  用于从大到小排序
// k(i) >= k(2i), k(i) >= k(2i+1)   大根堆  用于从小到大排序
// 以 0 为开始下标时，为 2i+1 和 2i+2
// 步骤：
// 堆化，调整使得满足成堆条件
// 输出元素后调整，用堆最后的元素作为顶，则左右子树都为堆，比较左右子树的堆顶来确定进行堆化的树

#include <stdio.h>

// 堆调整
void heap_adjust(int *a, int low, int high)
{
    int r = a[low];     // 大根
    for (int i=2*low + 1; i<=high; i=2*i+1)
    {
        // 大根堆时，沿较大的子堆调整
        if (i<high && a[i] < a[i+1])
            ++i;
        // 找到了位置
        if (r >= a[i])
            break;
        // 继续调整
        a[low] = a[i];
        low = i;
    }
    a[low] = r;
}

// 堆排序
void heap_sort(int a[], int a_len)
{
    // 堆化为大根堆，从 a_len/2 向前调整
    for (int i=(a_len-1)/2; i>=0; i--)
    {
        heap_adjust(a, i, a_len-1);
    }
    for (int i=a_len-1; i>0; i--)
    {
        // 大根交换到最后
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        // 调整堆再次成为大根堆
        heap_adjust(a, 0, i-1);
    }
}


int main(void)
{
    int a[] = {9, 7, 3, 4, 6, 2, 0, 11, 5, 10, 1};

    heap_sort(a, 11);

    for (int i= 0; i<11; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
