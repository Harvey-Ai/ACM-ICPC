#include <iostream>
using namespace std;
int main()
{
	int m,n,access_n,cut;
	while(cin>>n,n)
	{
		m=2;cut=1;
		access_n=n;
		while(access_n>=1)
		{
			if(cut!=0)//��CUT����0�����ʾɾ���������һ��������CUT--��
				cut--;
			access_n--;//���µ�������
			if(access_n==0)
				break;
			cut=(cut+m)%access_n;
			if(cut==1)
			{
				access_n=n;
				m++;
				cut=1;
			}
		}
		cout<<m<<endl;
	}
	return 0;
}





