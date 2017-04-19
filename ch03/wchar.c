//
// Created by fengyingcai on 2017/4/19.
//

#include <wchar.h>
#include <locale.h>
#include <stdio.h>

int main(void)
{
    wchar_t *s = L"你好，世界！\n";

    if (setlocale(LC_ALL, "zh_CN.UTF-8") == NULL)
    {
        printf("Could not set local!\n");
    }
    else
    {
        wprintf(s);
    }

    printf("A is %#x\n", 'A');
    printf("a is %#x\n", 'a');
    printf("<space> is %#x\n", ' ');
    printf("0 is %#x\n", '0');
    printf("<\\n> is %#x\n", '\n');
    printf("<\\r> is %#x\n", '\r');

    return 0;
}
