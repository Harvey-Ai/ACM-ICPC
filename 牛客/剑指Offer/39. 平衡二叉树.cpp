/*
题目描述

输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/

class Solution {
public:
    bool ok = true;
     
    int treeHeight(TreeNode* pRoot) {
        if (pRoot == NULL)
            return 0;
         
        int leftHeight = treeHeight(pRoot->left);
        int rightHeight = treeHeight(pRoot->right);
        if (abs(leftHeight - rightHeight) > 1)
            ok = false;
         
        return max(leftHeight, rightHeight) + 1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        treeHeight(pRoot);
         
        return ok;
    }
};
