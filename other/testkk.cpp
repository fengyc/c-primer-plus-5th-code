#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int M = 1000007;

// 以 27 为基大数减法，s2 > s1
int minus(char s1[], char s2[], int len) {
    char *tmp = new char[len];
    memcpy(tmp, s2, len);
    for (int i=len-1;i>=0;i--) {
        // 向前借位
        if (tmp[i] < s1[i]) {
            tmp[i] += 27;
            int j = i-1;
            for (;tmp[j]==0;j--) {
                tmp[j] += 26;
            }
            tmp[j] -= 1;
        }
        // 相减
        tmp[i]-=s1[i];
    }
    delete tmp;
}

// 字符串到大数
void str_to_big(string s1, char num[], int len) {
    for (int i=0;i<len;i++) {
        if (i<s1.size()) {
            num[i] = (char)(s1[i]-'a'+1);
        } else {
            num[i] = 0;
        }
    }
}

int main(void)
{
    string s1, s2;
    char num1[101], num2[101];
    int len1, len2;

    while (!cin.eof()) {
        cin >> s1 >> s2 >> len1 >> len2;

        // 长度为 len 时 s1 与 s2 之间的字符串数量为 s2[0..len]-s1[0..len]-1 ，每个字节有27种 0,a...z
        // 使用以27为基的计算方式

    }

    return 0;
}
