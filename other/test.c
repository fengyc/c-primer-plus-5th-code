#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// 数字键盘，最少为 10、20、33、40、50、66、70、80、99
int pad[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {-1, 0, -1}
};
int pad_min[] = {10, 20, 33, 40, 50, 66, 70, 80, 99};


void printMaxK(char *s)
{
    int len = strlen(s);
    int i, j;   // 当前位置
    int k, l;
    int delta, min_delta, m, n;  // 与数字最接近的位置
    int flag;   // 如果输出的数已少于 s
    while (s[0] != 0 && s[0]-'0' == 0) {
        s++;
        len--;
    }
    if (s[0] == 0 || s[0]=='0')
        printf("0\n");
    else {
        // 首个位置，确定从 s[0] 还是 s[0]-1 开始
        flag = 0;
        if (len >=2 ){
            if ((s[0]-'0')*(s[1]-'0') < (pad_min[s[0]-'0'-1]))
            {
                flag = 1;
                i = (s[0]-'0'-2)/3;
                j = (s[0]-'0'-2)%3;
            }
        }
        i = (s[0] - '0' - 1 - flag) / 3;
        j = (s[0] - '0' - 1 - flag) % 3;
        printf("%d", pad[i][j]);
        s++;
        while (s[0]!=0){
            if (flag) {
                printf("9");
            }
            // 找一个最近的数
            else{
                min_delta = -99;
                for (k=i; k < 3; k++){
                    for (l=j;l<4;l++) {
                        delta = (s[0]-'a') - pad[i][j];
                        if (min_delta < 0 || (delta >=0 && delta < min_delta)) {
                            min_delta = delta;
                            m=k;
                            n=l;
                        }
                    }
                }
                if (min_delta > 0){
                    flag = 1;
                }
                i=m;
                j=n;
                printf("%d", pad[i][j]);
            }
            s++;
        }
    }
    printf("\n");
}

int main(void)
{
    char s[550];
    int t;

    scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        printMaxK(s);
    }

    return 0;
}


