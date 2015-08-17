/*
题目描述

输入一个链表，从尾到头打印链表每个节点的值。
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> res;
         
        while(head) {
            res.push_back(head->val);
            head = head->next;
        }
         
        reverse(res.begin(), res.end());
        return res;
    }
};
