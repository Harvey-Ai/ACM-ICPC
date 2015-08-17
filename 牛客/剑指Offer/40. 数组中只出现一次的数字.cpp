/*
题目描述

一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/


class Solution {
public:
     
     
     
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
         
        if (data.size() < 2)
            return;
         
        int allXor = 0;
         
        for(auto num : data) {
            allXor ^= num;
        }
         
        int bitVal = 1;
        while((allXor & bitVal) == 0) {
            bitVal <<= 1;
        }
         
        *num1 = *num2 = 0;
        for(auto num : data) {
            if (bitVal & num)
                *num1 ^= num;
            else
                *num2 ^= num;
        }
    }
};
