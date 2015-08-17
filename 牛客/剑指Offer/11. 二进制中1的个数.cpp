/*
题目描述

输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

class Solution {
public:
     int  NumberOf1(int n) {
         int oneNum = 0;
         if (n < 0) {
             n &= 0x7FFFFFFF;
             oneNum++;
         }
          
         while(n) {
             oneNum++;
             n &= (n - 1);
         }
          
         return oneNum;
     }
};
