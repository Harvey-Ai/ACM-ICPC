/*
题目描述

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
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
    void walk(TreeNode* root, TreeNode* &pre, TreeNode* &next) {
        TreeNode *leftPre = NULL, *leftNext = NULL;
         
        if (root->left) {
            walk(root->left, leftPre, leftNext);
            root->left = leftNext;
            if (leftNext)
                leftNext->right = root;
        }
             
        TreeNode *rightPre = NULL, *rightNext = NULL;
        if (root->right) {
            walk(root->right, rightPre, rightNext);
            root->right = rightPre;
            if (rightPre)
                rightPre->left = root;
        }
          
        pre = (leftPre == NULL ? root : leftPre);
        next = (rightNext == NULL ? root : rightNext);
    }
      
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == NULL)
            return NULL;
          
        TreeNode *left, *right;
        walk(pRootOfTree, left, right);
        return left;
    }
};
