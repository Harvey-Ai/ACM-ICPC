/*
题目描述

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() == 0)
            return 0;
         
        int count = 0, val = numbers[0];
        for(auto num : numbers) {
            if (count == 0) {
                count = 1, val = num;
            } else if (val == num) {
                count++;
            } else {
                count--;
            }
        }
         
        count = 0;
        for(auto num : numbers) {
            count += (int) (num == val);
        }
         
        return count > numbers.size() / 2 ? val : 0;
    }
};
