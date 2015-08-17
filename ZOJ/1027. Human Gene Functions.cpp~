/*
It is well known that a human gene can be considered as a sequence, consisting of four nucleotides, which are simply denoted by four letters, A, C, G, and T. Biologists have been interested in identifying human genes and determining their functions, because these can be used to diagnose human diseases and to design new drugs for them. 

A human gene can be identified through a series of time-consuming biological experiments, often with the help of computer programs. Once a sequence of a gene is obtained, the next job is to determine its function. One of the methods for biologists to use in determining the function of a new gene sequence that they have just identified is to search a database with the new gene as a query. The database to be searched stores many gene sequences and their functions �C many researchers have been submitting their genes and functions to the database and the database is freely accessible through the Internet. 

A database search will return a list of gene sequences from the database that are similar to the query gene. Biologists assume that sequence similarity often implies functional similarity. So, the function of the new gene might be one of the functions that the genes from the list have. To exactly determine which one is the right one another series of biological experiments will be needed. 

Your job is to make a program that compares two genes and determines their similarity as explained below. Your program may be used as a part of the database search if you can provide an efficient one. 

Given two genes AGTGATG and GTTAG, how similar are they? One of the methods to measure the similarity of two genes is called alignment. In an alignment, spaces are inserted, if necessary, in appropriate positions of the genes to make them equally long and score the resulting genes according to a scoring matrix. 

For example, one space is inserted into AGTGATG to result in AGTGAT-G, and three spaces are inserted into GTTAG to result in �CGT--TAG. A space is denoted by a minus sign (-). The two genes are now of equal length. These two strings are aligned: 

AGTGAT-G 
-GT--TAG 

In this alignment, there are four matches, namely, G in the second position, T in the third, T in the sixth, and G in the eighth. Each pair of aligned characters is assigned a score according to the following scoring matrix. 


* denotes that a space-space match is not allowed. The score of the alignment above is (-3)+5+5+(-2)+(-3)+5+(-3)+5=9. 

Of course, many other alignments are possible. One is shown below (a different number of spaces are inserted into different positions): 

AGTGATG 
-GTTA-G 

This alignment gives a score of (-3)+5+5+(-2)+5+(-1) +5=14. So, this one is better than the previous one. As a matter of fact, this one is optimal since no other alignment can have a higher score. So, it is said that the similarity of the two genes is 14. 

Input 

The input consists of T test cases. The number of test cases ) (T is given in the first line of the input. Each test case consists of two lines: each line contains an integer, the length of a gene, followed by a gene sequence. The length of each gene sequence is at least one and does not exceed 100. 


Output 

The output should print the similarity of each test case, one per line. 


Sample Input 

2 
7 AGTGATG 
5 GTTAG 
7 AGCTATT 
9 AGCTTTAAA


Output for the Sample Input

14 
21
*/

#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;
int main()
{
	char str1[110],str2[110];
	int graph[110][110];
	int i,j,N,l1,l2,temp;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&l1);
		getchar();
		for(i=1;i<=l1;i++)
			str1[i]=getchar();

		scanf("%d",&l2);
		getchar();
		for(i=1;i<=l2;i++)
			str2[i]=getchar();
		graph[0][0]=0;
		for(i=1;i<=l1;i++)
		{
			switch(str1[i])
			{
				case 'A':{graph[i][0]=graph[i-1][0]-3;break;}
				case 'C':{graph[i][0]=graph[i-1][0]-4;break;}
				case 'G':{graph[i][0]=graph[i-1][0]-2;break;}
				case 'T':{graph[i][0]=graph[i-1][0]-1;break;}
				default:break;
			}
		}
		for(j=1;j<=l2;j++)
		{
			switch(str2[j])
			{
				case 'A':{graph[0][j]=graph[0][j-1]-3;break;}
				case 'C':{graph[0][j]=graph[0][j-1]-4;break;}
				case 'G':{graph[0][j]=graph[0][j-1]-2;break;}
				case 'T':{graph[0][j]=graph[0][j-1]-1;break;}
				default:break;
			}
		}
		for(i=1;i<=l1;i++)
			for(j=1;j<=l2;j++)
			{
				temp=abs(str1[i]-str2[j]);
				switch(temp)
				{
				case 0:{graph[i][j]=graph[i-1][j-1]+5;break;}
				case 2:{graph[i][j]=graph[i-1][j-1]-1;break;}
				case 4:{graph[i][j]=graph[i-1][j-1]-3;break;}
				case 6:{graph[i][j]=graph[i-1][j-1]-2;break;}
				case 13:{graph[i][j]=graph[i-1][j-1]-2;break;}
				case 17:{graph[i][j]=graph[i-1][j-1]-2;break;}
				case 19:{graph[i][j]=graph[i-1][j-1]-1;break;}
				case 20:{graph[i][j]=graph[i-1][j-1]-3;break;}
				case 22:{graph[i][j]=graph[i-1][j-1]-4;break;}
				case 26:{graph[i][j]=graph[i-1][j-1]-2;break;}
				case 39:{graph[i][j]=graph[i-1][j-1]-1;break;}
				default:break;
				}
				switch(str1[i])
				{
				case 'A':{temp=graph[i-1][j]-3;break;}
				case 'C':{temp=graph[i-1][j]-4;break;}
				case 'G':{temp=graph[i-1][j]-2;break;}
				case 'T':{temp=graph[i-1][j]-1;break;}
				default:break;
				}
				if(temp>graph[i][j])
					graph[i][j]=temp;
				switch(str2[j])
				{
				case 'A':{temp=graph[i][j-1]-3;break;}
				case 'C':{temp=graph[i][j-1]-4;break;}
				case 'G':{temp=graph[i][j-1]-2;break;}
				case 'T':{temp=graph[i][j-1]-1;break;}
				default:break;
				}
				if(temp>graph[i][j])
					graph[i][j]=temp;
			}
		printf("%d\n",graph[l1][l2]);
	}
	return 0;
}




/*



5 
7 AGCTATT 
9 AGCTTTAAA 
63 AGCTTTAAAAGCTTTAAAAGCTTTAAAAGCTTTAAAAGCTTTAAAAGCTTTAAAAGCTTTAAA 
49 AGCTATTAGCTATTAGCTATTAGCTATTAGCTATTAGCTATTAGCTATT 
40 AAAAAAAAAATTTTTTTTTTAAAAAAAAAAAAAAAAAAAA 
60 TTTTTTTTAAAAAAAAAAAAAAAAAAAAAATTTTTTTTTTAAAAAAAAAAAAAAAAAAAA 
100 CCCCCGGGGGAAAAATTTTTGTGTGTGTGTGTGTGCGCGCGCGACACACACATATATAAAAAAAAAATTTTTTTTTTACGTACGTACGTACGTACGTACA 
100 AAAAAAAAAATTTTTTTTTTAAAAAAAAAAAAAAAAAAAAGGGGGGGGGGAAAGGTCAAAAAAAAAAAAATTTTTTTTTTTTTTCCCCCCCCCCCCAAAA 
50 AAAAAAAAAAAAAAAAAAAAAAAAATTTTTGGGGGGGGGGGGGGGAAAAA 
40 TTTTTTTTTTAAAAAGGGGGGGTTTTTTTTTTTTTTTTTT
5
7 AGCTATT
9 AGCTTTAAA
21
63 AGCTTTAAAAGCTTTAAAAGCTTTAAAAGCTTTAAAAGCTTTAAAAGCTTTAAAAGCTTTAAA
49 AGCTATTAGCTATTAGCTATTAGCTATTAGCTATTAGCTATTAGCTATT
147
40 AAAAAAAAAATTTTTTTTTTAAAAAAAAAAAAAAAAAAAA
60 TTTTTTTTAAAAAAAAAAAAAAAAAAAAAATTTTTTTTTTAAAAAAAAAAAAAAAAAAAA
197
100 CCCCCGGGGGAAAAATTTTTGTGTGTGTGTGTGTGCGCGCGCGACACACACATATATAAAAAAAAAATTTTTTTTT
TACGTACGTACGTACGTACGTACA
100 AAAAAAAAAATTTTTTTTTTAAAAAAAAAAAAAAAAAAAAGGGGGGGGGGAAAGGTCAAAAAAAAAAAAATTTTTT
TTTTTTTTCCCCCCCCCCCCAAAA
154
50 AAAAAAAAAAAAAAAAAAAAAAAAATTTTTGGGGGGGGGGGGGGGAAAAA
40 TTTTTTTTTTAAAAAGGGGGGGTTTTTTTTTTTTTTTTTT

#include <stdio.h> 
#include <stdlib.h> 

int s[5][5] = { 
   {5, -1, -2, -1, -3}, 
   {-1, 5, -3, -2, -4}, 
   {-2, -3, 5, -2, -2}, 
   {-1, -2, -2, 5, -1}, 
   {-3, -4, -2, -1, 0}, 
}; 

int result[300][300]; //
