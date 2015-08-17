#include <iostream>
using namespace std;
int main()
{
	char str[50],s[50];
	char c;
	int i,n;
	bool flag1,flag2;
	while(cin>>str)
	{
		flag1=1;flag2=1;
		n=strlen(str);
		for(i=0;i<n/2;i++)
			if(str[i]!=str[n-i-1])
			{
				flag1=0;
				break;
			}
		strcpy(s,str);
		for(i=0;i<n;i++)
		{
			switch(str[i])
			{
			case 'E':{str[i]='3';break;}
			case 'J':{str[i]='L';break;}
			case 'L':{str[i]='J';break;}
			case 'S':{str[i]='2';break;}
			case 'Z':{str[i]='5';break;}
			case '2':{str[i]='S';break;}
			case '3':{str[i]='E';break;}
			case '5':{str[i]='Z';break;}
			case 'A':{str[i]='A';break;}
			case 'H':{str[i]='H';break;}
			case 'I':{str[i]='I';break;}
			case 'M':{str[i]='M';break;}
			case 'T':{str[i]='T';break;}
			case 'U':{str[i]='U';break;}
			case 'V':{str[i]='V';break;}
			case 'W':{str[i]='W';break;}
			case 'X':{str[i]='X';break;}
			case 'Y':{str[i]='Y';break;}
			case '1':{str[i]='1';break;}
			case '8':{str[i]='8';break;}
			case 'O':{str[i]='O';break;}
			default :{flag2=0;break;}
			}
			if(flag2==0)
				break;
		}
		if(flag2)
		{
			for(i=0;i<n;i++)
				if(s[i]!=str[n-i-1])
				{
					flag2=0;
					break;
				}
		}
		cout<<s<<" -- ";
		if(flag1)
		{
			if(flag2)
				cout<<"is a mirrored palindrome."<<endl;
			else
				cout<<"is a regular palindrome."<<endl;
		}
		else
		{
			if(flag2)
				cout<<"is a mirrored string."<<endl;
			else
				cout<<"is not a palindrome."<<endl;
		}
		cout<<endl;
	}
	return 0;
}
