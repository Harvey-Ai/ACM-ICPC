/*
题目描述

给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/


class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> window(num.size());
          
        int start = 0, end = -1;
        int i;
        for(i = 0;i < size - 1 && i < num.size();i++) {
            while(end >= start && num[i] >= num[window[end]])
                end--;
            window[++end] = i;
        }
          
        vector<int> ans;
          
        for(;i < num.size();i++) {
            while(start <= end && window[start] + size <= i) {
                start++;
            }
            while(end >= start && num[i] >= num[window[end]])
                end--;
            window[++end] = i;
              
            ans.push_back(num[window[start]]);
        }
          
        return ans;
    }
};
