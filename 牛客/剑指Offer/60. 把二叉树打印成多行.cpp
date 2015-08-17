/*
题目描述

从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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
                 
                ans.push_back(temp);
                nodeQ = nextQ;
            }
             
            return ans;
        }
     
};
