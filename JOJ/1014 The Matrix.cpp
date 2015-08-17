#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	bool flag1,flag2;
	bool F1,F2,F3,F4,F5,F6,F7,F8;
	int i,j,n=0,N;
	char matrix[20][20];
	char string[20];
	char c;
	
	while(c=cin.get()){
		if(c!='\n'){
			if(c>='a'&&c<='z'){
				matrix[0][n]=c;
				n++;
			}
		}
		else
			break;
	}
	for(i=1;i<=n-1;i++)
		for(j=0;j<=n-1;j++){
			cin>>c;
			if(c>='a'&&c<='z')
				matrix[i][j]=c;
			else
				j--;
		}
	if(n>1)
		c=cin.get();
	while(cin.getline(string,21)){  
		flag1=0;
		N=strlen(string);

		for(i=0;i<=2;i++)
			if(string[i]!='X')
				flag1=1;
		if(flag1==0)
			break;

		for(i=0;i<=n-1;i++){
			for(j=0;j<=n-1;j++){
				F1=1;F2=1;F3=1;F4=1;F5=1;F6=1;F7=1;F8=1;
				flag2=0;
				if(matrix[i][j]==string[0])
					flag2=1;

				if(flag2)
					for(int l=0;l<=N-1;l++){
						if(string[l]!=matrix[i][j+l])
							F1=0;
						if(string[l]!=matrix[i-l][j+l])
							F7=0;
						if(string[l]!=matrix[i+l][j+l])
							F5=0;
						if(string[l]!=matrix[i][j-l])
							F2=0;
						if(string[l]!=matrix[i-l][j-l])
							F6=0;
						if(string[l]!=matrix[i+l][j-l])
							F8=0;
						if(string[l]!=matrix[i+l][j])
							F3=0;
						if(string[l]!=matrix[i-l][j])
							F4=0;
						}
				else{
					F1=0;F2=0;F3=0;F4=0;F5=0;F6=0;F7=0;F8=0;
				}
				if(F1+F2+F3+F4+F5+F6+F7+F8)
					break;
			}
			if(F1+F2+F3+F4+F5+F6+F7+F8)
				break;
		}
		if(F1+F2+F3+F4+F5+F6+F7+F8)
			cout<<string<<" is in the matrix."<<endl;
		else
			cout<<string<<" is not in the matrix."<<endl;
	}
	return 0;
}