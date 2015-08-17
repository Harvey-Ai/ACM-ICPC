/*
Description

A palindrome is a string of symbols that is equal to itself when reversed. Given an input string, not necessarily a palindrome, compute the number of swaps necessary to transform the string into a palindrome. By swap we mean reversing the order of two adjacent symbols. For example, the string "mamad" may be transformed into the palindrome "madam" with 3 swaps: 
swap "ad" to yield "mamda" 
swap "md" to yield "madma" 
swap "ma" to yield "madam" 
Input

The first line of input gives n, the number of test cases. For each test case, one line of input follows, containing a string of up to 8000 lowercase letters.
Output

Output consists of one line per test case. This line will contain the number of swaps, or "Impossible" if it is not possible to transform the input to a palindrome. 
Sample Input

3
mamad
asflkj
aabb
Sample Output

3
Impossible
2
*/


#include <stdio.h>
#include <string.h>
char str[8005];
int rel,swp,len;
void dfs(int p)
{
	int j,k,temp;
	if(swp>=rel&&rel!=-1)
		return;
	if(p>=len/2)
	{
		if(swp<rel||rel==-1)
			rel=swp;
		return;
	}
	if(str[p]!=str[len-p-1])
	{
		for(j=len-p-2;j>p;j--)
			if(str[p]==str[j])
			{
				temp=str[j];
				for(k=j+1;k<=len-p-1;k++)
					str[k-1]=str[k];
				str[len-p-1]=temp;
				swp+=len-p-1-j;
				dfs(p+1);
				break;
			}
		if(j>p)
		{
			temp=str[len-p-1];
			for(k=len-p-1;k>j;k--)
				str[k]=str[k-1];
			str[j]=temp;
		}
		for(j=p+1;j<len-p-1;j++)
			if(str[len-p-1]==str[j])
			{
				temp=str[j];
				for(k=j;k>p;k--)
					str[k]=str[k-1];
				str[p]=temp;
				swp+=j-p;
				dfs(p+1);
				break;
			}
		if(j<len-p-1)
		{
			temp=str[p];
			for(k=p;k<j;k++)
				str[k]=str[k+1];
			str[j]=temp;
		}
	}
	else
		dfs(p+1);
}
int main()
{
	int count[27];
	int flag,i,n;
	scanf("%d",&n);
	while(n--)
	{
		memset(count,0,sizeof(count));
		scanf("%s",str);
		for(i=0;str[i]!='\0';i++)
			count[str[i]-'a']++;
		len=i;
		flag=0;
		for(i=0;i<26;i++)
			if(count[i]%2)
				flag++;
		rel=-1;swp=0;
		if((flag==0&&len%2==0)||(flag==1&&len%2))
			dfs(0);
		if(rel!=-1)
			printf("%d\n",rel);
		else
			printf("Impossible\n");
	}
	return 0;
}
