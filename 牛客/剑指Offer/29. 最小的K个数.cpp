/*
题目描述

输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/


class Solution {
public:
     
    void helper(vector<int> &input, int start, int end, int k, vector<int> &ans) {
        int pivot = input[start];
         
        int head = start + 1, tail = end - 1;
        while(head < tail) {
            while(head < end && input[head] <= pivot) head++;
            while(tail > start && input[tail] >= pivot) tail--;
             
            if (head < tail) {
                swap(input[head], input[tail]);
                head++, tail--;
            }
        }
        swap(input[start], input[tail]);
         
        if (tail - start + 1 <= k) {
            ans.insert(ans.end(), input.begin() + start, input.begin() + tail + 1);
            if (tail - start + 1 < k) {
                helper(input, tail + 1, end, k - (tail - start + 1), ans);
            }
        } else
            helper(input, start, tail, k, ans);
    }
     
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ans;
        if (k > input.size() || k <= 0 || input.size() == 0) {
            return ans;
        }
         
        helper(input, 0, input.size(), k, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
