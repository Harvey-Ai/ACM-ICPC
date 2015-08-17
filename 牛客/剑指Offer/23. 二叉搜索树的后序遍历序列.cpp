/*
题目描述

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

class Solution {
public:
    bool helperVerify(vector<int> &seq, int start, int end) {
        if (start > end)
            return true;
          
        int val = seq[end];
        int leftPos;
        for(leftPos = start;leftPos < end;leftPos++) {
            if (val < seq[leftPos])
                break;
        }
          
        for(int i = leftPos;i < end;i++) {
            if (val > seq[i])
                return false;
        }
          
        return helperVerify(seq, start, leftPos - 1) && helperVerify(seq, leftPos, end - 1);
    }
       
    bool VerifySquenceOfBST(vector<int> seq) {
        if (seq.size() == 0)
            return false;
          
        return helperVerify(seq, 0, seq.size() - 1);
           
    }
};
