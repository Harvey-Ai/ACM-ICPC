/*
题目描述

给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if (A.size() == 0)
            return vector<int>();
         
        vector<int> ans(A.size() + 1, 1);
        for(int i = A.size() - 1;i >= 0;i--) {
            ans[i] = ans[i + 1] * A[i];
        }
         
        int product = 1;
        for(int i = 0;i < A.size();i++) {
            ans[i] = product * ans[i + 1];
            product *= A[i];
        }
        ans.pop_back();
         
        return ans;
    }
};
