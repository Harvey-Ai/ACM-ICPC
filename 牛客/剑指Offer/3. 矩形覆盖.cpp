/*
题目描述

我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

class Solution {
public:
    int rectCover(int number) {
 
        int dp[number + 1];
        dp[0] = 1;
        dp[1] = 1;
         
        for(int i = 2;i <= number;i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
         
        return dp[number];
    }
};
