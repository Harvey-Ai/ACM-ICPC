/*
Description

Shiming (alpc02) is a boy likes to play PopKart very much. He is a good rider in this game. And one day he thought that he became a team leader of a team of N Kart riders.

Today, after the game begins, the riders of his team are now at different places at the racetrack, for that some of the riders got some short cut.

However, we know actually how long has each rider left to run along, and they will ride actually one meter per one time unit (maybe 10ms).

Luckily, Shiming now gets M accelerators, the accelerator can help one rider to ride k meters per one time unit. And all the accelerators are as the same. But one rider can't use more than one accelerator at one time unit.

Shiming is the team leader, and he wants all the team members to finish in the minimal time not just the fastest one to finish the race. He will distribute all the accelerators to the riders.

Note: Here some rules are not as the same as the game we played. At a time unit, Shiming distributes the accelerators to riders for one rider one accelerator, and at the next time unit, all the accelerator can be reused, and Shiming can re-distributes all the accelerators to riders also for one rider one accelerator and the distribution is no relationship with the last time unit.

So you will program to help Shiming to get the actually minimal time the team will use to finish the race.

Input

The input file has T (1<T<20) test cases, and the first line of the file will show the T.

Each of test cases, will be the N (1<= N <= 100000) rider, and N numbers Ai (1<= Ai <= 10^8) show how long will the rider have to finish the race. And the M and the K (1<= K*M <=10^8) for the accelerators.

Output

For each of test cases print a single integer on a single line, the minimal possible number of time units required to finish the race all team.
Sample Input

2
3
2 3 9
1 5
3
2 3 6
1 5
Sample Output

3
2
*/

#include <stdio.h>
int main()
{
	long long cnt,mid;
	int arr[100005];
	int i,k,ncase,n,head,tail,max,a,m;
	scanf("%d",&ncase);
	while(ncase--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		scanf("%d%d",&m,&k);
		head=1;max=0;
		for(i=0;i<n;i++)
			if(max<arr[i])
				max=arr[i];
		tail=max;
		if(k==1)
		{
			printf("%d\n",tail);
			continue;
		}
		while(head<=tail)
		{
			mid=(head+tail)/2;
			cnt=0;
			for(i=0;i<n;i++)
				if(arr[i]>mid)
				{
					a=(arr[i]-mid+k-2)/(k-1);
					cnt+=a;
					if(a>mid)
					{
						cnt=mid*m+2;
						break;
					}
				}
			if(cnt>m*mid)
				head=mid+1;
			else 
				tail=mid-1;
		}
		printf("%d\n",head);
	}
	return 0;
}
