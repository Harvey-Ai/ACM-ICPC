/*
题目描述：
输入一个链表，输出该链表中倒数第k个结点。
(hint: 请务必使用链表。)
输入：
输入可能包含多个测试样例，输入以EOF结束。
对于每个测试案例，输入的第一行为两个整数n和k(0<=n<=1000, 0<=k<=1000)：n代表将要输入的链表元素的个数,k代表要查询倒数第几个的元素。
输入的第二行包括n个数t(1<=t<=1000000)：代表链表中的元素。
输出：
对应每个测试案例，
若有结果，输出相应的查找结果。否则，输出NULL。
样例输入：
5 2
1 2 3 4 5
1 0
5
样例输出：
4
NULL
*/

#include <iostream>
#include <cstdio>
using namespace std;
 
struct ListNode{
    int val;
    struct ListNode * next;
};
 
 
 ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (k <= 0 || pListHead == NULL)
            return NULL;
          
        unsigned int len = 0;
        ListNode* p = pListHead;
        while(p != NULL) {
            p = p->next;
            len++;
        }
 
         
        p = pListHead;
        for(unsigned int i = 0;i < len - k;i++) {
            if (p == NULL)
               break;
            p = p->next;
        }
        return p;
    }
 
int main()
{
   int n, k;
   while(scanf("%d %d", &n, &k) != EOF && n>=0 && n<=1000 && k>=0 && k<=1000) {
        ListNode *head = new ListNode();
        ListNode *p = head;
        for(int i = 0; i < n;i++)
         {
            int a;
            scanf("%d", &a);
            p->next = new ListNode();
            p->next->val = a;
            p = p->next;
         }
         p = FindKthToTail(head->next, k);
         if (p)
             cout << p->val << endl;
         else
             cout << "NULL" << endl;
}
  return 0;
}
