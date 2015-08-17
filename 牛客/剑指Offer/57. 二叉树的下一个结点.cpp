/*
题目描述

给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/

using namespace std;
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
         
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == NULL)
            return NULL;
         
        if (pNode->right != NULL) {
            TreeLinkNode *p = pNode->right;
            while(p->left != NULL) {
                p = p->left;
            }
             
            return p;
        } else {
            TreeLinkNode *p = pNode;
            while(p->next != NULL && p != p->next->left) {
                p = p->next;  
            }
            return p->next;
        }
    }
};

