/*
Description

Some of the secret doors contain a very interesting word puzzle. The team of archaeologists has to solve it to open that doors. Because there is no other way to open the doors, the puzzle is very important for us. 

There is a large number of magnetic plates on every door. Every plate has one word written on it. The plates must be arranged into a sequence in such a way that every word begins with the same letter as the previous word ends. For example, the word ``acm'' can be followed by the word ``motorola''. Your task is to write a computer program that will read the list of words and determine whether it is possible to arrange all of the plates in a sequence (according to the given rule) and consequently to open the door. 
Input

The input consists of T test cases. The number of them (T) is given on the first line of the input file. Each test case begins with a line containing a single integer number Nthat indicates the number of plates (1 <= N <= 100000). Then exactly Nlines follow, each containing a single word. Each word contains at least two and at most 1000 lowercase characters, that means only letters 'a' through 'z' will appear in the word. The same word may appear several times in the list.
Output

Your program has to determine whether it is possible to arrange all the plates in a sequence such that the first letter of each word is equal to the last letter of the previous word. All the plates from the list must be used, each exactly once. The words mentioned several times must be used that number of times. 
If there exists such an ordering of plates, your program should print the sentence "Ordering is possible.". Otherwise, output the sentence "The door cannot be opened.". 
Sample Input

3
2
acm
ibm
3
acm
malform
mouse
2
ok
ok
Sample Output

The door cannot be opened.
Ordering is possible.
The door cannot be opened.

*/


#include <stdio.h>
#include <string.h>
int deg[26],vis[26],p[26],graph[26][26];
void dfs(int u)
{
	int v;
	vis[u]=1;
	for(v=0;v<26;++v)
		if(!vis[v]&&(graph[u][v]||graph[v][u]))
			dfs(v);
}
int main()
{
	char str[1009];
	int deg[26];
	int i,s,t,ss,tt,u,N,n;
	bool flag;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&n);
		memset(deg,0,sizeof(deg));
		memset(p,0,sizeof(p));
		memset(graph,0,sizeof(graph));
		for(i=0;i<n;i++)
		{
			scanf("%s",str);
			u=s=str[0]-'a';
			t=str[strlen(str)-1]-'a';
			deg[s]--;
			deg[t]++;
			p[s]=p[t]=1;
			graph[s][t]=1;
		}
		flag=1;
		for(i=0;i<26;i++)
			if(deg[i]!=0)
			{
				flag=0;
				break;
			}
		if(i<26)
		{
			ss=tt=0;
			while(i<26)
			{
				if(deg[i]==1) ss++;
				else if(deg[i]==-1) tt++;
				else if(deg[i]!=0) {ss=tt=2;break;}
				i++;
			}
			if(ss==1&&tt==1)
				flag=1;
		}
		if(flag)
		{
			memset(vis,0,sizeof(vis));
			dfs(u);
			for(i=0;i<26;i++)
				if(p[i]==1&&vis[i]==0)
				{
					flag=0;
					break;
				}
		}
		if(flag) printf("Ordering is possible.\n");
		else printf("The door cannot be opened.\n");
	}
	return 0;
}
