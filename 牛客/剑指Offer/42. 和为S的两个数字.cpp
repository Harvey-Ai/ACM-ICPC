/*
题目描述

输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。 
输出描述:
对应每个测试案例，输出两个数，小的先输出。*/


class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
         
        vector<int> ans;
        int head = 0, tail = array.size() - 1;
         
        while(head < tail) {
            if (array[head] + array[tail] < sum) {
                head++;
            } else if (array[head] + array[tail] > sum) {
                tail--;
            } else {
                ans.push_back(array[head]);
                ans.push_back(array[tail]);
                return ans;
            }
        }
         
        return ans;
    }
};
