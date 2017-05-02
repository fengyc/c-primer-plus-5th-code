//
// Created by fengyingcai on 2017/4/28.
//

// buffer 读写，使用双向队列

#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buff[BUFSIZE];

int head = 0;    // 队列头
int tail = 0;    // 队列尾

// 写 buff 函数
int write(char *data, size_t size){
    int count = 0;
    while ((head + 1) - BUFSIZE < tail && count < size)
    {
        buff[head] = data[count++];
        head = (head + 1) % BUFSIZE;
    }
    return count;
}


// 读 buff 函数
int read(char *data, size_t size)
{
    int count = 0;
    while( tail != head && count < size) {
        data[count++] = buff[tail];
        tail = (tail + 1) % BUFSIZE;
    }
    return count;
}

int main(void)
{
    char *data = "Hello, world!";
    char result[1000];
    char *presult = result;
    int i = 0;
    int count = 0;
    size_t datalen = strlen(data);

    for (i=0; i<15; i++) {
        count = write(data, datalen);
        printf("%d write %d bytes\n", i, count);
    }
    printf("\n");

    for (i=0; i<15; i++) {
        count = read(presult, 10);
        presult += count;
        printf("%d read %d bytes\n", i, count);
    }
    *presult = 0;
    printf("\n");
    printf("%s\n", result);

    return 0;
}
