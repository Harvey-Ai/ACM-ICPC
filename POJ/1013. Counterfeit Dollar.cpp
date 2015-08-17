/*
Description

Sally Jones has a dozen Voyageur silver dollars. However, only eleven of the coins are true silver dollars; one coin is counterfeit even though its color and size make it indistinguishable from the real silver dollars. The counterfeit coin has a different weight from the other coins but Sally does not know if it is heavier or lighter than the real coins. 
Happily, Sally has a friend who loans her a very accurate balance scale. The friend will permit Sally three weighings to find the counterfeit coin. For instance, if Sally weighs two coins against each other and the scales balance then she knows these two coins are true. Now if Sally weighs 
one of the true coins against a third coin and the scales do not balance then Sally knows the third coin is counterfeit and she can tell whether it is light or heavy depending on whether the balance on which it is placed goes up or down, respectively. 
By choosing her weighings carefully, Sally is able to ensure that she will find the counterfeit coin with exactly three weighings.
Input

The first line of input is an integer n (n > 0) specifying the number of cases to follow. Each case consists of three lines of input, one for each weighing. Sally has identified each of the coins with the letters A--L. Information on a weighing will be given by two strings of letters and then one of the words ``up'', ``down'', or ``even''. The first string of letters will represent the coins on the left balance; the second string, the coins on the right balance. (Sally will always place the same number of coins on the right balance as on the left balance.) The word in the third position will tell whether the right side of the balance goes up, down, or remains even.
Output

For each case, the output will identify the counterfeit coin by its letter and tell whether it is heavy or light. The solution will always be uniquely determined.
Sample Input

1 
ABCD EFGH even 
ABCI EFJK up 
ABIJ EFGH even 
Sample Output

K is the counterfeit coin and it is light.
*/


#include <stdio.h>
int main()
{
	char left[3][13],right[3][13],balance[3],str[6];
	int i,j,k,a[13];
	int lsum,rsum,n;
	scanf("%d",&n);
	getchar();
	for(i=0;i<12;i++)
		a[i]=1;
	while(n--)
	{
		for(i=0;i<3;i++)
		{
			scanf("%s",left[i]);
			getchar();
			scanf("%s",right[i]);
			getchar();
			scanf("%s",str);
			if(str[0]=='e') balance[i]=0;
			if(str[0]=='u') balance[i]=-1;
			if(str[0]=='d') balance[i]=1;
		}
		for(i=0;i<12;i++)
		{
			a[i]=0;
			for(j=0;j<3;j++)
			{
				lsum=rsum=0;
				for(k=0;left[j][k]!='\0';k++) lsum+=a[left[j][k]-'A'];
				for(k=0;right[j][k]!='\0';k++) rsum+=a[right[j][k]-'A'];
				if(rsum>lsum&&balance[j]<=0) break;
				if(rsum==lsum&&balance[j]!=0) break;
				if(rsum<lsum&&balance[j]>=0) break;
			}
			if(j>=3)
				break;
			a[i]=2;
			for(j=0;j<3;j++)
			{
				lsum=rsum=0;
				for(k=0;left[j][k]!='\0';k++) lsum+=a[left[j][k]-'A'];
				for(k=0;right[j][k]!='\0';k++) rsum+=a[right[j][k]-'A'];
				if(rsum>lsum&&balance[j]<=0) break;
				if(rsum==lsum&&balance[j]!=0) break;
				if(rsum<lsum&&balance[j]>=0) break;
			}
			if(j>=3)
				break;
			a[i]=1;
		}
		if(a[i])
			printf("%c is the counterfeit coin and it is heavy.\n",i+'A');
		else
			printf("%c is the counterfeit coin and it is light.\n",i+'A');
		a[i]=1;
	}
	return 0;
}
