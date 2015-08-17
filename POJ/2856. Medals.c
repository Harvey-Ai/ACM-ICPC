/*
Description


At the Olympic Games, countries are ranked according to the number of medals their athletes won. However, there is more than one possible way of ranking countries by their medals. In Europe, for example, countries are first ranked by the number of gold medals their athletes won. Ties are broken by looking at silver medals, and then at bronze medals. In Canada, however, because Canadian athletes do not win very many gold medals, countries are ranked by the overall number of medals won, giving the same weight to gold, silver, and bronze medals.

In general, a ranking scheme can be thought of as a vector of positive weights. This vector is multiplied with the vector of medals won by each country, and the scalar product of the two vectors defines the score of the respective country, which is then used to produce the ranking. In this general scheme, the European ranking technique corresponds to the weight vector (1020, 1010, 1), whereas the Canadian method corresponds to the vector (1, 1, 1).

In this problem, you will only need to consider weight vectors of the form (1/nj, 1/nk, 1/nl), where n is the total number of medals won by all athletes in the Olympic Games, and j, k, and l are integers.

Input

The input contains multiple test cases. Each test case starts with an integer c, the number of countries to follow. Each of the following c lines contains the name of a country and three integers g, s, and b – the number of gold, silver, and bronze medals won by the country. The last test case has c = 0 and must not be processed. It is guaranteed that each test case contains at most 20 different countries and that the total number of medals smaller than 100. Country names do not contain whitespace characters.

Output

Given a list of countries and the number of gold, silver, and bronze medals won by each country, print the line

Canada wins!
if there is a weight vector of the above form such that Canada ranks first according to the ranking scheme defined by that vector. Print the line
Canada cannot win.
if no such vector exists.
Sample Input

2
Canada 3 2 1
USA 1 2 3
2
USA 2 2 2
Canada 1 1 1
0
Sample Output

Canada wins!
Canada cannot win.
*.

#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	int i,j,k,l,n,sum;
	long medal[20][3],c[3],c_score,max_score,score;
	string s;
	bool flag;
	while(cin>>n,n)
	{
		i=0;flag=0;sum=0;
		while(i<n-1)
		{
			cin>>s;
			if(s=="Canada")
			{
				cin>>c[0]>>c[1]>>c[2];
				flag=1;
			}
			else
			{
				cin>>medal[i][0]>>medal[i][1]>>medal[i][2];
				i++;
			}
		}
		if(flag==0)
		{
			cin>>s;
			if(s=="Canada")
				cin>>c[0]>>c[1]>>c[2];
			else
			{
				cin>>medal[n-1][0]>>medal[n-1][1]>>medal[n-1][2];
				c[0]=0;c[1]=0;c[2]=0;
				cout<<"Canada cannot win."<<endl;
				continue;
			}
		}
		else
			flag=0;
		for(i=0;i<n-1;i++)
			sum+=(medal[i][0]+medal[i][1]+medal[i][2]);
		sum+=(c[0]+c[1]+c[2]);
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				for(k=0;k<3;k++)
				{
					c_score=c[0]*pow(sum,2-i)+c[1]*pow(sum,2-j)+c[2]*pow(sum,2-k);
					max_score=0;
					for(l=0;l<n-1;l++)
					{
						score=medal[l][0]*pow(sum,2-i)+medal[l][1]*pow(sum,2-j)+medal[l][2]*pow(sum,2-k);
						if(score>max_score)
							max_score=score;
					}
					if(c_score>=max_score)
					{
						flag=1;
						break;
					}
				}
				if(flag)
					break;
			}
			if(flag)
				break;
		}
		if(flag)
			cout<<"Canada wins!"<<endl;
		else
			cout<<"Canada cannot win."<<endl;
	}
	return 0;
}




