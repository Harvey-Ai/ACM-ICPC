/*
题目描述

把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        int uglyArr[index];
        uglyArr[0] = 1;
         
        int pos2 = 0, pos3 = 0, pos5 = 0;
        for(int i = 1;i < index;i++) {
            int val = min(uglyArr[pos5] * 5,
                    min(uglyArr[pos2] * 2, uglyArr[pos3] * 3));
            uglyArr[i] = val;
             
            if (val == uglyArr[pos2] * 2)
                pos2++;
            if (val == uglyArr[pos3] * 3)
                pos3++;
            if (val == uglyArr[pos5] * 5)
                pos5++;
        }
         
        return uglyArr[index - 1];
    }
};
