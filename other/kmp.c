//
// Created by fengyingcai on 2017/4/27.
//

/**
 * KMP 算法用于字符串匹配
 *
 * 在模式串中存在部分串与开头相同时，可跳过一部分的比较而继续比较剩下的部分
 *
 * 使用 next 跳转表保存模式串的跳转
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int find(char *s, char *p, int pos)
{
    int i = pos;    // 待搜索字符串下标
    int j = 0;      // 模式当前下标
    int slen = strlen(s);   // 待搜索字符串长度
    int plen = strlen(p);   // 模式长度
    while (i < slen)
    {
        if (s[i] != p[j])
        {
            i = i - j + 1;  // 不匹配，回溯
            j = 0;
        }
        else
        {
            i++;    // 匹配，下一个位置
            j++;
            if (j == plen)
            {
                return i - plen;
            }
        }
    }
    return -1;
}

int* getNext(char *p)
{
    int i, k;
    int plen = strlen(p);
    int *next = calloc(plen, sizeof(int));

    next[0] = -1;

    i = 1, k = 0;
    while (i < plen)
    {
        if (k==-1 || p[i] == p[k])
        {
            i++, k++;
            next[i] = k;
        }
        else
        {
            k = next[k];
        }
    }

    return next;

}

int kmp(char *s, char *p, int pos)
{
    int i = pos;
    int j = 0;
    int slen = strlen(s);
    int plen = strlen(p);

    int *next = getNext(p);

    while (i < slen)
    {
        if (j == -1 || s[i] == p[j])
        {
            i++, j++;
            if (j==plen)
            {
                return i-plen;
            }
        }
        else
        {
            j = next[j];
            printf("%s\n", s);
            printf("%s\n", p);
            printf("%d %d\n", i, j);
            printf("\n");
        }
    }

    free(next);
    next = NULL;

    return -1;
}

int main(void)
{
    char *s = "";
    char *p = "";
    int lenOfP = 0;
    int* next = NULL;
    int i, j;
    int r = 0;

//    printf("String is: ");
//    scanf("%s", s);
//    printf("Pattern is: ");
//    scanf("%s", p);
    s = "ababcabcacbab";
    p = "abcac";

//    r = find(s, p, 0);
    r = kmp(s, p, 0);
    printf("Index result: %d", r);

    return 0;
}
