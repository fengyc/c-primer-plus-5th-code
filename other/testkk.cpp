#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    vector<vector<int> > pads;
    vector<int> k;
    string s;

    vector<int> v0;
    v0.push_back(0);
    pads.push_back(v0);

    vector<int> v1;
    for (int i = 0; i< 10; i++)
        v1.push_back(i);
    pads.push_back(v1);

    vector<int> v2;
    v2.push_back(0);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(8);
    v2.push_back(9);
    pads.push_back(v2);

    vector<int> v3;
    v3.push_back(3);
    v3.push_back(6);
    v3.push_back(9);
    pads.push_back(v3);

    vector<int> v4;
    v4.push_back(0);
    v4.push_back(4);
    v4.push_back(5);
    v4.push_back(6);
    v4.push_back(7);
    v4.push_back(8);
    v4.push_back(9);
    pads.push_back(v4);

    vector<int> v5;
    v5.push_back(0);
    v5.push_back(5);
    v5.push_back(6);
    v5.push_back(8);
    v5.push_back(9);
    pads.push_back(v5);

    vector<int> v6;
    v6.push_back(6);
    v6.push_back(9);
    pads.push_back(v6);

    vector<int> v7;
    v7.push_back(0);
    v7.push_back(7);
    v7.push_back(8);
    v7.push_back(9);
    pads.push_back(v7);

    vector<int> v8;
    v8.push_back(0);
    v8.push_back(8);
    v8.push_back(9);
    pads.push_back(v8);

    vector<int> v9;
    v9.push_back(9);
    pads.push_back(v9);

    int t;
    cin >> t;
    while (t--) {
        cin >> s;

        k.clear();
        int x, y;       // 当前键盘位置
        int pos;        // 字符位置
        if (s == "0")
            cout << "0";
        else {
            k.push_back(s[0]-'0');
            pos = 1;
            int flag = 0;   // 标记是否已小于 s
            while (pos < s.length()) {
                int num = s[pos] - '0';
                vector<int> pad = pads[*k.rbegin()];
                // 已小于 s ，直接插入最大数
                if (flag) {
                    k.push_back(*pad.rbegin());
                    pos++;
                    continue;
                }
                // 超出范围
                if (num < *pad.begin()) {
                    // 回溯，上一个位置尝试
                    int num1 = *k.rbegin();
                    pos--;
                    k.pop_back();
                    vector<int> pad1 = pads[num1];
                    while(1) {
                        // 找前一个
                        vector<int>::reverse_iterator itr = find(pad1.rbegin(), pad1.rend(), num1);
                        // 前一个可用
                        if (itr+1 != pad1.rend()) {
                            k.push_back(*(itr + 1));
                            flag = 1;
                            pos++;
                            break;
                        } else {
                            // 是否还有前一个
                            if (k.rbegin()+1 != k.rend()) {
                                k.pop_back();
                                num1 = *k.rbegin();
                                pos--;
                                pad1 = pads[num1];
                            } else {
                                pad1 = v1;
                            }


                        }
                    }
                } else {
                    vector<int> pad =  pads[*k.rbegin()];
                    vector<int>::iterator itr = pad.begin();
                    int max_num = *itr;
                    while (itr != pad.end()) {
                        if (*itr <= num) {
                            max_num = *itr;
                            itr++;
                        } else
                            break;
                    }
                    if (max_num < num)
                        flag = 1;
                    k.push_back(max_num);
                    pos ++;
                }
            }
        }
        // 输出
        for (int i=0;i<k.size();i++) {
            cout<<k[i];
        }
        cout << endl;
    }

    return 0;
}
