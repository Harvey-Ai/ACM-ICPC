/*
题目描述

给定一颗二叉搜索树，请找出其中的第k大的结点。例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    int count(TreeNode *root) {
         
        if (root == NULL)
            return 0;
        else
            return count(root->left) + count(root->right) + 1;
    }
         
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        if (pRoot == NULL)
            return NULL;
         
        int leftCount = count(pRoot->left);
        if (leftCount + 1 == k)
            return pRoot;
        else if (leftCount >= k)
            return KthNode(pRoot->left, k);
        else
            return KthNode(pRoot->right, k - leftCount - 1);
    }
 
     
};
