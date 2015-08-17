/*
题目描述

输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点）。
*/

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == NULL)
            return NULL;
          
        RandomListNode *p = pHead, *next;
        while(p) {
            RandomListNode *copyNode = new RandomListNode(p->label);
            copyNode->next = p->next;
            p->next = copyNode;
            p = copyNode->next;
        }
        RandomListNode *newHead = pHead->next;
         
        for(p = pHead;p != NULL;p = p->next->next) {
            if (p->random)
                p->next->random = p->random->next;
        }
         
        for(p = pHead, next = p->next;p != NULL;p = next, next = p->next) {
            if (p->next != NULL)
                p->next = p->next->next;
        }
          
          
        return newHead;
    }
};
