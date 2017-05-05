//
// Created by fengyingcai on 2017/5/5.
//

// 表达式通用的计算框架
// 可扩展

#include <deque>
#include <cstdio>

using namespace std;

// 运算
int calc(int a, int b, char op){
    switch (op) {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
    }
    return 0;
}

// 获取运算符优先级别
char get_order(char op)
{
    switch(op){
        case '(':
        case ')':
            return 0;
        case '*':
        case '/':
            return -1;
        case '+':
        case '-':
            return -2;
    }
    return 0;
}

// 弹出
void pop_calc(deque<char>* operators, deque<int>* oprands)
{
    char op;
    int k0, k1;
    int r;

    op = *operators->rbegin();
    operators->pop_back();
    k0 = *oprands->rbegin();
    oprands->pop_back();
    k1 = *oprands->rbegin();
    oprands->pop_back();
    r = calc(k1, k0, op);
    oprands->push_back(r);
}

int main(void)
{
    char s[4000];
    char *p;
    int num;
    char op;
    int k0, k1;
    int r;
    deque<char> operators;
    deque<int> oprands;
    int i;
    int k;

    scanf("%s", s);
    p = s;
    while (*p!=0) {
        if (*p>='0' && *p<='9') {
            // 数字处理
            k = sscanf(p, "%d", &num);
            oprands.push_back(num);
            while(*p>='0' && *p<='9')
                p++;
        }
        else {

            // 操作符处理
            if (*p=='(') {
                operators.push_back(*p);
                p++;
            }
            else if (*p==')') {
                while(*operators.rbegin()!='(') {
                    pop_calc(&operators, &oprands);
                }
                // 退 (
                operators.pop_back();
                p++;
            }
            else {
                // *p 优先级计算
                while (operators.rbegin() != operators.rend() && *operators.rbegin()!='(' &&
                       op_order(*operators.rbegin(), *p)>=0) {
                    pop_calc(&operators, &oprands);
                }
                // 压符号
                operators.push_back(*p);
                p++;
            }
        }
    }

    // 最后的计算
    while(operators.rbegin() != operators.rend())
    {
        pop_calc(&operators, &oprands);
    }

    r = *oprands.rbegin();
    oprands.empty();
    operators.empty();

    printf("%d\n", r);

    return 0;
}
