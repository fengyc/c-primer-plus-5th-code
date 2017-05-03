//
// Created by fengyingcai on 2017/5/2.
//

#include <stdio.h>
#include <string.h>

#define N  200

unsigned char p0[N];
unsigned char p1[N];


// 字符串转成整数数字，底位为最低位
void convert_to_int(char *s, unsigned char *r)
{
    int len = strlen(s);
    int i, j;

    for (i=0, j=len-1; j >= 0; j--) {
        if (s[j] == '.') {
            continue;
        }
        r[i] = s[j] - '0';
        i++;
    }
}

// 大数相乘，底地址为数的最低位
void multiply(unsigned char *a, int a_len, unsigned char *b, int b_len, unsigned char *c)
{
    int i, j = 0;

    // 直接以整数方式计算，小数位后续加上
    for (i=0; i<b_len; i++) {
        for (j=0; j<a_len; j++) {
            int r =  b[i] * a[j];
            c[i+j] += r;
            c[i+j+1] += c[i+j] / 10;
            c[i+j] = c[i+j] % 10;
        }
    }

}

// 获取小数点位置
int getDotPos(char *s)
{
    int i = 0;
    int len = strlen(s);
    for (i=0; i<len; i++) {
        if (s[i] == '.') {
            return i;
        }
    }
    return -1;
}

void calcAndPrint(char *R, int n)
{
    int dot_pos = getDotPos(R);     // 小数点位置
    int dot_len = 0;                // 小数位数
    unsigned char r[6];             // 转换为整数
    int p0_len = 0;                 // p0 长度
    int low_0 = 0;                  // 底位 0
    int high_0 = 0;                 // 高位 0
    int i = 0;

    // 初始化
    if (dot_pos >= 0) {
        dot_len = strlen(R) - dot_pos - 1;
    }
    memset(r, 0, 6);
    memset(p0, 0, N);
    memset(p1, 0, N);
    convert_to_int(R, r);
    memcpy(p0, r, 6);
    p0_len = 6;

    // 计算大数
    for (i=1; i < n; i++)
    {
        multiply(p0, p0_len, r, 6, p1);
        p0_len += 6;
        memcpy(p0, p1, p0_len);
        memset(p1, 0, p0_len);
    }

    // 输出处理
    dot_len = dot_len * n;  // 总小数位数
    // 底位 0
    for (i=0; i < p0_len; i++)
    {
        if (p0[i]!=0)
            break;
        low_0 ++;
    }
    // 高位 0
    for (i=p0_len-1; i >= 0; i--) {
        if (p0[i]!=0)
            break;
        high_0 ++;
    }
    // 输出高位
    for (i=p0_len - high_0 - 1; i>=dot_len; i--)
    {
        printf("%d", p0[i]);
    }
    // 输出小数点
    if (dot_len > low_0) {
        printf(".");
    }
    // 输出低位
    for (i=dot_len-1; i >= low_0; i--)
    {
        printf("%d", p0[i]);
    }
    printf("\n");
}

int main(void)
{
    char R[7];
    int n;

    while(scanf("%s %d", R, &n) != EOF)
    {
        calcAndPrint(R, n);
    }

    return 0;
}
