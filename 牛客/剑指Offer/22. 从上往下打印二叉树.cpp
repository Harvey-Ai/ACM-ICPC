/*
题目描述

从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> ans;
        if (root == NULL)   return ans;
         
        queue<TreeNode *> treeQ;
        treeQ.push(root);
         
        while(!treeQ.empty()) {
            TreeNode *node = treeQ.front();
            treeQ.pop();
            ans.push_back(node->val);
             
            if (node->left)
                treeQ.push(node->left);
            if (node->right)
                treeQ.push(node->right);
        }
         
        return ans;
    }
};
