#include <iostream>
using namespace std;
int main()
{
	int i,j,k,t,l;
	int ciphertext[71],plaintext[71];
	char c;
	while(cin>>k,k)
	{
		cin.get();
		c=cin.get();
		i=0;
		while(c!='\n')
		{
			if(c=='_')
				ciphertext[i++]=0;
			else
				if(c=='.')
					ciphertext[i++]=27;
				else
					ciphertext[i++]=c-96;
			c=cin.get();
		}

		for(j=0;j<i;j++)
		{
			l=0;
			while(1)
			{
				t=ciphertext[j]-28*l+j;
				if(t>=0&&t<28)
					break;
				else
					l++;
			}
			plaintext[(k*j)%i]=t;
		}
		for(j=0;j<i;j++)
			if(plaintext[j]==0)
				cout<<"_";
			else
				if(plaintext[j]==27)
					cout<<".";
				else
					cout<<char(plaintext[j]+96);
		cout<<endl;
	}
	return 0;
}




