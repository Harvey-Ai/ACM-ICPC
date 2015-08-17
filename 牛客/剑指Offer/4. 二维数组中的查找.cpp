/*
题目描述

在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
        if (0 == array.size()) return false;
 
        for(int i = 0, j = array[0].size() - 1; j >= 0 && i < array.size();) {
            if (array[i][j] < target) {
                i++;
            } else if (array[i][j] > target) {
                j--;
            } else
                return true;
        }
          
        return false;
          
    }
};
