/*
题目描述

一个链表中包含环，请找出该链表的环的入口结点。
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == NULL || pHead->next == NULL)
            return NULL;
         
        ListNode *p1 = pHead->next, *p2 = pHead->next->next;
         
        while(p1 != p2) {
            if (p2 == NULL || p2->next == NULL)
                return NULL;
             
            p1 = p1->next;
            p2 = p2->next->next;
        }
          
        p2 = pHead;
        while(p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
          
        return p1;
    }
};
