/*
题目描述

请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > ans;
        if (pRoot == NULL)
            return ans;
         
        int flag = 0;
        queue<TreeNode *> nodeQ;
        nodeQ.push(pRoot);
         
        while(!nodeQ.empty()) {
            queue<TreeNode *> nextQ;
            vector<int> temp;
             
            while(!nodeQ.empty()) {
                TreeNode *p = nodeQ.front();
                temp.push_back(p->val);
                nodeQ.pop();
                 
                if (p->left)
                    nextQ.push(p->left);
                if (p->right)
                    nextQ.push(p->right);
            }
             
            if (flag)
                reverse(temp.begin(), temp.end());
            flag = 1 - flag;
            ans.push_back(temp);
            nodeQ = nextQ;
        }
         
        return ans;
    }
     
};
