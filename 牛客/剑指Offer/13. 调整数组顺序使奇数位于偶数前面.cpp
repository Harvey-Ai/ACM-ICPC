/*
题目描述

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> res(array.size());
         
        int start = 0, end = array.size() - 1;
        for(int i = 0, j = array.size() - 1;i < array.size() || j >= 0;i++, j--) {
            while(i < array.size() && ((array[i] & 0x01) == 0)) {
                i++;
            }
             
            while(j >= 0 && ((array[j] & 0x01) == 1)) {
                j--;
            }
             
            if (i < array.size())
                res[start++] = array[i];
             
            if (j >= 0)
                res[end--] = array[j];
        }
         
        array = res;
    }
};
