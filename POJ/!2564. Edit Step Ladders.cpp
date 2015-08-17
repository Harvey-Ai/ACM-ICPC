/*
Description

An edit step is a transformation from one word x to another word y such that x and y are words in the dictionary, and x can be transformed to y by adding, deleting, or changing one letter. So the transformation from dig to dog or from dog to do are both edit steps. An edit step ladder is a lexicographically ordered sequence of words w1, w2, ... wn such that the transformation from wi to wi+1 is an edit step for all i from 1 to n-1.
Input

For a given dictionary, you are to compute the length of the longest edit step ladder. The input to your program consists of the dictionary - a set of lower case words in lexicographic order - one per line. No word exceeds 16 letters and there are no more than 25000 words in the dictionary.
Output

The output consists of a single integer, the number of words in the longest edit step ladder. 
Sample Input

cat
dig
dog
fig
fin
fine
fog
log
wine
Sample Output

5
*/


#include <stdio.h>
#include <string>
char str[25005][20];
int arr[25005];
int main()
{
	bool check(char str1[20],char str2[20]);
	char c;
	int i,j,n,max;
	scanf("%c",&c);
	
		i=0;
		while(c!='\n')
		{
			str[0][i]=c;
			i++;
			c=getchar();
		}
		str[0][i]='\0';
		i=1;
		while(scanf("%s",str[i++])!=EOF){}
		getchar();
		n=i;
		for(i=0;i<n;i++)
		{
			arr[i]=1;
			for(j=i-1;j>=0;j--)
			{
				if(arr[j]>=arr[i])
					if(check(str[i],str[j]))
						arr[i]=arr[j]+1;
			}
		}
		max=0;
		for(i=0;i<n;i++)
			if(max<arr[i])
				max=arr[i];
		printf("%d\n",max);
	return 0;
}

bool check(char str1[20],char str2[20])
{
	bool flag;
	int i,j,len1,len2,cnt;
	len1=strlen(str1);
	len2=strlen(str2);
	if(len1-len2==1)
	{
		for(i=0;i<len1;i++)
		{
			flag=1;cnt=0;
			for(j=0;j<i;j++)
			{
				if(str1[j]!=str2[j])
				{
					cnt++;
					flag=0;
					if(cnt>1)
						break;
				}
			}
			if(cnt>1)
				break;
			for(j=i;j<len2;j++)
			{
				if(str1[j+1]!=str2[j])
				{
					flag=0;
					break;
				}
			}
			if(flag)
				break;
		}
	}
	else
	{	
		if(len2-len1==1)
		{
			for(i=0;i<len2;i++)
			{
				flag=1;cnt=0;
				for(j=0;j<i;j++)
				{
					if(str1[j]!=str2[j])
					{
						cnt++;
						flag=0;
						if(cnt>1)
							break;
					}
				}
				if(cnt>1)
					break;
				for(j=i;j<len1;j++)
				{
					if(str1[j]!=str2[j+1])
					{
						flag=0;
						break;
					}
				}
				if(flag)
					break;
			}
		}
		else
		{
			if(len1==len2)
			{
				flag=1;cnt=0;
				for(i=0;i<len1;i++)
					if(str1[i]!=str2[i])
					{
						cnt++;
						if(cnt>1)
						{
							flag=0;
							break;
						}
					}
			}
			else
				flag=0;
		}
	}
	return flag;
}
