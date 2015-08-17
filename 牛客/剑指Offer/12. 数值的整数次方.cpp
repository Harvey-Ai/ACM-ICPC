/*
题目描述

给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/

class Solution {
public:
    double Power(double base, int exponent) {
        bool neg = exponent < 0;
        exponent = abs(exponent);
          
        double res = 1;
        while(exponent) {
            if (exponent & 0x01) {
                res *= base;
            }
            exponent >>= 1;
            base *= base;
        }
          
          
        return neg ? 1.0 / res : res;
    }
};
