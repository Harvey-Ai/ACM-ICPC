/*
题目描述

将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
*/

class Solution {
public:
    int StrToInt(string str) {
        if (str.size() == 0)
            return 0;
         
        int pos = 0;
        bool neg = false;
        if (str[0] == '-') {
            pos++;
            neg = true;
        } else if (str[0] == '+')
            pos++;
         
        int res = 0;
        for(int i = pos;i < str.size();i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                res *= 10;
                res += str[i] - '0';
            } else
                return 0;
        }
         
        return neg ? -res : res;
    }
};
