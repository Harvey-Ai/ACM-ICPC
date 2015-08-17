/*
题目描述

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* guard = new ListNode(-1000000);
        ListNode* p = guard;
         
        while(pHead1 || pHead2) {
            if ((pHead1 && pHead2 && pHead1->val < pHead2->val) || (pHead2 == NULL)) {
                p->next = new ListNode(pHead1->val);
                p = p->next;
                pHead1 = pHead1->next;
            } else {
                p->next = new ListNode(pHead2->val);
                p = p->next;
                pHead2 = pHead2->next;
            }
        }
         
        return guard->next;
    }
};
