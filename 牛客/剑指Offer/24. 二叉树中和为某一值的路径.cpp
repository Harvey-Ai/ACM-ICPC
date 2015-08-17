/*
题目描述

输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
*/

class Solution {
public:
    void helper(TreeNode *node, int en, int sum, vector<vector<int> > &ans, vector<int> temp) {
        if (sum == en && node->left == NULL && node->right == NULL)
            ans.push_back(temp);
          
        if (node->left) {
            temp.push_back(node->left->val);
            helper(node->left, en, node->left->val + sum, ans, temp);
            temp.pop_back();
        }
          
        if (node->right) {
            temp.push_back(node->right->val);
            helper(node->right, en, node->right->val + sum, ans, temp);
            temp.pop_back();
        }
    }
      
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > ans;
        vector<int> temp;
          
        if (root) {
            temp.push_back(root->val);
            helper(root, expectNumber, root->val, ans, temp);
        }
          
        return ans;
    }
};
