/*
Description

Fatigued by the endless toils of farming, Farmer John has decided to try his hand in the MP3 player market with the new iCow. It is an MP3 player that stores N songs (1 ≤ N ≤ 1,000) indexed 1 through N that plays songs in a "shuffled" order, as determined by Farmer John's own algorithm:

Each song i has an initial rating Ri (1 ≤ Ri ≤ 10,000).
The next song to be played is always the one with the highest rating (or, if two or more are tied, the highest rated song with the lowest index is chosen).
After being played, a song's rating is set to zero, and its rating points are distributed evenly among the other N-1 songs.
If the rating points cannot be distributed evenly (i.e., they are not divisible by N-1), then the extra points are parceled out one at a time to the first songs on the list (i.e., R1 , R2 , etc. -- but not the played song) until no more extra points remain.
This process is repeated with the new ratings after the next song is played.
Determine the first T songs (1 ≤ T ≤ 1000) that are played by the iCow.

Input

* Line 1: Two space-separated integers: N and T
* Lines 2..N+1: Line i+1 contains a single integer: Ri

Output

* Lines 1..T: Line i contains a single integer that is the i-th song that the iCow plays.

Sample Input

3 4
10
8
11
Sample Output

3
1
2
3
*/


#include <stdio.h>
int arr[1001];
int main()
{
	int i,j,n,t,max,max_id,id,dis,temp;
	while(scanf("%d%d",&n,&t)!=EOF)
	{
		max=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			if(arr[i]>max)
			{
				max=arr[i];
				id=i;
			}
		}
		for(i=0;i<t;i++)
		{
			printf("%d\n",id+1);
			dis=arr[id]/(n-1);
			max=0;
			for(j=0;j<n;j++)
				if(j!=id)
				{
					arr[j]+=dis;
					if(arr[j]>max)
					{
						max=arr[j];
						max_id=j;
					}
				}
			if(arr[id]%(n-1)!=0)
			{
				temp=arr[id]%(n-1);
				for(j=0;j<temp;j++)
				{
					if(j==id)
						temp++;
					else
					{
						arr[j]++;
						if(arr[j]>max||(arr[j]==max&&max_id>j))
						{
							max=arr[j];
							max_id=j;
						}
					}
				}
			}
			arr[id]=0;
			id=max_id;
		}
	}
	return 0;
}
