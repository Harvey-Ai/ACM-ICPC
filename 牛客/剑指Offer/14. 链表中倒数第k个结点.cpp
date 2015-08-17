/*
题目描述

输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (k <= 0 || pListHead == NULL)
            return NULL;
           
        unsigned int len = 0;
        for(ListNode* p = pListHead; p != NULL; p = p->next) {
            len++;
        }
        if (k > len)
            return NULL;
          
        ListNode *res = pListHead;
        for(unsigned int i = 0;i < len - k;i++) {
            res = res->next;
        }
        return res;
    }
};
