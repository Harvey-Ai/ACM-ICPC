/*
题目描述

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {   
        for(int i = 1;i < rotateArray.size();i++) {
            if (rotateArray[i] < rotateArray[i - 1]) {
                return rotateArray[i];
            }
        }
         
        if (rotateArray.size() > 0)
            return rotateArray[0];
        return 0;
         
    }
};

