/*
题目描述

请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/

class Solution {
public:
    bool check(TreeNode *left, TreeNode *right) {
       
        if ((left == NULL) != (right == NULL)) {
             return false;
        }
               
        if (left == NULL) {
             return true;
        } else {
            return (left->val == right->val) && check(left->left, right->right)
                    && check(left->right, right->left);
        }
    }
       
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot == NULL)
            return true;
           
        return check(pRoot->left, pRoot->right);
           
    }
   
};
