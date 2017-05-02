//
// Created by fengyingcai on 2017/5/2.
//

// 使用 map 或位图

#include <cstdio>
#include <cstring>
#include <map>

using namespace std;


int conver_num(char c)
{
    switch (c) {
        case 'A':
        case 'B':
        case 'C':
            return 2;
        case 'D':
        case 'E':
        case 'F':
            return 3;
        case 'G':
        case 'H':
        case 'I':
            return 4;
        case 'J':
        case 'K':
        case 'L':
            return 5;
        case 'M':
        case 'N':
        case 'O':
            return 6;
        case 'P':
        case 'R':
        case 'S':
            return 7;
        case 'T':
        case 'U':
        case 'V':
            return 8;
        case 'W':
        case 'X':
        case 'Y':
            return 9;
    }
    return 0;
}

// 号码对应到数字
int calc(char *s)
{
    int i;
    int num = 0;

    for (i=0; i<strlen(s); i++){
        if (s[i] == '-')
            continue;
        if (s[i]>='0' && s[i] <= '9')
            num = num * 10 + (s[i] - '0');
        else
            num = num * 10 + conver_num(s[i]);
    }
    return num;
}

int main(void)
{
    map<int, int> counts;
    int n;
    int i, j = 0;
    char s[8];
    int flag = 0;
    int num = 0;
    map<int, int>::iterator iter;

    // 计数
    scanf("%d", &n);
    for (i=0; i < n; i++)
    {
        j = 0;
        while (j < 7) {
            scanf("%c", &s[j]);
            if ((s[j]>='0' && s[j]<='9') || (s[j] >= 'A' && s[j] <= 'Z')) {
                j++;
            }
        }
        s[7] = 0;
        num = calc(s);
        iter = counts.find(num);
        if (iter != counts.end())
        {
            iter->second += 1;
        }
        else
        {
            counts.insert(make_pair(num, 1));
        }
    }

    // 输出
    for (map<int, int>::iterator iter = counts.begin(); iter != counts.end(); iter++)
    {
        if (iter->second > 1) {
            flag = 1;
            printf("%03d-%04d %d\n", iter->first/10000, iter->first % 10000, iter->second);
        }
    }
    if (flag == 0)
    {
        printf("No duplicates.\n");
    }

    return 0;
}
