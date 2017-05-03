//
// Created by fengyingcai on 2017/5/3.
//

// 压缩图的处理，run lenght 转换为 index

#include <stdio.h>
#include <math.h>

typedef struct _Pair {
    int value;
    int rl;
} Pair, *PPair;


// 二分查找在压缩图中找到位置 k 所在的块
int bisearch(Pair image[], int k, int low_block, int high_block)
{
    int middle_block = low_block + high_block / 2;
    if (k <= image[middle_block].rl) {
        if (middle_block != 0) {
            if (k > image[middle_block-1].rl) {
                return middle_block;
            }
        }
        else
            return 0;
        return bisearch(image, k, low_block, middle_block);
    }
    return bisearch(image, k, middle_block+1, high_block);
}

// 计算位置 k 的 edge 值
int calcPosEdge(Pair image[], int blocks, int width, int heigh, int k)
{
    int emax = 0;
    int e = 0;
    int eblock = 0;
    int kblock = bisearch(image, k, 0, blocks-1);
    int kvalue = image[kblock].value;

    // 从左上到右下，k-width-1, k-width, k-width+1, k-1, k+1, k+width-1, k+width, k+width+1
    // 注意边界
    // k-width-1
    if ( k%width > 0 && k/width > 0)
    {
        eblock = bisearch(image, k-width-1, 0, kblock);
        e = (int)fabs((double)kvalue - image[eblock].value);
        emax = e > emax ? e : emax;
    }
    // k-width
    if (k / width > 0)
    {
        eblock = bisearch(image, k-width, 0, kblock);
        e = (int)fabs((double)kvalue - image[eblock].value);
        emax = e > emax ? e : emax;
    }
    // k-width+1
    if (k/width > 0 && k%width < (width-1))
    {
        eblock = bisearch(image, k-width+1, 0, kblock);
        e = (int)fabs((double)kvalue - image[eblock].value);
        emax = e > emax ? e : emax;
    }
    // k-1
    if (k%width > 0)
    {
        eblock = bisearch(image, k-1, 0, kblock);
        e = (int)fabs((double)kvalue - image[eblock].value);
        emax = e > emax ? e : emax;
    }
    // k+1
    if (k%width < (width-1))
    {
        eblock = bisearch(image, k+1, kblock, blocks-1);
        e = (int)fabs((double)kvalue - image[eblock].value);
        emax = e > emax ? e : emax;
    }
    // k+width-1
    if (k/width < (heigh-1) && k%width > 0)
    {
        eblock = bisearch(image, k+width-1, kblock, blocks-1);
        e = (int)fabs((double)kvalue - image[eblock].value);
        emax = e > emax ? e : emax;
    }
    // k+width
    if (k/width < (heigh-1))
    {
        eblock = bisearch(image, k+width, kblock, blocks-1);
        e = (int)fabs((double)kvalue - image[eblock].value);
        emax = e > emax ? e : emax;
    }
    // k+width+1
    if (k/width < heigh-1 && k%width < width-1)
    {
        eblock = bisearch(image, k+width+1, kblock, blocks-1);
        e = (int)fabs((double)kvalue - image[eblock].value);
        emax = e > emax ? e : emax;
    }
    return emax;
}

// 调整并打印结果
void adjustAndPrintResult(Pair *result, int r, int c)
{
    if (c !=0 && (result->rl = 0 || result->value == r)) {
        result->value = r;
        result->rl += c;
    }
    else {
        // 输出上一步结果
        printf("%d %d", result->value, result->rl);
        result->value = r;
        result->rl = c;
    }
}


int main(void)
{
    int width, height;
    int total;
    Pair image[1000];
    int i, j;
    int x, y, z;     //
    int blocks;      // 块数
    Pair result = {0,0};    // 上一步结果

    while (1) {
        scanf("%d", &width);
        if (width == 0)
            break;
        blocks = 0;
        while (1) {
            scanf("%d %d", &(image[blocks].value), &(image[blocks].rl));
            if (image[blocks].value != 0 && image[blocks].rl != 0)
                blocks++;
            else {
                // 当前压缩图输入完成，开始处理
                printf("%d\n", width);

                total = 0;
                for (i = 0; i < blocks; i++) {
                    total += image[i].rl;
                    // 转换 rl 到边界下标
                    image[i].rl = total - 1;
                }
                height = total / width;

                // 每个块，分为顶块，底块和中间块，中间块全为0
                for (j = 0; j < blocks; j++) {
                    int head_pos = j > 0 ? image[j - 1].rl + 1 : 0;    // 开始位置
                    int head_pox_x = head_pos % width;               // 开始 x
                    int head_pos_y = head_pos / width;               // 开始 y
                    int tail_pos = image[j].rl;                      // 结束位置
                    int tail_pos_x = tail_pos % width;               // 结束 x
                    int tail_pos_y = tail_pos / width;               // 结束 y
                    int k;                                           // 计算位置

                    // 头部处理
                    int flag = 0;   // 设置标志
                    if (head_pox_x != 0)
                        flag = 1;
                    for (k = head_pos; k <= head_pos + width + flag && k <= tail_pos; k++) {
                        int r = calcPosEdge(image, blocks, width, height, k);
                        adjustAndPrintResult(&result, r, 1);
                    }
                    // 中间部处理，先确定中间部结束位置
                    flag = 0;
                    if (tail_pos_x != width - 1)
                        flag = 1;
                    if (tail_pos - width - flag - k + 1 > 0) {
                        // 如果有中间部
                        adjustAndPrintResult(&result, 0, tail_pos - width - flag - k + 1);
                        // 调整 k
                        k = tail_pos - width - flag + 1;
                    }
                    // 尾部处理
                    for (; k <= tail_pos; k++) {
                        int r = calcPosEdge(image, blocks, width, height, k);
                        adjustAndPrintResult(&result, r, 1);
                    }
                }
                // 本次处理完成
                adjustAndPrintResult(&result, 0, 0);
                break;
            }
        }
    }

    return 0;
}
