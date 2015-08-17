/*
题目描述

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/


class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (matrix.size() == 0) return vector<int>();
         
        int m = matrix.size();
        int n = matrix[0].size();
         
        vector<int> ans;
        int topX = 0, bottomX = m - 1, leftY = 0, rightY = n - 1;
        while(topX < bottomX && leftY < rightY) {
            for(int i = leftY;i <= rightY;i++)
                ans.push_back(matrix[topX][i]);
            for(int i = topX + 1;i <= bottomX;i++)
                ans.push_back(matrix[i][rightY]);
            for(int i = rightY - 1;i >= leftY;i--)
                ans.push_back(matrix[bottomX][i]);
            for(int i = bottomX - 1;i > topX;i--)
                ans.push_back(matrix[i][leftY]);
            topX++, bottomX--, leftY++, rightY--;
        }
         
        if (leftY == rightY) {
            for(int i = topX;i <= bottomX;i++)
                ans.push_back(matrix[i][leftY]);
        } else if (topX == bottomX) {
            for(int i = leftY;i <= rightY;i++)
                ans.push_back(matrix[topX][i]);
        }
         
        return ans;
    }
};
