/*
题目描述

写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/

class Solution {
public:
    int Add(int num1, int num2)
    {
        int v1 = (num1 & num2) << 1, v2 = num1 ^ num2;
         
        while(v1) {
            int temp = v1;
            v1 = (v1 & v2) << 1;
            v2 = temp ^ v2;
        }
         
        return v2;
    }
};
