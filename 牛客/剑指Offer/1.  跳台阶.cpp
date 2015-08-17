/*
题目描述

一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

class Solution {
public:
    void multiMatrix(int matrix[2][2], int factorMatrix[2][2]) {
        int a11 = matrix[0][0] * factorMatrix[0][0] + matrix[0][1] * factorMatrix[1][0];
        int a12 = matrix[0][0] * factorMatrix[0][1] + matrix[0][1] * factorMatrix[1][1];
        int a21 = matrix[1][0] * factorMatrix[0][0] + matrix[1][1] * factorMatrix[1][0];
        int a22 = matrix[1][0] * factorMatrix[0][1] + matrix[1][1] * factorMatrix[1][1];
         
         
        matrix[0][0] = a11, matrix[0][1] = a12, matrix[1][0] = a21, matrix[1][1] = a22;
    }
     
    int jumpFloor(int number) {
         
        int matrix[2][2] = { {1, 1}, {0, 0}};
        int factorMatrix[2][2] = {{0, 1}, {1, 1}};
         
        while(number) {
            if (number & 0x01) {
                multiMatrix(matrix, factorMatrix);
            }
             
            multiMatrix(factorMatrix, factorMatrix);
            number >>= 1;
        }
         
        return matrix[0][0];
    }
};
