/*
题目描述

在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
     
    ListNode* findNext(ListNode *head) {
        if (head == NULL)
            return NULL;
         
        ListNode *p = head->next;
        while(p && head->val == p->val) {
            p = p->next;
        }
        return p;
    }
     
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == NULL || pHead->next == NULL) {
            return pHead;
        }
         
        ListNode *p = pHead, *newHead = NULL, *pre = NULL;
        while(p) {
            ListNode *nextP = findNext(p);
            if (nextP != p->next) {
                if (pre)
                    pre->next = nextP;
            } else {
                pre = p;
                if (newHead == NULL) {
                    newHead = p;
                }
            }
             
            p = nextP;
        }
         
        return newHead;
    }
};
