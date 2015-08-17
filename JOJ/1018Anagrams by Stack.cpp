#include <iostream>
#include <string>
using namespace std;
class stack
{
private:
	int top;
	char t[11];
public:
	stack();
	int pop();
	void push(int item);
	bool empty();
};

stack::stack()
{
	top=-1;
}

int stack::pop()
{
	int value=t[top];
	top--;
	return value;
}

bool stack::empty()
{
	return top==-1;
}

void stack::push(int item)
{
	top++;
	t[top]=item;
}


int main()
{
	stack s1,s2;
	void proess(stack s1,stack s2,char t1[11],char t2[22],int i,int j);
	char str1[11],str2[11],str3[22];
	int i;
	while(cin.getline(str1,11,'\n'))
	{
		i=0;
		while(str1[i]!='\0')
		{
			s1.push(str1[i]);
			i++;
		}
		s1.push('\0');
		cin.getline(str2,11,'\n');
		cout<<"["<<endl;
		proess(s1,s2,str2,str3,0,11);
		cout<<"]"<<endl;
	}
	return 0;
}

void proess(stack s1,stack s2,char t1[11],char t2[22],int i,int j)
{
	if(!s1.empty())
	{
		s2.push(s1.pop());
		t2[j]='i';
		j++;
		proess(s1,s2,t1,t2,i,j);
	}
	if(!s2.empty())
	{
		t2[i]=s2.pop();
		t2[j]='o';
		j++;i++;
		proess(s1,s2,t1,t2,i,j);
	}
	if(s1.empty()&&s2.empty())
	{
		int k;
		bool flag=1;
		for(k=0;k<i;k++)
			if(t1[k]!=t2[k])
			{
				flag=0;
				break;
			}
		if(flag&&t1[i]=='\0')
		{
			for(k=11;k<j;k++)
				cout<<t2[k]<<" ";
			cout<<endl;
		}
	}
}


		







