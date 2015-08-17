/*
题目描述

输入一个链表，反转链表后，输出链表的所有元素。
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
    ListNode* ReverseList(ListNode* pHead) {
 
        ListNode* pre = NULL, *p = pHead;
        while(p) {
            ListNode* next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
         
        return pre;
    }
};
