/*
题目描述

输入两颗二叉树A，B，判断B是不是A的子结构。
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
    bool check(TreeNode* root1, TreeNode *root2) {
        if (root1 == NULL)
            return root2 == NULL;
        if (root2 == NULL)
            return true;
         
        return root1->val == root2->val && check(root1->left, root2->left) &&
                check(root1->right, root2->right);
    }
     
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot2 == NULL)
            return false;
         
        if (check(pRoot1, pRoot2))  return true;
        if (pRoot1 && HasSubtree(pRoot1->left, pRoot2)) return true;
        if (pRoot1 && HasSubtree(pRoot1->right, pRoot2)) return true;
         
        return false;
    }
};
