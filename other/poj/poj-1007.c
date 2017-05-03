//
// Created by fengyingcai on 2017/5/3.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 计算无序性
int calc_unshorted(const char *s)
{
    int len = strlen(s);
    int i, j;
    int count = 0;
    for (i=0;i<len-1; i++){
        for (j=i+1;j<len; j++){
            if (s[i] > s[j])
                count++;
        }
    }
    return count;
}

typedef struct _Node {
    char *s;
    int u;
} Node, *PNode;

// 冒泡排序
void sort(PNode *a, int a_len)
{
    int i, j;
    int flag;

    for (i=0;i<a_len;i++) {
        flag = 0;
        for (j=0;j<a_len-i-1;j++) {
            if (a[j]->u > a[j+1]->u) {
                Node *tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                flag = 1;
            }
        }
        if (flag==0)
            break;
    }
}


int main(void)
{
    int n;
    int m;
    char *s;
    PNode *ss;
    int i;

    scanf("%d%d", &n, &m);
    ss = malloc(m * sizeof(PNode));

    for (i=0; i<m; i++) {
        s = malloc(n + 1);
        scanf("%s", s);
        ss[i] = malloc(sizeof(Node));
        ss[i]->s = s;
        ss[i]->u = calc_unshorted(s);
    }

    sort(ss, m);
    for (i=0;i<m;i++){
        printf("%s\n", ss[i]->s);
        free(ss[i]);
    }
    free(ss);
}
