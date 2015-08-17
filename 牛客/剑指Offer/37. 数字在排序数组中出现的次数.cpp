/*
题目描述

统计一个数字在排序数组中出现的次数。
*/

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        vector<int>::iterator it1 = lower_bound(data.begin(), data.end(), k);
        vector<int>::iterator it2 = upper_bound(data.begin(), data.end(), k);
         
        return it2 - it1;
    }
};
