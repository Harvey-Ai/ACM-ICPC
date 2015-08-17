/*
Description

The new founded Balkan Investment Group Bank (BIG-Bank) opened a new office in Bucharest, equipped with a modern computing environment provided by IBM Romania, and using modern information technologies. As usual, each client of the bank is identified by a positive integer K and, upon arriving to the bank for some services, he or she receives a positive integer priority P. One of the inventions of the young managers of the bank shocked the software engineer of the serving system. They proposed to break the tradition by sometimes calling the serving desk with the lowest priority instead of that with the highest priority. Thus, the system will receive the following types of request:

0	The system needs to stop serving
1 K P	Add client K to the waiting list with priority P
2	Serve the client with the highest priority and drop him or her from the waiting list
3	Serve the client with the lowest priority and drop him or her from the waiting list
Your task is to help the software engineer of the bank by writing a program to implement the requested serving policy.

Input

Each line of the input contains one of the possible requests; only the last line contains the stop-request (code 0). You may assume that when there is a request to include a new client in the list (code 1), there is no other request in the list of the same client or with the same priority. An identifier K is always less than 106, and a priority P is less than 107. The client may arrive for being served multiple times, and each time may obtain a different priority.

Output

For each request with code 2 or 3, the program has to print, in a separate line of the standard output, the identifier of the served client. If the request arrives when the waiting list is empty, then the program prints zero (0) to the output.

Sample Input

2
1 20 14
1 30 3
2
1 10 99
3
2
2
0
Sample Output

0
20
30
10
0
*/


#include <stdio.h>
int n1,n2;
int heap1[1000001],heap2[1000001],f[10000005];
void resort1(int root)
{
	int m,j,temp;
	j=root;
	while(j<=n1/2)
	{
		if((2*j<n1)&&(heap1[2*j]>heap1[2*j+1]))
			m=2*j+1;
		else
			m=2*j;
		if(heap1[j]>heap1[m])
		{
			temp=heap1[j];
			heap1[j]=heap1[m];
			heap1[m]=temp;
			j=m;
		}
		else
			j=n1;
	}
}
void resort2(int root)
{
	int m,j,temp;
	j=root;
	while(j<=n2/2)
	{
		if((2*j<n2)&&(heap2[2*j]<heap2[2*j+1]))
			m=2*j+1;
		else
			m=2*j;
		if(heap2[j]<heap2[m])
		{
			temp=heap2[j];
			heap2[j]=heap2[m];
			heap2[m]=temp;
			j=m;
		}
		else
			j=n2;
	}
}
void add()
{
	int j,m,k,p,temp;
	scanf("%d%d",&k,&p);
	f[p]=k;
	n1++;n2++;
	heap1[n1]=p;heap2[n2]=p;
	j=n2;
	while(j>=2)
	{
		m=j/2;
		if(heap2[j]>heap2[m])
		{
			temp=heap2[j];
			heap2[j]=heap2[m];
			heap2[m]=temp;
			j=m;
		}
		else
			j=-1;
	}
	j=n1;
	while(j>=2)
	{
		m=j/2;
		if(heap1[j]<heap1[m])
		{
			temp=heap1[j];
			heap1[j]=heap1[m];
			heap1[m]=temp;
			j=m;
		}
		else
			j=-1;
	}
}

int main()
{
	int c;
	n1=n2=0;
	while(scanf("%d",&c),c)
	{
		if(c==1)
			add();
		else
		{
			if(c==2)
			{
				while(f[heap2[1]]==0&&n2)
				{
					heap2[1]=heap2[n2];
					n2--;
					resort2(1);
					
				}
				if(n2)
				{
					printf("%d\n",f[heap2[1]]);
					f[heap2[1]]=0;
					heap2[1]=heap2[n2];
					n2--;
					resort2(1);
				}
				else
					printf("0\n");
			}
			else
			{
				while(f[heap1[1]]==0&&n1)
				{
					heap1[1]=heap1[n1];
					n1--;
					resort1(1);
				}
				if(n1)
				{
					printf("%d\n",f[heap1[1]]);
					f[heap1[1]]=0;
					heap1[1]=heap1[n1];
					n1--;
					resort1(1);
				}
				else
					printf("0\n");
			}
		}
	}
	return 0;
}
