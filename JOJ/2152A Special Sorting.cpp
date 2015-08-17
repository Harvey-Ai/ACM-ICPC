//baby
//accident
//accidental
//accept
//yes

#include <iostream>
#include <string>
using namespace std;
char letter[3][26]={{'q','w','e','r','t','y','u','i','o','p','\0'},{'a','s','d','f','g','h','j','k',
		'l','\0'},{'z','x','c','v','b','n','m','\0'}};
int main()
{
	bool cp(char str1[],char str2[]);
	char str[1500][300],temp[300],c;
	int i=0,j,n;
	bool flag=1;
	while(cin.get(str[i++][0]))
	{
		j=1;
		c=cin.get();
		while(c!='\n')
		{
			str[i-1][j]=c;
			c=cin.get();
			j++;
		}
		str[i-1][j]='\0';
	}
	n=i-1;
	while(flag)
	{
		flag=0;
		for(i=0;i<n-1;i++)
			if(cp(str[i],str[i+1]))
			{
				strcpy(temp,str[i]);
				strcpy(str[i],str[i+1]);
				strcpy(str[i+1],temp);
				flag=1;
			}
	}
	for(i=0;i<n;i++)
		cout<<str[i]<<endl;
	return 0;
}


bool cp(char str1[],char str2[])
{
	int i=0,l,r,line1=-1,line2=-1,row1=0,row2=0;
	while(str1[i]!='\0'&&str2[i]!='\0')
	{
		if(str1[i]==str2[i])
		{
			i++;
			continue;
		}
		for(l=0;l<3;l++)
		{
			r=0;
			while(letter[l][r]!='\0')
			{
				if(str1[i]==letter[l][r])
				{
					line1=l;
					row1=r;
				}
				if(str2[i]==letter[l][r])
				{
					line2=l;
					row2=r;
				}
				r++;
			}
			if((line1+1)&&(line2+1))
				break;
		}
		if(line1<line2)
			return 1;
		if(row1<row2&&line1==line2)
			return 1;
		return 0;
	}
	if(str1[i]!='\0'&&line1==line2&&row1==row2)
		return 1;
	else
		return 0;
}

		









			

