/*
题目描述：
大家都知道数据结构里面有一个结构叫做循环队列。顾名思义，这是一个队列，并且是循环的。但是现在，淘气的囧哥给这个循环队列加上了一些规矩，其中有5条指令:
(1) Push K, 让元素K进队列。
(2) Pop，对头元素出队列。
(3) Query K，查找队列中第K个元素，注意K的合法性。
(4) Isempty，判断队列是否为空。
(5) Isfull，判断队列是否已满。
现在有N行指令，并且告诉你队列大小是M。
输入：
第一行包含两个整数N和M。1<=N,M<=100000。
接下来有N行，表示指令，指令格式见题目描述。
其中元素均在int范围。
输出：
对于指令（1），若队列已满，输出failed，否则不做输出。
对于指令（2），若队列已空，输出failed，否则不做输出。
对于指令（3），输出队列中第K个元素，若不存在，输出failed。
对于指令（4）和（5），则用yes或者no回答。
详情见样例。
样例输入：
12 2
Push 1
Push 2
Push 3
Query 2
Query 3
Isempty
Isfull
Pop
Pop
Pop
Isempty
Isfull
样例输出：
failed
2
failed
no
yes
failed
yes
no
*/


#include <stdio.h>
#include <string.h>

int main()
{
	int n, m;
	int front, rear, cnt;
	int k;
	char str[100];
	int arr[100005];

	while(scanf("%d %d", &n, &m) != EOF)
	{
		front = rear = 0;
		cnt = 0;
		while(n--)
		{
			scanf("%s", str);
		//	cout << "fda" << str << endl;
			if (strcmp(str, "Push") == 0)
			{
				scanf("%d", &k);
				if (cnt == m)
					printf("failed\n");
				else
				{
					arr[rear] = k;
					rear = (rear + 1) % m;
					cnt++;
				}
			}
			else if (strcmp(str, "Pop") == 0)
			{
				if (cnt == 0)
					printf("failed\n");
				else
				{
					front = (front + 1) % m;
					cnt--;
				}
			}
			else if (strcmp(str, "Query") == 0)
			{
				scanf("%d", &k);
				if (cnt < k || k <= 0)
					printf("failed\n");
				else
					printf("%d\n", arr[(front + k - 1) % m]);
			}
			else if (strcmp(str, "Isempty") == 0)
			{
				if (cnt == 0)
					printf("yes\n");
				else
					printf("no\n");
			}
			else if (strcmp(str, "Isfull") == 0)
			{
				if (cnt == m)
					printf("yes\n");
				else
					printf("no\n");
			}
		}
	}
	return 0;
}
