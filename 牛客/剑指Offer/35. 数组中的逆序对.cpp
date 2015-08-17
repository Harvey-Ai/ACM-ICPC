/*
题目描述

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
*/

class Solution {
public:
    int count;
    void helper(vector<int> &data, int start, int end) {
        if (start + 1 >= end) {
            return;
        }
         
        int mid = (start + end) / 2;
        helper(data, start, mid);
        helper(data, mid, end);
         
        vector<int> temp;
        for(int index1 = start, index2 = mid;index1 < mid || index2 < end;) {
            if (index2 == end || (index1 < mid && data[index1] <= data[index2])) {
                temp.push_back(data[index1]);
                index1++;
            } else {
                temp.push_back(data[index2]);
                index2++;
                count += mid - index1;
            }
        }
         
        for(int i = start;i < end;i++) {
            data[i] = temp[i - start];
        }
         
    }
      
    int InversePairs(vector<int> data) {
        count = 0;
        helper(data, 0, data.size());
          
        return count;
    }
};
