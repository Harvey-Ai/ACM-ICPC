/*
题目描述

输入两个链表，找出它们的第一个公共结点
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        int len1 = 0, len2 = 0;
         
        ListNode *p = pHead1;
        while(p) {
            len1++;
            p = p->next;
        }
        p = pHead2;
        while(p) {
            len2++;
            p = p->next;
        }
         
        if (len2 > len1)
            swap(pHead1, pHead2);
       
        while(len1 != len2) {
            len1--;
            pHead1 = pHead1->next;
        }
        while(pHead1 != pHead2) {
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
         
        return pHead1;
    }
};
