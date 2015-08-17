/*
题目描述

输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        if (pre.size() == 0)
            return NULL;
          
        TreeNode* root = new TreeNode(pre[0]);
          
        int leftNum = 0;
        for(int i = 0;i < in.size();i++)
            if (in[i] != pre[0])
                leftNum++;
            else
                break;
        vector<int> leftPre(pre.begin() + 1, pre.begin() + leftNum + 1);
        vector<int> rightPre(pre.begin() + leftNum + 1, pre.end());
        vector<int> leftIn(in.begin(), in.begin() + leftNum);
        vector<int> rightIn(in.begin() + leftNum + 1, in.end());
 
        if (in.size() > 1) {
            root->left = reConstructBinaryTree(leftPre, leftIn);
            root->right = reConstructBinaryTree(rightPre, rightIn);
        }
  
        return root;
    }
};
